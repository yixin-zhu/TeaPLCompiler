# IR 与 Teampl的转换
```
@g = global i32 10
define i32 @fib(i32 %0) {
    %x = alloca i32
    store i32 %0, %x
    %g0 = load i32, i32* @g
    ret i32 %g0
}
define i32 @main() {
    %r0 = call i32 @fib(i32 1)
    ret i32 %r0;
}
```

```
g:int = 10;
fib(param1:int)->int {
    let x:int;
    x = param1;
    return g;
}

main()->int {
    return fib(1);
}
```
# 变量
## 声明
```teampl
let x:int = 0;
//没有初始右值默认为0？
```
```ir
%x = alloca i32
store i32 0, i32* %x
```
## 使用：使用前load到临时寄存器，更新后store
```teampl
x = x + 1;
```

```ir
%x0 = load i32, i32* %x
%x1 = add i32 %x0, 1
store i32 x1, i32* %x
```
优化时再做化简处理

# 复合类型数据定义和存取
```c++
enum class TempType
{
    INT_TEMP,
    INT_PTR,
    STRUCT_TEMP,
    STRUCT_PTR
};

struct Temp_temp
{
    int num;
    TempType type;
    std::string structname;
    std::string varname;
    int len;
    Temp_temp(int _num,
                TempType _type = TempType::INT_TEMP,
                int _len = 0,
                const std::string& _sname = std::string()
            );
};
```
Temp_temp是ir中寄存器的抽象：
- num：寄存器编号
- type：该寄存器中元素的类型
  - INT_TEMP代表该寄存器存的是int类型的数据
  - INT_PTR代表int类型的指针或数组
  - STRUCT_TEMP是struct类型的数据
  - STRUCT_PTR是struct类型的指针或数组
  - 注意：teampl中STRUCT_TEMP只存在于全局变量中
- structname是结构体的名字，当type为STRUCT_TEMP或STRUCT_PTR时有效
- 当此时type为INT_PTR或STRUCT_PTR时，len用于区分指针和数组
  - 当len为0时代表单个元素的指针
  - 当len为-1时代表数组头指针，这种情况只在数组作为函数参数时存在
  - 当len大于0时代表数组的长度
- varname用于debug。
## 数组
### teampl
```
fn main()->int{
    let a[2]:int;//数组定义
    a[0] = 99;//数组赋值
    return a[0];//取数
}
```
### ir
```
define i32 @main() {
    //定义局部变量，把对应关系存在localMap上
    %1 = alloca [2 x i32]
    //数组赋值
    %2 = getelementptr [2 x i32], [2 x i32]* %1, i32 0, i32 0 //获得数组元素对应的指针，存在临时变量中
    store i32 99, i32* %2 //给指针对应的地址赋值
    //数组取值
    %3 = getelementptr [2 x i32], [2 x i32]* %1, i32 0, i32 0//取指针
    %4 = load i32, i32* %3 //从指针对应的地址取值
    ret i32 %4
}
```

## 结构体
### teampl
```
struct Mystruct{
    int a;
    int b;
}

fn main()->int {
    let mystruct:Mystruct;
    //结构体成员赋值
    mystruct.a = 1;
    //end
    return 0;
}
```
### ir
```
%mystruct = type { i32, i32 }
define i32 @main() {
    %1 = alloca %mystruct
    //结构体成员赋值：找到成员在结构体里的位置，从而取出该成员的指针，然后给指针对应的地址赋值
    %2 = getelementptr %mystruct, %mystruct* %1, i32 0, i32 0
    store i32 1, i32* %2
    //end
    ret i32 0
}
```
## C++中的复合类型数据定义和存取
```
struct L_gep
{
    AS_operand *new_ptr,*base_ptr,*index;
    L_gep(AS_operand *_new_ptr,AS_operand *_base_ptr,AS_operand *_index);
};
```

