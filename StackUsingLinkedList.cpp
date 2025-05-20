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

// Stack class
class Stack {
private:
    Node *top;                              // Pointer ke elemen paling atas dalam stack

public:
    Stack() {
        top = NULL;                         // Stack awalnya kosong (top = NULL)
    }

    // Push operation: Insert an element onto the top of the stack
    int push(int value) {
 