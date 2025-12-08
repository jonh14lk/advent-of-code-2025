#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<array<int, 3>> v;
  string s;
  while (cin >> s)
  {
    string a, b, c;
    int cnt = 0;
    for (auto const &i : s)
    {
      if (i == ',')
      {
        cnt++;
        if (cnt == 1)
          swap(a, b);
        else
          swap(a, c);
      }
      else
      {
        a.push_back(i);
      }
    }
    swap(a, b);
    swap(b, c);
    v.push_back({stoll(a), stoll(b), stoll(c)});
  }
  int n = v.size();
  vector<array<int, 3>> edges;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int dist = (v[i][0] - v[j][0]) * (v[i][0] - v[j][0]) +
                 (v[i][1] - v[j][1]) * (v[i][1] - v[j][1]) +
                 (v[i][2] - v[j][2]) * (v[i][2] - v[j][2]);
      edges.push_back({dist, i, j});
    }
  }
  sort(edges.begin(), edges.end());
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < edges.size(); i++)
  {
    adj[edges[i][1]].push_back({edges[i][2], i});
    adj[edges[i][2]].push_back({edges[i][1], i});
  }
  vector<bool> vis(n, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vis[0] = 1;
  for (auto [y, id] : adj[0])
  {
    pq.push({id, y});
  }
  int mx = -1;
  while (!pq.empty())
  {
    auto [id, x] = pq.top();
    pq.pop();
    if (vis[x])
      continue;
    vis[x] = 1;
    mx = max(mx, id);
    for (auto [y, nxt_id] : adj[x])
      if (!vis[y])
        pq.push({nxt_id, y});
  }
  cout << v[edges[mx][1]][0] * v[edges[mx][2]][0] << endl;
  return 0;
}