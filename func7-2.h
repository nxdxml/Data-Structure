#include"c1.h"
#define MAX_INFO 30
typedef char InfoType;
void InputArc(InfoType *arc)
{
    char s[MAX_INFO];
    int m;
    printf("������û������Ϣ��%d���ַ���", MAX_INFO);
    gets(s);
    m = strlen(s);
    if (m)
    {
        arc = (char *)malloc(sizeof(char) * (m + 1));
        strcpy(arc, s); //��s����arc
    }
}
void InputArcFormFile(FILE *f, InfoType *arc)
{
    char s[MAX_INFO];
    fgets(s, MAX_INFO, f);
    arc = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(arc, s); //��s����arc
}
void OutputArc(InfoType *arc)
{
    printf("%s\n", arc);
}