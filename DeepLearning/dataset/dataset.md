# 目录
- [目录](#目录)
- [数据集制作](#数据集制作)
  - [图像标注](#图像标注)
- [开源数据集下载](#开源数据集下载)
  - [数据集库](#数据集库)
  - [图像数据集](#图像数据集)
  - [音频数据集](#音频数据集)

# 数据集制作
## 图像标注

<!-- https://blog.csdn.net/Dontla/article/details/102662815 -->
LabelImg是图形图像注释工具。它是用Python编写的，并将Qt用于其图形界面。

批注以 **PASCAL VOC** 格式（ImageNet使用的格式）另存为 `.xml` 文件。此外，它还支持 YOLO 格式

[labelImg Github](https://github.com/tzutalin/labelImg)

```bash
pip install labelImg
```
|  快捷键  |           功能           |
| :------: | :----------------------: |
| Ctrl + u |    从目录加载所有图像    |
| Ctrl + R |   更改默认注释目标目录   |
| Ctrl + s |           储存           |
| Ctrl + d |   复制当前标签和矩形框   |
|  space   |  将当前图像标记为已验证  |
|    w     |      创建一个矩形框      |
|    d     |        下一张图片        |
|    a     |        上一张图片        |
|   del    |     删除选定的矩形框     |
| Ctrl ++  |           放大           |
|  Ctrl–   |           缩小           |
|   ↑→↓←   | 键盘箭头移动选定的矩形框 |
# 开源数据集下载
## 数据集库
- [Tianchi Data Sets](https://tianchi.aliyun.com/dataset): 阿里系唯一对外开放数据分享平台
## 图像数据集
- [MNIST](https://datahack.analyticsvidhya.com/contest/practice-problem-identify-the-digits/?spm=a2c6h.12873639.0.0.52b8f729Cs5pxU) (50 MB): 手写数字数据集，包含一组 60,000 个示例的训练集和一个包含 10,000 个示例的测试集
- [MS-COCO](http://cocodataset.org/?spm=a2c6h.12873639.0.0.52b8f729Cs5pxU#home) (25 GB（压缩）): 大型的、丰富的物体检测，分割和字幕数据集。330K图像、80个对象类别、每幅图像有5个标签、25万个关键点
- [ImageNet](http://www.image-net.org/?spm=a2c6h.12873639.0.0.52b8f729Cs5pxU) (150 GB): 是根据WordNet层次结构组织的图像数据集。WordNet包含大约100,000个单词，ImageNet平均提供了大约1000个图像来说明每个单词。
- [Open Images](https://github.com/openimages/dataset?spm=a2c6h.12873639.0.0.52b8f729Cs5pxU) (500 GB（压缩）): 900万张超过5k标签的图像。包含9,011,219张图像的训练集，41,260张图像的验证集以及125,436张图像的测试集。
- [Fashion-MNIST](https://github.com/zalandoresearch/fashion-mnist?spm=a2c6h.12873639.0.0.52b8f729Cs5pxU) (30 MB): 包含60,000个训练图像和10,000个测试图像，它是一个类似MNIST的时尚产品数据库。每张图片都以灰度显示，并与10个类别的标签相关联。
- [CIFAR-10](http://www.cs.toronto.edu/~kriz/cifar.html?spm=a2c6h.12873639.0.0.52b8f729Cs5pxU) (170 MB): 是图像分类的另一个数据集，它由10个类的60,000个图像组成（每个类在上面的图像中表示为一行）。总共有50,000个训练图像和10,000个测试图像。


## 音频数据集
- [免费音乐档案（FMA）](https://github.com/mdeff/fma?spm=a2c6h.12873639.0.0.52b8f729Cs5pxU)(1000 GB): FMA是音乐分析的数据集，该数据集由full-length和HQ音频、预先计算的特征以及音轨和用户级元数据组成。它是一个开放数据集，用于评估MIR中的几个任务。以下是数据集连同其包含的csv文件列表：
  - `tracks.csv`：106,574首曲目的每首曲目元数据，如ID，标题，艺术家，流派，标签和播放次数。
  - `genres.csv`：163种风格的ID与他们的名字和父母（用于推断流派层次和顶级流派）。
  - `features.csv`：用librosa提取的共同特征 。
  - `echonest.csv`：由Echonest （现在的 Spotify）为13,129首音轨的子集提供的音频功能 。
  - [学习从音频中识别音乐风格](https://arxiv.org/pdf/1803.05337.pdf?spm=a2c6h.12873639.0.0.52b8f729Cs5pxU&file=1803.05337.pdf)
- [城市声音分类](https://datahack.analyticsvidhya.com/contest/practice-problem-urban-sound-classification/?spm=a2c6h.12873639.0.0.52b8f729Cs5pxU) (训练集:3 GB, 测试集:2 GB（压缩）): 包含超过8000个来自10个不同城市声音摘录。这个实践问题旨在向你介绍常见分类方案中的音频处理。

