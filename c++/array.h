#pragma once

#include <string>
#include <vector>

struct Array {
    std::string* data = nullptr;
    int size = 0;
    int capacity = 0;
};

Array* arrayCreate();
void arrayDestroy(Array* array);
int arraySize(const Array* array);
void arrayInsert(Array* array, int index, const std::string& value);
std::string arrayGet(const Array* array, int index);
void arraySet(Array* array, int index, const std::string& value);
std::string arrayDelete(Array* array, int index);
std::vector<std::string> arrayValues(const Array* array);
