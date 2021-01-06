#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int cnt = 0;
        int next = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == next) next++;
            else {
                while (next < arr[i]) {
                    cnt++;
                    if (cnt == k) return next;
                    next++;
                }
                next++;
            }
        }
        while (cnt < k) {
            cnt++;
            next++;
        }
        return next - 1;
    }
};

int main(int argc, char *argv[]) {
    vector<int> arr;
    int n;
    
    cout << "Please input n: ";
    cin >> n;
    cout << "Please input n integers (in ascending order): " << endl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int k;
    cout << "Please input k: ";
    cin >> k;

    Solution solution;
    cout << "Result: " << endl << solution.findKthPositive(arr, k) << endl;

    return 0;
}