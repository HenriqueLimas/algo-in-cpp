#include <iostream>
#include <string>
#include "data-structures/rolling_hash.cpp"

bool karpRabin(std::string s, std::string t) {

  int i;
  int ns = s.size();
  int nt = t.size();

  ds::RollingHash *rs = new ds::RollingHash(ns);
  ds::RollingHash *rt = new ds::RollingHash(ns);

  for (i = 0; i < ns; i++) {
    rs->append(s[i]);
  }

  for (i = 0; i < ns; i++) {
    rt->append(t[i]);
  }

  if (rs->hash() == rt->hash()) {
    return true;
  }

  for (i = ns; i < nt; i++) {
    rt->skip(t[i - ns]);
    rt->append(t[i]);

    if (rs->hash() == rt->hash()) {
      return true;
    }
  }

  return false;
}

int main() {
  std::string s = "substr";
  std::string t = "Some nice string with substr inside it";

  std::cout << karpRabin(s, t) << "\n";
}
