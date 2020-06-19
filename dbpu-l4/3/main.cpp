#include <pthread.h>
#include <iostream>
#include <chrono>
using namespace std;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
long wynik = 0;
void *count(void *param) {
  //pthread_mutex_lock(&m); 
   for (int i = 0; i < 5000000; i++) {
        cout<<wynik<<endl;
	    wynik++;
    }
  //pthread_mutex_unlock(&m); 
    return NULL;
}

int main() {
    pthread_t th1,th2;
    pthread_create(&th1, NULL, count, NULL);
    pthread_create(&th2, NULL, count, NULL);
    auto t1 = chrono::high_resolution_clock::now();
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(t2 - t1).count();
    cout<<"Wynik: "<<wynik<<" Czas: "<<duration<<" s"<<endl;
    return 0;
}
