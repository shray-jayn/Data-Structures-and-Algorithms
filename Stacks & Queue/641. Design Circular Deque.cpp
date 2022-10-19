#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

class MyCircularDeque
{
public:
    list<int> lst;
    int len;

    MyCircularDeque(int k)
    {
        len = k;
    }

    bool insertFront(int value)
    {
        if (lst.size() < len)
        {
            lst.push_front(value);
            return true;
        }

        return false;
    }

    bool insertLast(int value)
    {
        if (lst.size() < len)
        {
            lst.push_back(value);
            return true;
        }
        return false;
    }

    bool deleteFront()
    {
        if (!lst.size())
        {
            return false;
        }

        lst.pop_front();
        return true;
    }

    bool deleteLast()
    {

        if (!lst.size())
        {
            return false;
        }

        lst.pop_back();
        return true;
    }

    int getFront()
    {
        if (lst.size() == 0)
        {
            return -1;
        }

        return lst.front();
    }

    int getRear()
    {
        if (lst.size() == 0)
        {
            return -1;
        }

        return lst.back();
    }

    bool isEmpty()
    {
        return lst.empty();
    }

    bool isFull()
    {
        return lst.size() == len;
    }
};

int main()
{
    return 0;
}