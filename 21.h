/**
* 21.通过函数重载避免隐式类型转换
*/

namespace twentyOne {
    //改代码之前↓
    class UPInt {
    public:
        UPInt();

        UPInt(int value);
    };

    const UPInt operator+(const UPInt& lhs, const UPInt& rhs)
    {
        return UPInt(lhs.value() + rhs.value());
    }

    upi3 = upi1 + upi2;
    upi3 = 2 + upi1;
    upi3 = 10 + upi1;//会产生隐式类型转换,转换过程中会出现临时对象.

    //改代码之后↓

    const UPInt operator+(const UPInt& lhs, const UPInt& rhs)
    {
        return UPInt(lhs.value() + rhs.value());
    }
    const UPInt operator+(int lhs, const UPInt& rhs)
    {
        return UPInt(lhs + rhs.value());
    }
    const UPInt operator+(const UPInt& lhs, int rhs)
    {
        return UPInt(lhs.value() + rhs);
    }
}