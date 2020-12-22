# Back Propagation Neural Networks
- [Back Propagation Neural Networks](#back-propagation-neural-networks)
- [神经元模型](#神经元模型)
  - [M-P 神经元模型](#m-p-神经元模型)
    - [激活函数](#激活函数)
  - [感知机与多层网络](#感知机与多层网络)
- [BP神经网络原理](#bp神经网络原理)
  - [传递函数](#传递函数)
  - [激活函数](#激活函数-1)
  - [前向传播](#前向传播)

171 186 123
68775018
202.114.107.171
202.114.107.186
202.114.107.123
202.114.107.210


# 神经元模型
## M-P 神经元模型
基本神经元模型中，神经元接收到来自$n$个其他神经元传递过来的输入信号，这些输入信号通过带权重的连接(connection)进行传递  
神经元接收到的总输入值将与神经元的阈值进行比较，然后通过 **激活函数（activation function）** 处理以产生神经元的输出

神经元模型如下

![neuron](img/neuron.png)

$x_i$ 是来自第 $i$ 个神经元的输入，每个神经元会接收到 $n$ 个神经元的输入。每个输入值会占据一定的权重
$$\begin{aligned}
  \omega_i x_i
\end{aligned}$$

所有输入加权后进行累加
$$\begin{aligned}
  \sum_{i=1}^{n}\omega_i x_i
\end{aligned}$$

当该累加值超过一定的阈值 $\theta$ 之后，该神经元就会被“激活”
$$\begin{aligned}
  f(\sum_{i=1}^{n}\omega_i x_i-\theta)
\end{aligned}$$

该神经元“激活”之后，就会向其他神经元发送信息，这个信息就是该神经元的输出 $y$
$$\begin{aligned}
  y=f(\sum_{i=1}^{n}\omega_i x_i-\theta)
\end{aligned}$$

- 为什么要加权 $\omega_i$？
> 每个输入信息对于结果会有不同的影响，而我们需要衡量每个输入对于结果产生的影响的程度就需要这样一个权重。  
> 翻译成人话就是，你对象和你舍友都在你生日送礼物，但是你收到两个礼物之后的开心程度(应该？)是不一样的。

- `激活`是含义？
> 其实和和生物学上的定义是类似的，神经元的电位超过一定`阈值`之后就会被激活。当神经网络中的神经元接收到的值超过`阈值`$\theta$ 时，才会将信息继续传递，或者说，才会产生输出。  
> 翻译成人话就是，你在生日收到足够多的礼物之后，才会开心。  
> 因此，产生一个词叫`激活函数`，激活函数所做的事情就是去判定该`阈值`、衡量`多少礼物才叫足够多`这个问题。  

- 激活函数
> **理想**的**激活函数**是一个**阶跃函数**，如下  
> ![sgn](img/sgn.png)  
> 可以看到当输入的值大于0的时候，会输出1，这时候该神经元表现为`激活状态`，输出的1是对下一个神经元有贡献的，也就是说该神经元的输出是可以传递给下一个神经元；  
> 当输入的值小于0的时候，会输出0，0对于下一个神经元没有贡献，这时候的神经元是`未激活`的。  
> 这里的**贡献**是指，下一个神经元接收到的 $x_i=0$ ，那也就不会对下一个神经元产生任何影响；下一个神经元接收到的 $x_i\neq 0$时，那么会对下一个神经元产生影响   
> 减去阈值 $\theta$ 再激活，也就是把判断是否`激活`的条件统一成 $x\geq0$ (便于计算)，如下
> $$\begin{aligned}
  sgn(x)=
  \begin{cases}
    1,& x\geq\theta \\
    0,& x<\theta
  \end{cases}
\end{aligned}$$
> $$\begin{aligned}
  sgn(x-\theta)=
  \begin{cases}
    1,& x\geq0 \\
    0,& x<0
  \end{cases}
\end{aligned}$$


### 激活函数
- 理想激活函数

理想激活函数是一个阶跃函数

$$\begin{aligned}
  sgn(x)=
  \begin{cases}
    1,& x\geq0 \\
    0,& x<0
  \end{cases}
\end{aligned}$$
阶跃函数具有不连续、不光滑等缺点，因此常使用`Sigmoid`函数作为激活函数

- `Sigmoid` 函数

![sigmoid](img/sigmoid.png)

$$\begin{aligned}
    sigmoid(x)=\frac{1}{1+e^{-x}}
\end{aligned}$$


## 感知机与多层网络
感知机 (Perceptron) 由两层神经元组成



# BP神经网络原理
## 传递函数


## 激活函数
**BP神经网络**采用非线性变换函数 `Sigmoid` 作为激活函数
$$\begin{aligned}
    f(x)=\frac{1}{1+e^{-x}}
\end{aligned}$$
## 前向传播

