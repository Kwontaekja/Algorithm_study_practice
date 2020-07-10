#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> temp = nums;
        // 1. sort array
        sort(nums.begin(), nums.end());

        // 2. find two sum
        int i, j;
        for (i = 0; i < nums.size(); i++)
        {
            j = binary_search(nums, 0, nums.size() - 1, target - nums[i]);

            if ((j != -1) && (i != j))
            {
                break;
            }
            else
                continue;
        }

        // 3. find original indicies
        int real_i = -1, real_j = -1;
        if (i < nums.size())
        {
            if (nums[i] == nums[j])
            {
                for (int k = 0; k < nums.size(); k++)
                {
                    if ((real_i == -1) && (temp[k] == nums[i]))
                    {
                        real_i = k;
                    }
                    else if ((real_i != -1) && (temp[k] == nums[i]))
                    {
                        real_j = k;
                    }
                }
            }
            else
            {
                for (int k = 0; k < nums.size(); k++)
                {
                    if (temp[k] == nums[i])
                        real_i = k;
                    else if (temp[k] == nums[j])
                        real_j = k;
                }
            }
            return {real_i, real_j};
        }
        else
        {
            return {};
        }
    }

    int binary_search(vector<int> &nums, int a, int b, int key)
    {
        if (a > b)
            return -1;

        if (a == b)
        {
            if (nums[a] == key)
                return a;
            else
                return -1;
        }

        int mid = (a + b) / 2;

        if (nums[mid] == key)
        {
            return mid;
        }
        else if (nums[mid] > key)
        {
            return binary_search(nums, a, mid - 1, key);
        }
        else
        {
            return binary_search(nums, mid + 1, b, key);
        }
    }
};

int main()
{
    Solution sol;
    vector<int> v = {0, 4, 3, 0};
    vector<int> rslt = sol.twoSum(v, 0);
    for (int i = 0; i < rslt.size(); i++)
    {
        cout << rslt[i] << "\n";
    }
}