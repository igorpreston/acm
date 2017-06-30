#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int min_dist(string &s) {
  int a = 1000;
  for (int i = 1; i < s.size(); i++) a = min(a, abs(s[i-1]-s[i]));
  return a;
}

int main() {
  
  string p, copy;
  while(cin >> p) {
    copy = p;
    string perm = p;
    int dist = min_dist(p);

    for (int i = 0; i < 10; i++) {
      prev_permutation(copy.begin(), copy.end());
      int cdist = min_dist(copy);
      if (cdist >= dist) {
        perm = copy;
        dist = cdist;
      }
    }

    copy = p;
    for (int i = 0; i < 10; i++) {
      next_permutation(copy.begin(), copy.end());
      int cdist = min_dist(copy);
      if (cdist > dist) {
        perm = copy;
        dist = cdist;
      }
    }

    cout << perm << dist << endl;
  }

  return 0;
}
