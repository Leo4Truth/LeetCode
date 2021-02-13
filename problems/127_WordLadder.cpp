#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution127 {
public:
    void print(vector<int> path) {
        cout << "[";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    void print(vector<string> current) {
        cout << "[";
        for (int i = 0; i < current.size(); i++) {
            cout << current[i];
            if (i < current.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    void printDict(unordered_map<string, unordered_set<string>> next_dict) {
        for (auto dict : next_dict) {
            cout << dict.first << ": [";
            int i = 0;
            for (auto word : dict.second) {
                cout << word;
                if (i++ < dict.second.size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }

    // 此处用引用很重要，不用会导致超时
    bool isOneDiff(string& s1, string& s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 != len2) return false;

        int cnt = 0;
        for (int i = 0; i < len1; i++)
            if (s1[i] != s2[i]) cnt++;
        //cout << s1 << ", " << s2 << ", " << cnt << endl;

        return cnt == 1;
    }

    /*
     * 无向无权图最短路径问题
     * Dijkstra <==> BFS
     */
private:
    unordered_map<string, int> word2id;
    vector<string> id2word;
    vector<vector<int>> edges;

public:
    int findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int id = 0;
        for (auto& word : wordList) {
            if (!word2id.count(word)) {
                word2id[word] = id++;
                id2word.push_back(word);
            }
        }

        if (!word2id.count(endWord)) return {};
        if (!word2id.count(beginWord)) {
            word2id[beginWord] = id++;
            id2word.push_back(beginWord);
        }

        edges.resize(id2word.size());
        for (int i = 0; i < id2word.size(); i++) {
            for (int j = i + 1; j < id2word.size(); j++) {
                if (isOneDiff(id2word[i], id2word[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        const int s = word2id[beginWord];
        const int t = word2id[endWord];

        vector<vector<string>> res;
        queue<vector<int>> q;
        vector<int> cost(id2word.size(), INT_MAX);
        q.push(vector<int>{s});
        cost[s] = 0;
        while (!q.empty()) {
            vector<int> id_path = q.front();
            q.pop();

            int last = id_path.back();
            if (last == t) {
                vector<string> path;
                for (auto id : id_path)
                    path.push_back(id2word[id]);
                res.push_back(path);
            }
            else {
                for (int i = 0; i < edges[last].size(); i++) {
                    int to = edges[last][i];
                    // 此处等号很重要
                    if (cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> new_id_path(id_path);
                        new_id_path.push_back(to);
                        q.push(new_id_path);
                    }
                }
            }
        }

        if (res.size() > 0) return res[0].size();
        return 0;
    }

};

int main127(int argc, char* argv[]) {
    string beginWord, endWord;
    vector<string> wordList;
    int n;

    cout << "please input begin and end words: " << endl;
    cin >> beginWord >> endWord;
    cout << "please input size of word list: ";
    cin >> n;
    cout << "please input " << n << " word in word list: " << endl;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        wordList.push_back(word);
    }

    Solution127 solution;
    cout << solution.findLadders(beginWord, endWord, wordList) << endl;

    system("pause");
    return 0;
}