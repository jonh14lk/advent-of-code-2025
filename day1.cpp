#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  int pos = 50, ans = 0;
  while (cin >> s)
  {
    int num = stoll(s.substr(1));
    if (s[0] == 'L')
    {
      while (num--)
      {
        pos = (pos - 1 + 100) % 100;
        if (pos == 0)
          ans++;
      }
    }
    else
    {
      while (num--)
      {
        pos = (pos + 1) % 100;
        if (pos == 0)
          ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}