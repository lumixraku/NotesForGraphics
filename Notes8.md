# Lecture 08 Shading 2

## 高光模型

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading4.jpg)

Specular Shading  n 法向量 h 半程向量  p 是柔和衰减系数  h是观察方向和入射光方向的中间向量

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading5.jpg)

相比 Phong 高光, Blinn-Phong 高光因为引入了半程向量, 更容易计算.

上面的 p 次方, 是为了柔和衰减

PS: 这里有个max(0, cosα) 是为了考虑光从平面下方打到平面的情况  我们只取大于 0 的值

PS: cosα 可以写成 法线n 点乘 半程向量h

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading6.jpg)

PS: 另外需要说明的是入射光方向和中学物理中的方向是相反的， 这个公式中入射光的方向就是用光源减去点

## 环境光

ka 可以认为是常量 也就是环境光的颜色 Ia 表示环境光的强度  

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading7.jpg)


## Phong 光照总结

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading8.jpg)


## 着色频率
平坦着色: 逐个三角形着色
Gouraud着色: 逐个顶点着色 (根据顶点做插值) (顶点求法线)
Phong着色: 逐像素着色

顶点的法线

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading9.jpg)

每个像素点的法线

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading10.jpg)

## 渲染管线

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/pipeline.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/pipeline1.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/pipeline2.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/pipeline3.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/pipeline4.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/pipeline5.jpg)
