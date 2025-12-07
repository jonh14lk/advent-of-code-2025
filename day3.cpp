#include <bits/stdc++.h>
using namespace std;

#define int long long int

string s;
vector<vector<int>> dp;

int solve(int i, int j)
{
  if (i == s.size())
    return (j == 0) ? 0 : -2;
  if (dp[i][j] != -1)
    return dp[i][j];
  int ans = solve(i + 1, j);
  int num = s[i] - '0';
  if (j > 0)
    ans = max(ans, (10 * solve(i + 1, j - 1)) + num);
  return dp[i][j] = ans;
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ans = 0;
  while (cin >> s)
  {
    reverse(s.begin(), s.end());
    dp = vector<vector<int>>(s.size(), vector<int>(13, -1));
    ans += solve(0, 12);
  }
  cout << ans << endl;
  return 0;
}