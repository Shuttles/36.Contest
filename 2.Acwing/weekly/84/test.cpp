#include <iostream>
using namespace std;

int main() {
    int arr[5] = {0, 5, 2, 7, 3};
    sort(arr + 1, arr + 5);
    for (int i = 0; i <= 4; i++) {
        printf("%d ", arr[i]);
    }
    cout << endl;
    return 0;
}