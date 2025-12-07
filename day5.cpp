#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  vector<pair<int, int>> ranges;
  vector<int> qry;
  while (cin >> s)
  {
    if (count(s.begin(), s.end(), '-'))
    {
      string a, b;
      for (auto const &i : s)
      {
        if (i == '-')
          swap(a, b);
        else
          a.push_back(i);
      }
      swap(a, b);
      ranges.push_back({stoll(a), stoll(b)});
    }
    else
    {
      qry.push_back(stoll(s));
    }
  }
  sort(qry.begin(), qry.end());
  sort(ranges.begin(), ranges.end());
  int l = -1e18, r = -1e18, ans = 0, ptr = 0;
  // for (auto [a, b] : ranges) // task 1
  // {
  //   if (a > r)
  //     l = a, r = b;
  //   r = max(r, b);
  //   while (ptr < qry.size() && qry[ptr] <= r)
  //   {
  //     if (qry[ptr] >= l && qry[ptr] <= r)
  //       ans++;
  //     ptr++;
  //   }
  // }
  for (auto [a, b] : ranges) // task 2
  {
    if (a > r)
    {
      l = a, r = b;
      ans += r - l + 1;
    }
    ans += max(0ll, b - r);
    r = max(r, b);
  }
  cout << ans << endl;
  return 0;
}