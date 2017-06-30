#include <iostream>
#include <cstdio>
#include <set>
#include <string>

using namespace std;

typedef pair<int, int> ii;

int reg[3001];

int main() {
  string null;
  int n, c;
  set<ii> q;
  while(scanf("Register %d %d\n", &n, &c)) {
    reg[n] = c;
    q.insert(make_pair(c, n));
  }
  getline(cin, null);
  int k; cin >> k;

  for (int i = 0; i < k; i++) {
    ii top = *(q.begin()); q.erase(q.begin());
    cout << top.second << endl;
    q.insert(make_pair(top.first + reg[top.second], top.second));
  }

  return 0;
}



