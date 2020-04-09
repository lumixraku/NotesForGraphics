# Lecture 14 Ray tracing 2

## AABB 如何帮助加速光线追踪

与物体相交的格子标记为某一种类型 (右上角漏标记了)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/accray.png)


假设: 光线和盒子相交很快, 光线和物体三角面求交很快.

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/accray2.png)

因此很重要的是如何合理的将空间划分成各种格子.  如果这个光线经过的格子中有物体, 就要开始求光线和物体是否相交.

格子不能太密(不然光线和太多格子求交点效率低) 不能太稀疏(不然很容易要和格子中的物体求交点)



![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/accray3.png)

根据经验, 格子数 = 某个常数 * 空间中物体数

不过这种格子划分, 似乎太呆板了.  每个格子大小都一样, 实际上在物体稀疏的地方, 可以不用那么多格子.



如何在一个体育场中找到一个茶壶呢?

## 空间切分

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/spatial.png)


### Oct-Tree
通过对空间的切分, 切分成了一些不均匀的结构.

八叉树是针对三维世界而言, 图中看起像是四叉树, 但是这只是一个立方体的截面.
所以

对于平面来说, 八叉树就变成了四叉树.
对于线段来说, 八叉树就变成了二叉树.

### KD-tree
每次都是 水平 --- 竖直 --- 水平 --- 竖直 这样交替的划分.

### BSP-tree
不好计算

## KD-tree
从空间开始划分
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/kdtree.png)


## BVH
从物体开始划分