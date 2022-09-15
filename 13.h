/**
* 13.通过引用捕获异常
*/

namespace thirteen {
    //使用指针方式捕获异常:
    //不需要拷贝对象,但是最快的,但是 很多程序员忘记写static,忘记写static的话,会导致异常在抛出后,因为离开了作用域而失效:
    void someFunction() {
        static exception ex;
        throw ex;
    }

    void doSomething() {
        try {
            someFunction();
        }
        catch (exception *ex) {
            //...
        }
    }

    //创建堆对象抛出异常:
    //new exception 不会出现异常失效的问题,但是会出现在捕捉之后是否应该删除他们接受的指针,在哪一个层次删除指针的问题,
    //通过值捕获异常:
    //不会出现上述问题,但是会在被抛出时系统将异常对象拷贝两次,而且会出现派生类的异常对象被作为基类异常对象捕获时,会把派生类的一部分切掉

    class exception {
    public:
        virtual const char *what() throw();
    };

    class runtime_error : public exception {
        void someFunction() {
            if (true)
                throw runtime_error("runtime error");
        }

        void doSomething() {
            try {
                someFunction();
            }
            catch (exception ex) {
                //...
                cerr << ex.what() << endl;//这个时候调用的就是基类的what()方法,而不是派生类的what()方法
            }
        }
    };

    //通过引用捕获异常:可以避免上面的所有问题
    void someFunction() {
        static exception ex;
        throw ex;
    }

    void doSomething() {
        try {
            someFunction();
        }
        catch (exception &ex) {
            //... 这个时候就是调用的runtime_error而不是基类的exception::what()了，其他和上面其实是一样的
        }
    }
}