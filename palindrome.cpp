#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

bool is_palindrome_rvs(string s) {
  string r_s(s);

  reverse(r_s.begin(), r_s.end());

  return s.compare(r_s) == 0;
}

bool is_palindrome_set(string s) {
  set<char> s_set;

  for (string::iterator s_it=s.begin();s_it != s.end(); ++s_it) {
    if (s_set.find(*s_it) == s_set.end()) {
      s_set.insert(*s_it);
    } else {
      s_set.erase(*s_it);
    }
  }

  return s_set.size() <= 1;
}

int main() {
  cout << is_palindrome_rvs("toot") << "\n";
  cout << is_palindrome_rvs("nope") << "\n";
  cout << is_palindrome_set("toot") << "\n";
  cout << is_palindrome_set("toto") << "\n";
  cout << is_palindrome_set("nope") << "\n";
}
