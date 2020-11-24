# 快速引导

# 安装
https://docs.microsoft.com/zh-cn/windows/wsl/

# Linux安装图形界面
准备工作

WSL 不支持 systemd 而 Gnome 桌面又是基于 systemd，所以先解决这个问题。（参考：https://github.com/DamionGans/ubuntu-wsl2-systemd-script）
```bash
sudo apt update
sudo apt install git
git clone https://github.com/DamionGans/ubuntu-wsl2-systemd-script.git
cd ubuntu-wsl2-systemd-script/
bash ubuntu-wsl2-systemd-script.sh
```
重新启动子系统，或者重启电脑也行。

 

开始操作（参考：https://developer.aliyun.com/article/764492）


安装 Gnome 桌面
```bash
sudo apt update
sudo apt install -y ubuntu-desktop
```


安装 Xrdp
```bash
sudo apt install -y xrdp
sudo systemctl status xrdp
```

每次启动前运行：
```bash
sudo adduser xrdp ssl-cert
sudo systemctl restart xrdp
```

查看一下配置文件中的端口（默认：3389）
```bash
vim /etc/xrdp/xrdp.ini
```

配置防火墙
```bash
sudo ufw allow 3389
```
