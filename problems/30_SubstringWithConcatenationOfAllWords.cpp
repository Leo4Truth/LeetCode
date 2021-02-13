#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution30 {
public:
	// Pass, 216 ms, 45.25%, 215 MB, 69.57%
	// two umap
	vector<int> findSubstringTwoMap(string s, vector<string>& words) {
		vector<int> res;
		if (s == "") return res;
		if (words.size() == 0) return res;
		if (words[0].length() * words.size() > s.length()) return res;

		int wordLen = words[0].length();
		int M = words.size();
		int N = s.size();
		unordered_map<string, int> counts;

		// the counts umap(or dict) store the counts of each word 
		// that it should appear in each perm and dealing with the
		// duplicate words in the words vector so some value in the umap
		// can be more than 1 while the total size of the umap is
		// less than the size of words vector
		for (string word : words) counts[word]++;

		vector<int> indices;
		
		// main loop, loop variable i is the start index of each search
		for (int i = 0; i < N - M * wordLen + 1; i++) {
			unordered_map<string, int> seen;
			bool match = false;
			for (int j = 0; j < M; j++) {
				string word = s.substr(i + j * wordLen, wordLen);
				if (counts.find(word) != counts.end()) seen[word]++;
				else break;
				if (seen[word] > counts[word]) break;
				if (j == M - 1) match = true;
			}
			if (match) indices.push_back(i);
		}

		return indices;
	}

	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (s == "") return res;
		if (words.size() == 0) return res;
		if (words[0].length() * words.size() > s.length()) return res;

		int wordLen = words[0].length();
		int M = words.size();
		int N = s.size();
		unordered_map<string, int> counts;

		int targetAsciiSum = 0;
		for (auto word : words) {
			for (int i = 0; i < word.size(); i++)
				targetAsciiSum += word[i];
		}
		//cout << "target ascii sum: " << targetAsciiSum << endl;

		for (string word : words)
			counts[word]++;
		vector<int> indices;

		// main loop, loop variable i is the start index of each search
		for (int i = 0; i < N - M * wordLen + 1; i++) {
			int asciiSum = 0;
			for (int j = 0; j < M * wordLen; j++)
				asciiSum += s[i + j];
			//cout << i << " - ascii sum: " << asciiSum << endl;
			if (asciiSum != targetAsciiSum) continue;

			unordered_map<string, int> seen;
			bool match = false;
			for (int j = 0; j < M; j++) {
				string word = s.substr(i + j * wordLen, wordLen);
				if (counts.find(word) != counts.end()) seen[word]++;
				else break;
				if (seen[word] > counts[word]) break;
				if (j == M - 1) match = true;
			}
			if (match) indices.push_back(i);
		}

		return indices;
	}

	// Exceed the time limit
	// I think because there is a optimization for this problem since all words are with same length
	vector<int> findSubstringTimeOut(string s, vector<string>& words) {
		// first we generate all permutations for the words
		vector<string> permutations = generateWordsPermutations(words);
		cout << "all perms: " << endl;
		for (int i = 0; i < permutations.size(); i++) {
			if (i == 0) cout << "[";
			cout << permutations[i];
			if (i != permutations.size() - 1) cout << ", ";
			else cout << "]" << endl;
		}

		// then we check if the specific string contains such permutations
		vector<int> res;
		vector<bool> exist(s.length(), false);
		for (int i = 0; i < permutations.size(); i++) {
			vector<int> subres = KMP(s, permutations[i]);
			for (int i = 0; i < subres.size(); i++) {
				if (!exist[subres[i]]) {
					res.push_back(subres[i]);
					exist[subres[i]] = true;
				}
			}
		}

		return res;
	}

	vector<string> generateWordsPermutations(vector<string>& words) {
		vector<string> perms;
		vector<bool> used(words.size(), false);
		string currentPerm = "";
		backtrack(currentPerm, perms, words, used);
		return perms;
	}

	void backtrack(string currentPerm, vector<string>& perms, vector<string>& words, vector<bool> used) {
		if (!words.empty() && currentPerm.length() == words[0].length() * words.size()) {
			perms.push_back(currentPerm);
			return;
		}

		for (int i = 0; i < used.size(); i++) {
			if (!used[i]) {
				string tmp = currentPerm + words[i];
				used[i] = true;
				backtrack(tmp, perms, words, used);
				used[i] = false;
			}
		}
	}

	vector<int> KMP(string text, string pattern) {
		vector<int> indices;
		int M = pattern.length();
		int N = text.length();

		// longest prefix suffix
		vector<int> lps = vector<int>(M, 0);
		int len = 0; // length of the previous longest prefix suffix
		lps[0] = 0;
		int t = 1;
		while (t < M) {
			if (pattern[t] == pattern[len]) {
				len++;
				lps[t] = len;
				t++;
			}
			// pattern[t] != pattern[len]
			else {
				// This is tricky. Consider the example. 
				// AAACAAAA and t = 7. The idea is similar to search step. 
				if (len != 0) {
					len = lps[len - 1];

					// Also, note that we do not increment t here 
				}
				else // if (len == 0) 
				{
					lps[t] = 0;
					t++;
				}
			}
		}

		int i = 0, j = 0;
		while (i < N) {
			if (pattern[j] == text[i]) {
				j++;
				i++;
			}

			if (j == M) {
				indices.push_back(i - j);
				j = lps[j - 1];
			}
			// mismatch after j matches
			else if (i < N && pattern[j] != text[i]) {
				// Do not match lps[0..lps[j-1]] characters, 
				// they will match anyway 
				if (j != 0)
					j = lps[j - 1];
				else
					i = i + 1;
			}
		}
		return indices;
	}
};

int main30() {
	Solution30 solution;
	vector<string> words;
	int n;
	string str;
	cout << "input words size: " << endl;
	cin >> n;
	cout << "input n words: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> str;
		words.push_back(str);
	}
	cout << "input the string: " << endl;
	cin >> str;
	vector<int> res = solution.findSubstring(str, words);
	cout << "result: " << endl;
	for (int i = 0; i < res.size(); i++) {
		if (i == 0) cout << "[";
		cout << res[i];
		if (i != res.size() - 1) cout << ", ";
		else cout << "]" << endl;
	}
	system("pause");
	return 0;
}