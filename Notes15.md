# Lecture 15 Ray tracing 3

## 微分立体角

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/radiance6.png)

θ是和 Y轴的夹角, φ 是围绕 y 的旋转角度

PS  微分立体角 和 θ 有关, 靠近赤道和极地变化率不一样

## Irradiance
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

## Irradiance  VS  Radiance

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/radiance8.png)

dA 的能量就是每一个从每个方向来的的能量做积分.  或者说 Irradiance 就是是四面八方的 Radiance 的积分(求和)

## BRDF 双向反射分布函数
用于描述了光线和物体如何相互作用

通俗的说, BRDF是在解决光从某个方向打到以个物体上, 光向反射到不同方向的能量分布. OR  对于一个物体的表面, 如何把收集到的能量反射的另外的方向上去.

```
对于反射的理解:

Whitted Style 光线打到某一个物体上, 然后被弹走了(方向改变了).

另一种理解: 光线打到某一个表面, 被吸收了, 然后从这个物体表面, 朝某个特定的方向发射出去.
```

## The Reflection Equation 反射方程

ωi 表示不同方向的入射光 (从内到外)

p 表示反射点 point

Li(p, ωi) 是入射光的 radiance

fr 对于每一个入射方向都会对应一个着色点和出射方向 这样的BRDF 函数


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/brdf.png)

PS: Li(p, ωi)cos(θi)dωi 做积分就是图中那一个小块区域得到的 Irradiance








## The Rendering Equation 渲染方程

通过一个方程描述所有的光线传播(仅限于物体表面)

### 递归

射出的radiance 可能成为其他点的入射radiance (此刻被照亮的物体本身作为光源存在了), 因此入射光不仅仅是单一的光源.


### 渲染方程
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/rendering2.jpg)


所看到的光 等于物体自己发出的光 + 从四面八方反射过来的光


Le(p, ωo) 表示自发光

Ω+  OR   H^2 表示半球

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/rendering.jpg)


PS: 注意和 BlinnPhong 一样, 虽然我们知道光是从外部射入, 但是规定上入射光的方向 ωi 是从内向外

### Reflection Equation 反射方程

单一点光源的简单情况

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/reflect.jpg)

多个点光源的情况

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/reflect2.jpg)

当有一个面光源的时候

实际上就是把面光源当做多个点光源的集合,  对立体角做积分

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/reflect3.jpg)


但是对于其他物体反射过来的光应该怎么整?

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/rendering3.jpg)


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/rendering4.jpg)

PS: 光线追踪特别适合处理间接光照

## Brief Review of probability theory 概率论回顾

随机变量分布: 通俗的说随机变量根据不同的概率取不同的值. 取某些值概率大, 某些值概率小.

期望: 不断的取随机变量, 然后求平均.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/propability.jpg)

### PDF (Probability Distribution Function) 概率密度函数
描述连续情况下的概率和分布  (之前掷骰子的例子是离散情况)

PS: 仍然是微积分的思想, 把之前离散的取值(x=1, 2, 3 ..)
不断细分(x=1.11...1, x=1.11...2 ...), 使其成为连续的随机变量.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/propability2.jpg)


# Read More

## BRDF
https://blog.csdn.net/anx8282/article/details/101860444?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-3

双向反射是指地物的反射率随入射方向和反射方向而变化的特性  实际地物的反射都是具有方向性的，是入射方向和观测方向的函数。

https://www.cnblogs.com/mengdd/p/3237991.html

PDF 概率密度函数


## (Radiance versus irradiance
(Radiance versus irradiance)[http://sites.sinauer.com/animalcommunication2e/chapter04.02.html]

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/radiance11.jpg)
