#pragma once

#include <string>
#include <vector>

struct SingleNode {
    std::string value;
    SingleNode* next = nullptr;
};

struct SingleList {
    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;
    int size = 0;
};

SingleList* singleCreate();
void singleDestroy(SingleList* list);
int singleSize(const SingleList* list);
void singleInsert(SingleList* list, int index, const std::string& value);
std::string singleGet(const SingleList* list, int index);
std::string singleDelete(SingleList* list, int index);
int singleFind(const SingleList* list, const std::string& value);
std::vector<std::string> singleValues(const SingleList* list);
