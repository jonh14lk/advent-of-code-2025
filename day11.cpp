#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  map<string, int> mp;
  vector<vector<int>> adj;
  auto get_id = [&](string &s)
  {
    if (mp.find(s) == mp.end())
    {
      mp[s] = adj.size();
      adj.push_back({});
    }
    return mp[s];
  };
  while (getline(cin, s))
  {
    string a;
    string src;
    vector<string> dest;
    for (auto const &i : s)
    {
      if (i == ':')
      {
        src = a;
        a.clear();
      }
      else if (i == ' ')
      {
        if (a.size() > 0)
          dest.push_back(a);
        a.clear();
      }
      else
      {
        a.push_back(i);
      }
    }
    if (a.size() > 0)
    {
      dest.push_back(a);
    }
    int s = get_id(src);
    for (auto dd : dest)
    {
      int d = get_id(dd);
      adj[s].push_back(d);
    }
  }
  int svr, out, dac, fft;
  for (auto const &i : mp)
  {
    if (i.first == "svr")
      svr = i.second;
    if (i.first == "out")
      out = i.second;
    if (i.first == "dac")
      dac = i.second;
    if (i.first == "fft")
      fft = i.second;
  }
  int n = adj.size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
  auto dfs = [&](this auto &self, int v, int vis_dac, int vis_fft) -> int
  {
    if (v == out)
      return (vis_dac && vis_fft) ? 1 : 0;
    if (dp[v][vis_dac][vis_fft] != -1)
      return dp[v][vis_dac][vis_fft];
    int ans = 0;
    for (auto const &u : adj[v])
      ans += self(u, (vis_dac | (u == dac)), (vis_fft | (u == fft)));
    return dp[v][vis_dac][vis_fft] = ans;
  };
  cout << dfs(svr, 0, 0) << endl;
  return 0;
}
