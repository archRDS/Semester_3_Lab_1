#pragma once

#include <string>
#include <vector>

struct DoubleNode {
    std::string value;
    DoubleNode* prev = nullptr;
    DoubleNode* next = nullptr;
};

struct DoubleList {
    DoubleNode* head = nullptr;
    DoubleNode* tail = nullptr;
    int size = 0;
};

DoubleList* doubleCreate();
void doubleDestroy(DoubleList* list);
int doubleSize(const DoubleList* list);
void doubleInsert(DoubleList* list, int index, const std::string& value);
std::string doubleGet(const DoubleList* list, int index);
std::string doubleDelete(DoubleList* list, int index);
int doubleFind(const DoubleList* list, const std::string& value);
std::vector<std::string> doubleValues(const DoubleList* list, bool reverse);
