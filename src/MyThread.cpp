#include "MyThread.h"
#include <thread>
#include <atomic>

MyThread::MyThread()
{

}

MyThread::~MyThread()
{

}

void MyThread::join(PrimeProcessor *processor, PrimeData *data){
  configure(processor, data);
}

void inline MyThread::configure(PrimeProcessor *processor, PrimeData *data){
  active = true;
  int initialPos = data->Getposition();
  int endPos = initialPos + data->Getrange();
  this->processor = processor;
  thread = newThread(initialPos, endPos, data);
  thread.detach();
}

void MyThread::terminate(){
  processor->stop();
}

bool MyThread::isActive() {
  return active;
}

std::thread MyThread::newThread(int vBegin, int vEnd, PrimeData *data) {
  return std::thread([=, this]() {
    processor->verificaNumerosPrimos(vBegin, vEnd, data);
    this->active = false;
  });
}
