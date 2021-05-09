#include <iostream>
#include <vector>
#include <unordered_map>

#define DEBUG

using namespace std;

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    int counter;
    Node() : key(0), value(0), prev(nullptr), next(nullptr), counter(0) {}
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr), counter(0) {}
    Node(int k, int v, Node* p) : key(k), value(v), prev(p), next(nullptr), counter(0) {}
    Node(int k, int v, Node* p, Node* n) : key(k), value(v), prev(p), next(n), counter(0) {}
    Node(int k, int v, Node* p, Node* n, int cnt) : key(k), value(v), prev(p), next(n), counter(cnt) {}
};

/**
 * @brief LFU Cache
 * Leat Frequently Used Cache
 * Link List
 * The most recently visited data in the tail
 */
class LFUCache {
private:
    const int capacity;
    int cnt = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    unordered_map<int, Node*> key2Node;

public:
    LFUCache(int capacity_) : capacity(capacity_) {}
    
    int get(int key) {
        if (this->capacity == 0) return -1;
        else if (this->capacity == 1) return this->head && this->head->key == key ? this->head->value : -1;
        Node* node = this->extract(key);
        if (!node) return -1;
        node->counter++;
        this->insert(node);
        key2Node[key] = node;
        return node->value;
    }
    
    void put(int key, int value) {
        if (this->capacity == 0) return;
        else if (this->capacity == 1) {
            if (!this->head) {
                this->head = new Node(key, value);
                this->tail = this->head;
                this->head->counter = 1;
                return;
            }
            if (this->head->key == key) {
                this->head->value = value;
                this->head->counter++;
            }
            else {
                this->head->key = key;
                this->head->value = value;
                this->head->counter = 1;
            }
        }
        Node* node = this->extract(key);
        if (!node) node = new Node(key, value);
        else node->value = value;
        key2Node[key] = node;
        node->counter++;
        this->insert(node);
    }
    
    Node* extract(int key) {
        if (key2Node.find(key) == key2Node.end() || key2Node[key] == nullptr) return nullptr;
        Node* node = key2Node[key];
        key2Node[key] = nullptr;
        // node at the head
        if (!node->prev) {
            // node are both head and tail
            if (!node->next) {
                this->head = nullptr;
                this->tail = nullptr;
            }
            else {
                this->head = node->next;
                node->next->prev = nullptr;
            }
        }
        // node at the head, can't be both head and tail in this case
        else if (!node->next) {
            this->tail = node->prev;
            node->prev->next = nullptr;
        }
        // node neither head nor tail
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->prev = nullptr;
        node->next = nullptr;
        this->cnt--;
        return node;
    }

    void insert(Node* node) {
        if (!node) return;
        
        this->cnt++;
        if (this->cnt > this->capacity) {
            key2Node[this->head->key] = nullptr;
            this->head = this->head->next;
            this->head->prev = nullptr;
            this->cnt--;
        }

        Node* prev = nullptr;
        Node* current = this->head;
        while (current && current->counter <= node->counter) {
            prev = current;
            current = current->next;
        }
#ifdef DEBUG
        cout << "insert between ";
        if (prev) cout << prev->key << ":" << prev->value << " ";
        cout << "and ";
        if (current) cout << current->key << ":" << current->value << " ";
        cout << endl;
#endif // DEBUG
        // insert at the head
        if (!prev) {
            // insert into empty list 
            if (!current) this->tail = node;
            else {
                node->next = current;
                current->prev = node;
            }
            this->head = node;
        }
        // insert at the tail, can't be both head and tail in this case
        else if (!current) {
            prev->next = node;
            node->prev = prev;
            this->tail = node;
        }
        // insert into neither head nor tail
        else {
            prev->next = node;
            node->prev = prev;
            current->prev = node;
            node->next = current;
        }
    }

    void print() {
        cout << "print:" << endl;
        Node* node = this->head;
        while (node) {
            cout << node->key << ": " << node->value << ", " << node->counter << endl;
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
    LFUCache* obj = new LFUCache(n);
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
