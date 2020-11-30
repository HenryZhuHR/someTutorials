# 导航
- [导航](#导航)
- [官方手册](#官方手册)
- [命令行启动](#命令行启动)
- [接口配置文件](#接口配置文件)
  - [接口配置文件](#接口配置文件-1)
  - [板配置文件](#板配置文件)

# 官方手册

[OpenOCD User’s Guide](http://openocd.org/doc/html/index.html)

# 命令行启动
```bash
openocd \
    -f "interface/stlink-v2-1.cfg" \
    -f "target/stm32f4x.cfg" \
    -c "program ./build/stm32-test-makefile.hex"

```


# 接口配置文件
## 接口配置文件
接口文件配置
```cfg
# interface config
source [find interface/FOOBAR.cfg]
```
## 板配置文件
```cfg
# board config
source [find board/FOOBAR.cfg]
```