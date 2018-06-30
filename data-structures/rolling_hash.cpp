#define ALPHABET_SIZE 256
#define M 997

namespace ds {
class RollingHash {
  int hashValue;
  long RM;

  public:
    RollingHash(int n);
    void append(char c);
    void skip(char c);
    int hash();
};

RollingHash::RollingHash(int n) {
  hashValue = 0;

  RM = 1;

  for (int i = 1; i < n; i++) {
    RM = (ALPHABET_SIZE * RM) % M;
  }
}

void RollingHash::append(char c) {
  hashValue = (hashValue * ALPHABET_SIZE + c) % M;
}

void RollingHash::skip(char c) {
  hashValue = (hashValue + M - RM * c % M) % M;
}

int RollingHash::hash() {
  return hashValue;
}
};
