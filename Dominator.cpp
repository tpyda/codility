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
  if (S.empty()) return -1;
  int candidate = S.top();
  int count = 0;
  int N = A.size();
  for (auto it = A.begin(); it < A.end(); ++it) {
    if (candidate == *it) ++count;
    if (count > N / 2) return (it - A.begin());
  }
  return -1;
}

TEST(test, test) {
  vector<int> A;

  A = {3,4,3,2,3,-1,3,3};
  int idx = solution(A);
  ASSERT_NE(-1,idx);
  EXPECT_EQ(3,A[solution(A)]);

  A = {3,4};
  idx = solution(A);
  EXPECT_EQ(-1,solution(A));

  A = {1,2,3,4,5};
  idx = solution(A);
  EXPECT_EQ(-1,solution(A));

  A = {3};
  idx = solution(A);
  ASSERT_NE(-1,idx);
  EXPECT_EQ(3,A[solution(A)]);

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }
