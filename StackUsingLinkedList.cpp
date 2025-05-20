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
        Node* newNode = new Node();         // 1. Buat node baru secara dinamis
        newNode->data = value;              // 2. Isi node baru dengan nilai yang diberikan
        newNode->next = top;                // 3. Sambungkan node baru ke node teratas saat ini
        top = newNode;                      // 4. Jadikan node baru sebagai top baru
        cout << "Push value: " << value << endl;
        return value;                       // Kembalikan nilai yang dimasukkan
    }

    // Pop operation: Remove the topmost element from the stack
    void pop() {
        if (isEmpty()) {                    // Cek apakah stack kosong
            cout << "Stack is empty." << endl;
            return;                         // Berhenti jika kosong (tambah return untuk mencegah error)
        }
        cout << "Popped value: " << top->data << endl;  // Tampilkan data yang akan di-pop
        top = top->next;                    // Pindahkan pointer top ke node berikutnya (hapus top lama)
    }
