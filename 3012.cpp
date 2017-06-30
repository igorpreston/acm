#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main() {
  int n;
  int tc = 1;
  while(true) {
    cin >> n;
    if (n == 0) return 0;
    if (tc != 1) cout << endl;
    int sum = 0, in;
    for (int i = 0; i < n; i++) {
      cin >> in;
      sum += in;
    }

    bool neg = sum < 0;
    sum = abs(sum);
    int a = sum/n;
    int b = sum%n;
    int c = n;

    // Reduce the fraction
    int r = gcd(b, c);
    b /= r; c/= r;

    cout << "Case " << tc++ << ":\n";

    string s;
    if (neg) s += "- "; 
    if (a > 0) s += to_string(a);

    if (c == 1) {
      if (b == 0 and a != 0) cout << s; 
      else cout << a*b;
    } else {
      string space(s.size(), ' '),
             space2(to_string(c).size()-to_string(b).size(), ' ');
      string dash(to_string(c).size(), '-');
      cout << space << space2 << b << endl;
      cout << s << dash << endl;
      cout << space << c;
    }
    /*
    double sol = ((double)sum)/n;
    if (a) b += a*c;
    double got = ((double)b)/c;
    cout << sol << ' ' << got << endl;
    if (fabs(got-sol) > 0.0001) cout << "WROOOOOOOOOOOOOOOOOOOOOOOOOONG" << endl; 
    */
  }
}
