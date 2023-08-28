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

/// Approach-2

class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {

        int res = 0, curr_water = capacity;

        int n = plants.size();

        for (int i = 0; i < n; i++)
        {

            if (curr_water >= plants[i])
            {
                res++;
                curr_water -= plants[i];
                continue;
            }

            curr_water = capacity - plants[i];
            res++;
            res += 2 * i;
        }
        return res;
    }
};

int main()
{

    return 0;
}