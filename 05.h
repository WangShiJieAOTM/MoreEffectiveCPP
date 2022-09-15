/**
* 05.小心用户自定义的转换函数
*/
namespace five {
    //因为可能会出现一些无法理解的并且也是无能为力的运算,而且在不需要这些类型转换函数时,仍然可能会调用这些转换
    class Rational {
    public:
        Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {}

        operator double() const {};

    private:
        int n;
        int d;
    };

    int main1() {
        Rational r(1, 2);
        double d = 0.5 * r; //调用了Rational的转换函数,将r转换为double类型
        std::cout << r << std::endl;//会调用最接近的类型转换函数 double(),将r转换成double打印出来,而不是想要的1/2
        return 0;
    }
    //上面问题的解决方法是 把double变成:
    //double asDouble() const;
    //然后在main函数中调用asDouble()函数
    //但是即使这样做还是会出现隐式转化的问题:

    template<typename T>
    class Array {
    public:
        Array(int size);
        //explicit Array(int size);//explicit关键字可以阻止隐式转换

        T &operator[](int index);
    };

    bool operator==(const Array<int> &lhs, const Array<int> &rhs);

    int main2() {
        Array<int> a(10), b(10);

        if (a == b[3])//想要写 a[3] == b[3] 但是这时候编译器并不会报错,解决方法是使用explicit关键字
            ;
    }

    //还有一种很骚的写法:

    class Array2 {
    public:
        class ArraySize {
        public:
            ArraySize(int numElements) : theSize(numElements) {}

            int size() const { return theSize;}

        private:
            int theSize;
        };

        Array2(int lowBound, int highBound);
        Array2(ArraySize size);

        //↑这样在写代码 Array2 a(10); 时,编译器会通过类型转换转换炒年糕ArraySize,然后再进行构造,这样更麻烦效率也降低了许多
        //但是在一定程度上可以避免隐式转换的问题
    };


}