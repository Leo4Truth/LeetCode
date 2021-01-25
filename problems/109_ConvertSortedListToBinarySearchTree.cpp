#include <iostream>
#include <vector>


#include "ListNode.h"
#include "TreeNode.h"

using namespace std;

class Solution109 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
    	
        auto *fastPtr = head, *slowPtr = head;
        ListNode* prev = nullptr;
    	
    	while (fastPtr->next && fastPtr->next->next) {
            prev = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
    	}
        if (prev) prev->next = nullptr;
        else head = nullptr;
    	
    	auto* root = new TreeNode(slowPtr->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slowPtr->next);

    	return root;
    }

    TreeNode* sortedListToBST_inorderSim(ListNode* head) {
        if (!head) return nullptr;
        int size = getSize(head);
        auto* root = convertListToBST(head, 0, size - 1);
        return root;
    }

	int getSize(ListNode* head) {
        int size = 0;
        auto* ptr = head;
    	while (ptr) {
            size++;
            ptr = ptr->next;
    	}
        return size;
    }

	TreeNode* convertListToBST(ListNode* &head, int l, int r) {
	    // Invalid case
        if (l > r) return nullptr;

        int mid = (l + r) / 2;

    	// First step of simulated inorder traversal. Recursively form the left half.
    	// ��ִ����һ���Ǳ�Ҫ�ģ��ݹ����ȹ�����node����С��Ԫ�أ�Ȼ��head���ϵ����
        auto* left = convertListToBST(head, l, mid - 1);

    	// Once the left half is traversed, process the current node.
    	// �˴���head�Ѿ��������������ˣ���ʱ���б�head->valС��Ԫ�أ�����ԭlist�бȵ�ǰhead����ǰ��Ԫ�أ�
    	// ȫ���Ѿ�����һ���б��ɹ�����Ϊ��left��
        TreeNode* node = new TreeNode(head->val);
        node->left = left;

        head = head->next;

        node->right = convertListToBST(head, mid + 1, r);

        return node;
    }
};

int main109() {
    Solution109 solution;

    vector<int> nums = { -10, -3, 0, 5, 9 };
    auto* head = ListNode::List(nums);

    auto* root = solution.sortedListToBST_inorderSim(head);
	
	system("pause");

    return 0;
}