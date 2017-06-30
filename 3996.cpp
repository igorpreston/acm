#include <iostream>

using namespace std;

void count(int num, int arr[]) {
  while (num) {
    arr[num%10]++;
    num/=10;
  }
}

int main() {
  int tc;
  cin >> tc;
  for (; tc > 0; tc--) {
    int n;
    cin >> n;
    int counts[10];
    for (int i = 0; i <= 9; i++) counts[i] = 0;

    for (int i = 1; i <= n; i++) {
      count(i, counts);
    }
    for (int i = 0; i <= 9; i++) cout << counts[i] 
        << ((i == 9) ? "\n" : " ");
  }
  return 0;
}

