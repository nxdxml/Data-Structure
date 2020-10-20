#include "c1.h"
// typedef int ElemType;
typedef double ElemType;
#include "c1-1.h"
#include "bo1-1.h"
#include "func1-1.h"

int main()
{
    Triplet T;
    ElemType m;
    Status i;
    i = InitTriplet(T, 5.1, 7.2, 9.3);
    // i=InitTriplet(T,3,5,7);
    cout << "�жϳ�ʼ���Ƿ�ɹ���" << i << "(1:�ɹ�),���Ϊ��"<<endl;
    PrintT(T);

    i = Get(T, 2, m);
    if (i == OK)
    {
        cout << "T�ĵڶ���ֵΪ��";
        PrintE(m);
    }
    i = Put(T, 2, 66.66);
    
    if (i == OK)
    {
        cout << "�޸ĺ�T�ĵڶ���ֵΪ��";
        i = Get(T, 2, m);
        PrintE(m);
    }
    i = IsAscending(T);
    if (i == OK)
        PrintT(T);
    else
        cout << "����������" << endl;
    i = IsDecending(T);
    if (i == OK)
        PrintT(T);
    else
        cout << "�����㽵��" << endl;
    Triplet T2;
    InitTriplet(T2, 11, 22, 33);
    i = IsAscending(T2);
    if (i == OK)
        PrintT(T2);
    else
        cout << "����������" << endl;
    i = IsDecending(T2);
    if (i == OK)
        PrintT(T2);
    else
        cout << "�����㽵��" << endl;
    i = Max(T2, m);
    cout << "���ֵΪ:";
    PrintE(m);
    i = Min(T2, m);
    cout << "��СֵΪ��";
    PrintE(m);
    system("PAUSE");
    DestroyTriplet(T2);
    cout << T2;
    system("PAUSE");
    return 0;
}