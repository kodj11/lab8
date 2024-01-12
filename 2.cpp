#include <iostream>
#include <string>

template <class T>
int findInArray(const T arr[], int size, const T& value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
template <class T>
int findInArray(const T arr[], int size, const char* value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}


int main(void) {
    int arr[5] = { 1, 2, 3, 4, 5 };
    int index = findInArray(arr, 5, 3); // index = 2
    std::cout << "Number(index) of 3 in { 1, 2, 3, 4, 5 }: " << index << std::endl;
    std::string strings[4] = { "hello", "world", "foo", "bar" };
    int stringIndex = findInArray(strings, 4, "bar"); // stringIndex = 3
    std::cout << "Number(index) of \"bar\" in { \"hello\", \"world\", \"foo\", \"bar\" }: " << stringIndex << std::endl;
}