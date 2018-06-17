#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> memo;

int fib(int n)
{
    int f;
    std::unordered_map<int, int>::iterator exists = memo.find(n);
    if (exists != memo.end())
    {
        f = exists->second;
    } else if (n <= 2) {
        f = 1;
    } else {
        f = fib(n - 1) + fib(n - 2);
    }
    memo[n] = f;
    return f;
}

int fib_no_recursion(int n)
{
  std::unordered_map<int, int> fib;

  for(int i = 1; i <= n; i++)
  {
    int f;

    if (i <= 2)
    {
      f = 1;
    } else {
      f = fib[i - 1] + fib[i - 2];
    }

    fib[i] = f;
  }

  return fib[n];
}

int main()
{
  std::cout << fib_no_recursion(7) << "\n";
  return 0;
}
