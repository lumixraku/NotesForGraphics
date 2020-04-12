# Lecture 14 Ray tracing 3

## 微分立体角

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/radiance6.png)

θ是和 Y轴的夹角, φ 是围绕 y 的旋转角度

PS  微分立体角 和 θ 有关, 靠近赤道和极地变化率不一样

## Irrediance
一个物体表面单位面积接收到的光的能量

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/irradiance.png)

四季: 阳光和表面越垂直 接收到的能量就越多

能量总和是固定的

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/irradiance2.png)

注意intensity 没有变 (Radiant Intensity 是单位立体角上的power 随着 r 变大, 立体角并没有改变 )

是 Irrediance 在随着 r 变大在衰减


## Radiance

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/radiance6.png)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/radiance7.png)

Radiance 其实是在 Irradiance 基础上增加了方向

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/radiance8.png)

或者说 Irradiance 是四面八方的 Radiance 的积分

## BRDF 双向反射分布函数
通俗的说,  有多少能量, 从某个方向进来, 到反射方向上会分布多少能量.

对于反射的理解:

Whitted Style 光线打到某一个物体上, 然后被弹走了(方向改变了).

另一种理解: 光线打到某一个表面, 结果被吸收了, 然后又朝特定的方向发射出去了.

如何把某一个方向收集到的能量反射到其他方向上去?  BRDF 定义了如何去分配这些能量.
