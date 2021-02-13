#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution76 {
public:
    // do not support duplicate char in t
    string minWindow_1(string s, string t) {
        // init
        int minL = -1, minR = s.size() + 1;
        int l = 0, r = t.size() - 1;
        vector<int> cnt(t.size(), 0);    // count the char in t in the current window
        unordered_map<char, int> umap;   // map the char in t into its index in t
        for (int j = 0; j < t.size(); j++) umap[t[j]] = j;
        for (int i = l; i <= r; i++) {
            if (umap.find(s[i]) != umap.end()) {
                cnt[umap[s[i]]]++;
            }
        }

        bool flag = true;
        for (int k = 0; k < cnt.size(); k++) {
            if (cnt[k] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            minL = l;
            minR = r;
            return s.substr(l, r - l + 1);
        }

        for (;;) {
            cout << "l: " << l << ", r: " << r << endl;
            // if current window ok
            if (flag) {
                if (umap.find(s[l]) != umap.end()) cnt[umap[s[l]]]--;
                l++;
            }
            else {
                if (r < s.size() - 1) {
                    r++;
                    if (umap.find(s[r]) != umap.end()) cnt[umap[s[r]]]++;
                }
            }

            for (int k = 0; k < t.size(); k++) {
                cout << " " << t[k] << ": " << cnt[umap[t[k]]] << endl;
            }

            cout << "l: " << l << ", r: " << r << ", " << s.substr(l, r - l + 1) << ", ";
            // update flag
            flag = true;
            for (int k = 0; k < t.size(); k++) {
                if (cnt[k] == 0) {
                    cout << "k = " << k << ", ";
                    flag = false;
                    break;
                }
            }
            cout << flag << endl;

            if (flag) {
                if (r - l < minR - minL) {
                    minR = r;
                    minL = l;
                    cout << "minR: " << minR << ", minL: " << minL << endl;
                }
            }
            cout << endl;

            if (r >= s.size() - 1 && l >= r - t.size()) break;
        }
        if (minR - minL + 1 <= s.size()) return s.substr(minL, minR - minL + 1);
        else return "";
    }

    // Sliding window
    string minWindow_slidingWin(string s, string t) {
        if (s.size() == 0 || t.size() == 0) return "";

        // Dictionary which keeps a count of all the unique characters in t.
        unordered_map<char, int> umap;
        for (int j = 0; j < t.size(); j++) {
            if (umap.find(t[j]) != umap.end()) umap[t[j]]++;
            else umap[t[j]] = 1;
        }
        // Number of unique characters in t, which need to be present in the desired window.
        int required = umap.size();
        // formed is used to keep track of how many unique characters in t
        // are present in the current window in its desired frequency.
        // e.g. if t is "AABC" then the window must have two A's, one B and one C.
        // Thus formed would be = 3 when all these conditions are met.
        int formed = 0;
        // Left and Right pointer
        int l = 0, r = 0;

        // result list of the form (window length, left, right)
        int res[] = { -1, 0, 0 };

        // Dictionary which keeps a count of all the unique characters in the current window.
        unordered_map<char, int> winCnt;
        while (r < s.size()) {
            // Add one character from the right to the window
            winCnt[s[r]]++;

            // If the frequency of the current character added equals to the
            // desired count in t then increment the formed count by 1.
            if (umap.find(s[r]) != umap.end() && winCnt[s[r]] == umap[s[r]]) {
                formed++;
            }
            
            // Try and contract the window till the point where it ceases to be 'desirable'.
            while (l <= r && formed == required) {
                // Save the smallest window until now.
                if (res[0] == -1 || r - l + 1 < res[0]) {
                    res[0] = r - l + 1;
                    res[1] = l;
                    res[2] = r;

                    cout << "res[]: " << res[0] << ", " << res[1] << ", " << res[2] << endl;
                }

                // The character at the position pointed by the
                // `Left` pointer is no longer a part of the window.
                winCnt[s[l]]--;
                if (umap.find(s[l]) != umap.end() && winCnt[s[l]] < umap[s[l]]) {
                    formed--;
                }

                // Move the left pointer ahead, this would help to look for a new window.
                l++;
            }

            // Keep expanding the window once we are done contracting.
            r++;
        }

        return res[0] == -1 ? "" : s.substr(res[1], res[0]);
    }

    // optimized sliding window with filtered string
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0) return "";

        // Dictionary which keeps a count of all the unique characters in t.
        unordered_map<char, int> umap;
        for (int j = 0; j < t.size(); j++) {
            if (umap.find(t[j]) != umap.end()) umap[t[j]]++;
            else umap[t[j]] = 1;
        }
        int required = umap.size();

        // Filter all the characters from s into a new list along with their index.
        // The filtering criteria is that the character should be present in t.
        vector<pair<int, char>> filtered_s;
        for (int i = 0; i < s.size(); i++) {
            if (umap.find(s[i]) != umap.end()) {
                filtered_s.push_back(pair<int, char>(i, s[i]));
            }
        }

        /*
        for (int k = 0; k < filtered_s.size(); k++) {
            cout << "(" << filtered_s[k].first << ", " << filtered_s[k].second << ")" << endl;
        }
        cout << endl;
        */
        int l = 0, r = 0, formed = 0;
        unordered_map<char, int> winCnt;
        int res[] = { -1, 0, 0 };

        while (r < filtered_s.size()) {
            winCnt[filtered_s[r].second]++;

            if (umap.find(filtered_s[r].second) != umap.end() && winCnt[filtered_s[r].second] == umap[filtered_s[r].second]) {
                formed++;
            }

            while (l <= r && formed == required) {
                int end = filtered_s[r].first;
                int start = filtered_s[l].first;
                if (res[0] == -1 || end - start + 1 < res[0]) {
                    res[0] = end - start + 1;
                    res[1] = start;
                    res[2] = end;
                    //cout << "res[]: " << res[0] << ", " << res[1] << ", " << res[2] << endl;
                }

                winCnt[filtered_s[l].second]--;
                if (umap.find(filtered_s[l].second) != umap.end() && winCnt[filtered_s[l].second] < umap[filtered_s[l].second]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return res[0] == -1 ? "" : s.substr(res[1], res[0]);
    }
};

int main76() {
    Solution76 solution;
    string s, t;
    cin >> s >> t;
    cout << solution.minWindow(s, t) << endl;
    system("pause");
    return 0;
}