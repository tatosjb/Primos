#include "PrimeData.h"

PrimeData::PrimeData()
{
  PrimeData::Setfound(0);
  PrimeData::Setgreater(0);
  PrimeData::Setrange(1000000);
  PrimeData::Setposition(0);
}

PrimeData::~PrimeData()
{
  //dtor
}

std::mutex a_lock;
void PrimeData::lock(){
  std::lock_guard<std::mutex> lock(a_lock);
}

void PrimeData::unlock(){
  std::lock_guard<std::mutex> lock(a_lock);
}

int PrimeData::Getposition() {
  lock();
  position += range;
  int value = position - range;
  unlock();
  return value;
}

void PrimeData::Setposition(int val) {
  lock();
  position = val;
  unlock();
}

int PrimeData::Getrange() {
  return range;
}

void PrimeData::Setrange(int val) {
  range = val;
}

int PrimeData::Getfound() {
  return found;
}

void PrimeData::Setfound(int val) {
  lock();
  found = val;
  unlock();
}

void PrimeData::Incfound(int val){
  lock();
  found += val;
  unlock();
}

int PrimeData::Getgreater() {
  return greaterValue;
}

void PrimeData::Setgreater(int val) {
  lock();
  if(val > greaterValue)
    greaterValue = val;
  unlock();
}
