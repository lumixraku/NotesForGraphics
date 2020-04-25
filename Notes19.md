# Lecture 19 Camera & Lens & Light Fields

Sensor 记录的是 irradiance.

针孔相机无法得到景深效果, 不论远近都是一样清晰.


# FOV 视场

和广角有关

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/fov.jpg)

从上图可知, 视场和焦距, 传感器大小有关


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/fov2.jpg)

视场越窄, 到的东西就越远.

## 曝光

T ✖️ E 时间乘以 irradiance.  (irradiance 辐照度 简化的理解可以是流明, 光的强度)

瞳孔可以理解为光圈, 因此在暗光的环境下, 瞳孔会放大.

## ISO
ISO 是后期处理, 一张图 ✖️ 一个数 得到的结果. 因此原来的噪声也会成倍的放大.

## 机械快门

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shutter.jpg)

由于是像闸门一样打开快门, 因此对于螺旋桨这样的高速运转的物体拍摄存在问题.

# 镜头

一般来说透镜是将平行光聚集到一个点. 不过下面这个另一面是平的透镜则不能这样

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/len.jpg)

现在手机通过透镜组, 实现动态改变焦距.

光线通过透镜的中心, 方向不会改变.

焦距和物距相距的关系
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/len2.jpg)

# 景深

## Defocus Blur

## COC 弥散圆

近视的原理
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/coc.jpg)

大光圈和小光圈会影响到模糊的范围, 大光圈是远处的物体模糊.

所谓远处的物体模糊, 就是说清晰的范围很小. 而小光圈之所以整个物体不论远近都很清晰, 实际上是因为清晰的范围大.


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/dof.jpg)
DF 是最远的深度, DN 是最近的深度

关于上面说到的清晰的范围, 可以在 [这里](http://graphics.stanford.edu/courses/cs178/applets/dof.html) 体验各个参数对DOF的影响

DOF = DF - DN

这里左边红色的区域就是 DOF 的范围


当光圈很大的时候, DOF范围很有限.
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/dof1.jpg)


当光圈很小的时候, DOF 很大(很远)
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/dof2.jpg)
