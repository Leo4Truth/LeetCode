#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray_On2(vector<int>& array) {
        int n = array.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (array[j] % 2 == 0 && array[j + 1] % 2 == 1) {
                    int tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
        }
        return array;
    }

    vector<int> reOrderArray_bubble(vector<int>& array) {
        int n = array.size();
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 1; i < n; i++) {
                if (array[i - 1] % 2 == 0 && array[i] % 2 == 1) {
                    flag = true;
                    int tmp = array[i - 1];
                    array[i - 1] = array[i];
                    array[i] = tmp;
                }
            }
        }
        return array;
    }
};

int main(int argc, char* argv[]) {
    string s1 = argc >= 2 ? argv[1] : "";
    string s2 = argc >= 3 ? argv[2] : "";

    Solution solution;

    //system("pause");
    return 0;
}
