/**
* 30.代理类
*/

namespace thirty {
    //例子: 实现一个二维数组类

    template<typename T>
    class Array2D {
    public:
        Array2D(int dim1, int dim2);

        class Array1D {
        public:
            T &operator[](int index);

            const T &operator[](int index) const;
        };

        Array1D operator[](int index);

        const Array1D operator[](int index) const;
    };

    int main1() {
        Array2D<int> data(10, 20);
        cout << data[3][6];//这里面的[][]运算符是通过两次重载实现的
    };

    //例子:代理类区分[]操作符的读写:
    //采用延迟计算的方法,修改operator[]让他返回一个(代理字符的)proxy对象而不是字符本身
    //并且判断之后这个代理字符怎么被使用,从而判断是读还是写操作

    class String {
    public:
        class CharProxy {
        public:
            CharProxy(String &str, int index)
                    : theString(str), charIndex(index) {
            }

            CharProxy &operator=(char c) {
                theString.setChar(charIndex, c);
                return *this;
            }

            operator char() const {
                return theString.getChar(charIndex);
            }

        private:
            String theString;
            int charIndex;
        };

        const CharProxy operator[](int index) const {
            return CharProxy(const_cast<String &>(*this), index);
        }

        CharProxy operator[](int index) {
            return CharProxy(*this, index);
        }

        friend class CharProxy;

    private:
        RCPtr <StringValue> value;
    };

}