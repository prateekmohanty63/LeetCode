#include <iostream>
#include <vector>
using namespace std;

/// Approach-1

class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {

        int count = 0;

        int n = plants.size();
        int temp = capacity;

        for (int i = 0; i < n; i++)
        {

            if (temp >= plants[i])
            {
                temp -= plants[i];
                count++;
            }
            else if (temp < plants[i])
            {
                temp = capacity;
                count += i;
                count += i + 1;

                temp -= plants[i];
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}