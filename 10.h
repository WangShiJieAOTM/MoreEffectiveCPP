/***
* 10.防止构造函数里的资源泄漏
*/

namespace ten {
    //这一条主要是防止在构造函数里面抛出异常,导致资源泄漏

    class BooKEntry {
    public:
        BooKEntry();

        ~BooKEntry();
    };

    BooKEntry::BooKEntry() {
        // theImage = new Image;
        // theAudioClip = new AudioClip;
        throw 1;
    }//如果在构造函数里面抛出异常,那么theImage,theAudioClip就会泄漏,theImage,theAudioClip永远无法被释放
    //这样只能在构造函数内部使用try catch来捕获异常,然后在catch里面释放资源,这样不够优雅

    BooKEntry::~BooKEntry() {
        //...
    }


    //更好的方式是将theImage 和 theAudioClip做成成员来进行封装

    class BooKEntry2{
    public:
        //...
    private:
        const unique_ptr<Image> theImage;
        const unique_ptr<AudioClip> theAudioClip;
    };
}

/**
* 总之多用智能指针,少用裸指针!!!!
*/