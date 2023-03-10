#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > ranges(302, vector <int>(302));
vector <int> output(302);

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n - i; j++) cin >> ranges[i][i + j];
    output[0] = 0;
    output[1] = ranges[0][1];
    for (int i = 2; i < n; i++)
    {
        if (ranges[i - 1][i] == 0)
        {
            output[i] = output[i - 1];
            continue;
        }
        int hi_val = output[i - 1] + ranges[i - 1][i], lo_val = output[i - 1] - ranges[i - 1][i];
        bool flag = false;
        for (int p = i - 2; p >= 0; p--)
        {
            if (output[p] != output[p + 1])
            {
                int range_hi = max({output[p], output[p + 1], hi_val}) - min({output[p], output[p + 1], hi_val});
                int range_lo = max({output[p], output[p + 1], lo_val}) - min({output[p], output[p + 1], lo_val});
                if (range_hi == ranges[p][i]) output[i] = hi_val;
                else output[i] = lo_val;
                flag = true;
                break;
            }
        }
        if (!flag) output[i] = hi_val;
    }
    for (int i = 0; i < n; i++)
    {
        cout << output[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
}
