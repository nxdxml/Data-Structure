//c7-1
//ͼ���ڽӾ���洢
#include "func7-1.h"
#include "func7-2.h"
#define INFINITY INT_MAX //�������ֵ����������
typedef int VRType;
#define MAX_VERTAX_NUM 30
enum GraphKind
{
    DG,
    DN,
    UDG,
    UDN
}; //����ͼ ������
typedef struct
{
    VRType adj;     //�����ϵ����
    InfoType *info; //���������Ϣָ��
} ArcCell, AdjMatrix[MAX_VERTAX_NUM][MAX_VERTAX_NUM];
struct MGraph
{
    VertexType vexs[MAX_VERTAX_NUM]; //��������
    AdjMatrix arcs;
    int vexnum, arcnum;
    GraphKind kind; // ͼ������
};
