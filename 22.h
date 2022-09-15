/**
* 22.考虑使用 op=来取代单独的 op运算符
*/

namespace twentyTwo {
    // operator+ 和 operator+= 是有区别的,如果想要使用+=,那么最好重载operator+=,一个比较好的方法就是吧+号用+=号来代替

    template<class T>
    const T operator+(const T &lhs, const T &rhs) {
        return T(lhs) += rhs;
    }

    template<class T>
    const T operator-(const T &lhs, const T &rhs) {
        return T(lhs) -= rhs;
    }

    template<class T>
    const T operator+=(const T &lhs, const T &rhs) {
        return T(lhs.value) + rhs.value;
    }

}