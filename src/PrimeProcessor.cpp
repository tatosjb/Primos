#include "PrimeProcessor.h"
#include <exception>
#include <unistd.h>

PrimeProcessor::PrimeProcessor()
{
  listeners = new std::vector<ThreadOnTerminate*>();
  kill = false;
}

PrimeProcessor::~PrimeProcessor()
{
    //dtor
}

bool inline PrimeProcessor::isPrimeNumber(int number){
//    bool result;
//
//    result = !(((
//        number%2 == 0 ||
//        number%3 == 0 ||
//        number%5 == 0 ||
//        number%7 == 0
//        ) &&
//        number > 1)
//        || number < 4
//        || number == 5
//        || number == 7);
//
//    if(!result)
//      result = interativeVerificationMethod(number);

    return interativeVerificationMethod(number);;
}

bool inline PrimeProcessor::interativeVerificationMethod(int number){
  if(number < 4 && number > 1)
    return true;

  int maxNumber = sqrt(number);
  maxNumber++;

  for(int i = 5; i < number; i = i+2){
    if(number%i == 0){
      return false;
    }
  }

  return true;
}

void PrimeProcessor::stop(){
  kill = true;
}

void PrimeProcessor::onTerminate(ThreadOnTerminate *t){
  listeners->push_back(t);
}

void PrimeProcessor::callListeners(PrimeData *data){
  for(int i = 0; i < listeners->size(); i++){
    (*listeners)[i]->terminate(data);
  }
}

void PrimeProcessor::verificaNumerosPrimos(int vBegin, int vEnd, PrimeData *data){
  start(vBegin, vEnd, data);
}

void inline PrimeProcessor::start(int vBegin, int vEnd, PrimeData *data){
  int greaterPrime = 0;
  int primesFound = 0;

  if(vBegin%2 == 0)
    vBegin++;

    for(int i = vBegin; i <= vEnd && !kill; i = i+2){
      if(isPrimeNumber(i)){
        greaterPrime = i;
        primesFound++;
      }
    }

    data->Incfound(primesFound);
    data->Setgreater(greaterPrime);

//    callListeners(data);
}
