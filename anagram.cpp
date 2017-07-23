#include <iostream>
#include <string>
#include <map>
using namespace std;

// Function to check if two string are anagrams using map data structure
bool is_anagrams(string s1, string s2) {
  map<char, int> s_map;

  for (string::iterator it=s1.begin(); it != s1.end();++it) {
    char c = *it;
    s_map[c] = s_map[c] ? s_map[c] : 0;
    s_map[c]++;
  }

  for (string::iterator it=s2.begin(); it != s2.end();++it) {
    char c = *it;
    map<char, int>::iterator m_it = s_map.find(c);
    if (m_it == s_map.end()) return false;

    s_map[c]--;
  }

  for (map<char, int>::iterator m_it=s_map.begin(); m_it != s_map.end(); ++m_it) {
    if (m_it->second > 0) return false;
  }

  return true;
}

int main () {
  cout << is_anagrams("heart", "earth") << "\n";
  cout << is_anagrams("nope", "yep") << "\n";
}
