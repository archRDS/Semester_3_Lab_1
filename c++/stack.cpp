#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// Стек хранит ссылку на верхний элемент; первым удаляется последний добавленный.
struct StackNode {
    string value;
    StackNode* next = nullptr;
};

struct Stack {
    StackNode* top = nullptr;
};

Stack* stackCreate() {
    return new Stack;
}

void stackDestroy(Stack* stack) {
    while (stack->top != nullptr) {
        StackNode* next = stack->top->next;
        delete stack->top;
        stack->top = next;
    }
    delete stack;
}

// Добавляет элемент на вершину стека.
void stackPush(Stack* stack, const string& value) {
    stack->top = new StackNode{value, stack->top};
}

string stackGet(const Stack* stack) {
    if (stack->top == nullptr) throw runtime_error("stack is empty");
    return stack->top->value;
}

// Снимает элемент с вершины и возвращает его значение.
string stackPop(Stack* stack) {
    string value = stackGet(stack);
    StackNode* old = stack->top;
    stack->top = old->next;
    delete old;
    return value;
}

vector<string> stackValues(const Stack* stack) {
    vector<string> result;
    for (StackNode* node = stack->top; node != nullptr; node = node->next) {
        result.push_back(node->value);
    }
    return result;
}
