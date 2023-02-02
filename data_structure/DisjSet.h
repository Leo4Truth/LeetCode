#ifndef __DISJ_SET_H__
#define __DISJ_SET_H__

#include <vector>

/**
 * @brief Distinct Set
 * Union and Find
 */
class DisjSet {
public:
    DisjSet(int n) : parent(vector<int>(n)), rank(vector<int>(n, 0)) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }

    void union_(int x1, int x2) {
        int p1 = find(x1);
        int p2 = find(x2);
        if (rank[p1] > rank[p2]) parent[p2] = parent[p1];
        else {
            parent[p1] = p2;
            if (rank[p1] == rank[p2]) rank[p2]++;
        }    
    }

    bool is_same(int x1, int x2) {
        return find(x1) == find(x2);
    }

private:
    vector<int> parent;
    vector<int> rank;
};

#endif // DisjSet