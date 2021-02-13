#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Greedy
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int cnt = 0;
        int i = 0, j = people.size() - 1;
        while (i <= j) {
            cnt++;
            if (people[i] + people[j] <= limit) i++;
            else if (people[j] > limit) return -1;
            j--;
        }

        return cnt;
    }
};