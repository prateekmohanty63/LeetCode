class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        int n = nums.size();

        if (n < 3)
            return 0;

        int min = 999999;
        int closest = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target)
                    return sum;

                else if (sum < target)
                    left++;

                else
                    right--;

                if (abs(target - sum) < min)
                {
                    min = abs(target - sum);
                    closest = sum;
                }
            }
        }
        return closest;
    }
};