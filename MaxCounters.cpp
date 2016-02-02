// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include "common.h"

using namespace std;


vector<int> solution(int N, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
  vector<int> C(N,0);
  int minc = 0;
  int maxc = 0;
  for (auto i = A.begin(); i < A.end(); ++i)
  {
    int c = *i - 1;
    if (c == N )
    {
      minc = maxc;
    }
    else
    {
      if (C[c] < minc)
      {
        C[c] = minc;
      }
      ++C[c];
      if (maxc<C[c]) maxc = C[c];
    }
//    cout << C << endl;
  }
  for (auto i = C.begin(); i < C.end(); ++i)
  {
    if (*i < minc) *i = minc;
  }
  return C;
}

TEST (test,test) {
   vector<int> v1 = {3,4,4,6,1,4,4};
   vector<int> a1 = {3,2,2,4,2};
   EXPECT_EQ(a1,solution(a1.size(),v1));

   v1 = {1,2};
   a1 = {1};
   EXPECT_EQ(a1,solution(a1.size(),v1));
   
   v1 = {1,1,2,1,1};
   a1 = {4};
   EXPECT_EQ(a1,solution(a1.size(),v1));

   v1 = {1,5,2,5,3,5,4,5};
   a1 = {4,4,4,4};
   EXPECT_EQ(a1,solution(a1.size(),v1));

   v1 = {2};
   a1 = {0};
   EXPECT_EQ(a1,solution(a1.size(),v1));

   v1 = {3,3,3,3,3,3,3,1,2,1};
   a1 = {2,1};
   EXPECT_EQ(a1,solution(a1.size(),v1));

   v1 = {3,1,1,1,2,2,2,2,3};
   a1 = {4,4};
   EXPECT_EQ(a1,solution(a1.size(),v1));

   v1 = {3,1,1,1,2,2,2,2,3,1};
   a1 = {5,4};
   EXPECT_EQ(a1,solution(a1.size(),v1));

   v1 = {4,4,4,4,4,4,4,4,4};
   a1 = {0,0,0};
   EXPECT_EQ(a1,solution(a1.size(),v1));

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
