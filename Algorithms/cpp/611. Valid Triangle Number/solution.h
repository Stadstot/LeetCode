#pragma once

#include <algorithm>

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto notNullStart = nums.begin();
        for(; notNullStart < nums.end(); notNullStart += 1) {
            if (*notNullStart != 0) {
                break;
            }
        }
        
        if ((nums.end() - notNullStart) < 3) {
            return 0;
        }
        
        int result = 0;
        
        for(auto f = notNullStart; f != (nums.end() - 2); f += 1) {
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