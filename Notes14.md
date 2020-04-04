# Lecture 14 Ray tracing 2

## 包围盒切分

### Oct-Tree
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
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/kdtree.jpg)


## BVH
从物体开始划分