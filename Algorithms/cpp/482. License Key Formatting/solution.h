class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result = "";
        int counter = 0;
        
        for (int i = (S.size() - 1); i >= 0; i -= 1) {
            if (S[i] != '-') {
                if (counter == K) {
                    result.push_back('-');
                    counter = 0;
                }
                counter += 1;
                result.push_back(toupper(S[i]));
            }
        }
        int size = result.size();
        for (int i = 0; i < (size / 2); i += 1) {
            char c = result[i];
            result[i] = result[size - 1 - i];
            result[size - 1 - i] = c;
        }
        return result;
    }
};