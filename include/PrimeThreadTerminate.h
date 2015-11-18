#ifndef PRIMETHREADTERMINATE_H
#define PRIMETHREADTERMINATE_H

#include <ThreadOnTerminate.h>
#include <MyThread.h>

class PrimeThreadTerminate : public ThreadOnTerminate
{
  public:
    PrimeThreadTerminate();
    virtual ~PrimeThreadTerminate();
    void terminate(PrimeData*);
  protected:
  private:
};

#endif // PRIMETHREADTERMINATE_H
