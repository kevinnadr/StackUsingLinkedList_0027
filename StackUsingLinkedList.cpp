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

    // Peek/Top operation: Tampilkan semua isi stack
    void peek() {
        if (top == NULL) {                  // Cek apakah stack kosong
            cout << "List is empty." << endl;
        }
        else {
            Node* current = top;            // Mulai dari top
            while (current != NULL) {       // Selama node masih ada
                cout << current->data << " " << endl;  // Tampilkan data node
                current = current->next;    // Lanjut ke node berikutnya
            }
            cout << endl;
        }
    }

    // isEmpty operation: Cek apakah stack kosong
    bool isEmpty() {
        return top == NULL;                 // Jika top = NULL, maka stack kosong
    }
};

int main() {
    Stack stack;                            // Buat objek stack

    int choice = 0;                         // Menyimpan pilihan menu
    int value;                              // Menyimpan nilai input

    while (choice != 5) {                   // Looping menu hingga user memilih keluar
        cout << "1. Push\n";                // Tampilkan pilihan menu
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;                      // Input pilihan user

        switch (choice) {                   // Cek pilihan user
        case 1:
            cout << "Enter the value to push: ";
            cin >> value;                   // Input nilai
            stack.push(value);              // Panggil fungsi push
            break;

        case 2:
            if (!stack.isEmpty()) {         // Jika stack tidak kosong
                stack.pop();                // Hapus elemen paling atas
            }
            else {
                cout << "Stack is empty. Cannot pop." << endl;
            }
            break;

        case 3:
            if (!stack.isEmpty()) {         // Jika stack tidak kosong
                stack.peek();               // Tampilkan semua elemen
            }
            else {
                cout << "Stack is empty. No top value." << endl;
            }
            break;

        case 4:
            cout << "Exiting program." << endl;  // Keluar dari program
            break;

        default:
            cout << "Invalid choice. Try again." << endl; // Penanganan input yang salah
            break;
        }

        cout << endl;                       // Spasi antar iterasi menu
    }

    return 0;                               // Akhiri program
}
