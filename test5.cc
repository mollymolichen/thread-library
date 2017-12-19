/*
 * test_create.cc-- test thread_create().
 * 
 * Compile with g++ -o test_create thread.cc test_create.cc libinterrupt.a -ldl
*/

#include <stdio.h>
#include <stdlib.h>  
#include "thread.h"
#include <iostream>

using namespace std;

// declare method headers
void thread1(void* args);
void thread2(void* args);
void thread3(void* args);

// first/master thread
void thread1(void* a){
	cout << "First thread created.\n" << endl;
}

void thread2(void* a){
	cout << "Second thread created.\n" << endl;
}

void thread3(void* a){
	cout << "Third thread created.\n" << endl;
}

// test thread_init()
int main(int argc, char* argv[]){
	thread_libinit(thread1, 0);
	
	thread_create(thread2, 0);
	thread_create(thread3, 0);

	return 0;
}