/**
* 09.使用析构函数防止资源泄漏
*/

namespace nine {
    class ALA {
    public:
        virtual void processAdoption();
    };

    class Puppy :public ALA
    {
    public:
        virtual void processAdoption();
    };

    class Kitten :public ALA
    {
    public:
        virtual void processAdoption();
    };

    void processAdoptions(istream &dataSource) {
        while (dataSource) {
            ALA *pa = readALA(dataSource);//ALA(Abstract base class)是个抽象基类
            pa->processAdoption()
            delete pa;
        }
    }

    void processAdoptions2(istream &dataSource) {
        while (dataSource) {
            ALA *pa = readALA(dataSource);
            if (pa) {
                pa->processAdoption();
                delete pa;
            }
        }
    }

#include<memory>
    void processAdoptions3(istream &dataSource) {
        std::unique_ptr<ALA> pa(readALA(dataSource));//使用unique_ptr来管理对象,可以有效的防止内存泄漏
    }
}