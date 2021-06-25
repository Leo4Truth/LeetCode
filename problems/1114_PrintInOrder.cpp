#include <iostream>
#include <vector>
#include <mutex>        // C++ STL
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define __win__
#include <windows.h>
#elif __linux__
#include <semaphore.h> // Only work on Linux
#include <functional>
#include <pthread.h>
#endif

using namespace std;


#if __linux__
// 信号量 linux
class Foo {
protected:
    sem_t firstJobDone;
    sem_t secondJobDone;

public:
    Foo() {
        sem_init(&firstJobDone, 0, 0);
        sem_init(&secondJobDone, 0, 0);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first".
        printFirst();
        sem_post(&firstJobDone);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstJobDone);
        // printSecond() outputs "second".
        printSecond();
        sem_post(&secondJobDone);
        
    }

    void third(function<void()> printThird) {
        sem_wait(&secondJobDone);
        // printThird() outputs "third".
        printThird();
    }
};
#endif // __linux__

#if defined(__win__)
// 信号量 windows
class Foo {
protected:
    HANDLE firstJobDoneSemaphore;
    HANDLE secondJobDoneSemaphore;

public:
    Foo() {
        firstJobDoneSemaphore = CreateSemaphore(NULL, 0, 1, NULL);
        secondJobDoneSemaphore = CreateSemaphore(NULL, 0, 1, NULL);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first".
        printFirst();
        ReleaseSemaphore(firstJobDoneSemaphore, 1, NULL);
    }

    void second(function<void()> printSecond) {
        DWORD dwWaitResult = WaitForSingleObject(firstJobDoneSemaphore, 0L);
        // printSecond() outputs "second".
        printSecond();
        ReleaseSemaphore(secondJobDoneSemaphore, 1, NULL);
        
    }

    void third(function<void()> printThird) {
        DWORD dwWaitResult = WaitForSingleObject(secondJobDoneSemaphore, 0L);
        // printThird() outputs "third".
        printThird();
        ReleaseSemaphore(secondJobDoneSemaphore, 1, NULL);
    }
};
#endif

// while忙等
class Foo_count {
public:
    Foo_count() {}

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        count++;
    }

    void second(function<void()> printSecond) {
        while (count < 2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        count++;
        //mtx2.unlock();
    }

    void third(function<void()> printThird) {
        while (count < 3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    int count = 1;
};

// 互斥锁
class Foo_mutex {
public:
    Foo_mutex() {
        mtx1.lock();
        mtx2.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        mtx1.unlock();
    }

    void second(function<void()> printSecond) {
        mtx1.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        mtx1.unlock();
        mtx2.unlock();
    }

    void third(function<void()> printThird) {
        mtx2.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        mtx2.unlock();
    }

private:
    mutex mtx1, mtx2;
};
