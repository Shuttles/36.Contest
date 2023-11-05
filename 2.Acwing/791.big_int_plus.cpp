#include <iostream>
#include <vector>
using namespace std;

vector<int> v1, v2;
string s1, s2;

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
    return;
}

// 模拟手工加法
vector<int> add(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int tmp = 0; // tmp表示上一位的进位
    for (int i = 0; i < a.size() || i < b.size(); i++)
    {
        if (i < a.size())
        {
            tmp += a[i];
        }
        if (i < b.size())
        {
            tmp += b[i];
        }
        ans.push_back(tmp % 10);
        tmp /= 10;
    }
    if (tmp)
    {
        ans.push_back(1);
    }
    return ans;
}

void output()
{
    vector<int> ans = add(v1, v2);
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