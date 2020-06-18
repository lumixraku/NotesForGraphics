# Lecture 10  Geometry 1

## 一些经典模型
犹他茶壶
斯坦福兔子
斯坦福龙
康奈尔盒子

## 纹理贴图只能表示纹理吗
环境贴图 (把环境光描述在一张图上)
环境光记录在球上 (Spherical Environment Map)
凹凸贴图 (Bump Mapping)  (定义了一个点的在平面的高度)
凹凸贴图的进化版 位移贴图( Displacement mapping )

### 球体映射到立方体
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/texture10.png)

### Bump Mapping 凹凸贴图
一维场景
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/bump.jpg)

先求切线 得到导数是 dp, 法线和切线垂直， 所以法线是 (-dp, 1)

二维场景
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/bump2.jpg)
导数在二维的情况下叫做梯度  先求水平方向上的变化dp/du 再求垂直方向上的变化

这里的 h() 函数表示高度  c1 c2 表示缩放常数


### 位移贴图
凹凸贴图和位移贴图都是通过一张纹理贴图定义一个点的相对高度

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/texture11.png)

位移贴图真的移动了顶点, 凹凸贴图只是改了法线,那么在物体的边缘上就会穿帮(边缘还是很光滑) 从影子的部分就可以看出来

另外需要说明： 使用位移贴图之前要保证模型本身的三角形足够细， 不然和纹理中的变换对应不上。因为位移贴图是改变模型中顶点位置（也就是每一个三角形中的点）


## 3D 纹理
定义了三维空间中的点的颜色

https://zh.wikipedia.org/wiki/Perlin%E5%99%AA%E5%A3%B0


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/3dtexture.jpg)

三维纹理广泛运用在体积渲染中, 之前的光照模型就是在考虑一个表面.


PS: 纹理还可以定义阴影
下面有一个环境光遮蔽贴图


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/aotexture.jpg)

## 物体几何表示

### 隐式表示

f(x, y, z) = 0

不容易看出物体张啥样, 但是可以通过表达式 =0   >0   <0 判断出点在物体外还是物体内

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/geometry1.png)

### 显式表示

显示表示:  要么直接定义 要么通过参数来定义

点云 OR 参数映射

R^2 => R^3   二维到三维的映射

虽然很容易看出图形的形状, 但是却不好判断点是否在图形内还是外

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/geometry2.png)

### 构造实体几何 CSG

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/geometry3.png)

## 距离函数
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/distance.png)
