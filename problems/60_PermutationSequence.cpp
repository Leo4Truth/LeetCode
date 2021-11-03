#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution60 {
public:
    int fact(int x) {
        int res = 1;
        for (int i = 1; i <= x; i++) res *= i;
        return res;
    }

    string getPermutation(int n, int k) {
        int num = 0;
        vector<bool> used(n, false);
        int block = fact(n);

        for (int i = 0; i < n; i++) {
            block /= (n - i);
            int index = (k - 1) / block + 1;
            int cnt = 0;
            int digit = 0;
            cout << "k:     " << k << endl;
            cout << "block: " << block << endl;
            cout << "index: " << index << endl;
            for (int j = 0; j < n; j++) {
                if (!used[j]) cnt++;
                if (cnt == index) {
                    digit = j + 1;
                    break;
                }
            }
            cout << "digit: " << digit << endl;
            num = num * 10 + digit;
            cout << "num: " << num << endl;
            used[digit - 1] = true;
            /*
            for (int j = 0; j < n; j++) {
                cout << j + 1 << "used: " << used[j] << endl;
            }
            */
            cout << endl;
            k -= (index - 1) * block;
        }

        return to_string(num);
    }

    // work but exceed time limit
    string getPermutation_backTracking(int n, int k) {
        if (n > 9) return "";
        if (n == 1) {
            if (k == 1) return "1";
            else return "";
        }
        bool *used = new bool[n];
        for (int i = 0; i < n; i++) used[i] = false;

        int *index = new int[1];
        index[0] = 0;
        int *num = new int[1];
        num[0] = 0;
        int cnt = fact(n - 1);
        int first = (k - 1) / cnt + 1;
        used[first - 1] = true;
        index[0] += (first - 1) * cnt;
        num[0] += first;
        cout << "initial: " << num[0] << endl;
        backtracking(num, n, k, index, used);

        return to_string(num[0]);
    }

    bool backtracking(int *num, int n, int k, int *index, bool used[]) {
        if (to_string(num[0]).size() == n) {
            index[0]++;
            cout << "index: " << index[0] << ", " << num[0] << endl;
            if (index[0] == k) return true;
        }
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                num[0] = num[0] * 10 + i + 1;
                used[i] = true;
                bool found = backtracking(num, n, k, index, used);
                if (found) return true;
                num[0] /= 10;
                used[i] = false;
            }
        }
        return false;
    }

};

int main60() {
    Solution60 solution;
    int n, k;
    cin >> n >> k;
    cout << solution.getPermutation(n, k) << endl;
    system("pause");
    return 0;
}