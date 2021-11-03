#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Pass
    // Time:  0 ms,   defeat 100.00%
    // Space: 6.2 MB, defeat 63.51%
    string validIPAddress(string IP) {
        int n = IP.size();
        if (n == 0) return "Neither";
        vector<string> parts;
        int start = 0;
        int type = 0;
        for (int i = 0; i < n; i++) {
            if (IP[i] == '.') {
                //cout << IP.substr(start, i - start) << endl;
                if (type == 0) type = 4;
                if (type == 4) {
                    if (parts.size() >= 3) return "Neither";
                    if (!isValidIPv4Part(IP.substr(start, i - start))) return "Neither";
                    parts.push_back(IP.substr(start, i - start));
                    start = i + 1;
                }
                if (type == 6) return "Neither";
            }
            else if (IP[i] == ':') {
                //cout << IP.substr(start, i - start) << endl;
                if (type == 0) type = 6;
                if (type == 4) return "Neither";
                if (type == 6) {
                    if (parts.size() >= 7) return "Neither";
                    if (!isValidIPv6Part(IP.substr(start, i - start))) return "Neither";
                    parts.push_back(IP.substr(start, i - start));
                    start = i + 1;
                }
            }
            else if ('0' <= IP[i] && IP[i] <= '9') {
                if (type == 0) continue;
                if (type == 4) continue;
                if (type == 6) continue;
            }
            else if (('a' <= IP[i] && IP[i] <= 'f') || ('A' <= IP[i] && IP[i] <= 'F')) {
                if (type == 0) continue;
                if (type == 4) return "Neither";
                if (type == 6) continue;
            }
        }
        //cout << IP.substr(start, n - start) << endl;
        if (type == 4 && !isValidIPv4Part(IP.substr(start, n - start))) return "Neither";
        if (type == 6 && !isValidIPv6Part(IP.substr(start, n - start))) return "Neither";
        parts.push_back(IP.substr(start, n - start));
        //for (auto part : parts) cout << part << endl;
        if (type == 4 && parts.size() == 4) return "IPv4";
        if (type == 6 && parts.size() == 8) return "IPv6";
        return "Neither";
    }

    bool isValidIPv4Part(string part) {
        int n = part.size();
        if (n == 0) return false;
        if (n > 3) return false;
        if (part[0] == '0' && n > 1) return false;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum *= 10;
            if ('0' <= part[i] && part[i] <= '9') sum += part[i] - '0';
            else return false;
        }
        return (sum >= 0 && sum < 256) ? true : false;
    }
    
    bool isValidIPv6Part(string part) {
        int n = part.size();
        if (n == 0) return false;
        if (n > 4) return false;
        for (int i = 0; i < n; i++) {
            if (('0' <= part[i] && part[i] <= '9') || ('a' <= part[i] && part[i] <= 'f') || ('A' <= part[i] && part[i] <= 'F')) continue;
            else return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    string IP = argc >= 2 ? argv[1] : "";
    Solution solution;
    cout << solution.validIPAddress(IP) << endl;

    //system("pause");
    return 0;
}
