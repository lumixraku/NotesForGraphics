
# Lecture03 Transformation
## 线性变换
- Scale
- Reflection Matrix
- Shear Matrix
- Rotation Matrix


## 2D 旋转

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/rotate2.jpg)

旋转矩阵的推导

先考虑特殊点 (1, 0)  可以得到 A 和 C   之后在考虑特殊点(0, 1) 可以推算到 B D

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/rotate1.jpg)


## 线性变换的矩阵表示

这些变换都可以写成一种线性组合,

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/transform.jpg)



## 齐次坐标


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/homo.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/homo1.jpg)

考虑到 ponit + point 的运算(这样w 分量就是2了), 于是又扩展了齐次坐标的定义

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/homo2.jpg)


PS 对于向量(x, y, z, w), 只要 w !=0 就认为所在三维坐标空间中的点是(x/w, y/w, z/w)

## 2D变换的总结
“仿射变换”就是：“线性变换”+“平移”

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/transform3.jpg)

## 变换的顺序

既然变换是用矩阵来表达, 所以多个变换就如同矩阵乘法, 顺序不可以调换. 因为矩阵乘法不满足交换律.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/transform2.jpg)


下面表示最先做 A1 变换, 再做 A2 变换  ...最后到An

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/transform4.jpg)

## 变换分解

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/transform5.jpg)

对于不在原点上物体做变换, 可以先移动它到原点, 变换之后再移动回去.