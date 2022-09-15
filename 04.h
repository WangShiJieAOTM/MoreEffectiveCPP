/**
* 4.非必要不提供 default constructor
*/

namespace four {
    class EquipmentPiece {
    public:
        EquipmentPiece(int IDNumber);
    };

    int main1() {
        EquipmentPiece bestPieces1[10];//报错  没有默认构造函数可以调用
        EquipmentPiece *bestPieces2 = new EquipmentPiece[10];//报错  没有默认构造函数可以调用

        typedef EquipmentPiece *PEP;
        PEP bestPieces3[10];//不需要调用默认构造函数，所以不会报错
        PEP *bestPieces4 = new PEP[10];//不需要调用默认构造函数，所以不会报错

        for (int i = 0; i < 10; ++i) {
            bestPieces4[i] = new EquipmentPiece(2); //对指针数组中的每个元素都进行初始化
        }
        //↑ 这种方法虽然跳过了类的构造过程,但是需要额外的空间存放指向指针数组的指针和指针数组
        //但是两个缺点
        //1.需要额外的空间存放指向指针数组的指针和指针数组
        //2.需要记得将此数组所指的所有对象都删除

        for(int i  = 9;i>=0;--i){
            delete bestPieces4[i];
        }
        delete[] bestPieces4;

    }
}




