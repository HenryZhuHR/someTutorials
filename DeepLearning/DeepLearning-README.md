# 目录
- [x] [深度学习基础（神经网络）](basic_deepLearning/basic_deepLearning.md)
- [ ] [卷积神经网络 CNN](cnn/cnn.md)
- [ ] [循环神经网络 CNN](cnn/cnn.md)

<!-- # 模型评估与选择
**误差** (error)  
实际预测输出和样本的真实输出之间的察隅

**训练误差** (training error)  
训练集上产生的误差

**泛化误差** (generalization)  
新样本上的误差


**过拟合** (overfitting)  
当学习器把训练样本学习得“太好”时，以至于把训练样本自身的一些特点当成潜在样本都具有的一般性质，会导致`泛化性能下降`

**欠拟合** (underfitting)  
训练样本的一般性质尚未学习好

> 欠拟合是由学习能力低下造成的，是比较容易解决的，比如增加训练轮数等  
> 过拟合不容易解决，需要预防 -->

# SOTA
SOTA，全称「state-of-the-art」，用于描述机器学习中取得某个任务上当前最优效果的模型。例如在图像分类任务上，某个模型在常用的数据集（如 ImageNet）上取得了当前最优的性能表现，我们就可以说这个模型达到了 SOTA。
[sota](https://www.jiqizhixin.com/sota)

- [目录](#目录)
- [SOTA](#sota)
- [分类任务的网络模型](#分类任务的网络模型)
- [图像检测的网络模型](#图像检测的网络模型)
- [图像分割的网络模型](#图像分割的网络模型)
- [理解CNN](#理解cnn)
- [超分辨率重建](#超分辨率重建)
- [图像标定](#图像标定)
- [视频标注](#视频标注)
- [特征检测与匹配（块）的网络模型](#特征检测与匹配块的网络模型)

# 分类任务的网络模型

- [LeNet](http://yann.lecun.com/exdb/lenet/index.html)
- [AlexNet](http://papers.nips.cc/paper/4824-imagenet-classification-with-deep-convolutional-neural-networks.pdf)
- [Delving Deep into Rectifiers: Surpassing Human-Level Performance on ImageNet Classification](https://arxiv.org/pdf/1502.01852.pdf)
- [Batch Normalization](https://arxiv.org/pdf/1502.03167.pdf)
- [GoogLeNet](http://www.cv-foundation.org/openaccess/content_cvpr_2015/papers/Szegedy_Going_Deeper_With_2015_CVPR_paper.pdf)
- [VGGNet](https://arxiv.org/pdf/1409.1556.pdf)
- [ResNet](https://arxiv.org/pdf/1512.03385.pdf)
- [InceptionV4（Inception-ResNet）](https://arxiv.org/pdf/1602.07261.pdf)

# 图像检测的网络模型
基于图像分类的基础上所做的一些研究，即分类+定位。
- [OVerfeat](https://arxiv.org/pdf/1312.6229.pdf)
- [RNN](https://arxiv.org/pdf/1311.2524.pdf)
- [SPP-Net](https://arxiv.org/pdf/1406.4729.pdf)
- [DeepID-Net](https://arxiv.org/pdf/1409.3505.pdf)
- [Fast R-CNN](https://arxiv.org/pdf/1504.08083.pdf)
- [R-CNN minus R](https://arxiv.org/pdf/1506.06981.pdf)
- [End-to-end people detection in crowded scenes](https://arxiv.org/pdf/1506.04878.pdf)
- [DeepBox](https://arxiv.org/pdf/1505.02146.pdf)
- [MR-CNN](http://www.cv-foundation.org/openaccess/content_iccv_2015/papers/Gidaris_Object_Detection_via_ICCV_2015_paper.pdf)
- [Faster R-CNN](https://arxiv.org/pdf/1506.01497.pdf)
- [YOLO](https://arxiv.org/pdf/1506.02640.pdf)
- [DenseBox](https://arxiv.org/pdf/1509.04874.pdf)
- [Weakly Supervised Object Localization with Multi-fold Multiple Instance Learning](https://arxiv.org/pdf/1503.00949.pdf)
- [R-FCN](https://arxiv.org/pdf/1605.06409.pdf)
- [SSD](https://arxiv.org/pdf/1512.02325v2.pdf)
- [Inside-Outside Net](https://arxiv.org/pdf/1512.04143.pdf)
- [G-CNN](https://arxiv.org/pdf/1512.07729.pdf)
- [PVANET](https://arxiv.org/pdf/1608.08021.pdf)
- [Speed/accuracy trade-offs for modern convolutional object detectors](https://arxiv.org/pdf/1611.10012v1.pdf)

# 图像分割的网络模型

- [FCN](https://people.eecs.berkeley.edu/~jonlong/long_shelhamer_fcn.pdf)
- [segNet](https://arxiv.org/pdf/1511.00561.pdf)
- [Deeplab](https://arxiv.org/pdf/1606.00915.pdf)
- [deconvNet](https://arxiv.org/pdf/1505.04366.pdf)
- [Conditional Random Fields as Recurrent Neural Networks](http://www.robots.ox.ac.uk/~szheng/papers/CRFasRNN.pdf)
- [Semantic Segmentation using Adversarial Networks](https://arxiv.org/pdf/1611.08408.pdf)
- [SEC: Seed, Expand and Constrain：](http://pub.ist.ac.at/~akolesnikov/files/ECCV2016/main.pdf)


Efficient piecewise training of deep structured models for semantic segmentation
https://arxiv.org/pdf/1504.01013.pdf

Semantic Image Segmentation via Deep Parsing Network
https://arxiv.org/pdf/1509.02634.pdf

BoxSup: Exploiting Bounding Boxes to Supervise Convolutional Networks for Semantic Segmentation
https://arxiv.org/pdf/1503.01640.pdf

Learning Deconvolution Network for Semantic Segmentation
https://arxiv.org/pdf/1505.04366.pdf

Decoupled Deep Neural Network for Semi-supervised Semantic Segmentation
https://arxiv.org/pdf/1506.04924.pdf

PUSHING THE BOUNDARIES OF BOUNDARY DETECTION USING DEEP LEARNING
https://arxiv.org/pdf/1511.07386.pdf

Learning Transferrable Knowledge for Semantic Segmentation with Deep Convolutional Neural Network
https://arxiv.org/pdf/1512.07928.pdf

Feedforward Semantic Segmentation With Zoom-Out Features
http://www.cv-foundation.org/openaccess/content_cvpr_2015/papers/Mostajabi_Feedforward_Semantic_Segmentation_2015_CVPR_paper.pdf

Joint Calibration for Semantic Segmentation
https://arxiv.org/pdf/1507.01581.pdf

Hypercolumns for Object Segmentation and Fine-Grained Localization
http://www.cv-foundation.org/openaccess/content_cvpr_2015/papers/Hariharan_Hypercolumns_for_Object_2015_CVPR_paper.pdf

Scene Parsing with Multiscale Feature Learning
http://yann.lecun.com/exdb/publis/pdf/farabet-icml-12.pdf

Learning Hierarchical Features for Scene Labeling
http://yann.lecun.com/exdb/publis/pdf/farabet-pami-13.pdf

Segment-Phrase Table for Semantic Segmentation, Visual Entailment and Paraphrasing
http://www.cv-foundation.org/openaccess/content_iccv_2015/papers/Izadinia_Segment-Phrase_Table_for_ICCV_2015_paper.pdf

MULTI-SCALE CONTEXT AGGREGATION BY DILATED CONVOLUTIONS
https://arxiv.org/pdf/1511.07122v2.pdf

Weakly supervised graph based semantic segmentation by learning communities of image-parts
http://www.cv-foundation.org/openaccess/content_iccv_2015/papers/Pourian_Weakly_Supervised_Graph_ICCV_2015_paper.pdf


目标追踪

经典网络：

DLT
https://pdfs.semanticscholar.org/b218/0fc4f5cb46b5b5394487842399c501381d67.pdf

Transferring Rich Feature Hierarchies for Robust Visual Tracking
https://arxiv.org/pdf/1501.04587.pdf

FCNT
http://202.118.75.4/lu/Paper/ICCV2015/iccv15_lijun.pdf

Hierarchical Convolutional Features for Visual Tracking
http://www.cv-foundation.org/openaccess/content_iccv_2015/papers/Ma_Hierarchical_Convolutional_Features_ICCV_2015_paper.pdf

MDNet
https://arxiv.org/pdf/1510.07945.pdf

Recurrently Target-Attending Tracking
http://www.cv-foundation.org/openaccess/content_cvpr_2016/papers/Cui_Recurrently_Target-Attending_Tracking_CVPR_2016_paper.pdf

DeepTracking
http://www.bmva.org/bmvc/2014/files/paper028.pdf

DeepTrack
http://www.bmva.org/bmvc/2014/files/paper028.pdf

Online Tracking by Learning Discriminative Saliency Map
with Convolutional Neural Network
https://arxiv.org/pdf/1502.06796.pdf

Transferring Rich Feature Hierarchies for Robust Visual Tracking
https://arxiv.org/pdf/1501.04587.pdf


# 理解CNN

经典网络：

Visualizing and Understanding Convolutional Networks
https://www.cs.nyu.edu/~fergus/papers/zeilerECCV2014.pdf

Inverting Visual Representations with Convolutional Networks
https://arxiv.org/pdf/1506.02753.pdf

Object Detectors Emerge in Deep Scene CNNs
https://arxiv.org/pdf/1412.6856.pdf

Understanding Deep Image Representations by Inverting Them
http://www.cv-foundation.org/openaccess/content_cvpr_2015/papers/Mahendran_Understanding_Deep_Image_2015_CVPR_paper.pdf

Deep Neural Networks are Easily Fooled:High Confidence Predictions for Unrecognizable Images
http://www.cv-foundation.org/openaccess/content_cvpr_2015/papers/Nguyen_Deep_Neural_Networks_2015_CVPR_paper.pdf

Understanding image representations by measuring their equivariance and equivalence
http://www.cv-foundation.org/openaccess/content_cvpr_2015/papers/Lenc_Understanding_Image_Representations_2015_CVPR_paper.pdf


# 超分辨率重建

经典模型：

Learning Iterative Image Reconstruction
http://www.ais.uni-bonn.de/behnke/papers/ijcai01.pdf

Learning Iterative Image Reconstruction in the Neural Abstraction Pyramid
http://www.ais.uni-bonn.de/behnke/papers/ijcia01.pdf

Learning a Deep Convolutional Network for Image Super-Resolution
http://personal.ie.cuhk.edu.hk/~ccloy/files/eccv_2014_deepresolution.pdf

Image Super-Resolution Using Deep Convolutional Networks
https://arxiv.org/pdf/1501.00092.pdf

Accurate Image Super-Resolution Using Very Deep Convolutional Networks
https://arxiv.org/pdf/1511.04587.pdf

Deeply-Recursive Convolutional Network for Image Super-Resolution
https://arxiv.org/pdf/1511.04491.pdf

Deep Networks for Image Super-Resolution with Sparse Prior
http://www.ifp.illinois.edu/~dingliu2/iccv15/iccv15.pdf

Perceptual Losses for Real-Time Style Transfer and Super-Resolution
https://arxiv.org/pdf/1603.08155.pdf

Photo-Realistic Single Image Super-Resolution Using a Generative Adversarial Network
https://arxiv.org/pdf/1609.04802v3.pdf



# 图像标定

经典模型：

Explain Images with Multimodal Recurrent Neural Networks
https://arxiv.org/pdf/1410.1090.pdf

Unifying Visual-Semantic Embeddings with Multimodal Neural Language Models
https://arxiv.org/pdf/1411.2539.pdf

Long-term Recurrent Convolutional Networks for Visual Recognition and Description
https://arxiv.org/pdf/1411.4389.pdf

A Neural Image Caption Generator
https://arxiv.org/pdf/1411.4555.pdf

Deep Visual-Semantic Alignments for Generating Image Description
http://cs.stanford.edu/people/karpathy/cvpr2015.pdf

Translating Videos to Natural Language Using Deep Recurrent Neural Networks
https://arxiv.org/pdf/1412.4729.pdf

Learning a Recurrent Visual Representation for Image Caption Generation
https://arxiv.org/pdf/1411.5654.pdf

From Captions to Visual Concepts and Back
https://arxiv.org/pdf/1411.4952.pdf

Show, Attend, and Tell: Neural Image Caption Generation with Visual Attention
http://www.cs.toronto.edu/~zemel/documents/captionAttn.pdf

Phrase-based Image Captioning
https://arxiv.org/pdf/1502.03671.pdf

Learning like a Child: Fast Novel Visual Concept Learning from Sentence Descriptions of Images
https://arxiv.org/pdf/1504.06692.pdf

Exploring Nearest Neighbor Approaches for Image Captioning
https://arxiv.org/pdf/1505.04467.pdf

Image Captioning with an Intermediate Attributes Layer
https://arxiv.org/pdf/1506.01144.pdf

Learning language through pictures
https://arxiv.org/pdf/1506.03694.pdf

Describing Multimedia Content using Attention-based Encoder-Decoder Networks
https://arxiv.org/pdf/1507.01053.pdf

Image Representations and New Domains in Neural Image Captioning
https://arxiv.org/pdf/1508.02091.pdf

Learning Query and Image Similarities with Ranking Canonical Correlation Analysis
http://www.cv-foundation.org/openaccess/content_iccv_2015/papers/Yao_Learning_Query_and_ICCV_2015_paper.pdf

Generative Adversarial Text to Image Synthesis
https://arxiv.org/pdf/1605.05396.pdf

GENERATING IMAGES FROM CAPTIONS WITH ATTENTION
https://arxiv.org/pdf/1511.02793.pdf


# 视频标注

经典模型：

Long-term Recurrent Convolutional Networks for Visual Recognition and Description
https://arxiv.org/pdf/1411.4389.pdf

Translating Videos to Natural Language Using Deep Recurrent Neural Networks
https://arxiv.org/pdf/1412.4729.pdf

Joint Modeling Embedding and Translation to Bridge Video and Language
https://arxiv.org/pdf/1505.01861.pdf

Sequence to Sequence–Video to Text
https://arxiv.org/pdf/1505.00487.pdf

Describing Videos by Exploiting Temporal Structure
https://arxiv.org/pdf/1502.08029.pdf

The Long-Short Story of Movie Description
https://arxiv.org/pdf/1506.01698.pdf

Aligning Books and Movies: Towards Story-like Visual Explanations by Watching Movies and Reading Books
https://arxiv.org/pdf/1506.06724.pdf

Describing Multimedia Content using Attention-based Encoder-Decoder Networks
https://arxiv.org/pdf/1507.01053.pdf

Temporal Tessellation for Video Annotation and Summarization
https://arxiv.org/pdf/1612.06950.pdf

Summarization-based Video Caption via Deep Neural Networks
acm=1492135731_7c7cb5d6bf7455db7f4aa75b341d1a78”>http://delivery.acm.org/10.1145/2810000/2806314/p1191-li.pdf?ip=123.138.79.12&id=2806314&acc=ACTIVE%20SERVICE&key=BF85BBA5741FDC6E%2EB37B3B2DF215A17D%2E4D4702B0C3E38B35%2E4D4702B0C3E38B35&CFID=923677366&CFTOKEN=37844144&acm=1492135731_7c7cb5d6bf7455db7f4aa75b341d1a78

Deep Learning for Video Classification and Captioning
https://arxiv.org/pdf/1609.06782.pdf


# 特征检测与匹配（块）的网络模型
- [TILDE: A Temporally Invariant Learned DEtector](https://arxiv.org/pdf/1411.4568.pdf)
- [MatchNet: Unifying Feature and Metric Learning for Patch-Based Matching](https://pdfs.semanticscholar.org/81b9/24da33b9500a2477532fd53f01df00113972.pdf)
- [Discriminative Learning of Deep Convolutional Feature Point Descriptors](http://cvlabwww.epfl.ch/~trulls/pdf/iccv-2015-deepdesc.pdf)
- [Learning to Assign Orientations to Feature Points](https://arxiv.org/pdf/1511.04273.pdf)
- [PN-Net: Conjoined Triple Deep Network for Learning Local Image Descriptors](https://arxiv.org/pdf/1601.05030.pdf)
- [Multi-scale Pyramid Pooling for Deep Convolutional Representation](http://ieeexplore.ieee.org/stamp/stamp.jsp?arnumber=7301274)
- [Spatial Pyramid Pooling in Deep Convolutional Networks for Visual Recognition](https://arxiv.org/pdf/1406.4729.pdf)
- [Learning to Compare Image Patches via Convolutional Neural Networks](https://arxiv.org/pdf/1504.03641.pdf)
- [PixelNet: Representation of the pixels, by the pixels, and for the pixels](http://www.cs.cmu.edu/~aayushb/pixelNet/pixelnet.pdf)
- [LIFT: Learned Invariant Feature Transform](https://arxiv.org/pdf/1603.09114.pdf)
  - [深度学习的特征点检测](https://blog.csdn.net/prephet/article/details/80797583)


[参考](https://blog.csdn.net/wzz18191171661/article/details/70161595)