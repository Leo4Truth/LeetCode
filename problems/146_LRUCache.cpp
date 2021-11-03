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

class LRUCache_21_6_28 {
private:
    const int capacity;
    int size;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

public:
    LRUCache_21_6_28(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        // 如果 key 存在，先通过哈希表定位，再移到头部
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            Node* node = new Node(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                Node* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }
    
    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
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
 * @brief LRU Cache
 * Least Recently Used Cache
 * Doubly Link List
 * The most recently visited data in the tail
 * Pass
 * Time:  480 ms, defeat 15.09%
 * Space: 158 MB, defeat 16.25%
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
    LRUCache_21_6_28* obj = new LRUCache_21_6_28(n);
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
