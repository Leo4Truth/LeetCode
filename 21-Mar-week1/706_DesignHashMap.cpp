#include <iostream>
#include <vector>

using namespace std;

class Bucket {
private:
    vector<pair<int, int>> bucket;

public:
    Bucket() {}

    int get(int key) {
        for (auto p : this->bucket) {
            if (p.first == key) return p.second;
        }
        return -1; // not found;
    }
    void update(int key, int value) {
        bool found = false;
        for (int i = 0; i < this->bucket.size(); i++) {
            if (this->bucket[i].first == key) {
                this->bucket[i].second = value;
                found = true;
            }
        }
        if (!found) this->bucket.push_back({key, value});
    }

    void remove(int key) {
        for (int i = 0; i < this->bucket.size(); i++) {
            if (this->bucket[i].first == key) {
                this->bucket.erase(this->bucket.begin() + i);
                i--;
            }
        }
    }

    bool empty() { return this->bucket.empty(); }

    void print() {
        for (int i = 0; i < this->bucket.size(); i++) {
            cout << this->bucket[i].first << ", " << this->bucket[i].second;
            if (i < this->bucket.size() - 1) cout << "; ";
        }
        if (!this->bucket.empty()) cout << endl;
    }
};

class MyHashMap {
private:
    int keySpace;
    vector<Bucket> hashTable;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        this->keySpace = 1024;
        this->hashTable = vector<Bucket>(this->keySpace, Bucket());
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash = key % this->keySpace;
        this->hashTable[hash].update(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash = key % this->keySpace;
        return this->hashTable[hash].get(key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash = key % this->keySpace;
        this->hashTable[hash].remove(key);
    }

    void print() {
        for (int hash = 0; hash < this->keySpace; hash++) {
            this->hashTable[hash].print();
        }
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<char> ops;
    vector<int> keys;
    vector<int> values;
    for (int i = 0; i < n; i++) {
        char op;
        int key, value;
        cin >> op;
        cin >> key;
        if (op == 'p') cin >> value;
        ops.push_back(op);
        keys.push_back(key);
        values.push_back(value);
    }

    MyHashMap* obj = new MyHashMap();
    for (int i = 0; i < n; i++) {
        if (ops[i] == 'p') {
            obj->put(keys[i], values[i]);
        }
        else if (ops[i] == 'r') {
            obj->remove(keys[i]);
        }
        else if (ops[i] == 'g') {
            int value = obj->get(keys[i]);
            cout << "get: " << keys[i] << ", " << value << endl;
        }
    }

    obj->print();

    //system("pause");
    return 0;
}
