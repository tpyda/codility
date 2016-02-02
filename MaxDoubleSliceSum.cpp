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
  size_t N = A.size();

  if (N < 4) return 0;
  if (4 == N) return max(A[1], A[2]);

  int lending[N];
  int rending[N];

  lending[0] = 0;
  rending[0] = 0;
  lending[N - 1] = 0;
  rending[N - 1] = 0;

  // cout << "----------------" << endl;

  int max_ending = 0;
  for (int i = 1; i < N - 1; ++i) {
    max_ending = max(0, max_ending + A[i]);
    lending[i] = max_ending;
    // cout << max_ending << " ";
  }
  // cout << endl;

  max_ending = 0;
  for (int i = N - 2; i > 0; --i) {
    max_ending = max(0, max_ending + A[i]);
    rending[i] = max_ending;
    // cout << max_ending << " ";
  }
  // cout << endl;

  int max_slice = 0;
  for (int i = 0; i < N - 2; ++i) {
    max_slice = max(max_slice, lending[i] + rending[i + 2]);
    // cout << max_slice << " ";
  }
  // cout << endl;
  return max_slice;
}

TEST(test, test) {
  vector<int> v;

  v = {3, 2, 6, -1, 4, 5, -1, 2};
  EXPECT_EQ(17, solution(v));

  v = {3, 2, 6};
  EXPECT_EQ(0, solution(v));

  v = {-3, -2, -6, -1, -4, -5, -1, -2};
  EXPECT_EQ(0, solution(v));

  v = {3, 2, 6, 4};
  EXPECT_EQ(6, solution(v));

  v = {5, 0, 1, 0, 5};
  EXPECT_EQ(1, solution(v));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
