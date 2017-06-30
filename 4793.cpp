#include <iostream>
#include <cmath>

using namespace std;

bool visited[8][8];
int locations[4][2];
int n, m;

inline int dist(int x1, int y1, int x2, int y2) {
  return abs(x1-x2)+abs(y1-y2);
}

inline int dfs(int step, int i, int j) {
  int nsteps = n * m;

  // Prunning
  if (step < nsteps/4 
      and (dist(i, j, locations[0][0], locations[0][1]) > nsteps/4 - step
        or visited[locations[0][0]][locations[0][1]]))
    return 0;
  if (step < nsteps/2 
      and (dist(i, j, locations[1][0], locations[1][1]) > nsteps/2 - step
        or visited[locations[1][0]][locations[1][1]]))
    return 0;
  if (step < 3*nsteps/4 
      and (dist(i, j, locations[2][0], locations[2][1]) > 3*nsteps/4 - step
        or visited[locations[2][0]][locations[2][1]]))
    return 0;
  if (step < nsteps 
      and (dist(i, j, locations[3][0], locations[3][1]) > nsteps - step 
        or visited[locations[3][0]][locations[3][1]]))
    return 0;

  if (nsteps/4 == step and (i != locations[0][0] or j != locations[0][1])) return 0;
  if (nsteps/2 == step and (i != locations[1][0] or j != locations[1][1])) return 0;
  if (3*nsteps/4 == step and (i != locations[2][0] or j != locations[2][1])) return 0;
  if (nsteps == step and (i != locations[3][0] or j != locations[3][1])) return 0;
  else if (nsteps == step and i == locations[3][0] and j == locations[3][1]) return 1;

  int mi = 0;
  if (i > 0 and not visited[i-1][j]) {
    visited[i-1][j] = true;
    if (i-1 == 0 and j > 0 and not visited[i-1][j-1]
        and j < m-1 and not visited[i-1][j+1]);
    else
      mi += dfs(step+1, i-1, j);
    visited[i-1][j] = false;
  }
  if (j > 0 and not visited[i][j-1]) {
    visited[i][j-1] = true;
    if (j-1 == 0 and i > 0 and not visited[i-1][j-1]
        and i < n-1 and not visited[i+1][j-1]);
    else
      mi += dfs(step+1, i, j-1);
    visited[i][j-1] = false;
  }
  if (i < n-1 and not visited[i+1][j]) {
    visited[i+1][j] = true;
    if (i+1 == n-1 and j > 0 and not visited[i+1][j-1]
        and j < m-1 and not visited[i+1][j+1]);
    else
      mi += dfs(step+1, i+1, j);
    visited[i+1][j] = false;
  }
  if (j < m-1 and not visited[i][j+1]) {
    visited[i][j+1] = true;
    if (j+1 == m-1 and i > 0 and not visited[i-1][j+1] 
        and i < n-1 and not visited[i+1][j+1]);
    else
      mi += dfs(step+1, i, j+1);
    visited[i][j+1] = false;
  }
  return mi;
}

int main() {
  int ca = 1;
  while (cin >> n >> m) {
    if (n == 0 and m == 0) return 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) visited[i][j] = 0;

    cin >> locations[0][0] >> locations[0][1]
        >> locations[1][0] >> locations[1][1]
        >> locations[2][0] >> locations[2][1];
    locations[3][0] = 0, locations[3][1] = 1;

    visited[0][0] = true;
    cout << "Case " << ca++ << ": " << dfs(1, 0, 0) << endl;
  }
}
