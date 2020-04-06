# Lecture 12 Gemometry3

## Mesh Process
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/mesh1.jpg)

subdivision 细分
regularization 正规化 使用相同的三角形来表达

## Sub division 方法
### Loop (并不是循环  只是提出人的名字是loop)

Loop 细分: 先细分, 再调整 (但是 Loop 细分至适用于三角形网格)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/mesh2.jpg)

新顶点的位置 (图中白点为例子) 是原来 ABCD 取加权平均得到


旧顶点的位置

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/mesh3.jpg)

旧顶点的新位置由周围的顶点位置 和 自己原来的位置 共同决定.
n 表示顶点的度
u 是和顶点的度有关的一个数

### Catmull - Clark 细分
由于Loop 只能用在三角形网格, 对于四边形网格怎么办呢?

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/mesh4.jpg)

在面中间取一个点

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/mesh5.jpg)

在非四边形面内加上点, 是奇异点 (本次操作相比之前, 原来三角形面中间有两个度是3的点)

经过一次操作后, 都是四边形面了, 原来2个非四边形面(三角形),  现在2个奇异点.

在没有了非四边形面之后, 奇异点也不会增加了.

## 曲面简化 Simplification

### 边坍缩 (简化的方法之一)
减少一个边 , 同时这边边的两个顶点变为一个顶点

但是坍缩哪一条边呢?


### 二次误差度量

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/mesh6.jpg)

引入一个新的点, 使得这个点和 原来相关连的点所在的面 的距离 平方和 最小

因此要做的事情就是每一条边都遍历, 每次都找出对当前改变最小的边.

对于每次删除之后都要剩下的全局最优解, 使用堆结构最合适.  (堆中元素的排列不是按照到来的先后顺序，而是按照一定的优先顺序排列的。)


## 阴影 Shadow Mapping

光栅化中的阴影:
使用shadow Mapping, 在生成阴影的时候, 不需要知道场景几何信息

经典的shadow mapping 只能处理点光源

1. 从光源看向场景, 记录深度(光源到物体的距离, 考虑被遮挡的情况, 一些光根本照不到物体.)
2. 从摄像机出发, 看到的场景再投射回光源, 计算深度(点到光源的距离, 不考虑被遮挡)
3. 对比两个距离, 如果不一样, 表示存在遮挡(阴影).

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/shadow.jpg)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/shadow2.jpg)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/shadow3.jpg)

本影Umbra 半影PreUmbra 和光源大小有关.

软阴影 硬阴影 区别:  硬阴影的边缘很锐利, 清晰.

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/shadow4.jpg)