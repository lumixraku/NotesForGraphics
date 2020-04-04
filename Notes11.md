# Lecture 11

显式几何表示方式: 三角形顶点, 贝塞尔曲面, 细分曲面, 非均匀有理B样条(NURBS), 点云,

## Mesh

如何用三角形面来表示物体呢?
和编译出来的 obj 不一样, 这里的 obj 是文本文件
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/geometry4.jpg)

这里描述的是一个立方体, 所以有 8 个顶点v.
另外还描述了 6 个法线vn (因为有公用所以重复了2个).
另外如何用三角形描述面呢?  关注 f 开头的描述  f 第n个点/纹理坐标/法线 ...


## 贝塞尔曲线
用一系列控制点去定义曲线


![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/bezier.jpg)

给定三个点: 生成二次贝塞尔曲线

t 代表时间    b02 这个点表示时间t的时候 曲线所在的位置

PS 曲线并不一定要经过控制点 只要经过起始点和结束点就行

## de castelju 算法
https://blog.csdn.net/venshine/article/details/51758841

https://github.com/venshine/BezierMaker

对于4个控制点的情形:

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/bezier1.jpg)

从原来4个点 3条线段(b0b1  b1b2   b2b3)

变为三个点两条线段(b01b11  b11 b21)  问题规模缩小了

递归扫什么程度呢?    到三点在一条线上的时候 (就上一个图那样)

### 算法的数学表示

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/bezier2.jpg)

t = 0的时候 就应该是b0  t = 1 的时候 就是 b1

### 贝塞尔曲线在仿射变换下的性质  (放射不变性) :
对控制点做了仿射变换之后, 这些控制点形成的贝塞尔曲线  ==  根据这些控制点做出贝塞尔曲线做仿射变换之后得到的曲线.
但是其他变换不行, 比如投影变换

### 凸包性质:
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/bezier3.jpg)
画出的贝塞尔曲线一定在控制点形成的凸包内


一般人们习惯使用4个控制点去定义一条曲线, 下面这个曲线由多段贝塞尔曲线构成

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/bezier4.jpg)


为了保证多个贝塞尔曲线的光滑性质 新增的线段的控制点要和原先最后两个的控制点形成的线段共线 , 且长度相等.

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/bezier5.jpg)

## 贝塞尔曲面
相当于 x 方向 和 y 方向都有贝塞尔曲线.
总共 4 * 4 = 16 个点来控制一小段曲面

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/bezier6.jpg)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/bezier7.jpg)
这里曲面中的 u v 就相当于之前提到的 t

贝塞尔曲面是显示表示, 因为是参数映射
