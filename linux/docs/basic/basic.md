# 目录
- [目录](#目录)
- [常用命令](#常用命令)
  - [文件管理](#文件管理)
    - [ls-显示目录下的内容及属性](#ls-显示目录下的内容及属性)
    - [文件属性](#文件属性)
- [环境变量](#环境变量)
- [软链接](#软链接)
- [安装常用的软件](#安装常用的软件)

# 常用命令
可以查询 [Linux命令大全(手册)](https://www.linuxcool.com/)
## 文件管理
### ls-显示目录下的内容及属性
语法格式: 
```bash
ls [options] [dirx]
[options]:
-a 显示所有文件及目录 (. 开头的隐藏文件也会列出)
-l 除文件名称外，亦将文件型态、权限、拥有者、文件大小等资讯详细列出
-r 将文件以相反次序显示(原定依英文字母次序)
-t 将文件依建立时间之先后次序列出
-A 同 -a ，但不列出 "." (目前目录) 及 ".." (父目录)
-F 在列出的文件名称后加一符号；例如可执行档则加 "*", 目录则加 "/"
-R 若目录下有文件，则以下之文件亦皆依序列出
```

```bash
$ ls /usr/local/opencv4/
bin  include  lib  share
```

```bash
$ ls /usr/local/opencv4/ -l
drwxr-xr-x 2 root root  4096 1月   3 17:11 bin
drwxr-xr-x 3 root root  4096 1月   3 17:11 include
drwxr-xr-x 6 root root 12288 1月   3 17:11 lib
drwxr-xr-x 4 root root  4096 1月   3 17:11 share

$ ll /usr/local/opencv4/
总用量 32
drwxr-xr-x  6 root root  4096 1月   3 17:11 ./
drwxr-xr-x 12 root root  4096 1月   5 20:13 ../
drwxr-xr-x  2 root root  4096 1月   3 17:11 bin/
drwxr-xr-x  3 root root  4096 1月   3 17:11 include/
drwxr-xr-x  6 root root 12288 1月   3 17:11 lib/
drwxr-xr-x  4 root root  4096 1月   3 17:11 share/
```

### 文件属性
```bash
$ ls /usr/local/opencv4/ -l
drwxr-xr-x 2 root root  4096 1月   3 17:11 bin
```
`drwxr-xr-x`
|    d     |   rwx    |   r-x    |     r-x      |
| :------: | :------: | :------: | :----------: |
| 文件类型 | 属主权限 | 属组权限 | 其他用户权限 |
- 文件类型
  - 当为 `d` 则是目录
  - 当为 `-` 则是文件；
  - 若是 `l` 则表示为链接文档(link file)；
  - 若是 `b` 则表示为装置文件里面的可供储存的接口设备(可随机存取装置)；
  - 若是 `c` 则表示为装置文件里面的串行端口设备，例如键盘、鼠标(一次性读取装置)。
- 属主权限： **文件的所有者** 拥有该文件的权限
- 属组权限： **所有者的同组用户** 拥有该文件的权限
- 其他用户权限

权限每三个一组 `rwx` ，`r` 可读(read)、 `w` 可写(write)、 `x` 可执行(execute)。位置是固定的，`-` 则表示没有权限，



|     2      |  root  | root  | 4096  | 1月 3 17:11  |  bin   |
| :--------: | :----: | :---: | :---: | :----------: | :----: |
| 硬链接数目 | 用户名 | 组名  | 大小  | 最后修改时间 | 文件名 |



# 环境变量
- 修改家目录下的 .bashrc 文件
- 修改 /etc/profile 文件

```bash
变量名=变量值
...=...
export 变量名 ...
```

如：
```bash

JAVA_HOME=/opt/jdk1.8.0_91
CLASSPATH=.:./bin
PATH=$JAVA_HOME/bin:$PATH
export JAVA_HOME CLASSPATH PATH
```


```bash
source ~/.bashrc
```
或
```bash
source /etc/profile
```
# 软链接
```bash
sudo rm /usr/bin/python
sudo ln -s /usr/bin/python3 /usr/bin/python
ls -l /usr/bin | grep python
```

# 安装常用的软件
```bash
sudo apt install -y htop
sudo apt install -y vim gedit
sudo apt install -y git
sudo apt install -y gcc g++ cmake


# ------ Python -------------------------------
sudo apt install -y python3
sudo apt install -y python3-pip
pip3 install numpy
# ---------------------------------------------


# ------ SouGouPinYin -------------------------
# https://www.jb51.net/article/186808.htm
sudo apt install -y fcitx-bin
sudo apt install -y fcitx-table
# sudo dpkg -i sogoupinyin_2.3.1.0112_amd64.deb
# sudo apt install -f
# -- settings–>Region&language–>Manage Installed Languages
# -- 更改输入框架为fcitx，然后点击上面的Apply System-Wide应用到全局
# ---------------------------------------------

# https://mirrors.tuna.tsinghua.edu.cn/qt/archive/qt/5.14/5.14.2/qt-opensource-linux-x64-5.14.2.run
# https://wdl1.cache.wps.cn/wps/download/ep/Linux2019/9719/wps-office_11.1.0.9719_amd64.deb
sudo apt autoremove
```



[Desktop Entry]
Type=Application
Version=5.14.2
Name=QtCreator
Comment=QtCreator #鼠标放上去时的文字提示
Icon=/opt/Qt5.14.2/Tools/QtCreator/share/doc/qtcreator/qtcreator-dev/images/logo.png #要显示的图标绝对路径
Exec=/opt/Qt5.14.2/Tools/QtCreator/bin/qtcreator #启动程序
Terminal=false
Categories=Development;IDE;C++; #应用程序在菜单项中的分类，在我的系统中在 应用程序-》系统工具下