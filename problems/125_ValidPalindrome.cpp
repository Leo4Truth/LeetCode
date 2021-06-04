#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution125 {
public:
    bool isValid(char c) {
        return isLetter(c) || (c >= '0' && c <= '9');
    }
	
	bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
	
    bool isPalindrome(string s) {
        int len = s.length();

        int l = 0, r = len - 1;
    	while (l < r) {
            while (l < r && !isValid(s[l])) l++;
            while (l < r && !isValid(s[r])) r--;

            if (tolower(s[l]) != tolower(s[r])) return false;
    		
            l++;
            r--;
        }

        return true;
    }
};

int main125(int argc, char* argv[]) {
    string s;
    if (argc == 2) s = argv[1];
    else {
        cout << "please input string: ";
        cin >> s;
    }

    Solution125 solution;
    cout << solution.isPalindrome(s) << endl;

    system("pause");
	
    return 0;
}