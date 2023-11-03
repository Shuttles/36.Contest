#include <iostream>
#include <unordered_set>
#include <cstdio>
#include <string>
using namespace std;
#define IS_ODD(a) ((a) & 1)
#define IS_EVEN(a) (!((a) & 1))

string str;
unordered_set<char> h;

void input() {
    cin >> str;
    return ;
}

void output() {
    for (auto s : str) {
        h.insert(s);
    }
    printf("%s\n", IS_EVEN(h.size()) ? "even" : "odd");
    return ;
}


int main() {
    input();
    output();
    return 0;
}