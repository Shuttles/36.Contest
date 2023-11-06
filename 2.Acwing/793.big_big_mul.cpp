// 高精 * 高精，只需在高精*低精基础上加个双重循环即可
#include <iostream>
#include <vector>
using namespace std;

string s1, s2;
vector<int> v1, v2;

void input()
{
    cin >> s1 >> s2;
    return;
}

vector<int> mul(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());

    // 在高精*低精基础上加的两重循环
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            ans[i + j] += a[i] * b[j];
        }
    }

    // process
    int tmp = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        tmp += ans[i];
        ans[i] = tmp % 10;
        tmp /= 10;
    }

    // clear front 0
    while (ans.size() > 1 && ans.back() == 0)
        ans.pop_back();
    return ans;
}

void output()
{
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        v1.push_back(s1[i] - '0');
    }
    for (int i = s2.size() - 1; i >= 0; i--)
    {
        v2.push_back(s2[i] - '0');
    }

    vector<int> ans = mul(v1, v2);

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