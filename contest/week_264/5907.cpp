#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int num = n + 1; ; num++) {
            if (isBeautifulNumber(num)) return num;
        }
        return 0;
    }

private:
    bool isBeautifulNumber(int num) {
        unordered_map<int, int> count;
        while (num > 0) {
            count[num % 10]++;
            if (count[num % 10] > num % 10) return false;
            num /= 10;
        }
        for (auto& entry : count) if (entry.first != entry.second) return false;
        return true;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    cout << solution.nextBeautifulNumber(n) << endl;
    
    return 0;
}
