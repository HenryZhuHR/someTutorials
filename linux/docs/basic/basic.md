# 目录
- [目录](#目录)
- [环境变量](#环境变量)
- [软链接](#软链接)
- [安装常用的软件](#安装常用的软件)

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