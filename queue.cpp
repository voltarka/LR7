#include <iostream>

struct Node
{
    int information = 0;
    Node* next = nullptr;
};

struct Queue  // создание очереди
{
    Node* begin;
    Node* end;
    unsigned int size = 0;
};

void constructor(Queue& queue)  // функция инициализирует поля структуры когда она создается
{
    queue.begin = nullptr;
    queue.end = nullptr;
    queue.size = 0;
}

void push(Queue& queue, Node& node) { // добавляем элемент
    queue.size++;
    Node* element = new Node;
    element->information = node.information;
    if (queue.begin == nullptr) {
        queue.begin = element;
    } else {
        queue.end->next = element;
    }
    queue.end = element;
}

unsigned int size(Queue& queue)   // считаем кол-во элементов в структуре
{
    unsigned int count = 0;
    Node* node = queue.begin;
    while (node != nullptr) {
        node = node -> next;
        count ++;
    }
    return count;
}

int pop(Queue& queue) {  // удаляем элемент
    queue.size--;
    int k;
    Node* node = queue.begin;
    k = queue.begin-> information;
    queue.begin = queue.begin->next;
    delete node;
    return k;
}

void print( Queue& queue)    // напечатать элементы
{
    Node* node = queue.begin;
    for (auto i = queue.begin; i != nullptr; i = i->next) {
        std::cout << node->information << ' ';
        node = node->next;
    }
}

void destructor (Queue& queue) {  // функция очищает память задействованную под структуру
    while (queue.size != 0) {
        Node* used = queue.begin;
        queue.begin = queue.begin -> next;
        delete used;
        queue.size --;
    }
    std::cout << "Memory is cleared, job is done.";
}

int main() {
    Queue queue;
    constructor (queue);
    for (int i = 0; i < 10; i++)
    {
        Node node;
        node.information = i;
        push(queue, node);
    }
    print (queue);
    std::cout << std::endl;
    std::cout << "Size of queue is: " << size(queue) << std::endl;
    int node = pop (queue);
    std::cout << "Popped element is: " << node;
    std::cout << std::endl;
    print (queue);
    std::cout << std::endl;
    destructor(queue);
    return 0;
}
