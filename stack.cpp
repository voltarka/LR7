#include <iostream>

struct Node
{
    Node* previous = nullptr;
    int information = 0;
};

struct Stack
{
    Node* end;
    unsigned int size;
};

void constructor (Stack& stack) { // инциализация полей структуры
stack.end = nullptr;
stack.size = 0;
}

unsigned int size (Stack& stack) {
    unsigned int count = 0;
    Node* node = stack.end;
    while (node != nullptr) {
        node = node-> previous;
        count ++;
    }
    return count;
}

void push (Stack& stack, Node& node) {
    Node* element = new Node;
    element-> information = node.information;
    element->previous = stack.end;
    stack.end = element;
}

Node& pop (Stack& stack) {
    Node* node = stack.end;
    stack.end = stack.end->previous;
    return *node;
}

void print (Stack& stack) {
    for (auto i = stack.end; i != nullptr; i = i->previous ) {
        std::cout << i->information << ' ';
    }
}

void destructor (Stack& stack) { // очищает исп. область памяти
    while (stack.size != 0) {
        Node* used = stack.end;
        stack.end = stack.end -> previous;
        delete used;
        stack.size --;

    }
    std::cout << "Memory is cleared, job is done.";
}

int main() {
Stack stack;
constructor (stack);
for (int i = 0 ;i < 10; i++) {
    Node node;
    node.information = i;
    push (stack, node);
}
print (stack);
std::cout << std::endl;
std::cout << "Size of stack is: " << size(stack) << std::endl;
Node node = pop (stack);
std::cout << "Popped element is: " << node.information;
std::cout << std::endl;
print (stack);
std::cout << std::endl;
destructor(stack);
return 0;
}
