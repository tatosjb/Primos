#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <thread>
#include <PrimeData.h>
#include <PrimeProcessor.h>
#include <atomic>

class MyThread
{
public:
    MyThread();
    virtual ~MyThread();
    void join(PrimeProcessor*, PrimeData*);
    void inline configure(PrimeProcessor*, PrimeData*);
    bool isActive();
    void terminate();
  private:
//    vector<ThreadOnTerminate> listener;
    std::thread thread;
    PrimeProcessor *processor;
    bool active;
    std::thread newThread(int, int, PrimeData*);

};

#endif // MYTHREAD_H
