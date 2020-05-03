
# Lecture03 Transformation
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
