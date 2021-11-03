#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution126 {
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
     * DFS backtrack 1
     * 先构建每个节点的邻接列表，再在节点的邻接列表中搜索
     * Time Limit Exceeded
     */
	void backtrack_1(
        vector<vector<string>>& res, 
        unordered_map<string, unordered_set<string>>& next_dict, 
        vector<string> current, 
        unordered_map<string, bool>& used,
        string endWord
    ) {
        //print(current);
    	
        string current_word = current[current.size() - 1];
        unordered_set<string> next_list = next_dict[current_word];
    	for (string next : next_list) {

    		// found transformed sequence including all words in word list
    		/*
            if (current[current.size() - 1] == endWord && current.size() == target_len) {
                //cout << "found. ";
                //print(current);
                res.push_back(current);
                return;
            }
            */
            if (current[current.size() - 1] == endWord) {
                int len = current.size();
                int current_len = INT_MAX;
                if (res.size() > 0) current_len = res[0].size();
                if (len < current_len) while (!res.empty()) res.pop_back();
                if (len == current_len || len < current_len) {
                    //cout << "found. ";
                    //print(current);
                    res.push_back(current);
                }
                return;
            }
    		
            if (!used[next]) {
                current.push_back(next);
                used[next] = true;
                backtrack_1(res, next_dict, current, used, endWord);
                used[next] = false;
                current.pop_back();
            }
    	}
    }
	
    vector<vector<string>> findLadders_1(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_map<string, unordered_set<string>> next_dict;

        int n = wordList.size();
    	for (int i = 0; i < n; i++) {
            unordered_set<string> set;
    		for (int j = 0; j < n; j++) {
                if (i == j) continue;;
                if (isOneDiff(wordList[i], wordList[j])) set.insert(wordList[j]);
    		}
            next_dict[wordList[i]] = set;
    	}

        unordered_set<string> set;
    	for (int i = 0; i < n; i++) 
            if (isOneDiff(beginWord, wordList[i])) set.insert(wordList[i]);
        if (isOneDiff(beginWord, endWord)) set.insert(endWord);
        next_dict[beginWord] = set;

        unordered_map<string, bool> used;
        used[beginWord] = false;
        for (int i = 0; i < n; i++) used[wordList[i]] = false;
        if (used.find(endWord) == used.end()) return res;

        printDict(next_dict);

        vector<string> current;

        current.push_back(beginWord);
        used[beginWord] = true;
    	
        backtrack_1(res, next_dict, current, used, endWord);

        return res;
    }

	/*
	 * DFS backtrack 2
	 * 直接在wordList里搜索
	 * Time Limit Exceeded
	 */
    void backtrack_2(string beginWord, string endWord, vector<string>& wordList, vector<bool>& used, vector<vector<string>>& res, vector<string>& current) {
        //print(current);
    	
    	int current_len = current.size();
    	string current_last = current[current_len - 1];
    	if (current_last == endWord) {
            int res_len = INT_MAX;
            if (!res.empty()) res_len = res[0].size();
            if (current_len < res_len) while(!res.empty()) res.pop_back();
            if (current_len < res_len || current_len == res_len) res.push_back(current);
            return;
    	}
    	
        for (int i = 0; i < wordList.size(); i++) {
	        if (!used[i] && isOneDiff(current[current_len - 1], wordList[i])) {
                current.push_back(wordList[i]);
                used[i] = true;
                backtrack_2(beginWord, endWord, wordList, used, res, current);
                used[i] = false;
                current.pop_back();
	        }
        }
    }
	
    vector<vector<string>> findLadders_2(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<bool> used(wordList.size(), false);

        vector<string> current;

        current.push_back(beginWord);
        backtrack_2(beginWord, endWord, wordList, used, res, current);

        return res;
    }

	/*
	 * DFS backtrack 3 with pruning
	 * 直接在wordList里搜索，带剪枝
	 * Time Limit Exceeded
	 */
    void backtrack_3(string beginWord, string endWord, vector<string>& wordList, vector<bool>& used, vector<vector<string>>& res, vector<string> current) {
        //print(current);
    	
        int res_len = INT_MAX;
        if (!res.empty()) res_len = res[0].size();

        int current_len = current.size();
        string current_last = current[current_len - 1];
        if (res_len == current_len && current_last != endWord) return;
        if (current_last == endWord) {
            if (current_len < res_len) while (!res.empty()) res.pop_back();
            if (current_len < res_len || current_len == res_len) res.push_back(current);
            return;
        }

        for (int i = 0; i < wordList.size(); i++) {
            if (!used[i] && isOneDiff(current[current_len - 1], wordList[i])) {
                current.push_back(wordList[i]);
                used[i] = true;
                backtrack_3(beginWord, endWord, wordList, used, res, current);
                used[i] = false;
                current.pop_back();
            }
        }
    }
	
    vector<vector<string>> findLadders_3(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<bool> used(wordList.size(), false);

        vector<string> current;

        current.push_back(beginWord);
        backtrack_3(beginWord, endWord, wordList, used, res, current);

        return res;
    }

    /*
     * DFS backtrack 4 with pruning
     * 先构建每个节点的邻接列表，再在节点的邻接列表中搜索，带剪枝
     * Time Limit Exceeded
     */
    void backtrack_4(
        vector<vector<string>>& res,
        unordered_map<string, unordered_set<string>>& next_dict,
        vector<string> current,
        unordered_map<string, bool>& used,
        string endWord
    ) {
        //print(current);

    	int res_len = INT_MAX;
        if (!res.empty()) res_len = res[0].size();

        int current_len = current.size();
        string current_last = current[current_len - 1];
    	if (res_len == current_len && current_last != endWord) return;
        if (current_last == endWord) {
            if (current_len < res_len) while (!res.empty()) res.pop_back();
            if (current_len < res_len || current_len == res_len) res.push_back(current);
            return;
        }
    	
        unordered_set<string> next_list = next_dict[current_last];
        for (string next : next_list) {

            // found transformed sequence including all words in word list
            /*
            if (current[current.size() - 1] == endWord && current.size() == target_len) {
                //cout << "found. ";
                //print(current);
                res.push_back(current);
                return;
            }
            */
            if (current[current.size() - 1] == endWord) {
                int len = current.size();
                int current_len = INT_MAX;
                if (res.size() > 0) current_len = res[0].size();
                if (len < current_len) while (!res.empty()) res.pop_back();
                if (len == current_len || len < current_len) {
                    //cout << "found. ";
                    //print(current);
                    res.push_back(current);
                }
                return;
            }

            if (!used[next]) {
                current.push_back(next);
                used[next] = true;
                backtrack_4(res, next_dict, current, used, endWord);
                used[next] = false;
                current.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders_4(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_map<string, unordered_set<string>> next_dict;

        int n = wordList.size();
        for (int i = 0; i < n; i++) {
            unordered_set<string> set;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;;
                if (isOneDiff(wordList[i], wordList[j])) set.insert(wordList[j]);
            }
            next_dict[wordList[i]] = set;
        }

        unordered_set<string> set;
        for (int i = 0; i < n; i++)
            if (isOneDiff(beginWord, wordList[i])) set.insert(wordList[i]);
        if (isOneDiff(beginWord, endWord)) set.insert(endWord);
        next_dict[beginWord] = set;

        unordered_map<string, bool> used;
        used[beginWord] = false;
        for (int i = 0; i < n; i++) used[wordList[i]] = false;
        if (used.find(endWord) == used.end()) return res;

        printDict(next_dict);

        vector<string> current;

        current.push_back(beginWord);
        used[beginWord] = true;

        backtrack_4(res, next_dict, current, used, endWord);

        return res;
    }

	/*
	 * BFS
	 */
    vector<vector<string>> findLadders_5(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
    	
        vector<string> current;
        current.push_back(beginWord);
        unordered_set<string> current_set;
        current_set.insert(beginWord);
    	
        queue<vector<string>> q1;
        queue<unordered_set<string>> q2;
        q1.push(current);
        q2.push(current_set);
    	
        int n = wordList.size();
        int shortest_len = n + 1;

    	while (!q1.empty()) {
            current = q1.front();
            q1.pop();
            current_set = q2.front();
            q2.pop();
    		
            string current_last = current[current.size() - 1];

            if (current.size() == shortest_len && current_last != endWord) continue;
            else if (current.size() == shortest_len && current_last == endWord) {
                res.push_back(current);
                continue;
            }
            else if (current.size() < shortest_len && current_last == endWord) {
                while (!res.empty()) res.pop_back();
                res.push_back(current);
                shortest_len = current.size();
            }
    		
    		for (auto word : wordList) {
    			if (isOneDiff(current_last, word) && current_set.find(word) == current_set.end()) {
                    current.push_back(word);
                    current_set.insert(word);
                    q1.push(current);
                    q2.push(current_set);
                    current.pop_back();
                    current_set.erase(word);
    			}
    		}
    	}

        return res;
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
    vector<vector<string>> findLadders_6(string beginWord, string endWord, vector<string>& wordList) {
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

        return res;
    }

	/*
	 * Bi-BFS
	 * problem!
	 */
    vector<vector<string>> findLadders_7(string beginWord, string endWord, vector<string>& wordList) {
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
        int min = INT_MAX;

    	queue<vector<int>> q1;
        vector<int> cost1(id2word.size(), INT_MAX);
        q1.push(vector<int>{s});
        cost1[s] = 0;

        queue<vector<int>> q2;
        vector<int> cost2(id2word.size(), INT_MAX);
        q2.push(vector<int>{t});
        cost2[t] = 0;

    	while (!q1.empty() && !q2.empty()) {
            vector<int> id_path_1 = q1.front();
            vector<int> id_path_2 = q2.front();

            if (id_path_1.size() + id_path_2.size() > min) return res;

            cout << endl;
            print(id_path_1);
            print(id_path_2);

            int last_1 = id_path_1.back();
            int last_2 = id_path_2.back();

            bool connected = false;
    		for (int i = 0; i < edges[last_1].size(); i++) {
    			if (edges[last_1][i] == last_2) {
                    connected = true;
                    vector<string> path;
                    for (int j = 0; j < id_path_1.size(); j++)
                        path.push_back(id2word[id_path_1[j]]);
                    for (int j = id_path_2.size() - 1; j >= 0; j--)
                        path.push_back(id2word[id_path_2[j]]);
                    if (path.size() < min) {
                        res.clear();
                        min = path.size();
                    }
                    res.push_back(path);
    			}
    		}
    		
            if (edges[last_1].size() < edges[last_2].size()) {
                q1.pop();
                for (int i = 0; i < edges[last_1].size(); i++) {
                    int to = edges[last_1][i];
                    // 此处等号很重要
                    if (cost1[last_1] + 1 <= cost1[to]) {
                    	// TODO: Problem
                        cost1[to] = cost1[last_1] + 1;
                        vector<int> new_id_path(id_path_1);
                        new_id_path.push_back(to);
                        q1.push(new_id_path);
                    }
                }
            }
            else {
                q2.pop();
                for (int i = 0; i < edges[last_2].size(); i++) {
                    int to = edges[last_2][i];
                    // 此处等号很重要
                    if (cost2[last_2] + 1 <= cost2[to]) {
                        cost2[to] = cost2[last_1] + 1;
                        vector<int> new_id_path(id_path_2);
                        new_id_path.push_back(to);
                        q2.push(new_id_path);
                    }
                }
            }
    	}

        return res;
    }
};

int main126(int argc, char* argv[]) {
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

    Solution126 solution;
    vector<vector<string>> res = solution.findLadders_7(beginWord, endWord, wordList);

    cout << "Result: " << endl;
    cout << "[" << endl;
	for (int i = 0; i < res.size(); i++) {
        cout << "\t[";
		for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j < res[i].size() - 1) cout << ", ";
		}
        cout << "]" << endl;
	}
    cout << "]" << endl;

    system("pause");
    return 0;
}