# 项目文件说明
## 目录
- [x] [文件列表及其说明](#文件列表及其说明)
- [x] [第三方库](#第三方库)
- [x] [页面布局](#页面布局)
  - [x] [侧边栏 el-aside](#侧边栏-el-aside)
  - [x] [主视图 el-main](#主视图-el-main)
  - [x] [右下角的数据监控](#右下角的数据监控)
- [x] [脚本库](#脚本库)


## 文件列表
- [x] [fly_sim.html](#fly_sim.html)

## 第三方库
- Cesium：开发自己的web地图应用程序，本项目也是基于该工具来进行


## 页面布局
启动项目后看到`element-ui`布局，包括了`el-aside`和`el-main`
![element-ui布局示意图](./img/element-ui-view.jpg)  

### 侧边栏 el-aside
el-aside、el-menu、el-submenu和el-menu-item

0. 控制菜单
1. 视角控制
   - 固定视角
      - 上方
      - 右侧
      - 后方
      - 前方
   - 自由视角
      - 自由漫游
      - 锁定飞机
2. 辅助显示
   - 小地图
   - 数显表
   - 航迹
3. 场景控件
   - 动画控件
   - 半球阴影
4. 开始
5. 重置
6. 设置


### 主视图 el-main

### 右下角的数据监控

## 脚本库 
[js/MainScene.js](js\MainScene.js)
- 创建主场景
```{javascript}
init_Scene();
```
> 创建`viewer`变量，`viewer`是一个Cesium.Viewer对象，





## 文件说明
### fly_sim.html

#### element-ui布局：
| 组件 | 说明 |
| --- | --- |
|el-container|外层容器。当子元素中包含 或 时，全部子元素会垂直上下排列，否则会水平左右排列|
|el-header|顶栏容器|
|el-aside|侧边栏容器|
|el-main|主要区域容器|
|el-footer|底栏容器|
![布局示意](./img/el-container-view.png)


> [element-ui使用教程](https://www.cnblogs.com/tdcqcrtd/p/12766715.html)

联网：
```{html}
<!--引入 element-ui 的样式，-->
<link rel="stylesheet" href="https://unpkg.com/element-ui/lib/theme-chalk/index.css">
<!-- 必须先引入vue，  后使用element-ui -->
<script src="https://cdn.jsdelivr.net/npm/vue@2.5.17/dist/vue.js"></script>
<!-- 引入element 的组件库-->
<script src="https://unpkg.com/element-ui/lib/index.js"></script>
```
无网：
下载地址
- [vue.js]( https://cdn.jsdelivr.net/npm/vue/dist/vue.js)
- 脚本文件：[element.js](https://unpkg.com/element-ui@2.4.11/lib/index.js)
- 样式表文件：[element.css](https://unpkg.com/element-ui@2.4.11/lib/theme-chalk/index.css)
- 字体文件下载：[woff格式](https://unpkg.com/element-ui@2.10.1/lib/theme-chalk/fonts/element-icons.woff)、[tff格式](https://unpkg.com/element-ui@2.10.1/lib/theme-chalk/fonts/element-icons.ttf)
>注意element-ui使用的是2.4.11版本的