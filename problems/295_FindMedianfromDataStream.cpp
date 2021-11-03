#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * @brief MeidanFinder using two priority_queue
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size()) {
                queMax.push(queMin.top());
                queMin.pop();
            }
        } else {
            queMax.push(num);
            if (queMax.size() > queMin.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian() {
        if (queMin.size() > queMax.size()) {
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }

private:
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;
};

/**
 * @brief MedianFinder using sorted set and two pointers
 */
class MedianFinder_2 {
    multiset<int> nums;
    multiset<int>::iterator left, right; // multiset is sorted but doesn't support subscript index, so iterator as "pointer" 

public:
    MedianFinder() : left(nums.end()), right(nums.end()) {}

    void addNum(int num) {
        const size_t n = nums.size();

        nums.insert(num);
        if (!n) {
            left = right = nums.begin();
        } else if (n & 1) {
            if (num < *left) {
                left--;
            } else {
                right++;
            }
        } else {
            if (num > *left && num < *right) {
                left++;
                right--;
            } else if (num >= *right) {
                left++;
            } else {
                right--;
                left = right;
            }
        }
    }

    double findMedian() {
        return (*left + *right) / 2.0;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, char* argv[]) {
    int n = argc >= 2? stoi(argv[1]) : 0;
    
    MedianFinder* obj = new MedianFinder();
    
    obj->addNum(1);
    obj->addNum(1);
    obj->addNum(1);
    obj->addNum(2);
    obj->addNum(3);
    obj->addNum(4);
    obj->addNum(5);
    cout << obj->findMedian() << endl;

    return 0;
}
