#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(1.0 * area);
        while (area % w) {
            --w;
        }
        return {area / w, w};
    }
};

int main(int argc, char* argv[]) {
    int area = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    vector<int> rectangle = solution.constructRectangle(area);
    cout << "[" << rectangle[0] << ", " << rectangle[1] << "]" << endl;

    return 0;
}
