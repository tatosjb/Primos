#ifndef PRIMEPROCESSOR_H
#define PRIMEPROCESSOR_H

#include <ThreadOnTerminate.h>
#include <PrimeData.h>
#include <vector>
#include <atomic>
#include <cmath>

class PrimeProcessor
{
  public:
    PrimeProcessor();
    virtual ~PrimeProcessor();
    bool inline isPrimeNumber(int);
    void verificaNumerosPrimos(int, int, PrimeData*);
    void inline start(int, int, PrimeData*);
    void onTerminate(ThreadOnTerminate*);
    void stop();
  protected:
  private:
    bool kill;
    std::vector<ThreadOnTerminate*> *listeners;
    void callListeners(PrimeData*);
    bool inline interativeVerificationMethod(int);
};

#endif // PRIMEPROCESSOR_H
