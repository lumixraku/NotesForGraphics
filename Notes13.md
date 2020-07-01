# Lecture 13 Ray tracing 1

Read More

[解密NVIDIA光线追踪技术](https://zhuanlan.zhihu.com/p/35745255)

想了解光线追踪，你可以环顾四周，找到被光线照亮的物体，沿着到达视点的光线反方向进行追踪，就是光线追踪。


## why

光线追踪能解决全局效果的场景  (尤其是间接光照很合适, 当然并不是说光栅化就不能做全局光照)

一般认为光栅化是属于快速近似. 并不是那么精细. 而光线追踪追求更加真实.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/raytracing3.png)

glossy 表示有点反光, 但是又有些粗糙的物体 (铜镜)



早期人类认为人能看见物体, 是因为眼睛发出光线, 看到物体之后再返回来.  这和现在的常识不符.

PS：所以光线追踪的思想是感知光线

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/emmision.png)


光线追踪是跟踪眼睛发出的光线( 这点似乎和常识有点不同, 是由于光路可逆 ) 到达物体的过程

光线的一个性质: 光路可逆 (也就是追踪的意思)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/raytracing4.png)


沿着一根光线, 记录最近的交点

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/raytracing.png)

光线追踪因为 ray 是从眼睛( 摄像机 ) 发出, 因此天然的解决了遮挡(深度测试)的问题,



## Whitted Style Ray tracing

Whitted Style: 多次递归反射, 就是在模拟光线在不断弹射的过程.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/raytracing2.png)

下面是一个玻璃球, 既有折射, 又有反射. 同时还要计算和光源的情况.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/raytracing5.png)

其实从这个图可以看到 光路有很多条, 最终我们要计算的是他们的和 (每条光路存在能量损失, 不然加起来光线亮度就很亮了)


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/raytracing6.png)



### 和球的交点

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/raytracing7.png)

### 和显式表面求交点怎么做呢?
刚才 f(xx) = 0 是一个隐式表面的几何表达形式.

显式表面其实是求光线和三角形面的交点.

PS

如果一个点在封闭物体内部, 不论物体形状如何, 从这个点出发任意一条射线, 与物体的交点一定是奇数. 偶数的话一定是在物体外。 

根据这个性质，可以用来判断是否在一个点是否在物体内部

该性质2D 3D 都满足

More 奇偶规则和非零缠绕规则  https://blog.csdn.net/g0ose/article/details/54933038

### 和三角形面的交点

先判断和平面相交, 再判断交点是否在三角形中.

如何判断和平面是否相交呢?
光线的定义已经有了 o + td  那么如何定义平面呢?

通过法线 和某一个点  其实就定义了平面

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/raytracing8.png)

通过点法式（通过法线和一个点定义的平面）（图中左边的式子） 很容易判断一个点是不是在平面上

PS : 两个向量点乘是0  表示相互垂直   (p' 是平面上任意一个点)

More http://kjwy.5any.com/gdsx22/content/ch01/gdsx070501.htm

和前面和球球交点问题一样, 交点即在平面上 又在光线上. 因此两个公式都满足.
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/raytracing9.png)

之后判断点是否在三角形内（之前在点乘的时候介绍过方法）


### 上面的方式是先和平面求交点, 再判断是否在三角形内. 有么有更加直接的办法呢?
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/raytracing10.png)

Möller Trumbore MT 算法

如果有解(满足 t > 0 && b1 >0 && b2 >0 && 1 - b0 - b2 > 0 )，得到的结果是一个重心坐标。

注意公式中的 1 - b1 -b2 , 点既然在三角形内, 那么这个点可以使用重心坐标去表示.  (重心坐标的一个性质就是 b1+ b2 + b3 = 1)

剩下的部分就是解方程组了

图中底下一大串是用来判断方程组是否有解
More 克莱姆法则  https://zh.wikipedia.org/wiki/%E5%85%8B%E8%90%8A%E5%A7%86%E6%B3%95%E5%89%87


## AABB 轴对齐包围盒
用来减少没有必要的计算

我们的摄像机, 也就是你所看到的屏幕. 每个像素都要发出一条光线, 和场景中所有的三角形求交点, 然后光线还要不断反射. 这样太慢了 怎么帮



基于这么一条结论: 如果光线都不和包围盒相交, 那么光线更不和可能和包围盒中的物体相交. 所以可以利用包围盒做加速

上下左右前后 3对对面, 形成一个包围盒.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/aabb3.png)


先看2D 情况下的包围盒

光线射入, 记录下碰到对面1 的时间 和 离开对面2 的时间.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/aabb1.png)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/aabb2.png)

最终的包围盒中的射线, 是这三者求交集