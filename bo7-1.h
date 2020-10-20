#include "c7-1.h"
#include "func7-1.h"
#include "func7-2.h"

int LocateVex(MGraph G, VertexType u)
{
    int i;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (strcpy(u.name, G.vexs[i].name) == 0)
            return i;
    }
    return -1;
}
int CreateDG(MGraph &G) //有向图
{
    int i, j, k, IncInfo;
    VertexType v1, v2;
    printf("输入顶点数，弧数，弧是否含相关信息（1是0，否）");
    scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
    printf("输入%d个顶点的名称", G.vexnum);
    for (i = 0; i < G.vexnum; i++)
    {
        Input(G.vexs[i]);
    }
    for (i = 0; i < G.vexnum; i++)
    {
        for (j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj = 0;
            G.arcs[i][j].info = nullptr;
        }
    }
    printf("输入%d条边：", G.arcnum);
    for (int i = 0; i < G.arcnum; i++)
    {
        scanf("%s %s %*c", v1.name, v2.name);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j].adj = 1;
        if (IncInfo)
        {
            InputArc(G.arcs[i][j].info);
        }
    }
    G.kind = DG; //有向图
}
void CreateDN(MGraph &G)//有向网（权）
{
    int i, j, k, IncInfo;
    VRType w;
    VertexType v1, v2;
    printf("输入顶点数，弧数，弧是否含相关信息（1是0，否）");
    scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
    printf("输入%d个顶点的名称", G.vexnum);
    for (i = 0; i < G.vexnum; i++)
    {
        Input(G.vexs[i]);
    }
    for (i = 0; i < G.vexnum; i++)
    {
        for (j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj = INFINITY;
            G.arcs[i][j].info = nullptr;
        }
    }
    printf("输入%d条边及其权值：", G.arcnum);
    for (int i = 0; i < G.arcnum; i++)
    {
        scanf("%s %s %d %*c", v1.name, v2.name, &w);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j].adj = 1;
        if (IncInfo)
        {
            InputArc(G.arcs[i][j].info);
        }
    }
    G.kind = DN; //有向图
}