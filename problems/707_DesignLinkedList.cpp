#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * @brief Simple solution
 * Single Linked List, with dummy head, only head pointer no tail pointer.
 * Component len recording the length.
 * 
 * Possible Improvement:
 * 1. add tail pointer, imporve insertion in tail, but the all operation will be complex considering the maintaince of tail.
 */
class MyLinkedList {
public:
/** Initialize your data structure here. */
    MyLinkedList() {
        head = new Node(0);
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= len) return -1;
        Node* p = head->next;
        int x = 0;
        while (x++ < index) p = p->next;
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head->next;
        head->next = node;
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        Node* p = head;
        while (p->next) p = p->next;
        p->next = node;
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node* node = new Node(val);
        Node* p = head;
        int x = 0;
        while (x++ < index) p = p->next;
        node->next = p->next;
        p->next = node;
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= len) return;
        Node* p = head;
        int x = 0;
        while (x++ < index) p = p->next;
        Node* tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        len--;
    }

    void print() {
        Node* p = head;
        while (p) {
            cout << p->val;
            if (p->next) cout << "->";
            p = p->next;
        }
        cout << "  len:" << len << endl;
    }

    struct Node {
        int val;
        Node* next;
        Node() : val(0), next(nullptr) {}
        Node(int _val) : val(_val), next(nullptr) {}
    };

private:
    Node* head;
    int len;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(int argc, char* argv[]) {

    MyLinkedList list;
    while (true) {
        string op;
        int index, val;
        cin >> op;
        if (op == "addAtHead") {
            cin >> val;
            list.addAtHead(val);
        }
        else if (op == "addAtIndex") {
            cin >> index >> val;
            list.addAtIndex(index, val);
        }
        else if (op == "addAtTail") {
            cin >> val;
            list.addAtTail(val);
        }
        else if (op == "deleteAtIndex") {
            cin >> index;
            list.deleteAtIndex(index);
        }
        else if (op == "get") {
            cin >> index;
            cout << list.get(index) << endl;
        }
        else cout << "invalid operation." << endl;
        list.print();
    }

    //system("pause");
    return 0;
}
