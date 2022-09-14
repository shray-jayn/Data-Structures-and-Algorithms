#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Class
{
    int phy;
    int chem;
    int math;

    Class()
    {
    }

    Class(int phy, int chem, int math)
    {
        this->chem = chem;
        this->phy = phy;
        this->math = math;
    }
};

static bool comp(Class a, Class b)
{
    int phy1 = a.phy;
    int phy2 = b.phy;
    int chem1 = a.chem;
    int chem2 = b.chem;
    int math1 = a.math;
    int math2 = b.math;

    if (phy1 == phy2 && chem1 == chem2)
        return math1 < math2;
    else if (phy1 == phy2)
        return chem1 > chem2;
    else
        return phy1 < phy2;
}

void customSort(int phy[], int chem[], int math[], int n)
{
    vector<Class> marks(n);

    for (int i = 0; i < n; i++)
    {
        marks[i] = {phy[i], chem[i], math[i]};
    }

    sort(marks.begin(), marks.end(), comp);

    for (int i = 0; i < n; i++)
    {
        phy[i] = marks[i].phy;
        chem[i] = marks[i].chem;
        math[i] = marks[i].math;

        cout << phy[i] << " " << chem[i] << " " << math[i] << endl;
    }
}

int main()
{
    int a[] = {4, 1, 10, 4, 4, 4, 1, 10, 1, 10};
    int b[] = {5, 2, 9, 6, 3, 10, 2, 9, 14, 10};
    int c[] = {12, 3, 6, 5, 2, 10, 16, 32, 10, 4};

    customSort(a, b, c, 10);

    return 0;
}