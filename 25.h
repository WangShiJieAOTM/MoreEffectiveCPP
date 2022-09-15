/**
* 25.使构造函数和非成员函数具有虚函数的行为
*/

namespace twentyFive {
    class NewLetter {
    private:
        static NLComponent *readComponent(istream &str);

        virtual NLComponent *clone() const = 0;

    public:
        NewLetter(istream &str) {
            while (str) {
                components.push_back(readComponent(str));
            }
        }

        //通过上面这种方法,我们上面的NewLetter函数就可以这样
        NewsLetter(const NewsLetter &rhs) {
            for (vector<NLComponent *>::const_iterator it = rhs.components.begin(); it != rhs.components.end(); ++it) {
                components.push_back((*it)->clone());
            }
        }
        //这样每一个TextBlock都可以调用它自己的close函数,其他子类也可以调用他们对应的close函数
    };

    class TextBlock : public NLComponent {
    public:
        virtual TextBlock *close() const {
            return new TextBlock(*this);
        }
    };

    //上面这段代码中, readComponent就是一个具有构造行为的函数,我们叫做虚拟构造函数
    //close()叫做虚拟拷贝构造函数,相当于拷贝一个新的对象

}