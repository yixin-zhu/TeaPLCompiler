# Assignment3 Type check of compiler
## Classes of type check
1. not defined
    - variable 
    - function
    - struct
    - struct member
2. definition not matched
    - function definition vs declation
3. duplicate definition
    - duplicate definition of a name in same type[functino/variable/struct]
4. type not comparable
    - get member from a non-struct type 
    - assign value to a function
5. out of range
    - try to get array members beyong definition
### Rules
- 不需要支持变量声明时的类型推断。
- 函数声明和全局变量声明不关注位置
- 声明的全局变量引用了其他全局变量时，被引用的全局变量必须在被引用之前声明。
- 全局变量的声明不会依赖函数: Just check the type and other variables
- 局部变量不能与任何位置的全局变量重名
- 函数参数能与全局变量重名,函数参数在函数作用域内优先于全局变量
- 函数可以先声明后定义，也可以直接定义，但只能【声明+定义】或【定义】一次。不需要支持函数的重载。

## Workflow
### Step 1 Check global declations and definitions
### Step 2 Check local declations and definitions
## Examples
var c on line 6, col 5 is not defined.

cannot assign a value to function main on line 6, col 5.

function definition on line 8 doesn't match the declaration on line 1.

type check passed.

line 7, col 9: local variables dplicates with function params.

line 10, col 5: member 'tail' is not defined.

line 15, col 8: MyStruct is not comparable with int.

line 13, col 5: a is not a struct.