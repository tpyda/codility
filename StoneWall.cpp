// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include "common.h"

#include <stack>
using namespace std;

int solution(vector<int> &H) {
  // write your code in C++11 (g++ 4.8.2)
  stack<int> S;
  int bricks = 0;
  for (auto it = H.begin(); it< H.end(); ++it) {
    while (!S.empty() && S.top() > (*it)) S.pop();
    if (S.empty() || S.top() < *it) {
      S.push(*it);
      bricks++;
    }
  }
  return bricks;
}

TEST(test, test) {
  vector<int> H;

  H = {8, 8, 5, 7, 9, 8, 7, 4, 8};
  EXPECT_EQ(7, solution(H));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
