#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    virtual vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) = 0;
};

// sort and find target pair by two pointers
class Solution_sort_two_pointers : public Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int n1 = array1.size();
        int n2 = array2.size();

        int sum1 = accumulate(array1.begin(), array1.end(), 0);
        int sum2 = accumulate(array2.begin(), array2.end(), 0);
        int diff = sum1 - sum2;
        if (abs(diff) % 2 == 1) return {};

        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());

        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (array1[i] - array2[j] == diff / 2) return {array1[i], array2[j]};
            else if (array1[i] - array2[j] < diff / 2) i++;
            else if (array1[i] - array2[j] > diff / 2) j++;
        }

        return {};
    }
};

// sort and find target pair binary search
class Solution_sort_binary_search : public Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int n1 = array1.size();
        int n2 = array2.size();

        int sum1 = accumulate(array1.begin(), array1.end(), 0);
        int sum2 = accumulate(array2.begin(), array2.end(), 0);
        int diff = sum1 - sum2;
        if (abs(diff) % 2 == 1) return {};

        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());

        for (int i = 0; i < n1; i++) {
            int target = array1[i] - diff / 2;
            if (binary_search(array2.begin(), array2.end(), target)) return {array1[i], target};
        }

        return {};
    }
};

// sort and find target pair linear
class Solution_init : public Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int n1 = array1.size();
        int n2 = array2.size();

        int sum1 = accumulate(array1.begin(), array1.end(), 0);
        int sum2 = accumulate(array2.begin(), array2.end(), 0);
        int diff = sum1 - sum2;
        if (abs(diff) % 2 == 1) return {};

        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());

        for (int i = 0; i < n1; i++) {
            int target = array1[i] - diff / 2;
            for (int j = 0; j < n2; j++) {
                if (array2[j] == target) return {array1[i], array2[j]};
            }
        }

        return {};
    }
};

int main(int argc, char* argv[]) {
    int n1 = argc >= 2 ? stoi(argv[1]) : 0;
    int n2 = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> array1;
    vector<int> array2;
    for (int i = 0; i < n1; i++) {
        int num;
        cin >> num;
        array1.push_back(num);
    }
    for (int i = 0; i < n2; i++) {
        int num;
        cin >> num;
        array2.push_back(num);
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    vector<int> res = solution->findSwapValues(array1, array2);
    cout << "init: " << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    solution = new Solution_sort_binary_search();
    res = solution->findSwapValues(array1, array2);
    cout << "init: " << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    solution = new Solution_sort_two_pointers();
    res = solution->findSwapValues(array1, array2);
    cout << "init: " << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}
