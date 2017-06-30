#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int to_min(string &s) {
  istringstream iss(s);
  string token;
  getline(iss, token, ':');
  int h = stoi(token);
  getline(iss, token, ':');
  int m = stoi(token);
  return h*60+m;
}

int main() {
  int n;
  cin >> n;
  for (int tc = 1; tc <= n; tc++) {
    string in;
    cin >> in;
    int wstart = to_min(in);
    cin >> in;
    int wend = to_min(in);

    cin >> in;
    int mstart = to_min(in);
    cin >> in;
    int mend = to_min(in);

    if (mstart > wend or mend < wstart) cout << "Case " << tc << ": Hits Meeting\n";
    else cout << "Case " << tc << ": Mrs Meeting\n";
  }

  return 0;
}


