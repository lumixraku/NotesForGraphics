

> Written with [StackEdit](https://stackedit.io/).

[主办方主页](http://games-cn.org/)
[课程主页](https://sites.cs.ucsb.edu/~lingqi/teaching/games101.html)
[PPT](http://games-cn.org/graphics-intro-ppt-video/)

# Lecture01
图形学的应用
- VideoGames
- Movies
- Animations
- Design
- Visualization
- Virtual Reality
- Agumented Reality
- Digital Illustration
- Simulation



# Lecture02

## 点乘
点积是数量积

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/dot1.jpg)
```
A·B = |A| |B| cos(θ).
|A| cos(θ)是A到B的投影

```
满足交换律和结合律

点乘的笛卡尔坐标系(直角坐标系)表示形式

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/dot2.jpg)


### 点乘的几何运用
- Find angle between two vectors
- Finding projection of one vector on another (向量分解)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/dot4.jpg)

向量 b 在a上的投影 b’    其方向和a 相同
在得到b’ 后球另一个向量就容易了

### 点乘在图形中的运用
- 向量方向的接近程度
- 向量分解
- 方向是否相反(根据点乘的结果是否大于0)




## 叉乘
- 叉乘的结果是一个向量, 且和两个向量正交(垂直)
- 右手坐标系  右手螺旋定则   x 叉乘 y = z
- (如果是左手坐标系  x 叉乘 y 得到 -z   叉乘就是应用右手螺旋定则)

### 叉乘的笛卡尔方程表示形式

第二种是叉乘表示成矩阵形式

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/cross1.jpg)

叉乘没有交换律  但是有结合律



### 叉乘在图形中的应用
- 判定左右 (同一个起点的两个向量 如何判定谁在谁的左侧  a 叉乘 b 得到的结果z 是正  那么 b 在 a 的左侧)
- 判定内外



## 矩阵
点乘 叉乘的矩阵表示形式

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/matrix.jpg)

矩阵乘法没有交换律  但是有结合律分配律
- 结合律： (λμ)A=λ(μA) ； (λ+μ)A =λA+μA．  A(BC) = (AB)C
- 分配律： λ (A+B)=λA+λB． A(B+C) = AB + AC

转置
(AB)' = B'A'
(A + B)' = A' + B'

逆
(AB)" = B"A"   (暂时用" 表示 -1)
AA" = I


# Lecture03
## 线性变换
- Scale
- Reflection Matrix
- Shear Matrix
- Rotation Matrix

旋转矩阵的推导

先考虑特殊点 (1, 0)  可以得到 A 和 C   之后在考虑特殊点(0, 1) 可以推算到 B D

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/rotate1.jpg)

## 齐次坐标


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/homo.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/homo1.jpg)

考虑到 ponit + point 的运算(这样w 分量就是2了), 于是又扩展了齐次坐标的定义

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/homo2.jpg)

## 2D变换的总结
“仿射变换”就是：“线性变换”+“平移”

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/trans.jpg)

变换的顺序

下面表示最先做 A1 变换, 再做 A2 变换  ...最后到An

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/trans2.jpg)




# Lecture04

## 3D 变换


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/rotate3d.jpg)

PS 需要说明的是 这个3D变换是针对右手坐标系 左手坐标系的很多值和这里完全相反

## view transformation
- view camera transformation
- projection transformation
  - 正交投影
  - 透视投影

## view/camera transformation 视图变换  (也被称为 modelview transformation )
定义相机的 pos  lookat  up direction (前两个已经可以定义出相机镜头方向  up direction 就是镜头的旋转情况)
为了方便计算,  先让相机放在原点 看向 -z 的方向, up 方向是 y 的正方向  (相机所拍的物体跟着相机一起运动  这样相机所拍的场景和移动之前都是一样的)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/view.jpg)

因此要做下面的旋转

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/view1.jpg)

PS 旋转矩阵是正交矩阵


## 投影变换
### 正交投影
视锥体缩放到 [-1, 1] 的立方体中

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/project.jpg)

先平移到原点  再缩放到标准立方体

### 透视投影

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/project2.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/project3.jpg)


# Lecture 05
FOV
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/fov.jpg)

这个图中红色的角度  垂直可视角度
广角就是 FOV 比较大

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/fov2.jpg)

n 表示近平面

## 视椎体到屏幕 (After MVP)
在得到了标准视椎体之后就需要投射到屏幕上

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/screen.jpg)

## 光栅化

通过采样来做光栅化

采样是把函数离散化过程


三角形定义  (+0.5 就是中心)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/inside1.jpg)

光栅化的时候需要判断点是否在三角形内

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/inside.jpg)
判断 Q 点是否在各个边的左侧 (P1P1叉乘 P1Q 是否是y轴正方向  然后 P2P0 叉乘 P2Q ... 最后P0P1 逆时针 )

更快的三角形内点的一种方式

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/inside2.jpg)

