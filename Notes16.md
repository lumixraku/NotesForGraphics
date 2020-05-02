# Lecture 16 Ray tracing 4

# Monte Carlo Intergration 蒙特卡洛积分

## 黎曼积分
黎曼积分(Riemann Integral)，也就是所说的正常积分、定积分。 面积可以表达为无数条细长的长方体的和.

蒙特卡洛则是在积分区域内不断的采样, 最后求面积.

目的: 求定积分

# Path tracing

## whitted style raytracing.
不断的弹射光线 在任何弹射的位置和光源连接一条线
- 当光线到光滑物体表面 沿着镜面方向反射 OR 折射方向折射
- 打到漫反射物体, 光线就停住


一般把完全镜面叫做 specular  (mirror  reflection)
没有镜面那么光滑(金属材质) glossy