#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

struct SingleNode {
    string value;
    SingleNode* next = nullptr;
};

struct SingleList {
    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;
    int size = 0;
};

SingleList* singleCreate() {
    return new SingleList;
}

void singleDestroy(SingleList* list) {
    while (list->head != nullptr) {
        SingleNode* next = list->head->next;
        delete list->head;
        list->head = next;
    }
    delete list;
}

int singleSize(const SingleList* list) {
    return list->size;
}

SingleNode* singleAt(const SingleList* list, int index) {
    if (index < 0 || index >= list->size) throw runtime_error("index out of range");
    SingleNode* node = list->head;
    for (int i = 0; i < index; i++) node = node->next;
    return node;
}

void singleInsert(SingleList* list, int index, const string& value) {
    if (index < 0 || index > list->size) throw runtime_error("index out of range");
    SingleNode* node = new SingleNode{value};
    if (index == 0) {
        node->next = list->head;
        list->head = node;
        if (list->tail == nullptr) list->tail = node;
    } else {
        SingleNode* before = singleAt(list, index - 1);
        node->next = before->next;
        before->next = node;
        if (node->next == nullptr) list->tail = node;
    }
    list->size++;
}

string singleGet(const SingleList* list, int index) {
    return singleAt(list, index)->value;
}

string singleDelete(SingleList* list, int index) {
    if (index < 0 || index >= list->size) throw runtime_error("index out of range");
    SingleNode* node;
    if (index == 0) {
        node = list->head;
        list->head = node->next;
        if (list->head == nullptr) list->tail = nullptr;
    } else {
        SingleNode* before = singleAt(list, index - 1);
        node = before->next;
        before->next = node->next;
        if (before->next == nullptr) list->tail = before;
    }
    string value = node->value;
    delete node;
    list->size--;
    return value;
}

int singleFind(const SingleList* list, const string& value) {
    int index = 0;
    for (SingleNode* node = list->head; node != nullptr; node = node->next) {
        if (node->value == value) return index;
        index++;
    }
    return -1;
}

vector<string> singleValues(const SingleList* list) {
    vector<string> result;
    for (SingleNode* node = list->head; node != nullptr; node = node->next) {
        result.push_back(node->value);
    }
    return result;
}
