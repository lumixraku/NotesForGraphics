# Lecture 13 Ray tracing 1

## why

光线追踪能解决全局效果的场景  (尤其是间接光照很合适, 当然并不是说光栅化就不能做全局光照)

一般认为光栅化是属于快速近似. 并不是那么精细. 而光线追踪追求更加真实.

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/raytracing3.png)

glossy 表示有点反光, 但是又有些粗糙的物体 (铜镜)



早期人类认为人能看见物体, 是因为眼睛发出光线, 看到物体之后再返回来.  这和现在的常识不符.

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/emmision.png)


光线追踪是跟踪眼睛发出的光线( 这点似乎和常识有点不同, 是由于光路可逆 ) 到达物体的过程

光线的一个性质: 光路可逆 (也就是追踪的意思)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/raytracing.png)

光线追踪因为 ray 是从眼睛( 摄像机 ) 发出, 因此天然的解决了遮挡(深度测试)的问题,

## Whitted Style Ray tracing

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/raytracing2.png)

## AABB 轴对齐包围盒
用来减少没有必要的计算

基于这么一条结论: 如果光线都不和包
\围盒相交, 那么光线更不和可能和包围盒中的物体相交.

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/aabb1.png)

最终的包围盒中的射线, 是这三者求交集

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/aabb2.png)
