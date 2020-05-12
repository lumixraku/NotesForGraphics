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


### Mass spring system 弹簧质点系统

头发, 布料

在仿真中常用到的一种标记
x 上面一个点表示速度 v   x 上面两个点表示加速度 a

### 布料仿真
![image](https://raw.githubusercontent.com/lumixraku/NotesForGraphics/master/images/spring.jpg)


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
