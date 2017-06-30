#include <cmath>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
#define valid(i, t) (0 <= (i) && (i) < (t))
typedef unsigned long long int big;
 
struct state {
  public:
    big g;
    int l;
};
 
int m, n, checkin[4][2] = { {0, 0}, {0, 0}, {0, 0}, {0, 1} }, times[4];
big pows[64];
state S[64];
 
bool get(int s, int r, int c) {
  return (S[s].g & pows[r * n + c]) != 0ULL;
}
 
bool done(int s) {
  return S[s].l == 1ULL && s + 1 == m * n;
}
 
bool visited[8][8];
int count_empty(int s, int r, int c) {
  int z = 0;
  if (valid(r, m) && valid(c, n) && !get(s, r, c) && !visited[r][c]) {
    visited[r][c] = true;
    z = 1;
    z += count_empty(s, r, c + 1);
    z += count_empty(s, r + 1, c);
    z += count_empty(s, r, c - 1);
    z += count_empty(s, r - 1, c);
  }
  return z;
}
 
bool check(int s) {
  fill(visited[0], visited[8], false);
  int r = -1, c = -1, nt = 0, d = 0;
  for (int i = 0; i < 4; i++)
    if (s + 1 <= times[i] && nt == 0) {
      r = checkin[i][0];
      c = checkin[i][1];
      nt = times[i];
    }
  d = abs(S[s].l / n - r) + abs(S[s].l % n - c);
 
  if (nt == s + 1 && S[s].l != r * n + c)
    return false;
  else if (nt != s + 1 && (nt - (s + 1) < d || d == 0))
    return false;
  else if (count_empty(s, 0, 1) + s + 1 != m * n)
    return false;
  else
    return true;
}
 
int init_state(int s, big g, int l) {
  S[s].g = g | pows[l];
  S[s].l = l;
  return s;
}
 
int dfs(int s) {
  int count = 0;
 
  for (int i = (S[s].l / n) - 1; i <= (S[s].l / n) + 1; i++)
    for (int j = (S[s].l % n) - 1; j <= (S[s].l % n) + 1; j++)
      if (((i == (S[s].l / n)) ^ (j == (S[s].l % n))) && valid(i, m) && valid(j, n) && !get(s, i, j))
        if (done(init_state(s + 1, S[s].g, n * i + j)))
          count += 1;
        else if (check(s + 1))
          count += dfs(s + 1);
 
  return count;
}
 
int main() {
  pows[0] = 1ULL;
  for (int i = 1; i < 64; i++)
    pows[i] = pows[i - 1] << 1;
 
  int caseno = 0;
  while (++caseno && scanf("%i%i", &m, &n) == 2 && m != 0) {
    for (int i = 0; i < 3; i++)
      scanf("%i%i", checkin[i], checkin[i] + 1);
 
    for (int i = 0; i < 4; i++)
      times[i] = (i + 1) * m * n / 4;
 
    printf("Case %i: %i\n", caseno, dfs(init_state(0, 0ULL, 0)));
  }
 
  return 0;
}
