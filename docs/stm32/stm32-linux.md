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