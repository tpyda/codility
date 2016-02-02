// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>


using namespace std;



int solution(vector<int> &A) 
{
  sort(A.begin(),A.end());
  size_t s = A.size();
  for (size_t i = 0; i < s / 2; ++i)
  { 
    if (A[2*i] != A[2*i+1]) return A[2*i];
  }  
  return A.back();
}

TEST (test,test) {
  vector<int> v  = {1,2,3,1,2,3,4};
  vector<int> v1 = {1,1,2};
  vector<int> v2 = {1,2,2};
    
EXPECT_EQ(4,solution(v));
EXPECT_EQ(2,solution(v1));
EXPECT_EQ(1,solution(v2));


}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
