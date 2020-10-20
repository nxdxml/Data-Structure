#include"c1.h"
#define MAX_NAME 15
struct VertexType
{
    char name[MAX_NAME];
};
void Visit(VertexType ver)
{
    printf("%s", ver.name);
}
void Input(VertexType &ver)
{
    scanf("%s", ver.name);
}
void InputFprmFile(FILE *f, VertexType &ver)
{
    fscanf(f, "%s", ver.name);
}
