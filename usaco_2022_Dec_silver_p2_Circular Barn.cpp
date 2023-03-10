#include <bits/stdc++.h>
using namespace std;
 
const int MM = 5e6+1;
 
int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <int> min_turns(MM), max_mod4 = {2, 1, 2, 3};
    for (int i = 1; i < MM; i += 2) min_turns[i]++;
    vector <bool> check(MM, false);
	for (int i = 2; i < MM; i++)
	{
		if (!check[i])
		{
			for (int j = i; j < MM; j += i) check[j] = true;
			max_mod4[i % 4] = i;
		}
		min_turns[i] = (i - max_mod4[i % 4]) / 2 + 1;
	}
	int t;
	cin >> t;
	for (int x = 1; x <= t; x++)
	{
		int n, ans = MM, a;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			if (min_turns[a] / 2 < ans / 2) ans = min_turns[a];
		}
		if (ans % 2 == 1) cout << "Farmer John\n";
		else cout << "Farmer Nhoj\n";
	}
}
