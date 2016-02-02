// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include "common.h"

#include <stack>
using namespace std;

int solution(vector<int> &A, vector<int> &B) {
  // write your code in C++11 (g++ 4.8.2)
  size_t N = A.size();
  stack<int> S;
  int alive = 0;
  for (int i = 0; i < N; ++i) {
    if (0 == B[i]) {
      while (!S.empty() && S.top() < A[i]) S.pop();
      if (S.empty()) ++alive;
    } else
      S.push(A[i]);
  }
  alive += S.size();
  return alive;
}

TEST(test, test) {
  vector<int> A;
  vector<int> B;

  A = {4, 3, 2, 1, 5};
  B = {0, 1, 0, 0, 0};
  EXPECT_EQ(2, solution(A, B));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
