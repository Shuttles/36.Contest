#include <iostream>
using namespace std;

// 用stack不好输出，而string有back() pop_back()就很方便
string str, ans;

void input() {
    cin >> str;
    return ;
}

void output() {
    for (auto c : str) {
        if (!ans.empty() && ans.back() == c) {
            ans.pop_back();
        } else {
            ans += c;
        }
    }
    cout << ans << endl;
    return ;
}


int main() {
    input();
    output();
    return 0;
}