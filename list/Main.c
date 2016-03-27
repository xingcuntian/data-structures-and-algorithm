#include <stdio.h>
#include "List.h"

int main(int argc, char **argv) {

  // test NewList
  LIST TestNewList = NewList();
  int TestNewListResult = TestNewList->Tail == NULL && 
                         (int)TestNewList->Head == (int)&TestNewList->Tail &&
                         (int)TestNewList->LastNode == (int)&TestNewList->Head;
  printf("'TestNewList' is pass ? %d \n", TestNewListResult);

  // test GetTail
  NODE TestTailItem = GetTail(TestNewList);
  int TestGetTailResult = TestNewList->LastNode == TestTailItem;
  printf("'GetTail' is pass ? %d \n", TestGetTailResult);
 
  // test GetHead
  NODE TestGetHeadItem = GetHead(TestNewList);
  int TestGetHeadResult = TestNewList->Head == TestGetHeadItem;
  printf("'GetHead' is pass ? %d \n", TestGetHeadResult);

  // test IsEmpty
  printf("'IsEmpty' is pass ? %d \n", IsEmpty(TestNewList));

  // test Prepend
  NODE TestPrependItem = malloc(sizeof(NODE));
  Prepend(TestNewList, TestPrependItem);
  printf("'Prepend' is pass ? %d \n", TestNewList->Head == TestPrependItem && 
                                      TestPrependItem->Pred->Succ == TestPrependItem);

  // test Append
  NODE TestAppendItem = malloc(sizeof(NODE));
  Append(TestNewList, TestAppendItem);
  printf("'Append' is pass ? %d \n", TestAppendItem->Succ->Pred == TestAppendItem && 
                                     TestNewList->Tail == NULL);

  // test DeleteHead
  NODE TestDeleteHeadItem = TestNewList->Head;
  printf("'DeleteHead&Shift' is pass ? %d \n", TestDeleteHeadItem == DeleteHead(TestNewList) && 
                                         TestDeleteHeadItem->Succ == TestNewList->Head &&
                                         TestDeleteHeadItem->Pred->Succ == TestNewList->Head);

  // test DeleteTail
  NODE TestDeleteTailItem = TestNewList->LastNode;
  printf("'DeleteTail&Pop' is pass ? %d \n", TestDeleteTailItem == DeleteTail(TestNewList) && 
                                         TestDeleteTailItem->Succ == (NODE)&TestNewList->Tail &&
                                         TestDeleteTailItem->Succ->Pred == TestNewList->LastNode);
  // test InsertAfter
  Append(TestNewList, TestDeleteTailItem);
  Append(TestNewList, TestDeleteHeadItem);
  NODE TestInsertAfterItem = malloc(sizeof(NODE));
  InsertAfter(TestNewList, TestDeleteTailItem, TestInsertAfterItem);
  printf("'InsertAfter' is pass ? %d \n", TestInsertAfterItem->Pred == TestDeleteTailItem && 
                                          TestInsertAfterItem->Succ == TestDeleteHeadItem);

  // test DeleteNode
  NODE TestDeleteNodeItem = DeleteNode(TestNewList, TestInsertAfterItem);
  printf("'DeleteNode' is pass ? %d \n", TestDeleteTailItem->Succ != TestDeleteNodeItem && 
                                         TestDeleteHeadItem->Pred != TestDeleteNodeItem);

  // test Push
  NODE TestPushItem = malloc(sizeof(NODE));
  Push(TestNewList, TestPushItem);
  printf("'Push' is pass ? %d \n", TestNewList->LastNode == TestPushItem);

  // test Length
  printf("'Length' is pass ? %d \n", Length(TestNewList) == 3 );
  return 0 ;
}
