/**
* 12.理解 "抛出异常","传递参数" 和 "调用虚函数" 之间的区别
*/

namespace twelve {
    class Widget {

    };

    void f1(Widget w);

//    catch (Widget w) {
//        //...
//    }

    //上面两行代码的相同点: 传递函数参数与异常的途径可以是传值,传递引用,传递指针

    //一个比抛出的对象可以通过普通的引用捕获,它不需要通过指向const对选哪个的引用捕获,
    //但是在函数调用中不允许传递一个临时对象到一个非const引用类型的参数里面,同时异常抛出的时候实际上是抛出对象创建的临时对象拷贝

    //另外一个区别是在try语句块里面,抛出的异常不会进行类型转换(除了继承和基类之间的转换)

    void f(int value) {
        try {
            throw value; //value 可以是int也可以是double等其他类型
        } catch (double i) {
            //...    //这里只处理double类型的异常,如果遇到int或者其他类型的异常,则不会被捕获
        }
    }
}