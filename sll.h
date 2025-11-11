#ifndef SLL_H
#define SLL_H

#include <iostream>
#include <stdlib.h>
#include <string>

#define first(L) (L).first
#define next(P) (P)->next
#define info(P) (P)->info
#define NIL NULL

using namespace std;

//deklarasi struct infotype
typedef struct Infotype {
    int ID;
    string content;
    int like;
    int unlike;
    string username;
} infotype;

//deklarasi struct linked list
typedef struct Node *address;
typedef struct Node {
    infotype info;
    address next;
} Node;

typedef struct {
    address first;
} List;

//deklarasi subprogram (sesuai template)
address newElement(infotype data);
void createNewLList(List &a);
bool isEmpty(List a);
void insertFirst(List &a, address p);
void insertAfter(List &a, infotype x, address p);
void insertLast(List &a, address p);
void deleteFirst(List &a, address p);
void deleteLast(List &a, address p);
int length(List a);
address findElement(List a, infotype x);
void printList(List a);

//deklarasi subprogram split list
void splitList(List a, List &oddList, List &evenList);

// deklarasi fungsi untuk soal a-d
void insertAscending(List &a, address p);                   
void printByUsername(List a, const string &username);         
void printTopPopular(List a);                                 
void updateLike(List &a, int ID, bool isLike);                

#endif 
