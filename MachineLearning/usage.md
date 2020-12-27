# Usage of Darknet
- [Usage of Darknet](#usage-of-darknet)
- [工程结构](#工程结构)
- [编译](#编译)
  - [编译 CPU 版本](#编译-cpu-版本)
  - [编译 GPU 版本](#编译-gpu-版本)
    - [安装CUDA和cuDNN](#安装cuda和cudnn)
    - [修改makefile](#修改makefile)
    - [编译 gpu 版本](#编译-gpu-版本-1)
- [训练](#训练)

# 工程结构
```bash
tree -d
.
├── 3rdparty
│   ├── pthreads
│   │   ├── bin
│   │   ├── include
│   │   └── lib
│   └── stb
│       └── include
├── build
│   └── darknet
│       └── x64
│           ├── backup
│           ├── cfg
│           ├── data
│           │   ├── labels
│           │   └── voc
│           └── results
├── cfg
│   └── yolov1
├── cmake
│   └── Modules
├── data
│   └── labels
├── include
├── results
├── scripts
│   ├── log_parser
│   └── windows
└── src
```

```bash
tree -d
.
├── 3rdparty    # 
├── build       # 
├── cfg         # 模型结构文件
├── cmake
├── data        # 数据集文件
├── include     # 头文件
├── results     # 训练结果
├── scripts     
└── src
```


# 编译

## 编译 CPU 版本
在当前目录下
```bash
make
```

编译完成后，直接运行
```bash
./darknet
```

## 编译 GPU 版本
### 安装CUDA和cuDNN
检查自己的电脑是否有 Nvidia 的独立显卡
```bash
nvidia-settings
```
以及英伟达系统管理接口（NVIDIA System Management Interface, 简称 nvidia-smi）。这是是基于NVIDIA Management Library (NVML) 的命令行管理组件,旨在(intened to )帮助管理和监控NVIDIA GPU设备。  
在训练的时候可以看到信息
```bash
$ nvidia-smi 
Sun Dec 27 16:07:04 2020       
+-----------------------------------------------------------------------------+
| NVIDIA-SMI 455.38       Driver Version: 455.38       CUDA Version: 11.1     |
|-------------------------------+----------------------+----------------------+
| GPU  Name        Persistence-M| Bus-Id        Disp.A | Volatile Uncorr. ECC |
| Fan  Temp  Perf  Pwr:Usage/Cap|         Memory-Usage | GPU-Util  Compute M. |
|                               |                      |               MIG M. |
|===============================+======================+======================|
|   0  GeForce MX250       Off  | 00000000:01:00.0 Off |                  N/A |
| N/A   55C    P0    N/A /  N/A |    644MiB /  2002MiB |      0%      Default |
|                               |                      |                  N/A |
+-------------------------------+----------------------+----------------------+
                                                                               
+-----------------------------------------------------------------------------+
| Processes:                                                                  |
|  GPU   GI   CI        PID   Type   Process name                  GPU Memory |
|        ID   ID                                                   Usage      |
|=============================================================================|
|    0   N/A  N/A       917      G   /usr/lib/xorg/Xorg                 61MiB |
|    0   N/A  N/A      1484      G   /usr/lib/xorg/Xorg                150MiB |
|    0   N/A  N/A      1660      G   /usr/bin/gnome-shell              257MiB |
|    0   N/A  N/A      2072      G   ...gAAAAAAAAA --shared-files       42MiB |
|    0   N/A  N/A   1971566      G   ...AAAAAAAAA= --shared-files      111MiB |
+-----------------------------------------------------------------------------+
```
我们可以看到我们显卡的型号 `GeForce MX250`，显存大小及使用情况 `644MiB /  2002MiB`，驱动版本及CUDA版本

安装`CUDA10.1`，配置用户环境变量
```bash
vim ~/.bashrc
```
添加以下内容
```bash
# ------ CUDA 10.1 ------
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/cuda-10.1/lib64
export PATH=$PATH:/usr/local/cuda-10.1/bin
export CUDA_HOME=$CUDA_HOME:/usr/local/cuda-10.1
```
执行命令使其生效
```bash
source ~/.bashrc
```
验证是否安装成功
```bash
$ nvcc -V
nvcc: NVIDIA (R) Cuda compiler driver
Copyright (c) 2005-2019 NVIDIA Corporation
Built on Sun_Jul_28_19:07:16_PDT_2019
Cuda compilation tools, release 10.1, V10.1.243
```
下载 [cuDNN](https://developer.nvidia.com/zh-cn/cudnn)（需要登录）

### 修改makefile
在 [Makefile](./Makefile) 文件中（大约1～9行）
将
```makefile
GPU=0
CUDNN=0
CUDNN_HALF=0
OPENCV=0
AVX=0
OPENMP=0
LIBSO=0
ZED_CAMERA=0
ZED_CAMERA_v2_8=0
```
修改为
```makefile
GPU=1
CUDNN=1
CUDNN_HALF=0
OPENCV=0
AVX=0
OPENMP=0
LIBSO=0
ZED_CAMERA=0
ZED_CAMERA_v2_8=0
```

### 编译 gpu 版本
然后在当前目录下
```bash
make
```



# 训练
https://blog.csdn.net/u010122972/article/details/83541978




<!-- cudnn 链接 -->
https://developer.download.nvidia.cn/compute/machine-learning/cudnn/secure/8.0.4/10.1_20200923/cudnn-10.1-linux-x64-v8.0.4.30.tgz?oF254u_6JOFlv6n8TyhocCJHXQARhnEfrcbPgSu0FXFO_DBJgmUM1ozGGGk2U-ZfHlJXDZdk7mNwSjAnAEt1YIF1zlYapFVBE4FrUHsYCY0qXV2GDSpsHNeSq9ew83qiFzOWzLc6CvDE7hW8qDZEXspt16c4YLLLZynkjJ9DsoQhFFvcKtnwehz01MGipo2vIgcV4GQGZD_C8aY

https://developer.download.nvidia.cn/compute/machine-learning/cudnn/secure/7.6.5.32/Production/10.1_20191031/cudnn-10.1-linux-x64-v7.6.5.32.tgz?NzGTFQ61JP3MLKVpj--VWaQ44V-5RmrznTMhQtHWCVFwRnLtVUC85iiCaB0QzEuh3m97DLSsKVeReF-TzJOiq3tTwOTs4vbil5obErRMR3-6dXErqfM-URzq_sBVGlS-PLUuxAfil4fjnlpbW_C3XcZOC2G6CzBH4q9P52F7FrVxuLH8br-bnzEzvFK84fZKRP5snL-9fIVaLAvDL47MlfP4tqUyiPXDpg


下载解压之后，将cuda/include/cudnn.h文件复制到usr/local/cuda/include文件夹，将cuda/lib64/下所有文件复制到/usr/local/cuda/lib64文件夹中，并添加读取权限：
sudo chmod a+r /usr/local/cuda/include/cudnn.h /usr/local/cuda/lib64/libcudnn*
