#include <iostream>     
using namespace std;                   

class Node {
public:
    int data;                               // Menyimpan nilai data
    Node *next;                             // Pointer ke node berikutnya dalam list

    Node()                                  // Constructor Node
    {
        next = NULL;                        // Inisialisasi pointer next ke NULL
    }
};

