// a[i] - b[i] - tmp
//  >= 0: no change
//  < 0: a[i] - b[i] - tmp + 10; tmp = 1;
#include <iostream>
#include <vector>
using namespace std;

vector<int> v1, v2;
string s1, s2;
bool flag_negetive;

// a >= b ?
bool cmp(vector<int> &a, vector<int> &b)
{
    if (a.size() != b.size())
    {
        return a.size() > b.size();
    }
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
        {
            return a[i] > b[i];
        }
    }
    return true;
}

void input()
{
    cin >> s1 >> s2;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        v1.push_back(s1[i] - '0');
    }
    for (int i = s2.size() - 1; i >= 0; i--)
    {
        v2.push_back(s2[i] - '0');
    }
    if (!cmp(v1, v2))
    {
        swap(v1, v2);
        flag_negetive = true;
    }
    return;
}

// a一定是大的那个
vector<int> substract(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int tmp = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int res = a[i] - tmp;
        if (i < b.size())
        {
            res -= b[i];
        }

        if (res < 0)
        {
            res += 10;
            tmp = 1;
        }
        else
        {
            tmp = 0;
        }
        ans.push_back(res);
    }
    // 123-120 = 003，so要清除前导0
    while (ans.size() > 1 && ans.back() == 0)
    {
        ans.pop_back();
    }
    return ans;
}

void output()
{
    auto ans = substract(v1, v2);
    if (flag_negetive)
    {
        cout << "-";
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;
    return;
}

int main()
{
    input();
    output();
    return 0;
}