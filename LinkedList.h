#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include<iostream>

struct Node{
    int data;
    struct Node*next;
};
class LinkedList {
private:
    Node * first;
    Node * second;
    Node * third;
public:
    LinkedList(){first= NULL;second= NULL;third= NULL;};
    LinkedList(int A[] , int n);
    ~LinkedList();

    void create(int A[] ,int n);
    void create2(int A[] , int n);
    void Display();
    void RDisplayed();
    void Insert(int index , int x);
    void Insert_(int index , int x);
    int Count(struct Node *p);
    int RCount();
    int Delete( int index );
    int Add();
    int RMax ();
    int Max();
    Node* Search(int key);
    Node* RSearch(int key);
    Node* ImproveSearch(int key);
    void SortedInsert(int x);
    int IsSorted();
    void RemoveDublicate();
    void Reverse1();
    void Reverse2();
    void RecersiveReverse(struct Node *q , struct Node *p);
    void concat();
    void Merge();
    bool IsLoop();
};


#endif //LINKEDLIST_LINKEDLIST_H
