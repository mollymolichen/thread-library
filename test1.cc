#include <stdlib.h>
#include <iostream>
#include "thread.h"
#include <assert.h>
using namespace std;

// Test 1
// see if methods are called before init()
// see if init() is called with improper arguments
// see if init() is called more than once

void thread(void* arg){

}

int main(int argc, char* argv[]){
  if (thread_create(thread, NULL)){
    cout << "thread_libinit must be called first" << endl;
  }
  if (thread_yield()){
    cout << "thread_libinit must be called first" << endl;
  }
  if (thread_lock(0)){
    cout << "thread_libinit must be called first" << endl;
  }
  if (thread_unlock(0)){
    cout << "thread_libinit must be called first" << endl;
  }
  if (thread_wait(0, 0)){
    cout << "thread_libinit must be called first" << endl;
  }
  if (thread_signal(0, 0)){
    cout << "thread_libinit must be called first" << endl;
  }
  if (thread_broadcast(0, 0)){
    cout << "thread_libinit must be called first" << endl;
  }
  if (thread_libinit(NULL, NULL)){
    cout << "function passed to thread_libinit cannot be NULL" << endl;
  }
  cout << thread_libinit(thread, NULL) << endl;
  cout << thread_libinit(thread, NULL) << endl;
  cout << "this message should not appear if thread_libinit exited correctly" << endl;
}
