#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    Node(int k, int v, Node* p) : key(k), value(v), prev(p), next(nullptr) {}
    Node(int k, int v, Node* p, Node* n) : key(k), value(v), prev(p), next(n) {}
};

/**
 * @brief LRU Cache
 * Least Recently Used Cache
 * Link List
 * The most recently visited data in the tail
 */
class LRUCache {
private:
    const int capacity;
    int cnt = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    unordered_map<int, Node*> key2Node;

public:
    LRUCache(int capacity_) : capacity(capacity_) {}
    
    int get(int key) {
        // data not in cache
        if (key2Node.find(key) == key2Node.end() || key2Node[key] == nullptr) return -1;
        // data in cache
        else {
            Node* node = key2Node[key];
            this->move2tail(node);
            return node->value;
        }
    }
    
    void put(int key, int value) {
        // data not in cache
        if (key2Node.find(key) == key2Node.end() || key2Node[key] == nullptr) {
            Node* node = nullptr;
            // cache is not full
            // add new node to the tail
            if (cnt < this->capacity) {
                node = new Node(key, value);
                key2Node[key] = node;
                cnt++;
            }
            // cache is full
            // do not create new node, move the node to the tail and update its key and value
            else {
                node = this->head;
                key2Node[node->key] = nullptr;
                key2Node[key] = node;
                node->key = key;
                node->value = value;
            }
            this->move2tail(node);
        }
        // data in cache, update and move the node to the tail
        else {
            Node* node = key2Node[key];
            node->value = value;
            this->move2tail(node);
        }
    }

    void move2tail(Node* node) {
        if (!node) return;
        if (!this->head) {
            this->head = node;
            this->tail = node;
            node->prev = nullptr;
            node->next = nullptr;
            return;
        }
        if (node == this->head && node == this->tail) return;
        else if (node == this->head && node != this->tail) {
            this->head = node->next;
            node->next->prev = nullptr;
            this->tail->next = node;
            node->prev = this->tail;
            node->next = nullptr;
            this->tail = node;
        }
        else if (node != this->head && node == this->tail) return;
        else if (node != this->head && node != this->tail) {
            if (node->prev) node->prev->next = node->next;
            if (node->next) node->next->prev = node->prev;
            this->tail->next = node;
            node->prev = this->tail;
            node->next = nullptr;
            this->tail = node;
        }
    }

    void print() {
        cout << "print:" << endl;
        Node* node = this->head;
        while (node) {
            cout << node->key << ": " << node->value << endl;
            node = node->next;
        }
        cout << "print end." << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 2;
    LRUCache* obj = new LRUCache(n);
    string op;
    cin >> op;
    while (op != "exit") {
        cout << op << endl;
        if (op == "put") {
            int k, v;
            cin >> k >> v;
            obj->put(k, v);
        }
        else if (op == "get") {
            int k;
            cin >> k;
            cout << k << ": " << obj->get(k) << endl;
        }
        obj->print();
        cin >> op;
    }

    //system("pause");
    return 0;
}
