#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  vector<string> strs;
  while (cin >> s)
  {
    strs.push_back(s);
  }
  vector<vector<string>> group;
  group.push_back({});
  for (auto const &st : strs)
  {
    group.back().push_back(st);
    if (st[0] == '{')
      group.push_back({});
  }
  int ans = 0;
  for (int g = 0; g < group.size() - 1; g++)
  {
    int goal_mask = 0;
    for (int i = 1, bit = 0; i < group[g][0].size() - 1; i++, bit++)
    {
      if (group[g][0][i] == '#')
        goal_mask ^= (1 << bit);
    }
    vector<int> buttons;
    for (int i = 1; i < group[g].size() - 1; i++)
    {
      int button_mask = 0;
      for (auto const &ch : group[g][i])
      {
        if (ch >= '0' && ch <= '9')
          button_mask ^= (1 << (ch - '0'));
      }
      buttons.push_back(button_mask);
    }
    int mn = 1e9;
    for (int mask = 0; mask < (1 << buttons.size()); mask++)
    {
      int curr_mask = 0;
      for (int i = 0; i < buttons.size(); i++)
      {
        if (mask & (1 << i))
          curr_mask ^= buttons[i];
      }
      if (curr_mask == goal_mask)
        mn = min(mn, (int)__builtin_popcount(mask));
    }
    ans += mn;
  }
  cout << ans << endl;
  return 0;
}
// task 1: só é ótimo apertar um botão no maximo uma vez, então da para
// pensar em brutar todas as possibilidades possíveis e ver qual vai ser o mínimo