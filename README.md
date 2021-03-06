# C, C++, Objective-C学习笔记

## 简介
```
----code
    |
    |----StudentInfomationManagementSystem
    |
    |----SimpleDemo // 简单的一些属性之类设置
    |
    |----LoginDemo // 界面切换
    | 
    |----WeichatDemo // 微信模仿， 新功能介绍页和登录页面
    |
----note
    |
    |----1-1 C复习.md(c语言学习笔记)
```

## Chalk

`Chalk`类库用于实现终端下的彩色输出，支持高亮，多种颜色等。

你可以在`code/StudentInfomationManagementSystem`中找到原文件。

![show1-1](./note/_image/show1-1.png)

你可以这样使用

```c
#include "chalk.h"

// ....

Chalk *chalk = (Chalk *)malloc(sizeof(Chalk));
initialize_chalk(chalk);
chalk->setForecolor(chalk, "green");
// ... 其他一些配置 参见.h文件
chalk->print(chalk, message); // 打印输出
```

## 学生信息管理系统

基于纯C，面向过程实现，完成进度`40%`

![show2-1](./note/_image/show2-1.png)



![show2-2](./note/_image/show2-2.png)

![show2-3](./note/_image/show2-3.png)

## 界面仿制

### 微信模仿(精简)

![sss-1](note/_image/sss-1.png)

![sss-2](note/_image/sss-2.png)



### 网易云(抽象)

![show3-1](note/_image/show3-1.png)

