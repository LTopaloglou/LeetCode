#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            if (table.find(nums[i]) != table.end()) {
                return {table[nums[i]], i};
            } else {
                table[target-nums[i]] = i;
            }
        }
        return {999, 999};
    }
};