# 导航
- [导航](#导航)
- [安装依赖](#安装依赖)
  - [安装 STM32CubeMX](#安装-stm32cubemx)
    - [安装 JRE 环境](#安装-jre-环境)
    - [命令行安装 STM32CubeMX](#命令行安装-stm32cubemx)
  - [安装 OpenOCD](#安装-openocd)
    - [源码编译 OpenOCD](#源码编译-openocd)
    - [从 apt 获取 openocd](#从-apt-获取-openocd)
  - [安装 gcc](#安装-gcc)
  - [安装 GDB](#安装-gdb)
  - [安装ST-Link驱动](#安装st-link驱动)
    - [源码编译stlink](#源码编译stlink)
      - [安装 Release 版本](#安装-release-版本)
      - [安装 Debug 版本](#安装-debug-版本)
      - [添加udev规则](#添加udev规则)
- [文件说明](#文件说明)
- [调试](#调试)

# 安装依赖

## 安装 STM32CubeMX
### 安装 JRE 环境
```bash
# 更新软件包列表
sudo apt update

# 安装jdk8
sudo apt install -y openjdk-8-jdk

# 查看是否安装成功
java -version

# 卸载，如果不再需要 jre 环境的时候
sudo apt autoremove -y openjdk-8-jre
```

### 命令行安装 STM32CubeMX
下载 [STM32CubeMX](https://www.st.com/content/st_com/zh/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-configurators-and-code-generators/stm32cubemx.html)

```bash
sudo chmod 700 ./SetupSTM32CubeMX-6.0.1.linux

sudo ./SetupSTM32CubeMX-6.0.1.linux
# 按 1 enter 1 enter 1 1 y
# Press 1 to continue, 2 to quit, 3 to redisplay
# Press Enter to continue, X to exit
# Press 1 to accept, 2 to reject, 3 to redisplay
# Press Enter to continue, X to exit
# Press 1 to accept, 2 to reject, anything else to redisplay
# Press 1 to accept, 2 to reject, anything else to redisplay
# ...
# Generate an automatic installation script
# Enter Y for Yes, N for No:

cd ..
```
## 安装 OpenOCD
### 源码编译 OpenOCD
```bash
# clone
git clone --depth 1 git://git.code.sf.net/p/openocd/code openocd
cd openocd

# 安装依赖
sudo apt install -y libtool libsysfs-dev
sudo apt install -y make

# 编译源码
./bootstrap
./configure
make
sudo make install

# 检查是否安装成功
openocd --version

# 回到上级目录
cd ..
```
### 从 apt 获取 openocd
sudo apt install openocd


## 安装 gcc

```bash
sudo apt install -y gcc-arm-none-eabi
```

## 安装 GDB
```bash
# 添加源：deb http://cz.archive.ubuntu.com/ubuntu xenial main universe
sudo vim /etc/apt/sources.list

sudo apt update 
sudo apt install -y gdb-arm-none-eabi
```

## 安装ST-Link驱动

- `Linux`  We recommend to install `stlink-tools` from the package repository of the used distribution:
```bash
sudo apt install -y libusb-dev
sudo apt install -y libusb-1.0-0-dev
sudo apt install git libusb-1.0.0-dev
sudo apt install -y stlink-tools
```

### 源码编译stlink

[stlink Github](https://github.com/stlink-org/stlink)
```bash
sudo apt install -y gcc
sudo apt install -y build-essential
sudo apt install -y cmake
sudo apt install -y libusb-1.0
sudo apt install -y libusb-1.0-0-dev
sudo apt install git libusb-1.0.0-dev
sudo apt install -y libgtk-3-dev
sudo apt install -y pandoc
```

```bash
git clone --depth 1 https://github.com/stlink-org/stlink.git stlink
sudo chmod 777 stlink
cd stlink
```
#### 安装 Release 版本
```bash
# required by some linux variants.
make clean

# create the Release target
make release
```
用户安装，系统安装
```bash
# install to a user folder e.g $HOME:
cd build/Release && make install DESTDIR=$HOME

# install to system wide:
cd build/Release && sudo make install

```

#### 安装 Debug 版本
```bash
# required by some linux variants.
make clean

# create the Debug target (optional)
make debug
```
#### 添加udev规则
添加udev规则，让应用程序可以访问STlink仿真器设备
查看目录下是否有 `stlink` 的规则文件 `*.rules`
```bash
$ ls config/udev/rules.d/
49-stlinkv1.rules  49-stlinkv2-1.rules  49-stlinkv2.rules  49-stlinkv3.rules
```
复制这些文件到系统 `/etc/udev/rules.d/` 目录中，并且重新加载udev规则
```bash
sudo ldconfig
sudo cp config/udev/rules.d/* /etc/udev/rules.d/
sudo udevadm control --reload-rules
udevadm trigger
```
重启终端，输入
```bash
st-info –-version
```

在 `Makefile` 文件最后加上：
```makefile
#######################################
# clean up
#######################################
flash:
	st-flash write build/$(TARGET).bin 0x8000000
```
使用命令 ``make flash`` 就能下载程序到MCU里面去了

# 文件说明
里面有一个 `STM32F401RETx_FLASH.ld`、Makefile.include文件，其中 `STM32F401RETx_FLASH.ld` 文件是芯片的连接脚本文件，这个根据你的芯片来选择，Makefile.include是用来编译项目的文件，具体的请看Makefile相关手册。 

# 调试
```bash
sudo st-util 
arm-none-eabi-gdb 
tar extended-remote :4242 
load dfu.elf 
```