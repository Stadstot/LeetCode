#include <algorithm>

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i += 1) {
            if (nums[i] != 0) {
                nums.erase(nums.begin(), nums.begin() + i);
                break;
            }
        }
        if (nums.size() < 3) {
            return 0;
        }
        
        int result = 0;
        for(auto f = nums.begin(); f != (nums.end() - 2); f += 1) {
            for(auto s = f + 1; s != (nums.end() - 1); s += 1) {
                auto it = std::lower_bound(s + 1, nums.end(), *f + *s);
                result += (it - 1) - s;
            }
        }
        return result;
    }
};