# Lecture04 Transformation Part II

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
