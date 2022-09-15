/**
* 14.审慎地使用异常规格
*/

namespace fourteen {
    //异常规格指的是函数指定只能抛出异常的类型
    extern void f1(); //f1可以抛出任意类型的异常
    void f2() throw(int); //f2只能抛出int类型的异常
    void f2() throw(int) {
        f1();   //编译器会因为f1和f2的异常规格不同而在发出异常时调用 unexpected
    }

    template<class T>
    bool operator==(const T &lhs, const T &rhs) throw() {
        return &lhs == &rhs;
    }

    //↑看上去没啥问题  其实如果传入的T 的 &运算符被重载 operator &就有可能抛出异常,这样就违反了异常规则,让程序跳转到unexpected

    //阻止程序跳转到unexpected的三种方法:将所有的unexpected异常都替换成UnexpectedException对象

    class UnexpectedException {
    };//所有的unexpected异常都替换成UnexpectedException对象

    void convertUnexpected() {//如果一个unexpected异常被抛出,就会调用这个函数
        throw UnexpectedException();
    }

    set_unexpected(convertUnexpected);//将unexpected替换成convertUnexpected
}