//c6-1;
typedef char TElemType;// 应用时要注释在函数中定义数据类型
typedef struct BitNode
{
    TElemType data;
    BitNode *lchild;
    BitNode *rchild;
}BitNode, *BiTree;
