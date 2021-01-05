# 目录
- [目录](#目录)
- [Relu 函数](#relu-函数)
- [卷积计算过程](#卷积计算过程)
  - [TF描述卷积计算层](#tf描述卷积计算层)
- [感受野](#感受野)
- [全零填充 (Padding)](#全零填充-padding)
- [批标准化 (Batch Normalization, BN)](#批标准化-batch-normalization-bn)
- [池化 (Pooling)](#池化-pooling)
- [舍弃 (Dropout)](#舍弃-dropout)
- [CNN 网络架构](#cnn-网络架构)


<!-- https://www.zybuluo.com/hanbingtao/note/485480 -->

全连接神经网络是一种很重要的神经网络，但是对于图像识别并不是很友好。

- 参数数量太多。当我们输入的是一张 $100 \times 100$ 的图像时，其输入参数为 $100 \times 100  \times 3_{channels}=30000$，实在是太多了，如果扩展到 $1920 \times 1080$ 的 $1080p$ 图像时，输出参数就有 $2073600$ 个，仅灰度图像就有 $200$ 多万个参数，训练难度可想而知。并且待优化参数过多容易导致模型过拟合。
- 没有使用像素的位置信息。如果使用全连接网络的话，输入值就是按照离散的像素点进行输入，相邻像素点直接的关联性就被破坏了。
- 网络层数不可能太多。参数太多，就导致了网络的层数不可能太深

图像特征的提取需要采用卷积的方法，因此，**卷积神经网络** (CNN, Convolutional Neural Network) 就出现了。
<!-- 局部连接 这个是最容易想到的，每个神经元不再和上一层的所有神经元相连，而只和一小部分神经元相连。这样就减少了很多参数。
权值共享 一组连接可以共享同一个权重，而不是每个连接有一个不同的权重，这样又减少了很多参数。
下采样 可以使用Pooling来减少每层的样本数，进一步减少参数数量，同时还可以提升模型的鲁棒性。 -->

卷积神经网络更加适用于**图像**、**语言**识别的任务



# Relu 函数
在全连接神经网络中，我们使用了 `Sigmoid`函数 作为激活函数来解决阶跃函数 `sgn` 不连续的特点。

但是 `Sigmoid`函数 包含了指数运算 $e^{-x}$ ，计算复杂度就比较大了。

在全连接网络的反向传播的过程中，每经过一层 `Sigmoid`激活层，就会乘上一个`Sigmoid`的导数，其导数最大值为$0.25$，这就导致在`Sigmoid`函数作为激活函数的**深度**神经网络中，会产生梯度消失的问题。

因此几年来，新的激活函数 `Relu` 使用得越来越多了。

**Relu** 函数的定义是
$$\begin{aligned}
    f(X)=max(0,x)
\end{aligned}$$
![Relu](img/relu.png)

Relu函数的有如下优势
- **计算速度快**
- **减轻梯度消失**，
  ![d(sigmod)/dx](img/derivativeOfSigmoid.png)


- **稀疏性**，通过对大脑的研究发现，大脑在工作的时候只有大约5%的神经元是激活的，而采用sigmoid激活函数的人工神经网络，其激活率大约是50%。有论文声称人工神经网络在15%-30%的激活率时是比较理想的。因为relu函数在输入小于0时是完全不激活的，因此可以获得一个更低的激活率。

# 卷积计算过程
![Conv2D](img/con2d.gif)
2D
## TF描述卷积计算层
# 感受野
**感受野（Receptive Field）** 定义是卷积神经网络每一层输出的特征图（feature map）上的像素点在输入图片上映射的区域大小。即，特征图上的一个点对应输入图上的区域

![cnn](img/cnn-3x3_5x5conv.png)

> 假定图片的长、宽均为 $m$ ，卷积计算步长为 $1$

- $3 \times 3$ 卷积核的参数量：$3 \times 3 + 3 \times 3=18$（两次卷积过程，各有一个$3 \times 3$卷积核），计算量：$9(m-2)^2+9(m-4)^2=m^2-108m+180$
- $5 \times 5$ 卷积核的参数量：$5 \times 5=25$，计算量：$25(m-4)^2=25m^2-200ml+400$

当 $m>10$ 时，两层 $3 \times 3$ 卷积核的计算性能优于 一层 $5 \times 5$ 卷积核

<!-- https://www.bilibili.com/video/BV1B7411L7Qt?p=27 -->


# 全零填充 (Padding)
输出图片边长
- 全零填充: $\frac{输入图片边长}{步长}$
- 非全零填充: $\frac{输入图片边长-核边长+1}{步长}$

tensorflow 描述全零填充
```python
padding = 'SAME'    # 全零填充
padding = 'VALID'   # 非全零填充
```
# 批标准化 (Batch Normalization, BN)
# 池化 (Pooling)
# 舍弃 (Dropout)

# CNN 网络架构
![CNN Architecture](img/NetworkArchitecture.png)

CNN 网络架构 (Architecture) 包括:
- **卷积层** (Convolution Layer)
- **池化层** (Polling Layer)
- **全连接层** (Fully Connected Layer)



