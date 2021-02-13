#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution49 {
public:
	// hash(s) = sum(2^(s[i]-'a'))
	// if collision happen, hash(s) = sum(3^(s[i]-'a'))
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		vector<int> hashValues;
		for (int i = 0; i < strs.size(); i++) {
			int hash = 0;
			for (int j = 0; j < strs[i].size(); j++) {
				hash += pow(2, (strs[i][j] - 'a'));
			}
			bool exist = false;
			for (int k = 0; k < hashValues.size(); k++) {
				if (hashValues[k] == hash) {
					if (res[k][0].size() != strs[i].size()) continue;
					if (charSum(res[k][0]) != charSum(strs[i])) continue;
					res[k].push_back(strs[i]);
					exist = true;
					break;
				}
			}
			if (!exist) {
				hashValues.push_back(hash);
				res.push_back(vector<string>(0));
				res[res.size() - 1].push_back(strs[i]);
			}
		}
		return res;
    }

	int pow(int x, int n) {
		return x << n;
	}

	int charSum(string s) {
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			sum += s[i] - 'a';
		}
		return sum;
	}
};


int main49() {
	Solution49 solution;
	vector<string> strs;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		strs.push_back(s);
	}
	vector<vector<string>> res = solution.groupAnagrams(strs);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
			if (j < res[i].size() - 1) cout << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}