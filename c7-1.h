//c7-1
//图的邻接矩阵存储
#include "func7-1.h"
#include "func7-2.h"
#define INFINITY INT_MAX //整型最大值代替正无穷
typedef int VRType;
#define MAX_VERTAX_NUM 30
enum GraphKind
{
    DG,
    DN,
    UDG,
    UDN
}; //有向图 有向网
typedef struct
{
    VRType adj;     //顶点关系类型
    InfoType *info; //弧的相关信息指针
} ArcCell, AdjMatrix[MAX_VERTAX_NUM][MAX_VERTAX_NUM];
struct MGraph
{
    VertexType vexs[MAX_VERTAX_NUM]; //顶点向量
    AdjMatrix arcs;
    int vexnum, arcnum;
    GraphKind kind; // 图的种类
};
