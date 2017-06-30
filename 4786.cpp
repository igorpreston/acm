#include <iostream>
#include <string>
#include <vector>

using namespace std;

char lookup(string &s) {
  if (s == "00001") return '0';
  if (s == "10001") return '1';
  if (s == "01001") return '2';
  if (s == "11000") return '3';
  if (s == "00101") return '4';
  if (s == "10100") return '5';
  if (s == "01100") return '6';
  if (s == "00011") return '7';
  if (s == "10010") return '8';
  if (s == "10000") return '9';
  if (s == "00100") return '-';
  if (s == "00110") return 0;
  return -1;
}

void reverse(vector<int> &s) {
  for (int i = 0; i < s.size()/2; i++) swap(s[i], s[s.size()-i-1]);
}

int get_val(char c) {
  if (c == '-') return 10;
  return c - '0';
}

int getc(string &s) {
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    ans += (((s.size()-(i+1)) % 10) + 1) * get_val(s[i]);
  }
  return ans % 11;
}

int getk(string &s) {
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    ans += (((s.size()-(i+1)+1) % 9) + 1) * get_val(s[i]);
  }
  ans += getc(s);
  return ans % 11;
}

char get_token(vector<int> vals, int start, int gmin, int gmax) {
  // cout << start << endl;
  string s;
  for (int i = start; i < start + 5; i++) {
    // cout << vals[i]  << ' ' << gmin*1.05 << ' ' << (vals[i] <= gmin*1.05) << endl;
    if (vals[i] <= gmin*1.11) s += '0';
    else if (vals[i] >= gmax*0.899) s += '1';
    else return -1;
  }

  // cout << s << endl;

  return lookup(s);
}

int main() {
  int n, tc = 1;
  while(true) {
    cin >> n;
    if (n == 0) return 0;
    int gmin = 1000, gmax = 0;
    vector<int> vals;
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      gmin = min(c, gmin); gmax = max(gmax, c);
      vals.push_back(c);
    }

    bool reversed = get_token(vals, 0, gmin, gmax) != 0;
    if (reversed) reverse(vals);

    string s;
    bool bad_code = false;
    if (gmax > ((gmin*2) * 1.11) or gmax < ((gmin*2) * 0.899)) {
      s = "bad code";
      goto end;
    }

    for (int i = 0; i < n - 18; i += 6) {
      char t = get_token(vals, i, gmin, gmax);
      if (t == -1) { 
        s = "bad code";
        bad_code = true;
        break;
      } else if (t == 0) continue;
      else s += t;
    }
    // cout << getc(s)  << ' ' <<  get_val(get_token(vals, n-17, gmin, gmax)) << endl;
    // cout << getc(s)  << ' ' <<  getk(s) << endl;
    if (not bad_code and getc(s) != get_val(get_token(vals, n-17, gmin, gmax)))
       s = "bad c";
    if (not bad_code and getk(s) != get_val(get_token(vals, n-11, gmin, gmax)))
       s = "bad k";
    
    /*
    cout << get_token(vals, n-5, gmin, gmax) << ' ' 
         << get_token(vals, 0, gmin, gmax) << endl;
         */

    if (get_token(vals, n-5, gmin, gmax) != 0 
          or get_token(vals, 0, gmin, gmax) != 0)
      s = "bad code";
end:
    cout << "Case " << tc++ << ": " << s << endl;
  }

  return 0;
}
