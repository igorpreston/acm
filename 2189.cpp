#include <iostream>
#include <string>

using namespace std;

string diff(string a, string b) {
  int i;
  for (i = 0; b[i] == a[i]; i++);
  return b.substr(i, b.size()-i);
}

int main() {
  int tc = 1;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) return 0;
    int f, l;
    cin >> l;
    f = l;

    int c;
    cout << "Case " << tc++ << ":\n";
    for (int i = 1; i < n; i++) {
      cin >> c;
      if (c-l > 1) {
        if (l > f) {
          cout << '0' << f << '-' << diff(to_string(f), to_string(l)) << endl;
        } else {
          cout << '0' << f << endl;
        }
        f = c;
      }
      l = c;
    }
    if (f != l) {
      if (l > f) {
        cout << '0' << f << '-' << diff(to_string(f), to_string(l)) << endl;
      } else {
        cout << '0' << f << endl;
      }
    } else cout << '0' << f << endl;
    cout << endl;
  }
}

