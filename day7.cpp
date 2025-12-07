#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  vector<string> v;
  while (cin >> s)
  {
    v.push_back(s);
  }
  int n = v.size(), m = v[0].size();
  pair<int, int> st;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      if (v[i][j] == 'S')
        st = {i, j};
  }
  vector<vector<int>> dp(n, vector<int>(m, 0));
  dp[st.first][st.second] = 1;
  int splits = 0;
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (v[i - 1][j] != '^')
        dp[i][j] += dp[i - 1][j];
    }
    for (int j = 0; j < m; j++)
    {
      if (v[i][j] == '^')
      {
        splits += (dp[i][j] > 0);
        dp[i][j - 1] += dp[i][j];
        dp[i][j + 1] += dp[i][j];
      }
    }
  }
  // cout << splits << endl;
  int tot = 0;
  for (int i = 0; i < m; i++)
  {
    tot += dp[n - 1][i];
  }
  cout << tot << endl;
  return 0;
}