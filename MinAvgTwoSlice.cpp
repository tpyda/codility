// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include "common.h"

using namespace std;

int solution(vector<int> &A) {
  // write your code in C++11 (g++ 4.8.2)
  size_t N = A.size();
  int rangeLen = 1;
  int rangeSum = A[N - 1];
  int minIdx = 0;
  double minAvg = double(A[N - 1] + A[N - 2]) / 2.0;
  for (int i = N - 2; i >= 0; --i) {
    if (double(A[i] + rangeSum) / double(rangeLen) >
        double(A[i] + A[i + 1]) / 2.0) {
      rangeLen = 2;
      rangeSum = A[i] + A[i + 1];
    } else {
      ++rangeLen;
      rangeSum += A[i];
    }
//    cout << rangeLen << "," << rangeSum << " " << endl;
    if (double(rangeSum) / double(rangeLen) <= minAvg) {
      minAvg = double(rangeSum) / double(rangeLen);
      minIdx = i;
    }
  }
  return minIdx;
}

TEST(test, test) {
  vector<int> v1 = {4, 2, 2, 5, 1, 5, 8};

  EXPECT_EQ(1, solution(v1));

  v1 = {-3, -5, -8, -4, -10};

  EXPECT_EQ(2, solution(v1));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
