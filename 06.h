/**
* 06.区别自增运算符和自减运算符的前缀形式和后缀形式
*/

namespace six {
    class UPInt {
    public:
        UPInt &operator++();//前缀形式
        const UPInt operator++(int);//后缀形式

        UPInt &operator--();//前缀形式
        const UPInt operator--(int);//后缀形式

        UPInt &operator+=(int);//+=运算符,结合UPInts和ints
    };

    UPInt &UPInt::operator++() {
        *this += 1;
        //前缀形式
        return *this;
    }

    const UPInt UPInt::operator++(int) {
        UPInt oldValue = *this;
        ++(*this);
        //后缀形式
        return oldValue;
    }
}

/**
* 前缀式和后缀式的重载形式是不同的,重载的时候不要进行连续重载例如i++++,因为连续的+号会导致创建多个临时对象导致效率变低
*/