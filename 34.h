/**
* 34.理解如何在同一程序中混合使用C
*/

namespace thirtyFour {
    //因为 C++支持函数重载,C不支持所以C++的编译器为函数专门改变了名字

    //C++的extern 'C'可以禁止名字变换,例如:
    extern 'C'

    void drawLine(int x1, int y1, int x2, int y2);

    //静态初始化:在C++中静态的类对象和定义会在main执行前执行,在编译器中,这种处理方法通常是在main函数里面默认调用某个函数:
    int main(int argc, char *argv[]){
        performStaticInitialization();

        realmain();

        performStaticDestruction();
    }

    //动态内存分配:C++使用new 和 delete ,C使用malloc 和 free

    //数据结构的兼容性:C无法知道C++的特性

    //总结下来就是:确保C++和C编译器产生兼容的obj文件,将在两种语言下都是用的函数声明 extern 'C',只要可能,应该用C++ 写main(),
    //new delete成对使用,malloc和free成对使用
}