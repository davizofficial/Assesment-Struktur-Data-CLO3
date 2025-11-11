#include "sll.h"


address newElement(infotype data){
    address p = new Node;
    info(p) = data;
    next(p) = NIL;
    return p;
}

void createNewLList(List &a){
    first(a) = NIL;
}

bool isEmpty(List a){
    return first(a) == NIL;
}

//Silahkan uncomment untuk meja NIM ganjil
void insertFirst(List &a, address p){
    if (p == NIL) return;
    if (isEmpty(a)){
        first(a) = p;
        next(p) = NIL;
    } else {
        next(p) = first(a);
        first(a) = p;
    }
}

void insertAfter(List &a, infotype x, address p){
    if (p == NIL) return;
    address q = first(a);
    while (q != NIL){
        if (info(q).ID == x.ID){
            next(p) = next(q);
            next(q) = p;
            return;
        }
        q = next(q);
    }
}

void insertLast(List &a, address p){
    if (p == NIL) return;
    if (isEmpty(a)){
        first(a) = p;
        next(p) = NIL;
    } else {
        address q = first(a);
        while (next(q) != NIL){
            q = next(q);
        }
        next(q) = p;
        next(p) = NIL;
    }
}

void deleteFirst(List &a, address p){
    if (isEmpty(a)){
        p = NIL;
        return;
    }
    p = first(a);
    first(a) = next(p);
    next(p) = NIL;
}

void deleteLast(List &a, address p){
    if (isEmpty(a)){
        p = NIL;
        return;
    }
    if (next(first(a)) == NIL){
        p = first(a);
        first(a) = NIL;
        next(p) = NIL;
        return;
    }
    address q = first(a);
    while (next(next(q)) != NIL){
        q = next(q);
    }
    p = next(q);
    next(q) = NIL;
    next(p) = NIL;
}

int length(List a){
    int jml = 0;
    address p = first(a);
    while (p != NIL){
        jml++;
        p = next(p);
    }
    return jml;
}

address findElement(List a, infotype x){
    address p = first(a);
    while (p != NIL){
        if (info(p).ID == x.ID) return p;
        p = next(p);
    }
    return NIL;
}

void printList(List a){
    address p = first(a);
    if (p == NIL){
        cout << "List kosong." << endl;
        return;
    }
    while (p != NIL){
        cout << "[" << info(p).ID << ":" << info(p).username
             << ":" << info(p).like << ":" << info(p).unlike << "]";
        if (next(p) != NIL) cout << " -> ";
        p = next(p);
    }
    cout << endl;
}

void splitList(List a, List &oddList, List &evenList){
    createNewLList(oddList);
    createNewLList(evenList);
    address p = first(a);
    while (p != NIL){
        infotype d = info(p);
        address copy = newElement(d);
        if ((d.ID % 2) == 0) insertLast(evenList, copy);
        else insertLast(oddList, copy);
        p = next(p);
    }
}



void insertAscending(List &a, address p){
    if (p == NIL) return;
    if (isEmpty(a)){
        first(a) = p;
        next(p) = NIL;
        return;
    }
    if (info(p).ID < info(first(a)).ID){
        next(p) = first(a);
        first(a) = p;
        return;
    }
    address q = first(a);
    while (next(q) != NIL && info(next(q)).ID < info(p).ID){
        q = next(q);
    }
    next(p) = next(q);
    next(q) = p;
}

void printByUsername(List a, const string &username){
    address p = first(a);
    bool ada = false;
    while (p != NIL){
        if (info(p).username == username){
            cout << "[" << info(p).ID << ":" << info(p).username
                 << ":" << info(p).like << ":" << info(p).unlike << "] ";
            cout << info(p).content << endl;
            ada = true;
        }
        p = next(p);
    }
    if (!ada){
        cout << "Tidak ada postingan untuk username: " << username << endl;
    }
}

void printTopPopular(List a){
    if (isEmpty(a)){
        cout << "List kosong." << endl;
        return;
    }
    int maxLike = info(first(a)).like;
    address p = first(a);
    while (p != NIL){
        if (info(p).like > maxLike) maxLike = info(p).like;
        p = next(p);
    }
    cout << "Postingan terpopuler (like = " << maxLike << "):" << endl;
    p = first(a);
    while (p != NIL){
        if (info(p).like == maxLike){
            cout << "[" << info(p).ID << ":" << info(p).username
                 << ":" << info(p).like << ":" << info(p).unlike << "] ";
            cout << info(p).content << endl;
        }
        p = next(p);
    }
}


void updateLike(List &a, int ID, bool isLike){
    infotype key; key.ID = ID;
    address p = findElement(a, key);
    if (p == NIL){
        cout << "Posting dengan ID " << ID << " tidak ditemukan." << endl;
        return;
    }
    if (isLike){
        info(p).like = info(p).like + 1;
        if (info(p).unlike > 0) info(p).unlike = info(p).unlike - 1;
    } else {
        info(p).unlike = info(p).unlike + 1;
        if (info(p).like > 0) info(p).like = info(p).like - 1;
    }
    cout << "Update berhasil: ID " << ID
         << " -> like=" << info(p).like
         << ", unlike=" << info(p).unlike << endl;
}
