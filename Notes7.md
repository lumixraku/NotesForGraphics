# Lecture 07 Shading

## z-buffering 深度缓冲

画家算法: 先画远的, 再画近的

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/painter.jpg)

画家算法的问题:  如果有物体相互遮挡  就无从下手了

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/painter2.jpg)


用 0 ~ 1 表示远近程度, 越近越接近0,  颜色越黑

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/zbuffer.jpg)


O(n) 的计算深度的方法  每个物体诸葛遍历, 每个像素取最近的那个

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/zbuffer2.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/zbuffer1.jpg)

## 反射模型

Shading is local.  着色是局部的.(每一个像素点独立运算)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading.jpg)


兰伯特漫反射和角度有关
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading2.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/shading3.jpg)