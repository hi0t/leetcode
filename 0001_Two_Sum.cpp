#include "util.h"

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> idx;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = idx.find(target - nums[i]);
            if (it != idx.end())
            {
                return {it->second, i};
            }
            idx[nums[i]] = i;
        }

        return {0, 0};
    }
};

int main()
{
    Solution s;

    auto v = mkv(2, 7, 11, 15);
    assert(s.twoSum(v, 9) == mkv(0, 1));

    return 0;
}
