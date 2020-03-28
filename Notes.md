

> Written with [StackEdit](https://stackedit.io/).

[主办方主页](http://games-cn.org/)
[课程主页](https://sites.cs.ucsb.edu/~lingqi/teaching/games101.html)
[PPT](http://games-cn.org/graphics-intro-ppt-video/)
# Lecture01
图形学的应用VideoGames  Movies  Animations  Design  Visualization
Virtual Reality      Agumented Reality   Digital Illustration   Simulation



# Lecture02

## 点乘
点积是数量积

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/dot1.jpg | width=200)
```
A·B = |A| |B| cos(θ).
|A| cos(θ)是A到B的投影

```
满足交换律和结合律

点乘的笛卡尔坐标系(直角坐标系)表示形式

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/dot2.jpg)


### 点乘的几何运用
- Find angle between two vectors
- Finding projection of one vector on another (向量分解)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/dot4.jpg)

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

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/cross1.jpg)

叉乘没有交换律  但是有结合律



### 叉乘在图形中的应用
- 判定左右 (同一个起点的两个向量 如何判定谁在谁的左侧  a 叉乘 b 得到的结果z 是正  那么 b 在 a 的左侧)
- 判定内外



## 矩阵
点乘 叉乘的矩阵表示形式

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/matrix.jpg)

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

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/rotate1.jpg)

## 齐次坐标


![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/homo.jpg)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/homo1.jpg)

考虑到 ponit + point 的运算(这样w 分量就是2了), 于是又扩展了齐次坐标的定义

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/homo2.jpg)

## 2D变换的总结
“仿射变换”就是：“线性变换”+“平移”

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/trans.jpg)

变换的顺序

下面表示最先做 A1 变换, 再做 A2 变换  ...最后到An

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/trans2.jpg)




# Lecture04

## 3D 变换


![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/rotate3d.jpg)

PS 需要说明的是 这个3D变换是针对右手坐标系 左手坐标系的很多值和这里完全相反

## view transformation
- view camera transformation
- projection transformation
  - 正交投影
  - 透视投影

## view/camera transformation 视图变换  (也被称为 modelview transformation )
定义相机的 pos  lookat  up direction (前两个已经可以定义出相机镜头方向  up direction 就是镜头的旋转情况)
为了方便计算,  先让相机放在原点 看向 -z 的方向, up 方向是 y 的正方向  (相机所拍的物体跟着相机一起运动  这样相机所拍的场景和移动之前都是一样的)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/view.jpg)

因此要做下面的旋转

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/view1.jpg)

PS 旋转矩阵是正交矩阵


## 投影变换
### 正交投影
视锥体缩放到 [-1, 1] 的立方体中

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/project.jpg)

先平移到原点  再缩放到标准立方体

### 透视投影

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/project2.jpg)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/project3.jpg)


# Lecture 05
FOV
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/fov.jpg)

这个图中红色的角度  垂直可视角度
广角就是 FOV 比较大

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/fov2.jpg)

n 表示近平面

## 视椎体到屏幕 (After MVP)
在得到了标准视椎体之后就需要投射到屏幕上

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/screen.jpg)

## 光栅化

光栅化的时候需要判断点是否在三角形内
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/inside.jpg)

## 走样 (俗称锯齿)
