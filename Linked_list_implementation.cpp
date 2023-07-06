#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void pushFront(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void pushBack(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    const T& front() const {
        if (isEmpty()) {
            throw std::runtime_error("LinkedList is empty.");
        }
        return head->data;
    }

    const T& back() const {
        if (isEmpty()) {
            throw std::runtime_error("LinkedList is empty.");
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        return current->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<int> list;

    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;

    list.pushFront(5);

    std::cout << "Front after pushFront: " << list.front() << std::endl;
    std::cout << "Back after pushFront: " << list.back() << std::endl;

    list.clear();

    return 0;
}
