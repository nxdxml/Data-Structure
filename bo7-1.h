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
int CreateDG(MGraph &G) //����ͼ
{
    int i, j, k, IncInfo;
    VertexType v1, v2;
    printf("���붥���������������Ƿ������Ϣ��1��0����");
    scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
    printf("����%d�����������", G.vexnum);
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
    printf("����%d���ߣ�", G.arcnum);
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
    G.kind = DG; //����ͼ
}
void CreateDN(MGraph &G) //��������Ȩ��
{
    int i, j, k, IncInfo;
    VRType w;
    VertexType v1, v2;
    printf("���붥���������������Ƿ������Ϣ��1��0����");
    scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
    printf("����%d�����������", G.vexnum);
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
    printf("����%d���߼���Ȩֵ��", G.arcnum);
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
    G.kind = DN; //����ͼ
}
int CreateUDG(MGraph &G) //����ͼ
{
    int i, j, k, IncInfo;
    VertexType v1, v2;
    printf("���붥���������������Ƿ������Ϣ��1��0����");
    scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
    printf("����%d�����������", G.vexnum);
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
    printf("����%d���ߣ�", G.arcnum);
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
    G.kind = UDG; //����ͼ
}
void CreateUDN(MGraph &G) //��������Ȩ��
{
    int i, j, k, IncInfo;
    VRType w;
    VertexType v1, v2;
    printf("���붥���������������Ƿ������Ϣ��1��0����");
    scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
    printf("����%d�����������", G.vexnum);
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
    printf("����%d���߼���Ȩֵ��", G.arcnum);
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
    G.kind = UDN; //����ͼ
}
void CreateGraph(MGraph &G)
{
    printf("����ͼ������0 1 2 3��Ӧ ����ͼ ��Ȩ����ͼ ����ͼ ��Ȩ����ͼ��");
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

int FirstAdjVex(MGraph G, int v) //����v��һ���ڽӵ�����
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
int NextAdjVex(MGraph G, int v, int w) //����v���w����һ���ڽӵ����
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
        printf("����Ȩ��");
        scanf("%d", &G.arcs[v1][w1]);
    }
    else
        G.arcs[v1][w1].adj = 1; //ͼ
    printf("�Ƿ����뻡����Ϣ��1��0��");
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
void CreateFromFile(MGraph &G, char *filename, int IncInfo) //ʹ���ļ�����
{
}
