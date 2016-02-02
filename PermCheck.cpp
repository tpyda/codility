// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>

using namespace std;


int solution(vector<int> &A)
{
  // write your code in C++11 (g++ 4.8.2)
  int N = A.size();
  bool B[N];
  for (int i = 0; i< N; ++i) B[i] = false;

  for (int i = 0; i< N;++i)
  {
    if (A[i] > N) return 0;
    if (false == B[A[i]-1]) 
    {
      B[A[i]-1] = true;
    }
    else return 0;
  }
  return 1;
}

TEST (test,test) {
  vector<int> v1 = {1,2,3,4};
  vector<int> v2 = {1};
  vector<int> v3 = {1,2,3,3};
  vector<int> v4 = {1,2,4};
  vector<int> v5 = {1};
  vector<int> v6 = {2};
  vector<int> v7 = {1,1,1,1,1};
  vector<int> v8 = {4,3,2,1};
  vector<int> v9 = {4,3,2};


  EXPECT_EQ(1,solution(v1));
  EXPECT_EQ(1,solution(v2));
  EXPECT_EQ(0,solution(v3));
  EXPECT_EQ(0,solution(v4));
  EXPECT_EQ(1,solution(v5));
  EXPECT_EQ(0,solution(v6));
  EXPECT_EQ(0,solution(v7));
  EXPECT_EQ(1,solution(v8));
  EXPECT_EQ(0,solution(v9));
 
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
