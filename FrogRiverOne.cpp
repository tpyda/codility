// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>

using namespace std;


int solution(int X, vector<int> &A) {
  bool R[X]; //river
  for (int i =0; i< X; ++i)
  {
    R[i] = false;
  }
  int leafesFallen = 0;
  int maxSecond = 0;
  int N = A.size();
  for (int i = 0; i < N; ++i)
  {
    if (A[i] -1 < X)
    if (false == R[A[i]-1])
    {
       ++leafesFallen;
       R[A[i]-1] = true;
       if (i > maxSecond) maxSecond = i;
       if (X == leafesFallen) return maxSecond;
    } 
  }
  return -1;
}


TEST (test,test) {
  vector<int> v1 = {1,3,1,4,2,3,5,4};
  vector<int> v2 = {1,3,1,4,2,3,4,4}; //-1
  vector<int> v3 = {1,1,1,1,1}; 
  vector<int> v4 = {2,3,4}; //-1
  vector<int> v5 = {1,2,3,4};
  vector<int> v6 = {1};
  vector<int> v7 = {2};
  vector<int> v8 = {1,2,3,4,4,5};
  vector<int> v9 = {5,4,3,2,1};

  EXPECT_EQ(6,solution(5,v1));
  EXPECT_EQ(-1,solution(5,v2));
  EXPECT_EQ(0,solution(1,v3));
  EXPECT_EQ(-1,solution(4,v4));
  EXPECT_EQ(-1,solution(5,v5));
  EXPECT_EQ(0,solution(1,v6));
  EXPECT_EQ(-1,solution(1,v7));
  EXPECT_EQ(5,solution(5,v8));
  EXPECT_EQ(4,solution(5,v9));
  EXPECT_EQ(2,solution(3,v8));
  EXPECT_EQ(0,solution(1,v8));


}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
