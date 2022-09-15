/**
* 24.理解虚函数,多重继承,虚基类以及RTTI所带来的开销
*/

namespace twentyFour {
    //C++ 的特性和编译器会很大程度上影响着程序的效率,所以我们有必要知道编译器在一个C++特性后面做了什么事情

    //例如虚函数,指向对象的指针或引用的类型是不重要的,大多数编译器使用的是 virtual table 和 virtual table pointer来实现的

    //virtual table
    class C1 {
    public:
        C1();

        virtual ~C1();

        virtual void f1();

        virtual int f2(char c) const;

        virtual void f3(const string &s);

        void f4() const;

        //vtbl的虚拟表类似于下面这样,只有虚函数在里面，非虚函数的f4不在里面
        // ___
        //|___| → ~C1()
        //|___| → f1()
        //|___| → f2()
        //|___| → f3()

        //vptr
        // __________
        //|__________| → 存放类的数据
        //|__________| → 存放vptr
        //每一个对象都只存储一个指针，但是在对象很小的时候，多于的vptr将会看起来非常占地方。
        //在使用vptr的时候，编译器会先通过vptr找到对应的vtbl，然后通过vtbl开始找到指向的函数 事实上对于函数：
        //pC1->f1();
        //他的本质是:
        //(*pC1->vptr[i])(pC1);
    };

    //RTTI  Runtime Type Information 在runtime的时候能找到对象的类信息就说明肯定有一个地方存储了这些信息,
    //如果把每个对象都添加一个隐形的数据成员type_info来存储这些信息,这样会占用很大的空间.

}