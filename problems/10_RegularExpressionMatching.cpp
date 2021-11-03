#include <iostream>
#include <vector>

using namespace std;

class Solution10 {
public:
    // simple recursion, slow but work (pass), 552 ms
    bool isMatch_recursion(string s, string p) {
        // for empty pattern
        if (p.empty()) return s.empty();
        // for one char pattern
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        // for not *
        if (p[1] != '*') {
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch_recursion(s.substr(1), p.substr(1));
        }
        // for *
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            // current x* represents empty in string
            if (isMatch_recursion(s, p.substr(2))) return true;
            // add one more matched char in s, shift
            s = s.substr(1);
        }
        // end the mtaching process for *, go ahead to the remain pattern
        return isMatch_recursion(s, p.substr(2));
    }
    
    // Bottom Up DP, 4 ms
    bool isMatch_dp_bottom_up(string s, string p) {
        int m = s.size(), n = p.size();
        bool** dp = new bool*[m + 1];
        for (int i = 0; i <= m; i++)
            dp[i] = new bool[n + 1];
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = false;
        dp[m][n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                bool firstMatch = i < m && (s[i] == p[j] || p[j] == '.');
                if (j + 1 < n && p[j + 1] == '*')
                    dp[i][j] = dp[i][j + 2] || firstMatch && dp[i + 1][j];
                else
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }

    // 16 ms
    bool isMatch_dp_2(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // dp[i][j] = true --> s[0, i - 1] matches p[0, j - 1]
        dp[0][0] = true;
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
        }
        bool isMulti = false;
        int lastPatternIndex = 0;
        char currentPatternChar;
        // j, index of pattern
        for (int j = 1; j <= n; j++) {
            isMulti = false;
            currentPatternChar = p[j - 1];
            while (j < n && p[j] == '*') {
                isMulti = true;
                j++;
            }
            // i, index of string
            for (int i = 1; i <= m; i++) {
                // not * match
                if (!isMulti) {
                    dp[i][j] = dp[i - 1][lastPatternIndex] && (currentPatternChar == '.' || s[i - 1] == currentPatternChar);
                }
                // * match
                else {
                    dp[i][j] = dp[i][lastPatternIndex] || ((currentPatternChar == '.' || s[i - 1] == currentPatternChar) && dp[i - 1][j]);
                }
            }
            lastPatternIndex = j;
        }
        /*
        cout << "x ";
        for (int j = 0; j <= n; j++) cout << j << " ";
        cout << endl;
        for (int i = 0; i <= m; i++) {
            cout << i << " ";
            for (int j = 0; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */
        return dp[m][n];
    }

    class Node {
    public:
        char value;
        vector<Node*> links;
        bool isHead;
        bool isTail;

        Node(char c) {
            value = c;
            isHead = false;
            isTail = false;
        }
    };

    vector<Node*> parse(string p) {
        vector<Node*> nodes;
        for (int j = 0; j < p.size(); j++) {
            nodes.push_back(new Node(p[j]));
        }
        for (int j = 0; j < nodes.size(); j++) {
            Node *current = nodes[j];
            if (current->value >= 'a' && current->value <= 'z' || current->value == '.') {
                if (j > 0) {
                    Node* preNode = nodes[j - 1];
                    preNode->links.push_back(current);
                }
            }
            else if (current->value == '*') {
                if (j > 0) {
                    Node* preNode = nodes[j - 1];
                    preNode->links.push_back(preNode);
                    if (j < nodes.size() - 1) {
                        Node* nextNode = nodes[j + 1];
                        preNode->links.push_back(nextNode);
                        cout << "add " << nextNode->value << " to " << preNode->value << endl;
                    }
                }
                nodes.erase(nodes.begin() + j);
            }
        }
        nodes[0]->isHead = true;
        nodes[nodes.size() - 1]->isTail = true;
        if (nodes[nodes.size() - 1]->links.size() > 1 && nodes.size() > 1)
            nodes[nodes.size() - 2]->isTail = true;
        return nodes;
    }

    bool isMatch_NFA(string s, string p) {
        vector<Node*> nfa = parse(p);
        printNodes(nfa);
        return isMatch_NFA_base(s, 0, nfa[0]);
    }

    bool isMatch_NFA_base(string s, int index, Node* node) {
        if (index >= s.size()) {
            if (node->links.empty()) return false;
            else if (node->links.size() == 1) {
                if (node->links[0] == node) return true;
                else return false;
            }
            else if (node->links.size() == 2) {
                return isMatch_NFA_base(s, index, node->links[1]);
            }
        }
        char c = s[index];
        if (c == node->value || node->value == '.') {
            if (index == s.size() - 1 && node->isTail) return true;
            for (vector<Node*>::iterator it = node->links.begin(); it != node->links.end(); it++) {
                if (isMatch_NFA_base(s, index + 1, *it)) return true;
            }
        }
        else {
            for (vector<Node*>::iterator it = node->links.begin(); it != node->links.end(); it++) {
                if (*it != node) {
                    if (isMatch_NFA_base(s, index, *it)) return true;
                }
            }
        }
        return false;
    }

    void printNodes(vector<Node*> nodes) {
        for (int i = 0; i < nodes.size(); i++) {
            cout << nodes[i]->value << ": ";
            for (vector<Node*>::iterator it = nodes[i]->links.begin(); it != nodes[i]->links.end(); it++) {
                cout << (*it)->value << " ";
            }
            cout << endl;
        }
    }
};

int main10() {
    Solution10 solution;
    string s = "bbbba", p = ".*a*a";
    //cin >> s;
    //cin >> p;
    cout << solution.isMatch_NFA(s, p) << endl;
    system("pause");
    return 0;
}