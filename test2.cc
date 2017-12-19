// basic test of libinit, create, and yield
#include <stdlib.h>
#include <iostream>
#include "thread.h"
#include <assert.h>
using namespace std;

void thread1(void* arg) {
  if (thread_yield()){
    cout << "thread_yield failed" << endl;
    exit(1);
  }
  char* input = (char*) arg;
  cout << "thread1 called with input " << input << endl;
}

void thread2(void* arg){
  cout << "thread2 called with no input" << endl;
}

void thread0(void* arg){
  int input = *(int*) arg;
  cout << "thread0 called with input " << input << endl;
  if (thread_create(thread1, (char*)("1234"))) {
    cout << "thread_create failed" << endl;
    exit(1);
  }
  if (thread_create(thread2, NULL)) {
    cout << "thread_create failed" << endl;
    exit(1);
  }
  cout << "thread0 finished" << endl;
}

int main(int argc, char* argv[]){
  int input = 1234;
  if (thread_libinit(thread0, &input)){
    cout << "thread_libinit failed" << endl;
    exit(1);
  }
}
