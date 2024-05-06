#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class ParkingSystem
{

    int bigCar;
    int mediumCar;
    int smallCar;

public:
    ParkingSystem(int big, int medium, int small)
    {
        bigCar = big;
        mediumCar = medium;
        smallCar = small;
    }

    bool addCar(int carType)
    {
        if (carType == 1 and bigCar > 0)
        {
            bigCar -= 1;
            return true;
        }

        else if (carType == 2 and mediumCar > 0)
        {
            mediumCar -= 1;
            return true;
        }

        else if (carType == 3 and smallCar > 0)
        {
            smallCar -= 1;
            return true;
        }

        return false;
    }
};

int main()
{

    return 0;
}