// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include "common.h"

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
  int p = 0;
  int pEast = 0;
  for (auto it = A.begin();it<A.end(); ++it)
  {
    if (0 == *it)
     ++pEast;
    else
    {
      if (p + pEast > 1000000000) return - 1;
      p+=pEast; 
    }
  }
  return p;
}

TEST (test,test) {
  vector<int> v1 = {0,1,0,1,1};
  EXPECT_EQ(5,solution(v1));
  
  v1 = {0,0,0,0};
  EXPECT_EQ(0,solution(v1));

  v1 = {0,0,0,0,1};
  EXPECT_EQ(4,solution(v1));

  v1 = {0,0,1,1};
  EXPECT_EQ(4,solution(v1));

  v1 = {1};
  EXPECT_EQ(0,solution (v1));

  v1 = {1,1,1,1,0};
  EXPECT_EQ(0,solution (v1));

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
