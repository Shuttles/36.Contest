#include <iostream>
#include <stack>
using namespace std;

stack<char> s;
string str;

void input() {
    cin >> str;
    return ;
}

void output() {
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if (!s.empty() && s.top() == str[i]) {
            s.pop();
        } else {
            s.push(str[i]);
        }
    }
    
    len = s.size();
    for (int i = 0; i < s.size(); i++) {
        cout << s;
    }
    cout << endl;
    return ;
}

int main() {
    input();
    output();
    return 0;
}