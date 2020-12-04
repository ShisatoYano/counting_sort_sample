#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define RANGE 255

// function to sort string character by counting sort algorithm
// sort in alphabetical order
void counting_sort_char(char array[]) {
    char output[strlen(array)];

    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    // count array to store count of individual
    for (i = 0; array[i]; ++i) {
        ++count[array[i]];
    }

    // store count of each character
    for (i = 1; i <= RANGE ; ++i) {
        count[i] += count[i - 1];
    }

    // build output character array
    for (i = 0; array[i]; ++i) {
        output[count[array[i]] - 1] = array[i];
        --count[array[i]];
    }

    // copy output to array
    for (i = 0; array[i]; ++i) {
        array[i] = output[i];
    }
}

void print_array_int(vector<int>& array) {
    for (int element : array) {
        cout << element << " ";
    }
    cout << "\n";
}

void counting_sort_int(vector<int>& array) {
    int max = *max_element(array.begin(), array.end());
    int min = *min_element(array.begin(), array.end());
    int range = max - min + 1;

    vector<int> count(range), output(array.size());
    for (int element : array) {
        count[element - min]++;
    }

    for (int i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }

    for (int i = array.size() - 1; i >= 0; --i) {
        output[count[array[i] - min] - 1] = array[i];
        count[array[i] - min]--;
    }

    for (int i = 0; i < array.size(); ++i) {
        array[i] = output[i];
    }
}

int main() {
    char array_char[] = "geeksforgeeks";

    cout << "Given character array: " << array_char << endl;

    counting_sort_char(array_char);

    cout << "Sorted character array: " << array_char << endl;

    vector<int> array_int = {-5, -10, 0, -3, 8, 5, -1, 10};

    cout << "Given integer array: ";
    print_array_int(array_int);

    counting_sort_int(array_int);

    cout << "Sorted integer array: ";
    print_array_int(array_int);

    return 0;
}
