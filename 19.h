/**
* 19.了解临时对象的来源
*/

namespace nineteen {

#define MAX_STRING_LEN 1000;
    //临时对象通常指的是temp = a; a = b;b=temp;这种形式的临时对象
    //但在C++中,临时对象是指那些看不见的东西,例如:

    size_t countChar(const string &str, char ch) {}

    int main1() {
        //char buffer[MAX_STRING_LEN];
        std::cout << countChar(buffer, 'a');//这样就创建了一个 string临时对象
    }
//另外再入 operator + 的重载函数中,函数的返回值是临时的,因为他没有被命名,所以在任何时候只要见到函数中的常量引用参数,就存在建立临时对象的可能性
}
