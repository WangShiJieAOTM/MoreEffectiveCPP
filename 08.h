/**
* 08.理解 new和 delete在不同情形下的含义
*/

namespace eight {
    string *p = new string("Memory  Management");

    void *operator new(size_t size) {
        //分配内存
        return malloc(size);
    }

    //一般不会直接调用operator new,但是可以像调用其他函数一样调用它
    void *rawMemory = operator new(sizeof(string));
    //placement new:placement new 是有一些已经被分配但是没有被处理的内存,需要在这个内存里面构造一个对象,使用
    //placement new可以实现这个需求,实现方法:

    class Widget {
    public:
        Widget(int widgetSize);
    };

    Widget *constructWidgetInBuffer(void *buffer, int widgetSize) {
        return new(buffer) Widget(widgetSize);
    }
    //这样就返回一个指针,指向一个Widget对象,对象在传递给函数的buffer里面分配

    //placement new 出来的内存就不应该直接使用 delete 操作符,因为delete会使用 operator delete来释放内存,
    //但是包含对象的内存最初不是被 operator new 分配的,所以不能使用 operator delete 释放它
}