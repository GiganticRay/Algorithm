#include "bits/stdc++.h"

using ll = long long;
using VI = std::vector<int>;
using VVI = std::vector<VI>;

#define MAXN 1000000 + 4
#define COUT(x) std::cout << (x) << std::endl;
#define CIN(...) (std::cin >> ... >> __VA_ARGS__)
static const int MOD = 1e9 + 7;

#define LOG(fmt, ...)                                                          \
  do {                                                                         \
    char buffer[1024]; /* Adjust buffer size as needed */                      \
    snprintf(buffer, sizeof(buffer), fmt, __VA_ARGS__);                        \
    std::cout << buffer << std::endl;                                          \
  } while (0)

int f[MAXN][20];

/*
  - DP formation
    - define f(i, j) as the wanted number of range [i, i + 2^j - 1], aka [i, i +
  (2 << j) - 1] f(i, j) = op(f(i, j - 1), f(i + 2^(j-1), j - 1))
  - boundary
    - f[i][0] = nums[i] is the boundary scenario
  - why j firstly?
    - depends on the dp dependencies
*/
void RmqInitial(int n) {
  for (int j = 1; j < 21; ++j) {
    for (int i = 0; i < n; ++i) {
      if (i + (1 << (j - 1)) >= n) {
        break;
      }

      f[i][j] = std::max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }

  return;
}

/*
  find a minimum k so that the union of ([l, 2^k), [r - 2^k, r)) contains [l, r).
  which means 2^k <= r - l + 1 <= 2^(k+1)
  => k >= log2(r - l + 1) - 1
*/
int RmqQuery(int l, int r) {
  int k = log(r - l + 1) / log(2);
  return std::max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() { return 0; }