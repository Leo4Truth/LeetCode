#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isOneDiff(const string& s1, const string& s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 != len2) return false;
        
        int diffCnt = 0;
        for (int i = 0; i < len1; i++) {
            if (s1[i] != s2[i]) diffCnt++;
        }

        return diffCnt == 1;
    }

    // BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;

        unordered_map<string, int> word2id;
        vector<string> id2word;

        int n = wordList.size();

        int id = 0;
        for (auto& word : wordList) {
            word2id[word] = id++;
            id2word.push_back(word);
        }
        if (!word2id.count(endWord)) return 0;
        if (!word2id.count(beginWord)) {
            word2id[beginWord] = id++;
            id2word.push_back(beginWord);
        }

        // construct the graph
        vector<vector<int>> edges;
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

        vector<int> cost(id2word.size(), INT32_MAX);
        cost[s] = 0;

        queue<vector<int>> q;
        q.push(vector<int>{s});
        while (!q.empty()) {
            auto id_path = q.front();
            q.pop();

            int last = id_path.back();

            if (last == t) {
                vector<string> path;
                for (auto id : id_path) path.push_back(id2word[id]);
                res.push_back(path);
            }
            else {
                for (auto to : edges[last]) {
                    if (cost[last] + 1 < cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> next_id_path(id_path);
                        next_id_path.push_back(to);
                        q.push(next_id_path);
                    }
                }
            }    
        }

        if (res.size() > 0) return res[0].size();
        else return 0;
    }
};