// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include "common.h"

#include <set>
using namespace std;

int solution(vector<int> &A) {
  // write your code in C++11 (g++ 4.8.2)
  set<int> S;
  for (auto it = A.begin(); it < A.end(); ++it) {
    S.insert(*it);
  };

  return S.size();
}

TEST(test, test) {}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
