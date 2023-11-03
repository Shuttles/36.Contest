#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

int n;
long long ans;

class Product {
public:
    string name;
    string place;
    bool operator==(const Product &product);
    bool operator<(const Product &product);
};

bool Product::operator==(const Product &product) {
    if (this->name == product.name && this->place == product.place) {
        return true;
    }
    return false;
}
bool Product::operator<(const Product &product) {
    if (this->name < product.name && this->place < product.place) {
        return true;
    }
    return false;
}


unordered_map<string, set<string> > h;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        Product temp;
        cin >> temp.name >> temp.place;
        h[temp.name].insert(temp.place);
    }
    return ;
}

void output() {
    for (auto iter : h) {
        ans += iter.second.size();
    }
    cout << ans << endl;
    return ;
}

int main() {
    input();
    output();
    return 0;
}