# Lecture 05 Rasterization 光栅化

Part I Triangle


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