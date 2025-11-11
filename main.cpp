#include "sll.h"
#include <iostream>
using namespace std;

int main(){
    cout << "Nama   : Davis Arvaputra Dwiansyah" << endl;
    cout << "NIM    : 103122400034" << endl;
    cout << "Kelas  : SE-08-01" << endl << endl;

    // buat list kosong
    List L;
    createNewLList(L);

    // tambahkan data contoh
    infotype a, b, c;
    a.ID = 1; a.content = "Selamat datang di MyTelU"; a.like = 10; a.unlike = 0; a.username = "admin";
    b.ID = 3; b.content = "Pengumuman UTS minggu depan"; b.like = 7; b.unlike = 1; b.username = "dosen";
    c.ID = 5; c.content = "Event coding competition"; c.like = 12; c.unlike = 0; c.username = "hmti";

    insertLast(L, newElement(a));
    insertLast(L, newElement(b));
    insertLast(L, newElement(c));

    cout << "Data awal:" << endl;
    printList(L);
    cout << endl;

    // a. tambah posting secara ascending
    infotype d;
    d.ID = 2; d.content = "Halo mahasiswa TelU"; d.like = 0; d.unlike = 0; d.username = "budi";
    insertAscending(L, newElement(d));

    cout << "Setelah insertAscending(ID=2):" << endl;
    printList(L);
    cout << endl;

    // b. tampilkan posting berdasarkan username
    cout << "Posting dengan username 'budi':" << endl;
    printByUsername(L, "budi");
    cout << endl;

    // c. tampilkan posting terpopuler
    cout << "Posting terpopuler:" << endl;
    printTopPopular(L);
    cout << endl;

    // d. ubah jumlah like dan unlike
    cout << "Like posting ID=2:" << endl;
    updateLike(L, 2, true);

    cout << "Unlike posting ID=1:" << endl;
    updateLike(L, 1, false);
    cout << endl;

    // tampilkan hasil akhir
    cout << "Data akhir:" << endl;
    printList(L);
    cout << endl;

    cout << "Program selesai." << endl;
    return 0;
}