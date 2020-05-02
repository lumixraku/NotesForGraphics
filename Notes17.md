# Lecture 17 Material


# BRDF  (R:Reflection)

BRDF 就是两个方向的函数 (一个入射方向 一个出射方向)
入射方向决定以后, BRDF 可以得到出射方向的分布.


# 散射 Scatter
散射包括反射和折射

# 反射

# 折射

## 焦散
由于光线的聚焦产生的明显图案

海底的这幅图  (老师本人设为焦散这个翻译不合适  因为实际上是聚焦  并没有发散)

因为海水不平整 肯定会形成多个光线聚在一块的情况

## 斯涅耳定律 Snell Law

当这个根号下的内容 < 0 的时候  也就是 1 - xxx < 0  这个 xxx 的部分 > 0  也就是 N1/N2 > 1  此刻全反射

也即是入射介质的折射率大于折射介质的折射率  比如从水中看向水面

## 非涅耳项

决定多少能量发射了反射  多少能量发生了折射

较为平视物体的时候  能看到能多反射
俯角看物体的时候  反射最少

# 微表面 MircoFacet
近处看  是不同的几何
远处看  是材质

漫反射的粗糙表面  在很近的地方看, 可以理解为是很多很小的镜面

每一个微表面  就是很小很小的镜面


## PBR
PBR 就会使用微表面模型

## 各向异性材质  各项同性材质
各向同性:  微表面不存在方向性 OR  方向性很弱  发生漫反射的物体

各项异性:  微表面存在明确的方向性 (比如金属水壶, 不锈钢杯子等)

## BRDF 的性质
入射方向和出射方向调换  得到的出射方向就是之前的入射方向

能量守恒 (能量不会增多)