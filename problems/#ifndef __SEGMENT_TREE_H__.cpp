#ifndef __SEGMENT_TREE_H__
#define __SEGMENT_TREE_H__

struct SegNode {
    int lo;
    int hi;
    int data;
    int mark = 0;
    
    SegNode(int _lo, int _hi) : lo(_lo), hi(_hi) {}
    void addMark(int val) { this->mark += val; }
    void clearMark() { this->mark = 0; }
};


#endif // segment_tree.h