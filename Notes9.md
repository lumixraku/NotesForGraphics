# Lecture 09

## 重心坐标

一种三角形的坐标系统 (只要这个点在三角形内, 表示这个点不一定需要常见的笛卡尔那种坐标系统)

只要知道了三角形的三个点, 那么重心坐标可以由这三个点的线性组合来表示

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/barycentric1.jpg)

求解
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/barycentric2.jpg)

这里还可以看 [重心坐标](https://zhuanlan.zhihu.com/p/58199366)


### 用途

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/barycentric.jpg)

已知三个顶点的情况下用来求线性插值
(顶点可以表示位置  纹理坐标 颜色 法线 深度)


## 纹理的应用

最常见: 漫反射的颜色
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/texture2.jpg)

当纹理太小  不足以覆盖物体表面的时候, 怎么办?

### 双线性插值
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/texture2.jpg)


综合下来 双线性插值最好
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/texture3.jpg)

### 如果纹理太大, 怎么办?

很远很远的物体, 由于透视显得很小, 但是纹理图片的尺寸是固定的, 此时会出现很多个纹理要挤在很小的像素范围内渲染

这样近处有锯齿 远处有摩尔纹
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/texture4.jpg)


最左边是最近的像素点, 一个像素点上只有纹理的一小部分

最右边是远处的像素点, 此时一个像素点会覆盖纹理上很多点

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/texture5.jpg)

解决办法之一可以是超采样, 但是代价也很大

## Mipmap
可以很快速做正方形的范围查询

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/texture6.jpg)

虽然相比原图 128 * 128 多了 64*64, 32 * 32 .... 等这样的图, 但即使这些小图和原图加在一起, 也只比原图多了 1/3 的大小.

参考极限  https://en.wikipedia.org/wiki/1/4_%2B_1/16_%2B_1/64_%2B_1/256_%2B_%E2%8B%AF


![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/texture7.jpg)

近大: 使用底层纹理   远小: 使用高层纹理 (纹理金字塔)

可以看到这里的一个近处表面, 使用的纹理不相同, 可能会导致渲染后表面的纹理不连续, 导致物体表面清晰度的不一样.
主要是因为我们的纹理是第1层, 第2层这样, 并不存在一种1.5层这样中间的纹理.

因此可以利用三线性插值, 最后得到  (其中第三个线性是纹理金字塔的垂直方向)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/texture8.jpg)


### 各项异性过滤
![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/texture9.jpg)

对于矩形区域范围查询比 mipmap 的正方形过滤要好  但是斜着的扔不好

因此引入了 EWA filtering