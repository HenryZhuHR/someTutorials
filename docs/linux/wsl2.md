# 快速引导

# 安装
https://docs.microsoft.com/zh-cn/windows/wsl/

# Linux安装图形界面
## 更新软件
```bash
sudo apt-get update
sudo apt-get upgrade -y
```

## 安装 Gnome 桌面的必要元素
```bash
sudo apt-get install tasksel -y
sudo tasksel
# 选择 “Ubuntu Desktop”，空格选择，tab移动到ok，确定安装
# 然后用 Tab 键选择 “OK”，回车确定
# 接着就是等待，如果突然退出，遇到 “tasksel: apt-get failed (100)”
# 这时要重新运行上面最后一条命令，并且重新选择 “Ubuntu Desktop”
# 安装完成会出现 “xserver-xorg install”
```


## 安装 VNC 服务器端软件
```bash
sudo apt-get install -y tigervnc-standalone-server
```
## 安装 DotNet
```bash
wget https://packages.microsoft.com/config/ubuntu/20.04/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb
sudo apt-get update
sudo apt-get install -y dotnet-runtime-3.1
```

## 安装配置 LightDM
### 安装 LightDM
```bash
sudo apt-get install -y lightdm
```
### 选择 GDM，还是 LightDM
这里建议选择 LightDM
```bash
sudo dpkg-reconfigure lightdm
```


## 配置 XVnc
### 设置 VNC 登录密码
```bash
# 为你的一般用户设置，密码：00000000，不用设置 “view-only password”，直接选择 “n”
vncpasswd
# 为你的 root 用户设置，密码：00000000，不用设置 “view-only password”，直接选择 “n”
sudo vncpasswd
# 如果窗口管理器选择的是 GDM
sudo -u gdm vncpasswd
## 如果选择的是 LightDM
sudo -u lightdm vncpasswd
```
### 替换原来的 X Server
```bash
sudo mv /usr/bin/Xorg /usr/bin/Xorg_old
sudo vim /usr/bin/Xorg
```

键入以下内容到 Xorg 文件：
```txt
#!/bin/bash
for arg do
  shift
  case $arg in
    # Xvnc doesn't support vtxx argument. So we convert to ttyxx instead
    vt*)
      set -- "$@" "${arg//vt/tty}"
      ;;
    # -keeptty is not supported at all by Xvnc
    -keeptty)
      ;;
    # -novtswitch is not supported at all by Xvnc
    -novtswitch)
      ;;
    # other arguments are kept intact
    *)
      set -- "$@" "$arg"
      ;;
  esac
done

# Here you can change or add options to fit your needs
## command=("/usr/bin/Xvnc" "-geometry" "2736x1824" "-PasswordFile" "${HOME:-/root}/.vnc/passwd" "$@") 
# Because my host monitor resolution matches 1440x860
command=("/usr/bin/Xvnc" "-geometry" "1440x860" "-PasswordFile" "${HOME:-/root}/.vnc/passwd" "$@") 

systemd-cat -t /usr/bin/Xorg echo "Starting Xvnc:" "${command[@]}"

exec "${command[@]}"
```

更改 Xorg 文件的文件权限属性
```bash
sudo chmod 0755 /usr/bin/Xorg
```

## 安装 Systemd-Genie
```bash
curl -s https://packagecloud.io/install/repositories/arkane-systems/wsl-translinux/script.deb.sh | sudo bash
sudo apt-get install -y systemd-genie
```
## 调整 SystemD-Genie for Ubuntu
```bash
sudo mkdir /usr/lib/genie/
sudo vim /usr/lib/genie/deviated-preverts.conf
```
键入以下内容：

```bash
{
  "daemonize": "/usr/bin/daemonize"
}
```

## 启动 SystemD-Genie
启动 SystemD-Genie 只需要一行命令

```bash
genie -s
```
现在就可以通过 VNC 客户端软件访问 Ubuntu 20.04 图形界面了。

在 WSL Ubuntu 中可以通过 hostname -I | awk '{print $1}' 命令获取 Ubuntu 的 IP 地址。

Windows 下的免费 VNC 软件：https://www.uvnc.com/downloads/ultravnc.html 。用迅雷下载会快很多。

安装好 UltraVNC 后，在 “开始” 菜单启动 “UltraVNC Viewer”，然后输入 WSL Ubuntu 的 IP 地址，连接成功后输入上面 “vncpasswd” 命令所设置的密码，即可登录 上 VNC 。



## 通过 Windows 的 X-Windows 服务端软件登录 WSL Ubuntu
### 配置 LightDM，使之使用 XDMCP 替代 VNC 方式登录图形界面
```bash
sudo vim /etc/lightdm/lightdm.conf
```
文件不存在会创建新文件。输入以下内容：

```bash
[LightDM]
start-default-seat=false

[XDMCPServer]
enabled=true
port=177
```

重启 LightDM，此步骤只在运行 genie -s 时有效。。

```bash
sudo service lightdm restart
```
如果没有运行 genie -s ，那么就要重启 WSL Ubunttu 20.04 ，从而使配置生效：

如果想要重新启用 VNC，只须把 /etc/lightdm/lightdm.conf 文件中的下面两行注释掉，然后重启 LightDM 。

```bash
#[LightDM]
#start-default-seat=false
```
在 Windows 的终端上运行 wsl.exe -t Ubuntu-20.04，然后运行 ubuntu2004.exe

### 下载并安装基于 Windows 的 X-server 服务端软件 “VcXsrv Windows X Server”
到 https://sourceforge.net/projects/vcxsrv/ 这里下载，建议用迅雷下载。

### VcXsrv 的使用
#### 连接
打开 “开始” 菜单，然后选择 “XLaunch”。

步骤一，运行 “XLaunch” ，得到一个窗口界面，选择右下角，也就是 “One window without titlebar” ，然后点击 “下一步”。
步骤二，选择 “Open session via XDMCP” , 然后点击 “下一步”。
步骤三，在 “Connect to host” 输入框中输入 WSL Ubuntu 的 IP 地址，然后点击 “下一步”。
步骤四，选择 “Clipboard” 和 “Disable access control” ，同时取消选择 “Native opengl”。然后点击 “下一步”。
步骤五，点击 “完成”。
步骤六，如果 “VcXsrv” 是第一次连网，那么就会弹出 Windows 防火墙选择，通常需要既选择 “专用网络” （private），也要选择 “公用网络” （public） 。然后点击 “允许访问” 。
然后就可以见到 Ubuntu 20.04 的登录界面了。输入系统用户密码便可登录系统。

#### 退出 WSL 的图形用户界面
从 Ubuntu 20.04 注销，然后直接关闭退出 “XLaunch“ 。






