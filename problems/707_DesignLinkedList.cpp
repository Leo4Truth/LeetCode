#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= len || index < 0) return -1;
        Node* p = head;
        int x = 0;
        while (p && x++ < index) p = p->next;
        if (p) return p->val;
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        if (!head) tail = node;
        else {
            node->next = head;
            head->prev = node;
        }
        head = node;
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        if (!head) head = node;
        else {
            tail->next = node;
            node->prev = tail;
        }
        tail = node;
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > len || index < 0) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == len) {
            addAtTail(val);
            return;
        }
        Node* node = new Node(val);
        Node* next = head;
        int x = 0;
        while (x++ < index) {
            cout << "next: " << next->val << endl;
            next = next->next;
        }
        next->prev->next = node;
        node->prev = next->prev;
        node->next = next;
        next->prev = node;
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= len) return;
        if (index == 0) {
            Node* tmp = head;
            if (head->next) head->next->prev = nullptr;
            head = head->next;
            delete tmp;
        }
        else if (index == len - 1) {
            Node* tmp = tail;
            if (tail->prev) tail->prev->next = nullptr;
            tail = tail->prev;
            delete tmp;
        }
        else {
            Node* prev = nullptr;
            Node* current = head;
            Node* next = current->next;
            int x = 0;
            while (current && x++ < index) {
                prev = current;
                current = next;
                next = current->next;
            }
            prev->next = next;
            next->prev = prev;
            delete current;
        }
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
        Node* prev;
        Node* next;
        Node() : val(0), prev(nullptr), next(nullptr) {}
        Node(int _val) : val(_val), prev(nullptr), next(nullptr) {}
    };

private:
    Node* head;
    Node* tail;
    int len;
};

class MyLinkedListWithDummyHead {
public:
    /** Initialize your data structure here. */
    MyLinkedListWithDummyHead() {
        head = new Node(0);
        tail = nullptr;
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= len || index < 0) return -1;
        Node* p = head->next;
        int x = 0;
        while (p && x++ < index) p = p->next;
        if (p) return p->val;
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        if (!tail) tail = node;
        node->next = head->next;
        head->next = node;
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        tail->next = node;
        tail = node;
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > len || index < 0) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == len) {
            addAtTail(val);
            return;
        }
        Node* node = new Node(val);
        Node* prev = head;
        int x = 0;
        while (x++ < index) prev = prev->next;
        node->next = prev->next;
        prev->next = node;
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= len) return;
        if (index == 0) {
            Node* tmp = head;
            head->next = head->next->next;
            delete tmp;
        }
        else if (index == len - 1) {
            Node* p = head;
            while (p->next != tail) p = p->next;
            p->next = nullptr;
            delete tail;
            tail = p;
        }
        else {
            Node* prev = head;
            Node* current = head->next;
            Node* next = current->next;
            int x = 0;
            while (x++ < index) {
                prev = current;
                current = next;
                next = current->next;
            }
            prev->next = next;
            delete current;
        }
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
    Node* tail;
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

    MyLinkedListWithDummyHead list;
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
