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
            auto s = f + 1;
            auto t = s + 1;
            while (t != nums.end()) {
                if (s == t) {
                    t += 1;
                    continue;
                }
                if ((*f + *s) > *t) {
                    result += t - s;
                    t += 1;
                } else {
                    s += 1;
                }
            }
        }
        return result;
    }
};