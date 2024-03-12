#include "LinkedList.h"
#include <bits/stdc++.h>
using namespace std;
#define NULL nullptr
void LinkedList::create(int A[] ,int n){
    int i;
    struct Node *t ,*last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i=1 ; i<n ; i++) {
        t=new Node;
        t->data = A[i];
        t->next = NULL;
        last -> next =t;
        last = t;
    }
}
LinkedList::~LinkedList(){
    Node*p = first;
    while(first){
        first = first->next;
        delete p;
        p=first;
    }
}
void LinkedList::Display() {
    Node *p =first;
    while(p!= NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
void LinkedList::Insert(int index, int x) {
    struct Node*p=first;
    struct Node *t;
    int i;
    if(index <0 || index > Count(p))
        return;
    t= new Node;
    t->data = x;
    if(index == 0){
        t->next = first;
        first = t;
    }
    else{
        for(i=0 ; i<index-1 ; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
int LinkedList::Count(struct Node *p) {
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
int LinkedList::Delete( int index) {
    Node*p=first;
    struct Node *q =NULL;
    int x=-1,i;
    if(index <1 ||index>Count(p) ){
        return -1;
    }
    if (index ==1){
        q=first;
        x=first->data;
        first = first->next;
        delete q;
        return x;
    }
    else{
        for(i=0 ; i<index-1 ; i++){
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

void LinkedList::RDisplayed(){
    Node*p=first;
    if(p!= NULL ){
        cout<<p->data<<" ";
        RDisplayed();
    }
}

/*int LinkedList::RCount() {
    struct Node*p=first;
    if (p==NULL)
        return 0;
    else
        return RCount(p->next)+1;
}*/

int LinkedList::Add() {
    struct Node*p=first;
    int sum=0;
    while(p){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

/*int LinkedList::RMax() {
    int x=0;
    struct Node*p=first;
    if (p==NULL)
        return INT16_MIN;
    x= RMax(p->next);
    return x>p->data ? x : p->data;
}*/
int LinkedList::Max(){
    struct Node*p=first;
    int max =INT16_MIN;
    while(p){
        if (p->data > max)
            max = p->data;
        p=p->next;
    }
    return max;
}

void LinkedList::Insert_( int index, int x) {
    struct Node*p=first;
    struct Node *t;
    int i;
    if(index <0 || index > Count(p))
        return;
    t= new Node;
    t->data = x;
    if(index == 0){
        t->next = first;
        first = t;
    }
    else{
        for(i=0 ; i<index-1 ; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

Node *LinkedList::Search(int key) {
    struct Node*p=first;
    while(p!= NULL){
        if (p->data == key)
            return p;
        p=p->next;
    }
    return NULL;
}

/*Node *LinkedList::RSearch(struct Node *p, int key) {
    if (p== NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RSearch(p->next , key);
}*/

Node *LinkedList::ImproveSearch(int key) {
    struct Node*p=first;
    struct Node *q ;
    while(p!=NULL){
        if(key== p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void LinkedList::SortedInsert(int x) {
    struct Node*p=first;
    struct Node *t,*q=NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if(first == NULL)
        first=t;
    else{
        while (p && p->data < x){
            q=p;
            p = p->next;
        }
        if(p==first){
            t->next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

int LinkedList::IsSorted() {
    struct Node*p=first;
    int x = -65536;
    while(p!=NULL){
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;}

void LinkedList::RemoveDublicate() {
    struct Node*p=first;
    struct Node *q= p->next;
    while(q!=NULL){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q=p->next;
        }
    }
}

void LinkedList::Reverse1() {
    struct Node*p=first;
    int *A , i=0;
    struct Node *q=p;
    A = (int *) malloc(sizeof(int)*Count(p));
    while(q!=NULL){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data = A[i];
        q=q->next;
        i--;
    }
}

void LinkedList::Reverse2() {
    struct Node*p=first;
    struct Node *q = NULL , *r =NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
}

void LinkedList::RecersiveReverse(struct Node *q, struct Node *p) {
    if(p){
        RecersiveReverse(p , p->next);
        p->next =q;
    }
    else
        first = q;
}

void LinkedList::concat() {
    struct Node*p=first;
    struct Node*q=second;
    third = p;
    while(p->next != NULL){
        p=p->next;
    }
    p->next =q;
}

void LinkedList::Merge() {
    struct Node*p=first;
    struct Node*q=second;
    struct Node *last;
    if(p->data < q->data){
        third = last =p;
        p=p->next ;
        third->next = NULL;
    }
    else{
        third = last =q;
        q=q->next ;
        third->next = NULL;
    }
    while(p&&q){
        if(p->data < q->data){
            last->next = p;
            last =p;
            p=p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last =q;
            q=q->next;
            last->next = NULL;
        }
    }
    if(p)last->next =p;
    if(q)last->next=q;
}

bool LinkedList::IsLoop() {
    struct Node*p,*q;
    struct Node*f=first;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q ? q->next : NULL;
    } while (p && q && p!=q);
    if(p==q)
        return true;
    else
        return false;
}

void LinkedList::create2(int *A, int n) {
    int i;
    struct Node *t ,*last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = first;
    for (i=1 ; i<n ; i++) {
        t=new Node;
        t->data = A[i];
        t->next = NULL;
        last -> next =t;
        last = t;
    }
}
