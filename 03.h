/**
* 03.绝对不要以多态的方式处理数组
*/

namespace three {
    //继承的一个最重要的性质之一就是你可以通过指向 base class objects 的指针来访问 derived class objects
    //这个特性被称为多态

    class BST {

    };

    class BalanceBST : public BST {

    };

    void printBSTArray(os::ostream &s, const BST array[], int numElements) {
        for (int i = 0; i < numElements; ++i) {
            s << array[i];
        }
    }

    //如果传入的是BST那没问题，如果传入的是BalanceBST呢？
    //这里的问题在于，printBSTArray()函数并不知道传入的是BST还是BalanceBST
    //如果传入的是BalanceBST，那么就会调用BalanceBST的operator<<()函数
    //但是BalanceBST并没有重载operator<<()函数，所以会调用BST的operator<<()函数
    //这样就会导致输出的结果不正确(而且还不报错)
}