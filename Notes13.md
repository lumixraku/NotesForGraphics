# Lecture 13 Ray tracing 1


光线追踪是跟踪眼睛发出的光线( 这点似乎和常识有点不同, 是由于光路可逆 ) 到达物体的过程

光线的一个性质: 光路可逆 (也就是追踪的意思)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/raytracing.jpg)

光线追踪因为 ray 是从眼睛( 摄像机 ) 发出, 因此天然的解决了遮挡(深度测试)的问题,

## Whitted Style Ray tracing

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/raytracing2.jpg)

## AABB 轴对齐包围盒
用来减少没有必要的计算

基于这么一条结论: 如果光线都不和包围盒相交, 那么光线更不和可能和包围盒中的物体相交.

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/aabb1.jpg)

![image](https://github.com/lumixraku/NotesForGraphics/raw/master/images/aabb2.jpg)
