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
void CreateDN(MGraph &G) //有向网（权）
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
int CreateUDG(MGraph &G) //无向图
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
            G.arcs[j][i].info = G.arcs[i][j].info;
        }
    }
    G.kind = UDG; //无向图
}
void CreateUDN(MGraph &G) //无向网（权）
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
            G.arcs[j][i].info = G.arcs[i][j].info;
        }
    }
    G.kind = UDN; //有向图
}
void CreateGraph(MGraph &G)
{
    printf("输入图的类型0 1 2 3对应 有向图 带权有向图 无向图 带权无向图：");
    scanf("%d", &G.kind);
    switch (G.kind)
    {
    case DG:
        CreateDG;
        break;
    case DN:
        CreateDN;
        break;
    case UDG:
        CreateUDG;
        break;
    case UDN:
        CreateUDN;
        break;
    }
}
VertexType GetVex(MGraph G, int i)
{
    if (i >= G.vexnum || i < 0)
        exit(OVERFLOW);
    return G.vexs[i];
}
Status PutVex(MGraph &G, VertexType v, VertexType value)
{
    int k = LocateVex(G, v);
    if (k < 0)
        return ERROR;
    G.vexs[k] = value;
    return OK;
}

int FirstAdjVex(MGraph G, int v) //返回v第一个邻接点的序号
{
    int i;
    VRType j = 0;
    if (G.kind % 2)
        j = INFINITY;
    for (i = 0; i < G.vexnum; i++)
    {
        if (G.arcs[v][i].adj != j)
            return i;
    }
    return -1;
}
int NextAdjVex(MGraph G, int v, int w) //返回v相对w的下一个邻接点序号
{
    int i;
    VRType j = 0;
    if (G.kind % 2)
        j = INFINITY;
    for (i = w + 1; i < G.vexnum; i++)
    {
        if (G.arcs[v][i].adj != j)
            return i;
    }
    return -1;
}
void InsertVex(MGraph &G, VertexType v) //
{
    int i;
    VRType j = 0;
    if (G.kind % 2)
        j = INFINITY;
    G.vexs[G.vexnum] = v;
    for (i = 0; i <= G.vexnum; i++)
    {
        G.arcs[i][G.vexnum].adj = G.arcs[G.vexnum][i].adj = j;
        G.arcs[i][G.vexnum].info = G.arcs[G.vexnum][i].info = nullptr;
    }
    ++G.vexnum;
}
Status InsertArc(MGraph &G, VertexType v, VertexType w) //
{
    int i, v1, w1;
    v1 = LocateVex(G, v);
    w1 = LocateVex(G, w);
    if (v1 < 0 || w1 < 0)
        return ERROR;
    ++G.arcnum;
    if (G.kind % 2)
    {
        printf("输入权：");
        scanf("%d", &G.arcs[v1][w1]);
    }
    else
        G.arcs[v1][w1].adj = 1; //图
    printf("是否输入弧线信息（1，0）");
    scanf("%d%*c", &i);
    if (i)
    {
        InputArc(G.arcs[v1][w1].info);
    }
    if (G.kind > 1)
        G.arcs[v1][w1] = G.arcs[w1][v1];
    return OK;
}
Status DeleteArc(MGraph &G, VertexType v, VertexType w) //
{
}
Status DeleteVex(MGraph &G, VertexType v) //
{
}
void DestroyGraph(MGraph &G) //
{
}
void Display(MGraph G) //
{
}
void CreateFromFile(MGraph &G, char *filename, int IncInfo) //使用文件创建
{
}
