#ifndef PRIMEDATA_H
#define PRIMEDATA_H
#include <mutex>
#include <thread>


class PrimeData
{
  public:
    PrimeData();
    virtual ~PrimeData();

    int Getposition();

    void Setposition(int);

    int Getrange();

    void Setrange(int);

    int Getfound();

    void Setfound(int);

    void Incfound(int);

    int Getgreater();

    void Setgreater(int);

  private:
    int position;
    int range;
    int found;
    int greaterValue;
    void lock();
    void unlock();
};

#endif // PRIMEDATA_H
