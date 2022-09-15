/**
* 33.将非尾端类设计为抽象类
*/

namespace thirtyThree {
    namespace Origin {
        class Animal {
        public:
            virtual Animal &operator=(const Animal &rhs);
        };

        class Lizard : public Animal {
        public:
            virtual Lizard &operator=(const Animal &rhs);
        };

        class Chicken : public Animal {
        public:
            virtual Chicken &operator=(const Animal &rhs);
        };
    }

    //↑会出现我们不愿意出现的类型转换和赋值:
    int main1() {
        Animal *pAnimal1 = new Lizard;
        Animal *pAnimal2 = new Chicken;
        *pAnimal1 = *pAnimal2;//把一个chicken赋值给一个lizard

        //但是我们又希望下面这个操作是可行的:
        Animal *pAnimal1 = new Lizard;
        Animal *pAnimal2 = new Lizard;
        *pAnimal1 = *pAnimal2;//把一个lizard赋值给一个lizard
    }

    //解决这个问题的最简单的方法是使用dynamic_cast进行类型检测,但是还有一种方法就是把Animal设为抽象类或者创建一个抽象 Animal 类
    namespace abstractAnimal {
        class AbstractAnimal {
        protected: //这个protected是精髓  防止了不同的派生类赋值
            AbstractAnimal &operator=(const AbstractAniml &rhs);

        public:
            virtual ~AbstractAnimal() = 0;
        };

        class Animal : public AbstractAnimal {
        public:
            Animal &operator=(const Animal &rhs);
        };

        class Lizard : public AbstractAnimal {
        public:
            virtual Lizard &operator=(const Lizard &rhs);
        };

        class Chicken : public AbstractAnimal {
        public:
            virtual Chicken &operator=(const Chicken &rhs);
        };
    };
}