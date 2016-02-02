// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include "common.h"

#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
  // write your code in C++11 (g++ 4.8.2)
  sort(A.begin(), A.end());
  size_t N = A.size();
  int a = A[0] * A[1] * A[N - 1];
  int b = A[N - 3] * A[N - 2] * A[N - 1];
  if (a > b)
    return a;
  else
    return b;
}

TEST(test, test) {
  vector<int> v1;

  v1 = {-3, 1, 2, -2, 5, 6};
  EXPECT_EQ(60, solution(v1));

  v1 = {-3, -2, -1, 0, 1};
  EXPECT_EQ(6, solution(v1));

  v1 = {-3, -2, -1, 0};
  EXPECT_EQ(0, solution(v1));

  v1 = {-3, -2, 1, 2, 3};
  EXPECT_EQ(18, solution(v1));

  v1 = {-3, -3, -2, -2, 1, 2, 3, 4};
  EXPECT_EQ(36, solution(v1));

  v1 = {-5, 1, 2, 3};
  EXPECT_EQ(6, solution(v1));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