每一行都找出边界的点(先找最左边 再找最右边)


# Lecture 06
## 反走样Antialiasing (俗称抗锯齿)

Artifact 在图形学中的含义: 一切和预想的不一致的表现的情况

摩尔纹moire: 采样带来的问题, 在一个像素上有过多的频率的变化

走样出现的根本原因: 信号的变化速度太快, 而采样频率跟不上信号的变化速度

解决办法之一: 先模糊 再采样

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/antialias.jpg)

但是, 为什么这样可以解决问题呢?

## 频域

傅立叶变换，表示能将满足一定条件的某个函数表示成三角函数（正弦和/或余弦函数）或者它们的积分的线性组合  [百度百科 更注重数学上的概念](https://baike.baidu.com/item/%E5%82%85%E9%87%8C%E5%8F%B6%E5%8F%98%E6%8D%A2)

傅里叶变换 是一种线性积分变换，用于信号在时域（或空域）和频域之间的变换， [wiki 更注重于时间域频域](https://zh.wikipedia.org/wiki/%E5%82%85%E9%87%8C%E5%8F%B6%E5%8F%98%E6%8D%A2)


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/fourier1.jpg)



蓝色是实际信号  圆圈是采样点  黑色是根据采样得到的点拟合的信号  可见由于采样频率不够 导致错误

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/fourier1.jpg)


低通滤波和高通滤波

滤波（Wave filtering）是将信号中特定波段频率滤除的操作

low pass filter &  high pass filter

高通滤波  —  只允许高频信号可以通过, 去掉低频信息  —  保留图片上的轮廓  —  轮廓素描

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/filter1.jpg)

低通滤波  —  只允许低频通过 , 去掉高频信息 — 去除图片上物体轮廓 — 模糊

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/filter2.jpg)





滤波 == 卷积操作 == 求平均

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/antialias2.jpg)



Convolution (下面是图形学中的简化版本  并不是数学中的定义)

卷积在移动窗口的过程中  把窗口覆盖的信号和对应的过滤器做点乘然后求和   结果写回窗口的中心值

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/antialias3.jpg)


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/fourier3.jpg)

时域卷积 等于 频域乘积

时域的乘积 等于 频域上的卷积



Sampling = Repeating Frequency Contents

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/sampling.jpg)

这里 a 是原本的信号, 然后用 c 对其 采样, 最后得到 e  (a 是连续的, 经过采样之后得到了一堆离散的点),

这里 a c 都是时域 ( c 是冲激函数 )    b d 分别是他们的频域

a c 的乘积 e  就是 b d 的卷积 f

通过 f 图可以看起来就是对 b 图的复制粘贴

因此定义 ==>  采样:重复原始信号的频谱


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/sampling2.jpg)

采样频率不够  采样时间间隔越大  那么频谱间隔越小   (时域和频域有很多相反的关系)

由于频域之间间隔越小, 导致频域发生混叠, 因此产生了走样


## 如何反走样
先用低通滤波, 去掉高频信息, (模糊), 然后再采样

下面做的就是去掉高频信号 之后还是以原来的采样率去采样, 去掉高频之后就不再发生混叠了

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/sampling3.jpg)

## 反走样解决方式之 MSAA
超采样, 每一个像素都再次划分, 然后判断点是否在三角形内, 之后再做平均 (这样去做的模糊).

PS 超采样并没有增加分辨率

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/sampling4.jpg)


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/sampling5.jpg)


# Lecture 07
## z-buffering 深度缓冲

画家算法: 先画远的, 再画近的

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/painter.jpg)

画家算法的问题:  如果有物体相互遮挡  就无从下手了

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/painter2.jpg)


用 0 ~ 1 表示远近程度, 越近越接近0,  颜色越黑

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/zbuffer.jpg)


O(n) 的计算深度的方法  每个物体诸葛遍历, 每个像素取最近的那个

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/zbuffer2.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/zbuffer1.jpg)

## 反射模型

Shading is local.  着色是局部的.(每一个像素点独立运算)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading.jpg)


兰伯特漫反射和角度有关
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading2.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading3.jpg)


# Lecture 08

## 高光模型

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading4.jpg)


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading5.jpg)

相比 Phong 高光, Blinn-Phong 高光因为引入了半程向量, 更容易计算.

上面的 p 次方, 是为了柔和衰减

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading6.jpg)


## 环境光

ka 可以认为是常数

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading7.jpg)


## Phong 光照总结

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading8.jpg)


## 着色频率
平坦着色: 逐个三角形着色
Gouraud着色: 逐个顶点着色 (根据顶点做插值) (顶点求法线)
Phong着色: 逐像素着色

顶点的法线

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading9.jpg)

每个像素点的法线

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading10.jpg)

## 渲染管线

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/pipeline.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/pipeline1.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/pipeline2.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/pipeline3.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/pipeline4.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/pipeline5.jpg)
