#ifndef THREADONTERMINATE_H
#define THREADONTERMINATE_H

//#include <iostream>
#include <PrimeData.h>

class ThreadOnTerminate
{
  public:
    ThreadOnTerminate();
    virtual ~ThreadOnTerminate();
    virtual void terminate(PrimeData*) {};
  protected:
  private:
};

#endif // THREADONTERMINATE_H
