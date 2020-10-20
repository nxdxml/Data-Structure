#include"c1.h"
#define MAX_INFO 30
typedef char InfoType;
void InputArc(InfoType *arc)
{
    char s[MAX_INFO];
    int m;
    printf("请输入该弧相关信息（%d个字符）", MAX_INFO);
    gets(s);
    m = strlen(s);
    if (m)
    {
        arc = (char *)malloc(sizeof(char) * (m + 1));
        strcpy(arc, s); //把s赋给arc
    }
}
void InputArcFormFile(FILE *f, InfoType *arc)
{
    char s[MAX_INFO];
    fgets(s, MAX_INFO, f);
    arc = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(arc, s); //把s赋给arc
}
void OutputArc(InfoType *arc)
{
    printf("%s\n", arc);
}