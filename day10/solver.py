import pulp

ans = 0
q = int(input())

for ii in range(q):
    n, m = map(int, input().split())
    v = [list(map(int, input().split())) for _ in range(n)]
    goal = list(map(int, input().split()))

    lp_problem = pulp.LpProblem("advent of code", pulp.LpMinimize)

    x = [pulp.LpVariable(f"x_{i}", lowBound=0, cat='Integer') for i in range(n)]

    lp_problem += pulp.lpSum(x)

    for i in range(m):
        lp_problem += pulp.lpSum(v[j][i] * x[j] for j in range(n)) == goal[i]

    lp_problem.solve()

    for i in range(n):
        ans += x[i].value()

print(ans)