# Lecture 07 Shading

## z-buffering 深度缓冲

画家算法: 先画远的, 再画近的

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/painter.jpg)

画家算法的问题:  如果有物体相互遮挡  就无从下手了

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/painter2.jpg)

深度缓存每一个像素计算最浅深度

用 0 ~ 1 表示远近程度, 越近越接近0,  颜色越黑

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/zbuffer.jpg)


O(n) 的计算深度的方法  每个物体每个三角形逐个遍历, 每个像素取深度最浅的那个

一开始的时候， 每一个像素的深度都是无穷大. 另外深度缓存是每一帧都会更新

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/zbuffer2.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/zbuffer1.jpg)

## 反射模型

Shading is local.  着色是局部的.(每一个像素点独立运算)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading2.jpg)

兰伯特漫反射和观察角度无关 Independent of view direction

这里的大写字母 I 是光的强度 

diffuse 扩散，Kd (diffuse coefficient) 漫反射系数  （基本上就是材质本身的颜色）
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading3.jpg)

PS:这里入射光方向是指光源相对于这个点的方向，并不是光线射出的方向。

PS: 另外说明一下 max(0, N.I) 当光源从下方打到这个点的时候 N.I的点乘结果是小于0的  因为是兰伯特表面光照， 不考虑物体内部的光。