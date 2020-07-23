#include <algorithm>

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int notNullStart = 0;
        int n = nums.size();
        for(; notNullStart < n; notNullStart += 1) {
            if (nums[notNullStart] != 0) {
                break;
            }
        }
        
        if ((n - notNullStart) < 3) {
            return 0;
        }
        
        int result = 0;
        int endElem = n - 2;
        for(int f = notNullStart; f != endElem; f += 1) {
            int s = f + 1;
            int t = s + 1;
            while (t != n) {
                if (s == t) {
                    t += 1;
                    continue;
                }
                if ((nums[f] + nums[s]) > nums[t]) {
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