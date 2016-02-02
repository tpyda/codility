// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>

using namespace std;

#include <limits>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
  int sumr = 0;
  int suml = 0;

  for (auto it = A.begin(); it < A.end(); ++it )
  { 
    sumr += *it;
  }
  int diff = numeric_limits<int>::max();
  for (auto it = A.begin(); it < A.end()-1; ++it)
  {
    suml+=*it;
    sumr-=*it;
    //cout << *it << " " << suml << " " << sumr << " " << suml - sumr << " " << it - A.begin() << endl;
    if (abs(suml - sumr) < diff)
    { 
      diff = abs(suml - sumr);
    }
  }
  return diff;
}


TEST (test,test) {
  vector<int> v  = {3,1,2,4,3};
  vector<int> v2 = {6,10};
  vector<int> v3 = {-1000,1000};
  vector<int> v4 = {2000,0};
  EXPECT_EQ(1,solution(v));
  EXPECT_EQ(4,solution(v2));
  EXPECT_EQ(2000,solution(v3));
  EXPECT_EQ(2000,solution(v4));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
