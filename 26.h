/**
* 26.限制类对象的个数
*/

namespace twentySix {
    //比如某个类指引只应该有一个对象,那么最简单的限制这个个数的方法就是把构造函数声明为私有的,这样每个人都没有权力创建对象
    //或者做一个约束,每一次创建的时候都返回static的对象
    class Printer {
    public:
        friend Printer &thePrinter();

    private:
        Printer();  //声明为私有的,这样就不能创建对象了
        Printer(const Printer &rhs);
    };

    Printer &thePrinter() {
        static Printer printer;//返回static对象,这样就只能创建一个对象了 典型的Singleton模式
        return printer;
    }

    //另一个直观的方法来限制对象的个数就是使用一个计数器,每次创建对象的时候计数器加一,每次销毁对象的时候计数器减一
    //这种方法在出现继承的时候会出现问题(一个Printer和一个继承自Printer的colorPrinter同时存在的时候,就会超出numObjects个数,这个时候就要限制继承)


    //一个具有对象计数功能的基类,如果拥有大量像Printer这样的类需要计数,name较好的方法就是一次性封装所有的技术工鞥和,确保每个进项实例基础的类都有
    //一个相互隔离的计数器:

    template<class BeingCounted>
    class Counted {
    public:
        class TooManyObjects {
        };

        static int objectCount() {
            return numObjects;
        }

    protected:
        Counted();

        Counted(const Counted &rhs);

        ~Counted() { --numObjects; }

    private:
        static int numObjects;
        static const size_t maxObjects;

        void init();//避免构造函数的代码重复
    };
}