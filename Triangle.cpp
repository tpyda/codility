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
  if (A.size() <3) return 0;
  sort(A.begin(), A.end());
  for (auto it = A.begin(); it < A.end() - 2; ++it) {
    if (*it > *(it + 2) - *(it+1)) return 1;
  }
  return 0;
}

TEST(test, test) {
  vector<int> v1;

  v1 = {10, 2, 5, 1, 8, 20};
  EXPECT_EQ(1, solution(v1));

  v1 = {10, 2, 5, 1, 8, 20};
  EXPECT_EQ(1, solution(v1));

  v1 = {10, 2, 5};
  EXPECT_EQ(0, solution(v1));

  v1 = {2, 5, 1, 3};
  EXPECT_EQ(0, solution(v1));

  v1 = {1, 2, 3};
  EXPECT_EQ(0, solution(v1));

  v1 = {1, 3, 3};
  EXPECT_EQ(1, solution(v1));

  v1 = {3, 3, 3};
  EXPECT_EQ(1, solution(v1));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
