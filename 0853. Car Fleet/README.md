因为不能超车，所以由近及远的方向，每辆车的实际到达时间是一个递增数列。  
如果后车的`无遮挡到达时间`比前车短，那么按照规则，后车会加入前车形成车队，降速到前车的速度一并行驶。  
由近及远的方向，把每辆车的无遮挡到达时间逐一入栈（单调递增栈）；  
如果待入栈元素（后车）`不大于`栈顶元素（前车），则前车构成遮挡，待入栈元素不能入栈。  
数据结构映射为`单调递增栈`，非常合适！

![My Image](./images/0853_01.png)