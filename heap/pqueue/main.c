#include <stdio.h>
#include "pqueue.h"

static int _match (const void *key1, const void *key2) {
  return (* (int *)key1) - (* (int *)key2);
}

int main (int argc, char **argv) {
  Heap *testHeap1 = (PQueue *)malloc(sizeof(PQueue));
  int testData1 = 90;
  int testData2 = 80;
  int testData3 = 70;
  int testData4 = 60;
  int testData5 = 40;
  int testData6 = 30;
  int testData7 = 20;
  int testData8 = 10;
  int testData9 = 50;
  int testData10 = 85;
  void *testPtr1;
  // test pqueue_init
  pqueue_init(testHeap1, _match, NULL);
  printf("'pqueue_init' is pass ? %d \n", testHeap1->size == 0 &&
                                        testHeap1->tree == NULL);
  // test pqueue_insert
  testPtr1 = &testData1;
  pqueue_insert(testHeap1, testPtr1);
  testPtr1 = &testData2;
  pqueue_insert(testHeap1, testPtr1);
  testPtr1 = &testData3;
  pqueue_insert(testHeap1, testPtr1);
  testPtr1 = &testData4;
  pqueue_insert(testHeap1, testPtr1);
  testPtr1 = &testData5;
  pqueue_insert(testHeap1, testPtr1);
  testPtr1 = &testData6;
  pqueue_insert(testHeap1, testPtr1);
  testPtr1 = &testData7;
  pqueue_insert(testHeap1, testPtr1);
  testPtr1 = &testData8;
  pqueue_insert(testHeap1, testPtr1);
  testPtr1 = &testData9;
  pqueue_insert(testHeap1, testPtr1);
  testPtr1 = &testData10;
  pqueue_insert(testHeap1, testPtr1);

  printf("'pqueue_insert' is pass ? %d \n", testHeap1->size == 10 &&
                                          *(int *)testHeap1->tree[0] == 90 &&
                                          *(int *)testHeap1->tree[1] == 85 &&
                                          *(int *)testHeap1->tree[2] == 70 &&
                                          *(int *)testHeap1->tree[3] == 60 &&
                                          *(int *)testHeap1->tree[4] == 80 &&
                                          *(int *)testHeap1->tree[5] == 30 &&
                                          *(int *)testHeap1->tree[6] == 20 &&
                                          *(int *)testHeap1->tree[7] == 10 &&
                                          *(int *)testHeap1->tree[8] == 50 &&
                                          *(int *)testHeap1->tree[9] == 40);
  
  // test pqueue_extract
  pqueue_extract(testHeap1, &testPtr1);
  printf("'pqueue_extract' is pass ? %d \n", testHeap1->size == 9 &&
                                          *(int *)testPtr1 == 90 &&
                                          *(int *)testHeap1->tree[0] == 85 &&
                                          *(int *)testHeap1->tree[1] == 80 &&
                                          *(int *)testHeap1->tree[2] == 70 &&
                                          *(int *)testHeap1->tree[3] == 60 &&
                                          *(int *)testHeap1->tree[4] == 40 &&
                                          *(int *)testHeap1->tree[5] == 30 &&
                                          *(int *)testHeap1->tree[6] == 20 &&
                                          *(int *)testHeap1->tree[7] == 10 &&
                                          *(int *)testHeap1->tree[8] == 50);


  // test pqueue_destory
  pqueue_destory(testHeap1);
  printf("'pqueue_destory' is pass ? %d \n", heap_size(testHeap1) == 0);
  
  free(testHeap1);
  return 0;
}
