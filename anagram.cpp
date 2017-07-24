#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

// Function to check if two strings are anagrams using sort algorithm
bool is_anagram_sort(string s1, string s2) {
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  return s1.compare(s2) == 0;
}

// Function to check if two strings are angrams using map data structure
bool is_anagram_map(string s1, string s2) {
  unordered_map<char,int> s_map;

  for (string::iterator s_it = s1.begin(); s_it != s1.end(); ++s_it) {
    char c = *s_it;

    s_map[c] = s_map[c] ? s_map[c] : 0;
    s_map[c]++;
  }

  for (string::iterator s_it = s2.begin(); s_it != s2.end(); ++s_it) {
    if (!s_map[*s_it]) return false;

    s_map[*s_it]--;
  }

  for (unordered_map<char,int>::iterator m_it = s_map.begin(); m_it != s_map.end(); ++m_it) {
    if (m_it->second > 0) return false;
  }

  return true;
}

int main() {
  cout << is_anagram_sort("altitude", "latitude") << endl;
  cout << is_anagram_sort("yep", "nope") << endl;

  cout << is_anagram_map("altitude", "latitude") << endl;
  cout << is_anagram_map("yep", "nope") << endl;
}
