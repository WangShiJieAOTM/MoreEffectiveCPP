/**
* 20.协助编译器实现返回值优化
*/

//一个返回整个对象的函数效率是很低的,因为要调用对象的析构函数和构造函数,但是有时候编译器会帮助优化我们实现
namespace twenty {
    class Rational {
    public:
        Rational(int numerator = 0, int denominator = 1);

        int numerator() const { return n; }

        int denominator() const { return d; }

    private:
        int n;
        int d;
    };

    int main1() {
        inline const Rational operator*(const Rational &lhs, cnst Rational &
        rhs)
        {
            return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator())
        }

        //上面这个操作太骚了,初看起来好像是会创建一个Rational的临时对象,但是实际上编译器会把这个临时对象优化掉,这样就免除了析构和构造的开销
        //而且inline可以减少函数的调用开销

        //直接return 到赋值的地方-->>这个地方是编译器帮我们优化的地方
    }
}