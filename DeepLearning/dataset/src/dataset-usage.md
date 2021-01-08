# 目录
- [目录](#目录)
- [数据集制作](#数据集制作)
  - [VOC 数据集制作](#voc-数据集制作)
- [数据集格式](#数据集格式)

# 数据集制作
## VOC 数据集制作

- **生成 VOC 模板**

在当前目录下，执行
```bash
python ./scripts/VOC-create.py
```
会在上层目录 `../` 中产生目录 `../VOC2012`

（如果需要）删除 `VOC2012` 数据集目录
```bash
python ./scripts/VOC-delete.py
```

- **重命名数据集全部文件**

重命名 `../images` 内数据文件
```bash
python ./scripts/rename.py
```

标注完成后，检查所有图像是否都有对应的标注文件

- **数据集复制到 VOC 目录**

```bash
python ./scripts/img-copyto-voc.py
```

- **生成训练文件** `train.txt` `val.txt` 及**类别文件** `classes.names`
```bash
python ./scripts/generate-txt.py
```

- **VOC 转 YOLO**

```bash
python ./scripts/voc-to-yolo.py
```

# 数据集格式
**VOC2012** 数据集描述：

- **Annotations**: 存放了数据`xml`格式存储的标签，里面包含了每张图片的`bounding box`信息，主要用于**目标检测**。
- **ImageSets**: ImageSets中的Segmentation目录下存放了用于分割的train, val, trainval数据集的索引。
- **JPEGImages**: 这里存放的就是JPG格式的原图，包含17125张彩色图片，但只有一部分(2913张)是用于分割的。
- **SegmentationClass**: 语义分割任务中用到的label图片，PNG格式，共2913张，与原图的每一张图片相对应。
- **SegmentationObject**: 实例分割任务用到的label图片，在语义分割中用不到，这里不详解介绍。

