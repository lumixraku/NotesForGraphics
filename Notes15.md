# Lecture 14 Ray tracing 3

## 微分立体角

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/radiance6.png)

θ是和 Y轴的夹角, φ 是围绕 y 的旋转角度

PS  微分立体角 和 θ 有关, 靠近赤道和极地变化率不一样

## Irrediance
一个物体表面单位面积接收到的光的能量

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/irradiance.png)

四季: 阳光和表面越垂直 接收到的能量就越多

能量总和是固定的

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/irradiance2.png)

注意intensity 没有变 (Radiant Intensity 是单位立体角上的power 随着 r 变大, 立体角并没有改变 )

是 Irrediance 在随着 r 变大在衰减


## Radiance

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/radiance6.png)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/radiance7.png)

Radiance 其实是在 Irradiance 基础上增加了方向

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/radiance8.png)

或者说 Irradiance 是四面八方的 Radiance 的积分

## BRDF 双向反射分布函数
通俗的说, BRDF是在解决光从某个方向打到以个物体上, 光向不同方向去反射的能量分布.

描述了光线和物体如何相互作用

对于反射的理解:

Whitted Style 光线打到某一个物体上, 然后被弹走了(方向改变了).

另一种理解: 光线打到某一个表面, 结果被吸收了, 然后又朝特定的方向发射出去了.

ωi 表示不同方向的入射光

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/brdf.png)


射出的radiance 可能成为其他点的入射radiance (此刻被照亮的物体本身作为光源存在了)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/brdf2.png)
