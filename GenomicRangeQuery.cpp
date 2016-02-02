// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include "common.h"

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  // write your code in C++11 (g++ 4.8.2)
  int C[S.size() + 1][3];
  C[0][0] = 0;
  C[0][1] = 0;
  C[0][2] = 0;
  for (int i = 0; i < S.size(); ++i) {
    for (int g = 0; g < 3; ++g) C[i + 1][g] = C[i][g];
    if ('A' == S[i]) ++C[i + 1][0];
    if ('C' == S[i]) ++C[i + 1][1];
    if ('G' == S[i]) ++C[i + 1][2];
  }

  /* for (int i = 0; i< S.size()+1;++i)
     {
       cout << i << ": ";
       for (int g = 0;g < 3;++g) cout << C[i][g] << " ";
       cout << endl;
     } */

  size_t M = P.size();

  vector<int> R(M, 4);

  for (int i = 0; i < M; ++i) {
    for (int g = 2; g >= 0; --g) {
      if (C[Q[i] + 1][g] - C[P[i]][g] > 0) R[i] = g + 1;
    }
  }
  return R;
}

TEST(test, test) {
  string S;
  vector<int> P;
  vector<int> Q;
  vector<int> R;

  S = "CAGCCTA";
  P = {2, 5, 0};
  Q = {4, 5, 6};
  R = {2, 4, 1};
  EXPECT_EQ(R, solution(S, P, Q));

  S = "TTTTTTT";
  P = {2, 5, 0};
  Q = {4, 5, 6};
  R = {4, 4, 4};
  EXPECT_EQ(R, solution(S, P, Q));

  S = "C";
  P = {0};
  Q = {0};
  R = {2};
  EXPECT_EQ(R, solution(S, P, Q));

  S = "T";
  P = {0};
  Q = {0};
  R = {4};
  EXPECT_EQ(R, solution(S, P, Q));

  S = "CAGCCTA";
  P = {0, 5, 0};
  Q = {0, 5, 6};
  R = {2, 4, 1};
  EXPECT_EQ(R, solution(S, P, Q));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