#### 对应 arr[index]
L_gep对应的是llvm ir中的getelementptr，当base_ptr为int数组时，对应的llvm ir如下：
```
%new_ptr = getelementptr [len x i32], [len x i32]* %base_ptr, i32 0, i32 %index
```

#### 对应 arr+index，当arr为函数的传入参数时使用
当base_ptr为int指针时，对应的llvm ir如下：
```
%new_ptr = getelementptr i32, i32* %base_ptr, i32 %index
```

#### 对应 Mystruct.a
当base_ptr为结构体时，对应的llvm ir如下：

```
%new_ptr = getelementptr %structname, %structname* %base_ptr, i32 0, i32 %index
```

#### 对应 arr[10]:Mystruct, arr[0]
当base_ptr为确定长度的结构体数组时，对应的llvm ir如下：
```
%new_ptr = getelementptr [len x %structname], [len x %structname]* %base_ptr, i32 0, i32 %index
```

#### 对应 arr[x]:Mystruct ？存疑
当base_ptr为不定长度的结构体数组时，对应的llvm ir如下：
```
%new_ptr = getelementptr %structname, %structname* %base_ptr, i32 %index
```


# 函数
## 声明
define
## 调用
call
- 使用call指令调用函数
- call指令的第一个参数是函数名，后面的参数是函数的参数
- 用临时变量存储返回值

```
%r0 = call i32 @fib(i32 1)
```
## 返回
ret
```
ret i32 %r0
```

## 参数
？

# 算数运算
## teampl
```
fn main(a:int) ->int {
    let b:int;
    //算数运算
    b = (a+1-2)*3/4;
    return b;
}
```
## ir
```
%2 = alloca i32
//算数运算，中间值用临时变量记录，最后store到dst
%3 = add i32 %0, 1
%4 = sub i32 %3, 2
%5 = mul i32 %3, 3
%6 = sdiv i32 %4, 4
store i32 %6, i32* %2
//函数返回值
%7 = load i32, i32* %2
ret i32 %7
```
# 比较和类型转换
## teample
## ir
```
%2 = alloca i32
%3 = alloca i8
store i32 %0, i32* %2
%4 = load i32, i32* %2
%5 = icmp sgt i32 %4, 0
%6 = icmp sge i32 %4, 0
%7 = icmp slt i32 %4, 0
%8 = icmp sle i32 %4, 0
%9 = icmp eq i32 %4, 0
%10 = icmp ne i32 %4, 0
%11 = zext i1 %10 to i8
store i8 %11, i8* %3
%12 = load i8, i8* %3
%13 = trunc i8 %12 to i1
```
s: signed
g: greater
l: less
e: equal
n: not
类型转换： zero extend
类型转换： truncate

# 跳转语句和Phi指令
```ir
%2 = alloca i32
store i32 0, i32* %2
%3 = load i32, i32* %2
%4 = icmp sgt i32 %3, 0
br i1 %4, label %bb1, label %bb2//条件跳转
bb1:
    store i32 1, i32* %2
    br label %bb3
bb2:
    store i32 0, i32* %2
    br label %bb3//直接跳转
bb3:
    %r0 = phi i32 [ 0, %bb1 ], [ %3, %bb2 ]
    //如前序代码块为%bb1，则%8=0，如前序代码块为%bb2，则%8=%3
ret i32 %r0
```

# 逻辑运算
```ir
%7 = xor i1 %6, true # !%6
```

# 逻辑运算的短路
```ir
//%5 && %7
%5 = xor i1 %4, true
br i1 %5, label %6, label %9
6:
    %7 = load i8, i8* %2,
    %8 = trunc i8 %7 to i1
    br label %9
9:
    %10 = phi i1 [ false, %0 ], [ %8, %6 ]
```

```ir
//%5 || %7
br i1 %5, label %9, label %6
6:
    %7 = load i8, i8* %2, align 1
    %8 = trunc i8 %7 to i1
    br label %9
9:
    %10 = phi i1 [ true, %0 ], [ %8, %6 ]
```