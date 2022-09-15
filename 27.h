/**
* 27.要求或禁止对象分配在堆上
*/

namespace twentySeven {
    //必须在堆中建立对象(程序有自我管理对象的需求):
    //禁用隐式的构造函数和析构函数,例如声明为private,或者仅仅让析构函数成为 private(副作用小一些),然后创建一个public的destory()方法来调用析构,
    //遇到继承析构的话,现在的做法无法继承,也可以将析构函数声明成protected的

    //判断一个对象是否在堆中: 在构造函数中无法区分是否在堆中,但是在new里面可以做些事情:

    class UPNumber {
    public:
        class HeapConstraintViolation {
        };

        static void *operator new(size_t size);

        UPNumber();

    private:
        static bool onTheHeap;
    };
    //实际上,上面这段代码是跑不了的,因为如果使用new[]创造数组的话就没有办法用了
    //另一种是方法判断变量所在的地址 因为 stack 是从高位地址向下的,heap是从低位地址向上的

    bool onHeap(const void *address) {
        char onTheStack;//局部栈变量,因为他是新的变量,所以比他小的都在堆里或者在静态空间里,比他大的都在栈里面
        return address < &onTheStack;
    }

    //禁止堆对象: 直接重写 operator new 就行了,比如弄成private
}