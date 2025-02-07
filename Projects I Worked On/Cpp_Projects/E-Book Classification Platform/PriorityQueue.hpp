#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>

using namespace std;

template <typename T>
class Queue {
private:
    struct Item {
        T value;
        Item *next;
    };

    Item *first;
    Item *last;
    int _size;

    // Método privado auxiliar para copiar items
    void copyItems(const Item *item, Item *(&first), Item *(&last), int &_size) {
        if (item == nullptr) {
            first = last = nullptr;
            _size = 0;
            return;
        }
        first = new Item{item->value, nullptr};
        last = first;
        _size = 1;
        const Item *current = item->next;
        while (current != nullptr) {
            last->next = new Item{current->value, nullptr};
            last = last->next;
            current = current->next;
            _size++;
        }
    }

    // Método privado auxiliar para eliminar items
    void deleteItems(Item *item) {
        while (item != nullptr) {
            Item *temp = item;
            item = item->next;
            delete temp;
        }
    }

public:
    // Constructor por defecto
    Queue() : first(nullptr), last(nullptr), _size(0) {}

    // Constructor de copia (acepta referencia constante)
    Queue(const Queue &q) { // Cambio: aceptar referencia constante
        copyItems(q.first, first, last, _size);
    }

    // Destructor
    ~Queue() {
        deleteItems(first);
    }

    // Operador de asignación (acepta referencia constante)
    Queue &operator=(const Queue &q) { // Cambio: aceptar referencia constante
        if (this != &q) {
            deleteItems(first);
            copyItems(q.first, first, last, _size);
        }
        return *this;
    }

    // Métodos modificadores
    void pop() {
        if (first == nullptr) return;
        Item *temp = first;
        first = first->next;
        if (first == nullptr) last = nullptr;
        delete temp;
        _size--;
    }

    void push(const T &value) {
        Item *newItem = new Item{value, nullptr};
        if (last != nullptr) {
            last->next = newItem;
        } else {
            first = newItem;
        }
        last = newItem;
        _size++;
    }

    void remove(const T &value) {
        if (first == nullptr) {
            std::cerr << "Error: remove on empty queue" << std::endl;
            return;
        }

        Item *current = first;
        Item *previous = nullptr;

        while (current != nullptr && !(current->value == value)) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cerr << "Error: value not found in queue" << std::endl;
            return;
        }

        if (previous == nullptr) {
            first = first->next;
            if (first == nullptr) last = nullptr;
        } else {
            previous->next = current->next;
            if (current == last) last = previous;
        }

        delete current;
        _size--;
    }

    // Métodos consultores
    T front() const {
        if (first == nullptr) throw runtime_error("Queue is empty");
        return first->value;
    }

    int size() const {
        return _size;
    }

    bool empty() const {
        return first == nullptr;
    }

    // Lectura y escritura
    template<typename U> friend ostream &operator<<(ostream &os, Queue<U> &q);
    template<typename U> friend istream &operator>>(istream &is, Queue<U> &q);
};

#endif

