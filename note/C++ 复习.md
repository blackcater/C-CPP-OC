# C++ 复习

[TOC]

## C++与C区别

`c++`支持bool类型。

支持新的初始化方法：

```c++
int x(1024);
// 相当于
int x = 1024;
```

变量随用随定义。

```c++
cout << oct << x << endl; // 八进制输出数字
cout << dec << x << endl; // 十进制输出数字
cout << hex << x << endl; // 十六进制输出数字
cout << boolalpha << y << endl; // 以布尔值方式输出
```



## 命名空间

防止变量函数重名的冲突。

命名空间定义使用关键字`namespace`。

```c++
// 定义命名空间
namespace A {
  
}
// 使用命名空间
using namespace A;
```



## 引用

```c++
int &a = b; // 需要被初始化 相当于给b区了个别名a
// 这样a和b地址一样，有点像int *a = &b;

// 引用作为函数参数，例如将两值进行交换，就需要使用指针。而现在引用就可以搞定
```



## `const`

