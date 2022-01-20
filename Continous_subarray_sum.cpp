class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {

        vector<int> vec1, vec2;
        vec2 = nums;

        if (nums.size() == 1)
            return false;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1] && nums[i] == 0)
            {
                cout << "IN";
                return true;
            }
        }

        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            vec1.push_back(sum);
        }

        for (int i = 0; i < vec1.size(); i++)
            cout << vec1[i] << " ";

        for (int i = 0; i < vec1.size(); i++)
        {
            if (vec1[i] % k == 0 && i != 0)
                return true;
        }
        return false;
    }
};