//COMSC 210 | Lab 21 Goat Herder | Robert Stonemetz

#include <iostream>
#include <string>

using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class Goat {
    private:
        int age;
        string name;
        string color;
        static const string names[];
        static const string colors[];

    public:
        Goat() {
            age = rand() % 20 + 1;
            name = names[rand() % 15];
            color = colors[rand() % 15];
        }

        Goat(int a, string n, string c) : age(a), name(n), color(c) {}

        friend ostream& operator << (ostream& os, const Goat& goat) {
            os << goat.name << " (" << goat.color << ", " << goat.age << ")";

            return os;
        }
    bool operator==(const Goat& other) const {
        return (age == other.age && name == other.name && color == other.color);
    }
};

const string Goat :: names[] = {"Billy", "Nanny", "Gruff", "Daisy", "Pepper", 
                                "Snowball", "Buttercup", "Rocky", "Luna", "Charlie", 
                                "Bella", "Max", "Lucy", "Oreo", "Gizmo"};

const string Goat::colors[] = {"White", "Black", "Brown", "Gray", "Cream", "Tan", "Beige", 
                                "Spotted", "Speckled", "Patched", "Mottled", "Dappled", "Piebald", 
                                "Roan", "Tricolor"};



class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(const Goat& val, Node* p = nullptr, Node* n = nullptr) : 
            data(val), 
            prev(p), 
            next(n) {}
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(const Goat& value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(const Goat& value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(const Goat& value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void delete_node(const Goat& value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data == value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void print() {
        Node* current = head;
        cout << "List Forward: " << endl;
        if (!current) {
            cout << "\tList is empty" << endl;
            return;
        }
        while (current) {
            cout << "\t" << current->data << endl;;
            current = current->next;
        }
    }

    void print_reverse() {
        Node* current = tail;
        cout << "List backward:" << endl;
        if (!current) {
            cout << "\tList is empty" << endl;
            return;
        }
        while (current) {
            cout << "\t" << current->data << endl;
            current = current->prev;
        }
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    srand(time(0)); //randomnumber generator

    DoublyLinkedList list;

    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(Goat());

    cout << "List forward: \n";
    list.print();

    cout << "List backward: \n";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}