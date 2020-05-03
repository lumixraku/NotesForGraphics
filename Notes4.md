# Lecture04 Transformation Part II


## 旋转矩阵是正交矩阵

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/transform6.jpg)

发现旋转 -θ 角度的矩阵, 就是旋转 θ 角度矩阵的转置

而是旋转 θ 角度矩阵的逆矩阵, 也是旋转 -θ 的矩阵

也就是说 旋转 θ 角度矩阵的逆矩阵 == 旋转 θ 角度矩阵的转置

根据定义, 一个矩阵的逆等于其转置, 那么这个矩阵是正交矩阵, 因此旋转矩阵是正交矩阵



## 3D 变换

因为三维的旋转比较复杂, 因此先从某一个固定轴旋转开始. (逆时针)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/rotate3d.jpg)

Rx(α) 绕 x 轴旋转, y z 就相当于二维坐标中的 x y.

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

Projection is a Transformation.  投影是一种变换.

### 正交投影
视锥体缩放到 [-1, 1] 的立方体中

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/project.jpg)

先平移到原点  再缩放到标准立方体

### 透视投影

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/project2.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/project3.jpg)

## Read More

### 正交矩阵
- 正交矩阵每一列都是单位向量，并且两两正交  (单位向量就是长度为1 的向量)
- 正交矩阵的逆（inverse）等于正交矩阵的转置（transpose）  且行列式的结果只能1 OR -1

### 旋转矩阵一定是正交矩阵

https://www.zhihu.com/question/316200199

正交矩阵之所以叫正交矩阵，是因为一套正交基向量在该矩阵变换下仍然是正交的，这是正交矩阵的充分必要条件。很明显的，任何两个向量在旋转矩阵的变换下，这两个向量仍然是正交的，所以旋转矩阵是正交矩阵