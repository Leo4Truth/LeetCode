#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

int cmp(pair<string, string>& p1, pair<string, string>& p2) {
    string s1 = p1.second;
    string s2 = p2.second;
    int n1 = s1.size();
    int n2 = s2.size();
    int k1 = s1.find_first_of(' ');
    int k2 = s2.find_first_of(' ');
    string content1 = s1.substr(k1 + 1, n1 - k1 - 1);
    string content2 = s2.substr(k2 + 1, n2 - k2 - 1);
    int res = content1.compare(content2);
    if (res == 0) {
        string id1 = s1.substr(0, k1);
        string id2 = s2.substr(0, k2);
        return id1.compare(id2) < 0;
    }
    return res < 0; 
}

class Solution {
public:
    virtual vector<string> reorderLogFiles(vector<string>& logs) = 0;
};

class Solution_init : public Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        if (n == 0) return {};
        if (n == 1) return logs;

        vector<string> sorted;
        vector<pair<string, string>> digit_logs;
        vector<pair<string, string>> letter_logs;

        for (int i = 0; i < n; i++) {
            vector<string> split_log = getSplitLog(logs[i]);
            for (int j = 0; j < split_log.size(); j++) {
                cout << split_log[j] << ",";
            }
            cout << endl;
            if (split_log.size() > 1) {
                if (isDigit(split_log[1][0])) {
                    digit_logs.push_back(make_pair(split_log[0], logs[i]));
                    continue;
                }
                if (isLetter(split_log[1][0])) {
                    letter_logs.push_back(make_pair(split_log[0], logs[i]));
                    continue;
                }
            }
        }

#ifdef DEBUG
        cout << "digit logs:" << endl;
        for (int i = 0; i < digit_logs.size(); i++) {
            cout << "id: " << digit_logs[i].first << ", ";
            cout << "content: " << digit_logs[i].second << endl;
        }

        cout << "letter logs:" << endl;
        for (int i = 0; i < letter_logs.size(); i++) {
            cout << "id: " << letter_logs[i].first << ", ";
            cout << "content: " << letter_logs[i].second << endl;
        }
#endif // DEBUG

        sort(letter_logs.begin(), letter_logs.end(), cmp);
        
        for (int i = 0; i < letter_logs.size(); i++) sorted.push_back(letter_logs[i].second);
        for (int i = 0; i < digit_logs.size(); i++) sorted.push_back(digit_logs[i].second);

        return sorted;
    }

private:
    vector<string> getSplitLog(string& log) {
        int len = log.size();
        if (len == 0) return {};
        vector<string> split_log;
        string curr_log;
        for (int i = 0; i < len; i++) {
            if (log[i] == ' ') {
                // skip the start blank chars
                if (curr_log.empty()) continue;
                // add a single log block
                else {
                    split_log.push_back(curr_log);
                    curr_log = "";
                }
            }
            // add char to a single block
            else curr_log.push_back(log[i]);
        }
        if (!curr_log.empty()) split_log.push_back(curr_log);
        return split_log;
    }

    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<string> logs;
    for (int i = 0; i < n; i++) {
        int content_words_num;
        cin >> content_words_num;
        string log;
        string id;
        string word;
        cin >> id;
        log.append(id);
        for (int j = 0; j < content_words_num; j++) {
            cin >> word;
            log.append(" ");
            log.append(word);
        }
        logs.push_back(log);
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    vector<string> sorted = solution->reorderLogFiles(logs);
    cout << "[";
    for (int i = 0; i < sorted.size(); i++) {
        cout << "\"" << sorted[i] << "\"";
        if (i < sorted.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
