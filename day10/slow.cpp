#include <bits/stdc++.h>
using namespace std;

#define int long long int

vector<int> freq;
int best, curr;
vector<int> ord;
vector<int> sol;
vector<vector<int>> adj;
vector<vector<int>> to_define;
vector<int> curr_transition;
vector<vector<int>> precomputed_transitions[14][305];
bool computed[14][305];

void brute_transitions(int rem, int i, vector<vector<int>> &transitions)
{
  if (i == 0)
  {
    if (rem == 0)
      transitions.push_back(curr_transition);
    return;
  }
  for (int j = 0; j <= rem; j++)
  {
    curr_transition.push_back(j);
    brute_transitions(rem - j, i - 1, transitions);
    curr_transition.pop_back();
  }
}
void solve(int i)
{
  if (curr > best)
  {
    return;
  }
  if (i == freq.size())
  {
    best = min(best, curr);
    return;
  }
  int x = ord[i];
  int sum = 0;
  for (auto const &y : adj[x])
  {
    if (sol[y] != -1)
      sum += sol[y];
  }
  if (sum > freq[x])
  {
    return;
  }
  int rem = freq[x] - sum;
  int todo = to_define[x].size();
  if (todo == 0)
  {
    if (rem != 0)
      return;
    solve(i + 1);
  }
  else
  {
    if (!computed[todo][rem])
    {
      computed[todo][rem] = 1;
      brute_transitions(rem, todo, precomputed_transitions[todo][rem]);
    }
    int prv_curr = curr;
    for (auto const &v : precomputed_transitions[todo][rem])
    {
      for (int j = 0; j < todo; j++)
        sol[to_define[x][j]] = v[j], curr += v[j];
      solve(i + 1);
      curr = prv_curr;
    }
    for (int j = 0; j < todo; j++)
    {
      sol[to_define[x][j]] = -1;
    }
  }
}
__int128 ncr(int n, int k)
{
  if (k < 0 || k > n)
    return 0;
  __int128 res = 1;
  for (long long i = 1; i <= k; i++)
    res = res * (n - i + 1) / i;
  return res;
}
__int128 stars_and_bars(int n, int k)
{
  return ncr(n + k - 1, k - 1);
}
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
  int mx = 0;
  for (int g = 0; g < group.size() - 1; g++)
  {
    cout << "solving test case: " << g << endl;
    freq.clear();
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
    int n = freq.size(), m = 0;
    adj.assign(n, {});
    to_define.assign(n, {});
    for (int i = 1; i < group[g].size() - 1; i++)
    {
      m++;
      for (auto const &ch : group[g][i])
      {
        if (ch >= '0' && ch <= '9')
          adj[ch - '0'].push_back(m - 1);
      }
    }
    ord.clear();
    for (int i = 0; i < n; i++)
    {
      ord.push_back(i);
    }
    vector<int> best_ord;
    __int128 best_prod = 1e20;
    do
    {
      vector<bool> vis(m, 0);
      __int128 prod = 1;
      for (auto const &i : ord)
      {
        int cnt = 0;
        for (auto const &j : adj[i])
        {
          if (!vis[j])
          {
            cnt++;
            vis[j] = 1;
          }
        }
        if (cnt >= 1)
          prod *= stars_and_bars(freq[i], cnt);
      }
      if (best_prod > prod)
      {
        best_prod = prod;
        best_ord = ord;
      }
    } while (next_permutation(ord.begin(), ord.end()));
    ord = best_ord;
    vector<bool> vis(m, 0);
    for (auto const &i : ord)
    {
      for (auto const &j : adj[i])
      {
        if (!vis[j])
        {
          vis[j] = 1;
          to_define[i].push_back(j);
        }
      }
    }
    sol.assign(m, -1);
    best = 1e9, curr = 0;
    solve(0);
    ans += best;
  }
  cout << ans << endl;
  return 0;
}
// backtracking que tentei pra tentar resolver a task2
// mas tem um caso do input que ele demora demais :)