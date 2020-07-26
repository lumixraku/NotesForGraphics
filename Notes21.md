# Lecture 21 Animation

- 关键帧动画
- Physical Simulation 物理仿真
- Kinematic 运动学
- Rigging 骨骼动画

## 关键帧动画

插值

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/keyframe.jpg)

线性插值效果往往不好  一般会使用样条函数来插值

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/keyframe2.jpg)

## 物理仿真

- 衣物仿真
- 流体仿真


## Mass spring system 弹簧质点系统

## 非0 长度的弹簧
Ks 系数
b - a 受力方向 （向量b - 向量a） 最后归一化
最后面表示受力大小

###
在仿真中常用到的一种标记
x 上面一个点表示速度 v   x 上面两个点表示加速度 a


## Damping Force
摩擦力 OR 阻尼
没有这个值的话  弹簧将永远震动下去

这里 b 上面有一个点表示速度  速度是向量

为了使弹簧停下来不要震动  需要施加一个和弹簧速度相反的力  

但是这只能描述弹簧作为一个整体的情况  无法描述弹簧内部的力

b - a 弹簧内的相对速度

一个向量 点乘单位向量， 就是在这个向量上做投影

只考虑沿着ab方向的相对速度

### 布料仿真
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/spring.jpg)

第一种结构无法描述布料拉伸（切变）  
第一种结构无法描述布料对折 （布料很难像纸那样完整的对折  目前这个结构很容易做成对折纸张）

因此每个小格子都加上对角线  应对拉伸切变

但是这个还是可以对折 （沿着 x OR y 方向）

因此又加上跳跃链接


## 粒子系统 Particle system
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/particle.jpg)

牛顿万有引力: 计算粒子之间相互的作用力

基于粒子的流体模拟
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/particle2.jpg)

鸟群行为模拟
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/particle3.jpg)


## 运动学

### 正向运动学
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/kinematic.jpg)

正向运动学的优缺点
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/kinematic2.jpg)

主要缺点是 完成一个动作操作太繁琐

### 反向运动学

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/kinematic3.jpg)


![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/kinematic4.jpg)

![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/kinematic5.jpg)

反向运动学可能有多个解  且解可能不存在

## Rigging 骨骼动画

### 运动捕捉
