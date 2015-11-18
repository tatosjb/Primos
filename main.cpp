#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <math.h>
#include <vector>
#include <PrimeProcessor.h>
#include <MyThread.h>
#include <PrimeThreadTerminate.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

#define NUCLEOS 4

//void processa(int vBegin, int vEnd, PrimeData *data, PrimeProcessor *processor){
//  processor->verificaNumerosPrimos(vBegin, vEnd, data);
//}

int main()
{
  PrimeData *data = new PrimeData();

  PrimeProcessor *primeProcessor = new PrimeProcessor();
  primeProcessor->onTerminate(new PrimeThreadTerminate());

  vector<MyThread*> *threads = new vector<MyThread*>;
  for(int i = 0; i < NUCLEOS; i++){
    threads->push_back(new MyThread());
  }

  cout<<"Comecou"<<endl;
  struct timeval inicio, fim;
  int tmili = 0;
  gettimeofday(&inicio, NULL);

  for(int i = 0; i < threads->size(); i++){
    (*threads)[i]->join(primeProcessor, data);
  }

  while(tmili < 60000){

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    gettimeofday(&fim, NULL);
    tmili = (int) (1000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000);

    for(int i = 0; i < threads->size(); i++){
      if(!(*threads)[i]->isActive())
        (*threads)[i]->join(primeProcessor, data);
    }
  }

  for(int i = 0; i < threads->size(); i++){
    (*threads)[i]->terminate();
  }

  cout<<"Processando resultados"<<endl;
  sleep(5);
  cout<<"------------------------------"<<endl;
  cout<<"------------RESULTADO---------"<<endl;
  cout<<"------------------------------"<<endl;
  cout << "Encontrados: " << data->Getfound() << " Maior: " << data->Getgreater() << endl;
}


