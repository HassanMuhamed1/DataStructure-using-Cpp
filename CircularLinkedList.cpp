//
// Created by hassa on 3/11/2024.
//

#include "CircularLinkedList.h"

void CircularLinkedList::Create(int *A, int n) {
        int i;
        struct Node *t ,*last;
        Head = new Node;
        Head->data = A[0];
        Head->next = NULL;
        last = Head;
        for (i=1 ; i<n ; i++) {
            t=new Node;
            t->data = A[i];
            t->next = last->next;
            last -> next =t;
            last = t;
        }
    }

void CircularLinkedList::Display(Node *h) {

        do{
            cout<<h->data;
            h=h->next;
        }while(h!=Head);
        cout<<'\n';
    }

int CircularLinkedList::Count(struct Node *p) {
    int len=0;
    do
    {
        len++;
        p = p->next;
    } while (p!=Head);
    return len;
}

void CircularLinkedList::Insert(int index, int x) {
    struct Node *p=Head;
    Node *t;
    int i;
    if(index < 0 || index >Count(Head))
        return;
    if(index == 0){
        t=new Node;
        t->data = x;
        if(Head == NULL){
            Head  =t;
            Head->next = Head;
        }
        else{
            while (p->next != Head) p=p->next;
            p->next = t;
            t->next = Head;
            Head =t;
        }
    }
    else{
        for (i = 0; i <index-1; i++)p=p->next;
        t=new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int CircularLinkedList::Delete(int index) {
    struct Node *q;
    struct Node *p=Head;
    int x;
    if(index==1){
        while (p->next!=Head)
            p=p->next;
        x=Head->data;
        if(Head==p){
            delete []Head;
            Head = NULL;
        }
        else{
            p->next = Head->next;
            delete[] Head;
            Head=p->next;
        }
    }
    else{
        for(int i=0;i<index-2 ; i++)
            p=p->next;
        q=p->next;
        p->next = q->next;
        x=q->data;
        delete []q;
    }
    return x;
}
