/**
* 01.仔细区别 pointer 和 reference
*/

namespace one
{
    // pointer 和 reference 的区别
    // 1. pointer 可以为空，reference 不可以为空(必须初始化)
    // 2. pointer 可以改变指向，reference 不可以改变指向
}

/**
 * 1.当你知道你需要指向某个东西,而且绝对不会改变指向时,使用 reference
 * 2.当你不知道你需要指向某个东西,或者你需要改变指向时,使用 pointer
*/