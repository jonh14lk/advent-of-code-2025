#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string inp;
  cin >> inp;
  vector<string> v;
  string curr;
  for (auto const &i : inp)
  {
    if (i == ',')
    {
      v.push_back(curr);
      curr.clear();
    }
    else
    {
      curr.push_back(i);
    }
  }
  v.push_back(curr);
  vector<int> nums;
  for (int i = 1; i <= 1000000; i++)
  {
    string t = to_string(i);
    string s = t + t;
    while (s.size() <= 10)
    {
      nums.push_back(stoll(s));
      s += t;
    }
  }
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  vector<int> pref(nums.size() + 1, 0);
  for (int i = 1; i <= nums.size(); i++)
  {
    pref[i] = pref[i - 1] + nums[i - 1];
  }
  int ans = 0;
  for (int x = 0; x < v.size(); x++)
  {
    string a, b;
    for (auto const &i : v[x])
    {
      if (i == '-')
        swap(a, b);
      else
        a.push_back(i);
    }
    swap(a, b);
    int na = stoll(a), nb = stoll(b);
    int l = lower_bound(nums.begin(), nums.end(), na) - nums.begin();
    int r = upper_bound(nums.begin(), nums.end(), nb) - nums.begin();
    ans += pref[r] - pref[l];
  }
  cout << ans << endl;
  return 0;
}