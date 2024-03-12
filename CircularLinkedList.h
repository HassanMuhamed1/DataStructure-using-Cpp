#ifndef LINKEDLIST_CIRCULARLINKEDLIST_H
#define LINKEDLIST_CIRCULARLINKEDLIST_H
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
};
class CircularLinkedList {
private:
    Node *Head;
public:
    CircularLinkedList(){Head=NULL;}
    void Create (int A[] , int n);
    void Display(Node *h);
    int Count(struct Node *p);//doesn't work
    void Insert(int index , int x);//doesn't work
    int Delete(int index);//doesn't work

};

#endif //LINKEDLIST_CIRCULARLINKEDLIST_H
