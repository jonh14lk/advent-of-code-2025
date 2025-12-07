#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<string> v;
  string s;
  while (cin >> s)
  {
    v.push_back(s);
  }
  int n = v.size(), m = v[0].size();
  int ans = 0;
  queue<pair<int, int>> q;
  auto check = [&](int i, int j)
  {
    int adj = 0;
    for (int a = -1; a <= 1; a++)
    {
      for (int b = -1; b <= 1; b++)
      {
        if (a == 0 && b == 0)
          continue;
        int x = i + a, y = j + b;
        if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '@')
          adj++;
      }
    }
    if (adj < 4)
    {
      v[i][j] = '.';
      q.push({i, j});
    }
  };
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (v[i][j] == '@')
        check(i, j);
    }
  }
  while (!q.empty())
  {
    auto [i, j] = q.front();
    q.pop();
    ans++;
    for (int a = -1; a <= 1; a++)
    {
      for (int b = -1; b <= 1; b++)
      {
        if (a == 0 && b == 0)
          continue;
        int x = i + a, y = j + b;
        if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '@')
          check(x, y);
      }
    }
  }
  cout << ans << endl;
  return 0;
}