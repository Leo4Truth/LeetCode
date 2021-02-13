#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings_1(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if (len1 != len2) return false;

        unordered_map<char, int> word1Map;
        unordered_map<char, int> word2Map;

        vector<char> word1KeySet, word2KeySet, word1FrequencyList, word2FrequencyList;
        for (char c : word1) word1Map[c - 'a']++;
        for (char c : word2) word2Map[c - 'a']++;
        for (auto keyValuePair : word1Map) {
            word1KeySet.push_back(keyValuePair.first);
            word1FrequencyList.push_back(keyValuePair.second);
        }
        for (auto keyValuePair : word2Map) {
            word2KeySet.push_back(keyValuePair.first);
            word2FrequencyList.push_back(keyValuePair.second);
        }

        sort(word1KeySet.begin(), word1KeySet.end());
        sort(word2KeySet.begin(), word2KeySet.end());
        
        if (word1KeySet != word2KeySet) return false;

        sort(word1FrequencyList.begin(), word1FrequencyList.end());
        sort(word2FrequencyList.begin(), word2FrequencyList.end());
        
        return word1FrequencyList == word2FrequencyList;
    }

    bool closeStrings_2(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if (len1 != len2) return false;

        vector<int> word1Map(26, 0);
        vector<int> word2Map(26, 0);
        
        for (char c : word1) word1Map[c - 'a']++;
        for (char c : word2) word2Map[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if ((word1Map[i] == 0 && word2Map[i] > 0) ||
                (word2Map[i] == 0 && word1Map[i] > 0)) {
                return false;
            }
        }

        sort(word1Map.begin(), word1Map.end());
        sort(word2Map.begin(), word2Map.end());
        
        return word1Map == word2Map;
    }
    
    bool closeStrings_3(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if (len1 != len2) return false;

        vector<int> word1Map(26, 0);
        vector<int> word2Map(26, 0);
        int word1Bit = 0;
        int word2Bit = 0;
        
        for (char c : word1) {
            word1Map[c - 'a']++;
            word1Bit = word1Bit | (1 << (c - 'a'));
        }
        for (char c : word2) {
            word2Map[c - 'a']++;
            word2Bit = word2Bit | (1 << (c - 'a'));
        }

        if (word1Bit != word2Bit) return false;

        sort(word1Map.begin(), word1Map.end());
        sort(word2Map.begin(), word2Map.end());

        for (int i = 0; i < 26; i++)
            if (word1Map[i] != word2Map[i]) return false;
        
        return true;
    }
};

int main(int argc, char* argv[]) {
    string word1 = argc >= 2 ? argv[1] : "ab";
    string word2 = argc >= 3 ? argv[1] : "acb";

    Solution solution;
    cout << solution.closeStrings(word1, word2) << endl;

    //system("pause");
    return 0;
}
