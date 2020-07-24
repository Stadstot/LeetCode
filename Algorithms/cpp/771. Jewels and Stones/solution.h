#pragma once

#include <set>

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        std::set<char> jewels;
        for(auto j: J) {
            jewels.insert(j);
        }
        int result = 0;
        for(auto s: S) {
            if (jewels.find(s) != jewels.end()) {
                result += 1;
            }
        }
        return result;
    }
};