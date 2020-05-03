# Lecture 16 Ray tracing 4  Monte Carlo Path Tracing 蒙特卡洛路径追踪

# Monte Carlo Intergration 蒙特卡洛积分

蒙特卡罗是为了解决定积分的问题

之前大学数学中学的求定积分的方法, 是先求出原函数再带入值.  对于一些复杂的函数是没有办法求到原函数的, 怎么办呢?

## 黎曼积分
Riemann Integral，黎曼积分的核心思想就是试图通过无限逼近来确定这个积分值. 把积分区域分割为无数个细长的条.

## 蒙特卡罗积分
目的: 求定积分    蒙特卡洛则是在积分区域内不断的采样, 采样很多次, 最后求平均值, 也就是面积.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/monte.jpg)

PS: 这里的 N 是采样次数  N越大, 得到的结果越准

PS: 蒙特卡罗适合任何形式的积分.


# Path tracing 路径追踪

和之前的 Ray Tracing 有什么不同呢?

## whitted style raytracing.

这种ray tracing 的特点是

- 当光线到光滑物体表面 沿着镜面方向反射 OR 折射方向折射
- 打到漫反射物体, 光线就停住

问题1 whitted形式的ray tracing 对于完全镜面的材质是OK的, 但是对于 glossy 材质的物体则有问题.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/whittedProblem.jpg)



```
什么是 glossy

一般把完全镜面叫做 specular  (mirror  reflection)

没有镜面那么光滑(金属材质) glossy

```

问题2  同样, 对于漫反射, 其实也没有停下来, 光线还是会存在弹射, 反射到不同的方向上.

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/whittedProblem2.jpg)

满发射和漫反射之间的情况就没有考虑到.



# Read More
关于蒙特卡罗积分的详细介绍  [Wyman的博客](https://www.qiujiawei.com/monte-carlo/)