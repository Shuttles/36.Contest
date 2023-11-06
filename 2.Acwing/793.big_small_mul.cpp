// 高精*低精很简单，高精每一位*低精，注意进位就行，和高精加法很像
#include <iostream>
#include <vector>
using namespace std;

string s1;
vector<int> v1;
int b;

void input()
{
    cin >> s1 >> b;
    return;
}

vector<int> mul(vector<int> &a, int b)
{
    vector<int> ans;
    int tmp = 0;
    for (int i = 0; i < a.size() || tmp > 0; i++)
    {
        if (i < a.size())
        {
            tmp += a[i] * b;
        }
        ans.push_back(tmp % 10);
        tmp /= 10;
    }
    // clear front 0
    while (ans.size() > 1 && ans.back() == 0)
    {
        ans.pop_back();
    }

    return ans;
}

void output()
{
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        v1.push_back(s1[i] - '0');
    }

    vector<int> ans;
    ans = mul(v1, b);

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