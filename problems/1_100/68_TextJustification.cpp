#include <iostream>
#include <vector>

using namespace std;

class Solution68 {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int line = 0;
        int width = 0;
        int cnt = 0;
        int lastEnd = -1;
        for (int i = 0; i < words.size(); i++) {
            if (cnt == 0 && words[i].size() <= maxWidth) {
                width += words[i].size();
                cnt++;
            }
            else if (width + words[i].size() + 1 <= maxWidth) {
                width += words[i].size() + 1;
                /*
                if (!current.empty()) current.append(" ");
                current.append(words[i]);
                */
                cnt++;
            }
            else {
                int spaces = maxWidth - width;
                string current;
                if (cnt == 1) {
                    current.append(words[lastEnd + 1]);
                    for (int i = 0; i < spaces; i++) current.append(" ");
                }
                else {
                    vector<string> intervals;
                    string interval;
                    int intervalWidth = spaces / (cnt - 1) + 2;
                    int longCnt = spaces % (cnt - 1);
                    /*
                    cout << "spaces:        " << spaces << endl;
                    cout << "cnt:           " << cnt << endl;
                    cout << "intervalWidth: " << intervalWidth << endl;
                    cout << "longCnt:       " << longCnt << endl;
                    */
                    for (int j = 0; j < intervalWidth; j++) interval.append(" ");
                    for (int j = 0; j < longCnt; j++) intervals.push_back(interval);
                    interval = interval.substr(0, interval.size() - 1);
                    for (int j = 0; j < cnt - longCnt - 1; j++) intervals.push_back(interval);
                    intervals.push_back("");

                    for (int j = 0; j < cnt; j++) {
                        current.append(words[lastEnd + 1 + j]);
                        current.append(intervals[j]);
                    }
                }
                
                res.push_back(current);
                line++;
                width = 0;
                cnt = 0;
                i--;
                lastEnd = i;
            }
        }
        //cout << "last cnt: " << cnt << endl;
        if (cnt != 0) {
            int spaces = maxWidth - width;
            string current;
            for (int j = 0; j < cnt; j++) {
                if (j != 0) current.append(" ");
                current.append(words[lastEnd + 1 + j]);
            }
            for (int j = 0; j < spaces; j++) current.append(" ");
            res.push_back(current);
        }
        return res;
    }
};

int main68() {
	Solution68 solution;
    int n;
    string word;
    vector<string> words;
    int maxWidth;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        words.push_back(word);
    }
    cin >> maxWidth;
    vector<string> res = solution.fullJustify(words, maxWidth);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    system("pause");
    return 0;
}