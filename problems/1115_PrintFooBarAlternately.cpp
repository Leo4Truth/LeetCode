#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

// two mutex lock
class FooBar {
private:
    int n;
    mutex l1;
    mutex l2;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            l1.lock();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            l2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            l2.lock();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            l1.unlock();
        }
    }
};

// two semaphore, same idea as two mutex lock
#include <semaphore.h>
class FooBar {
private:
    int n;
    sem_t f;
    sem_t b;
public:
    FooBar(int n) {
        this->n = n;
        sem_init(&f, 0, 1);
        sem_init(&b, 0, 0);

    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            sem_wait(&f);
        	printFoo();
            sem_post(&b);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            sem_wait(&b);
        	printBar();
            sem_post(&f);
        }
    }
};

// one mutex lock and two condition_variables
class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv1, cv2;
    bool f;
public:
    FooBar(int n) {
        this->n = n;
        f = true;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock<mutex> l(mtx);
            cv1.wait(l, [&] {return f;}); // lock when l is unlocked and f is true otherwise wait
        	printFoo();
            f = false;
            cv2.notify_one(); // unlock l
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> l(mtx);
            cv2.wait(l, [&] {return !f;}); // lock when l is unlocked and f is false otherwise wait
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            f = true;
            cv1.notify_one();
        }
    }
};
