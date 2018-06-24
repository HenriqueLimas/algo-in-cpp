#include <iostream>
#include <string.h>

using namespace std;

int count(string coded) {
  int v[coded.size() + 1];

  v[0] = 1;
  v[1] = 1;

  int i;

  for (i = 2; i <= coded.size(); i++) {
    v[i] = 0;

    if (coded[i - 1] > '0') {
      v[i] = v[i - 1];
    }

    if (coded[i - 2] == '1' || (coded[i - 2] == '2' && coded[i - 1] < '7')) {
        v[i] += v[i - 2];
    }
  }

  return v[coded.size()];
}

int main() {
  cout << count("1234") << endl;
}
