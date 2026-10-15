#include <stdexcept>
#include "DoubleList.h"

using namespace std;

DoubleList* doubleCreate() {
    return new DoubleList;
}

void doubleDestroy(DoubleList* list) {
    while (list->head != nullptr) {
        DoubleNode* next = list->head->next;
        delete list->head;
        list->head = next;
    }
    delete list;
}

int doubleSize(const DoubleList* list) {
    return list->size;
}

DoubleNode* doubleAt(const DoubleList* list, int index) {
    if (index < 0 || index >= list->size) throw runtime_error("index out of range");
    DoubleNode* node = list->head;
    for (int i = 0; i < index; i++) node = node->next;
    return node;
}

// Вставляет узел и обновляет связи с соседними узлами.
void doubleInsert(DoubleList* list, int index, const string& value) {
    if (index < 0 || index > list->size) throw runtime_error("index out of range");
    DoubleNode* node = new DoubleNode{value};
    if (index == list->size) {
        node->prev = list->tail;
        if (list->tail == nullptr) list->head = node;
        else list->tail->next = node;
        list->tail = node;
    } else {
        DoubleNode* after = doubleAt(list, index);
        node->next = after;
        node->prev = after->prev;
        if (after->prev == nullptr) list->head = node;
        else after->prev->next = node;
        after->prev = node;
    }
    list->size++;
}

string doubleGet(const DoubleList* list, int index) {
    return doubleAt(list, index)->value;
}

// Удаляет узел, сохраняя прямые и обратные связи списка.
string doubleDelete(DoubleList* list, int index) {
    DoubleNode* node = doubleAt(list, index);
    if (node->prev == nullptr) list->head = node->next;
    else node->prev->next = node->next;
    if (node->next == nullptr) list->tail = node->prev;
    else node->next->prev = node->prev;
    string value = node->value;
    delete node;
    list->size--;
    return value;
}

int doubleFind(const DoubleList* list, const string& value) {
    int index = 0;
    for (DoubleNode* node = list->head; node != nullptr; node = node->next) {
        if (node->value == value) return index;
        index++;
    }
    return -1;
}

// Читает список от начала или от конца.
vector<string> doubleValues(const DoubleList* list, bool reverse) {
    vector<string> result;
    if (reverse) {
        for (DoubleNode* node = list->tail; node != nullptr; node = node->prev) {
            result.push_back(node->value);
        }
    } else {
        for (DoubleNode* node = list->head; node != nullptr; node = node->next) {
            result.push_back(node->value);
        }
    }
    return result;
}
