// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include "common.h"

#include <stack>
using namespace std;

int solution(vector<int> &A) {
  // write your code in C++11 (g++ 4.8.2)
  stack<int> S;
  for (auto i : A) {
    if (!S.empty() && S.top() != i)
      S.pop();
    else
      S.push(i);
  }
  if (S.empty()) return 0;
  int candidate = S.top();
  int count = 0;
  int N = A.size();
  int equi = 0;
  for (auto it = A.begin(); it < A.end(); ++it) {
    if (candidate == *it) ++count;
  }
  if (count < N / 2) return 0;
  int e = 0;
  for (int i = 0; i < A.size(); ++i) {
    if (A[i] == candidate) ++e;
    if ((e > (i + 1) / 2) && (count - e > (N - i - 1) / 2)) ++equi;
  }
  return equi;
}

TEST(test, test) {
  vector<int> A;

  A = {4, 3, 4, 4, 4, 2};
  EXPECT_EQ(2, solution(A));

  A = {4, 3, 4, 4};
  EXPECT_EQ(2, solution(A));

  A = {4};
  EXPECT_EQ(0, solution(A));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
