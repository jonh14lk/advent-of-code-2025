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
  cout << group.size() - 1 << endl;
  for (int g = 0; g < group.size() - 1; g++)
  {
    vector<int> freq;
    string goal = group[g].back();
    int ptr = 0;
    while (ptr < goal.size())
    {
      if (goal[ptr] >= '0' && goal[ptr] <= '9')
      {
        int num = 0;
        while (goal[ptr] >= '0' && goal[ptr] <= '9')
        {
          num *= 10;
          num += (goal[ptr] - '0');
          ptr++;
        }
        freq.push_back(num);
      }
      else
      {
        ptr++;
      }
    }
    vector<vector<int>> buttons;
    for (int i = 1; i < group[g].size() - 1; i++)
    {
      vector<int> curr(freq.size(), 0);
      for (auto const &ch : group[g][i])
      {
        if (ch >= '0' && ch <= '9')
          curr[ch - '0'] = 1;
      }
      buttons.push_back(curr);
    }
    cout << buttons.size() << " " << freq.size() << endl;
    for (int i = 0; i < buttons.size(); i++)
    {
      for (auto const &j : buttons[i])
        cout << j << " ";
      cout << endl;
    }
    for (auto const &i : freq)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
// task 2: da para modelar como um problema de programação linear inteira e usar
// algum solver para resolver, só reaproveitei uma parte do código da task1 que tinha
// em c++ para parsear um input em um formato mais tranquilo de ler no código em python (que chama o solver)