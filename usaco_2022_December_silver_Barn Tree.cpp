#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+1;

struct order_t
{
    int src, dest;
    long long amt;
};

vector <long long> h(MM);
vector <long long> subtree_sum(MM);
vector <vector <int> > adj;
vector <order_t> orders;

long long dfs_sum(int x, int p)
{
    long long cur_sum = h[x];
    for (int nxt : adj[x]) if (nxt != p) cur_sum += dfs_sum(nxt, x);
    return subtree_sum[x] = cur_sum;
}

void dfs_ord(int x, int p)
{
    for (int nxt : adj[x]) if (nxt != p && subtree_sum[nxt] > 0) dfs_ord(nxt, x);
    for (int nxt : adj[x])
    {
        if (nxt != p && subtree_sum[nxt] <= 0)
        {
            if (subtree_sum[nxt] < 0) orders.push_back({x, nxt, -1 * subtree_sum[nxt]});
            dfs_ord(nxt, x);
        }
    }
    if (x != 1 && subtree_sum[x] > 0) orders.push_back({x, p, subtree_sum[x]});
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, u, v;
    cin >> n;
    long long hsum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        hsum += h[i];
    }
    long long goal = hsum / n;
    for (int i = 1; i <= n; i++) h[i] -= goal;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs_sum(1, 1);
    dfs_ord(1, 1);
    cout << orders.size() << "\n";
    for (int i = 0; i < orders.size(); i++)
    {
        order_t o = orders[i];
        cout << o.src << " " << o.dest << " " << o.amt << "\n";
    }
}
