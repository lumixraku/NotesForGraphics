# Lecture 14 Ray tracing 2

## AABB 如何帮助加速光线追踪

与物体相交的格子标记为某一种类型 (右上角漏标记了)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/accray.png)


假设: 光线和盒子相交很快, 光线和物体三角面求交很快.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/accray2.png)

因此很重要的是如何合理的将空间划分成各种格子.  如果这个光线经过的格子中有物体, 就要开始求光线和物体是否相交.

格子不能太密(不然光线和太多格子求交点效率低) 不能太稀疏(不然很容易要和格子中的物体求交点)



![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/accray3.png)

根据经验, 格子数 = 某个常数 * 空间中物体数

不过这种格子划分, 似乎太呆板了.  每个格子大小都一样, 实际上在物体稀疏的地方, 可以不用那么多格子.



如何在一个体育场中找到一个茶壶呢?

## 空间切分

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/spatial.png)


### Oct-Tree
通过对空间的切分, 切分成了一些不均匀的结构.

八叉树是针对三维世界而言, 图中看起像是四叉树, 但是这只是一个立方体的截面.
所以

对于平面来说, 八叉树就变成了四叉树.

对于线段来说, 八叉树就变成了二叉树.

很显然 是n叉树, 和维度有关, 这样不太好.

因此就有了 KD tree 能对空间进行划分, 同时又和维度没有关系.

### KD-tree

在每一个格子中, 按照水平/垂直 方向只砍一刀
每次都是 水平 --- 竖直 --- 水平 --- 竖直 这样交替的划分.

### BSP-tree
和 KD tree 的区别是并不是横屏竖直的砍开

但是因为不是水平或者竖直, 不好计算

## KD-tree

从空间开始划分

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/kdtree.png)


如果光线和最外面的盒子有交点, 那么可能和子盒子有交点. 需要继续判断一下. 递归直到叶子节点.

如果一个子盒子是叶子节点, 光线就需要和这个叶子节点中的所有物体求交.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/kdtree1.png)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/kdtreeA.png)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/kdtreeB.png)

那么如何知道一个盒子和空间中的三角形面有交集呢?

有可能三角形的三个顶点都不在盒子里, 但是三角形却和盒子相交 (当盒子很小, 三角形很大的时候 )


同时 KD tree 还有另一个问题, 一个物体有可能和多个叶子节点相交

例如 t hit 这个位置的物体 和3个叶子节点相交

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/kdtree3.png)




## BVH  Bounding Volume Hierarchy

从物体开始划分, 而不是从空间开始划分. 一开始将一堆三角形划分成两个部分。然后分别对这两堆三角形再次划分。

现代图形学中, 不论离线还是实时渲染,  AABB 加速基本上都使用的这种算法


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/bvh1.png)

一堆三角形分为两堆, 左边的那一堆三角形又再次划分.

实际的物体都记录在叶子节点里

一个好处: 一个三角形只可能在一个包围盒中. 解决了 KD tree 的问题

但是 BVH 对于空间划分出的盒子有可能相交

PS BVH对节点的划分： 可以每次都是根据最长的轴最划分  也可以每次都找中间的三角形做划分

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/bvh2.png)

这里的median 怎么理解呢? 就是不管按照何种方式去划分三角形, 最后划分出的两堆三角形数量差不多.
(平衡树的概念, 避免树的深度过高, 这样查找起来才效率才高. )

寻找中位数算法： 任意一列无序数， 找到第N 大的数，有一种 O(n) 的算法可以解决  快速选择算法（受到快速排序的算法的启发）

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/bvh3.png)

KD tree 是对空间划分, 物体可能即在左边又在右边

BVH 是对物体划分(更形象点说是分组) 但是空间上组与组之间可能有交集.  不需要计算三角形和包围盒如何相交



## 辐射度量学

辐射度量学 在物理上准确定义光线的方法


辐射能是电磁辐射的能量。它以焦耳为单位进行测量.

辐射通量是每单位时间发出,反射,传输或接收的能量  (也就是功率)  单位是w

描述光的功率: 流明 lm

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/radiance.png)

- Radiant flux 辐射通量 (又称为 power) 也称为功率
- Radiant intensity 辐射强度  (和方向有关) power per solid angle 在单位立体角中的能量
- Irrediance 辐照度 OR 辐射照度 power per projected unit area (物理学: 单位面积接收到的辐射通量    图形学:一个物体表面单位面积接收到的光的能量)
- Radiance 辐射亮度 (物理学:单位投影面积且单位立体角上的辐射通量  图形学:光线在传播过程中度量能量) 和方向有关

PS 图形学中所说到的能量一般都是单位时间内的能量 也就是power 功率  Joule 焦耳在图形学中很少使用

Read More https://zhuanlan.zhihu.com/p/52497510

这篇文章有有一些更形象的说法
- Radiant flux 光子每秒击中物体的量 功率，单位是瓦特 通常使用字母 Φ 表示
- Radiant intensity 
- Irradiance 每秒每单位面积的击中
- Radiance 辐射度是沿着由原点p和方向 ω	定义的射线的能量



![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/radiance2.png)

Radiant Intensity 是单位立体角上的power


### 立体角的定义

一般科学上, 针对平面 对于角的定义是用弧长来表示的.

那么对于立体情况, 就是用这个角对应的球的表面积来定义.  (这里 A 是立体角对应的球面积)  (也就是对弧度制的延伸)

立体角就是描述空间中角度有多大, 比如一个椎体张开的程度

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/radiance3.png)

单位立体角可以理解为 半径为1的二维球面上的一小块面积

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/radiance3.png)
所有单位立体角的积分是 4π


# Read More
(Radiance versus irradiance)[http://sites.sinauer.com/animalcommunication2e/chapter04.02.html]

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/radiance11.jpg)
