#include <iostream>
#include <unordered_set>
using namespace std;

int n;
unordered_set<string> h;

void input() {
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;
        h.insert(a + ", " + b);
    }
    return ;
}

void output() {
    cout << h.size() << endl;
    return ;
}

int main() {
    input();
    output();
    return 0;
}