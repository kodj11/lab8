#include <iostream>
#include <string>
#include <vector>

template <class T>
void findMinMax(const T arr[], int size, T& min, T& max) {

    min = arr[0];
    max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
}
// Ñäåëàåì ïîèñê ìèíèìàëüíîé äëèíû è ìàêñèìàëüíîé äëèíû
template < >
void findMinMax<std::string>(const std::string arr[], int size, std::string& min, std::string& max) {

    min = arr[0];
    max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i].length() < min.length()) {
            min = arr[i];
        }
        if (arr[i].length() > max.length()) {
            max = arr[i];
        }
    }
}
// äåëàåì ïîèñê äëÿ âåêòîðîâ
template <typename T>
void findMinMax(const std::vector<T> arr[], int size,
    std::vector<T>& min, std::vector<T>& max) {

    int minLen = arr[0].size();
    int maxLen = arr[0].size();
    min = arr[0];
    max = arr[0];
    for (int i = 1; i < size; i++) {

        int len = arr[i].size();

        if (len < minLen) {
            min = arr[i];
            minLen = len;
        }

        if (len > maxLen) {
            max = arr[i];
            maxLen = len;
        }
    }
}

int main(void) {
    int arr[] = { 5, 2, 10, -1, 150 };
    int min, max;
    findMinMax(arr, 5, min, max);
    std::string sarr[] = { "5", "22", "10", "-11", "1500" };
    std::string smin, smax;
    findMinMax(sarr, 5, smin, smax);

    char carr[5] = { 'a', '2', 'g', 'h', 'j' };
    char cmin, cmax;
    findMinMax(carr, 5, cmin, cmax);
    std::cout << "In { 5, 2, 10, -1, 150 } MIN: " << min << " MAX: " << max << std::endl;
    std::cout << "In { \"5\", \"22\", \"10\", \"-11\", \"1500\" } MIN: " << smin << " MAX: " << smax << std::endl;
    std::cout << "In { 'a', '2', 'g', 'h', 'j' } MIN: " << cmin << " MAX: " << cmax << std::endl;

    std::vector<int> intVecs[] = { {5, 4}, { 5, 3, 2, 1 }, {3, 2, 1} };
    std::vector<int> minIntVec, maxIntVec;
    findMinMax(intVecs, 3, minIntVec, maxIntVec);
    std::cout << "In { {5, 4}, { 5, 3, 2, 1 }, {3, 2, 1} } MIN: " << std::endl;
    for (auto& el : minIntVec) {
        std::cout << el << " ";
    }
    std::cout << std::endl << " MAX: ";
    for (auto& el : maxIntVec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    std::vector<char> stringVecs[] = { {'5', '4'}, { '5', '3', '0', '0' }, {'3', '2', '1'} };
    std::vector<char> minStringVec, maxStringVec;
    findMinMax(stringVecs, 3, minStringVec, maxStringVec);
    std::cout << "In { {'5', '4'}, { '5', '3', '0', '0' }, {'3', '2', '1'} } MIN: " << std::endl;
    for (auto& el : minStringVec) {
        std::cout << el << " ";
    }
    std::cout << std::endl << " MAX: ";
    for (auto& el : maxStringVec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}
