#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

#define DEBUG

using namespace std;


class Solution {
public:
    virtual vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) = 0;
};

class Solution_init : public Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        // unordered_set<string> req_skills_set;
        // for (string req_skill : req_skills) req_skills_set.insert(req_skill);

        int min = INT32_MAX;
        vector<int> *minTeam = nullptr;
        vector<vector<int>> teams = getAllTeams(people.size());
        for (vector<int>& team : teams) {
            unordered_set<string> teamSkills = getTeamSkills(people, team);
            if (teamSkills.size() == req_skills.size()) {
                if (team.size() < min) {
                    min = team.size();
                    minTeam = &team;
                }
            }
        }

        return *minTeam;
    }

private:
    unordered_set<string> getTeamSkills(vector<vector<string>>& people, vector<int> team) {
        unordered_set<string> team_skills_set;
        for (int i : team) {
            for (string skill : people[i]) {
                team_skills_set.insert(skill);
            }
        }
        return team_skills_set;
    }

    vector<vector<int>> getAllTeams(int m) {
        vector<vector<int>> all_teams;
#ifdef DEBUG
        cout << "teams: " << endl;
#endif // DEBUG
        for (int k = 1; k <= m; k++) {
            for (vector<int> team : combine(m, k)) {
                all_teams.push_back(team);
#ifdef DEBUG
                for (int member : team) {
                    cout << member << ", ";
                }
                cout << endl;
#endif // DEBUG
            }
        }
        return all_teams;
    }

    vector<vector<int>> combine(int m, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        
        // 初始化
        // 将 temp 中 [0, k - 1] 每个位置 i 设置为 i + 1，即 [0, k - 1] 存 [1, k]
        // 末尾加一位 n + 1 作为哨兵
        for (int i = 1; i <= k; ++i) {
            temp.push_back(i);
        }
        temp.push_back(m + 1);
        
        int j = 0;
        while (j < k) {
            ans.emplace_back(temp.begin(), temp.begin() + k);
            j = 0;
            // 寻找第一个 temp[j] + 1 != temp[j + 1] 的位置 t
            // 我们需要把 [0, t - 1] 区间内的每个位置重置成 [1, t]
            while (j < k && temp[j] + 1 == temp[j + 1]) {
                temp[j] = j + 1;
                ++j;
            }
            // j 是第一个 temp[j] + 1 != temp[j + 1] 的位置
            ++temp[j];
        }

        return ans;
    }

};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    if (n == 0) return 0;
    vector<string> req_skills;
    for (int i = 0; i < n; i++) {
        string req_skill;
        cin >> req_skill;
        req_skills.push_back(req_skill);
    }

    int m = argc >= 3 ? stoi(argv[2]) : 0;
    vector<vector<string>> people;
    for (int i = 0; i < m; i++) {
        vector<string> person;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            string skill;
            cin >> skill;
            person.push_back(skill);
        }
        people.push_back(person);
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    vector<int> smallestTeam = solution->smallestSufficientTeam(req_skills, people);
    cout << "team: [";
    for (int i = 0; i < smallestTeam.size(); i++) {
        cout << smallestTeam[i];
        if (i < smallestTeam.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
