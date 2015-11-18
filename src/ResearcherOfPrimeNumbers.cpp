#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "ResearcherOfPrimeNumbers.h"

#define THREADS 4

ResearcherOfPrimeNumbers::ResearcherOfPrimeNumbers()
{
    //ctor
}

ResearcherOfPrimeNumbers::~ResearcherOfPrimeNumbers()
{
    //dtor
}

void* ResearcherOfPrimeNumbers::search(void* data){
    int *range = (int*)data;
    std::cout << range[0];
    std::cout << range[1];
}

void ResearcherOfPrimeNumbers::research(float time){
    int range[2];
    range[0] = 1;
    range[1] = 2;

    pthread_t* t;

    t = pthread_create(t, NULL, ResearcherOfPrimeNumbers::search, (void *) &range);
}

