// test lock
/*
Expected output:
thread2 called
thread1 called
thread2 called
Thread library exiting.
*/
#include <stdlib.h>
#include <iostream>
#include "thread.h"
#include <assert.h>
using namespace std;

static unsigned int lock1 = 1;

void thread2(void* arg){
  thread_lock(lock1);
  cout << "thread2 called" << endl;
  thread_unlock(lock1);
}

void thread1(void* arg) {
  thread_lock(lock1);
  thread2(NULL);
  thread_unlock(lock1);
  cout << "thread1 called" << endl;
}

void thread0(void* arg){
  thread_create(thread1, NULL);
  thread_create(thread2, NULL);
}

int main(int argc, char* argv[]){
  thread_libinit(thread0, NULL);
}
