# Lecture20

# Ligth Of Field 光场



## 全光函数 Plenotic Function

全光函数, 也就是 VR 相机和全息影像的原理

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/plenotic.jpg)


t 表示时间, 用一个7 个维度的函数来描述的场景.
θ 表示眼睛所在点
φ 表示看向物体的方向
λ 波长 (颜色)
Vx Vy Vz 人的位置


光场就是任何一个位置往任何一个方向光的强度.

通过两个平面来定义光场,  两个平面,各自取一个点来定义方向.
u v 是一个平面上的坐标, s t 是另一个平面上的坐标.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/lumigraph.jpg)

## 光场相机
光场相机不仅记录下光的强度信息, 还记录下光的方向信息.

不同方向的光, 记录在不同的位置.
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/lfc.jpg)

因为记录下了光的方向, 取不同方向的光线, 就可以做到虚拟的移动摄像机的位置.

可以在这些不同方向的光线中按需查询, 最后就可以改变焦平面的位置.
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/lfc2.jpg)

分辨率降低了, 原本一个像素记录一个信息. 现在可能要100个像素才记录原本一个像素的信息, 不过这100个像素是从不同方向的光得到的.


# 颜色
光谱: 光线的能量在不同波长上的分布

谱功率密度: 光的不同波长的强度

加色系统 (计算机中的rgb)

减色系统 (颜料)

## 颜色匹配函数

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/color.jpg)

sRGB 缺点是色域不够广泛

色域: 所有颜色空间能够显示的颜色.


### XYZ 色域 (CIE XYZ 色彩空间)
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/color2.jpg)

如何可视化一个三维的东西呢?

对 XYZ 作归一化处理, 那么只要知道其中的两个维度, 剩下的一个维度的值就可以确定了.

所以可以用一个  xy 这样的二维坐标来表示

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/color3.jpg)


下图说明 sRGB 的色域空间就是图中三角形划定的大小

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/color4.jpg)

其他的一些色彩空间

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/color5.jpg)


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/color6.jpg)

CMYK  减色系统
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/color7.jpg)
