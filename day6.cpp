#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  vector<string> inp;
  while (getline(cin, s))
  {
    inp.push_back(s);
  }
  vector<int> v(inp[0].size(), 0);
  for (int i = 0; i < (inp.size() - 1); i++)
  {
    for (int j = 0; j < inp[i].size(); j++)
    {
      if (inp[i][j] >= '0' && inp[i][j] <= '9')
      {
        v[j] *= 10;
        v[j] += (inp[i][j] - '0');
      }
    }
  }
  int ptr = 0, ans = 0;
  for (auto const &c : inp.back())
  {
    if (c != '+' && c != '*')
      continue;
    while (v[ptr] == 0)
      ptr++;
    int i = ptr;
    while (ptr < v.size() && v[ptr] > 0)
      ptr++;
    int j = ptr - 1, res = (c == '+') ? 0 : 1;
    for (int x = i; x < ptr; x++)
    {
      if (c == '+')
        res += v[x];
      else
        res *= v[x];
    }
    ans += res;
  }
  cout << ans << endl;
  return 0;
}