#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution141 {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p1 && p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (!p2) return false;
            p2 = p2->next;
            if (p1 == p2) return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    string s1 = argc >= 2 ? argv[1] : "";
    string s2 = argc >= 3 ? argv[2] : "";

    Solution141 solution;

    //system("pause");
    return 0;
}
