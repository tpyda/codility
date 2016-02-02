// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>


#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
  sort(A.begin(),A.end());
  size_t size = A.size();
  for (size_t i = 0; i < size; ++i)
  {
    if (A[i] != i+1) return (i+1);
  }
  return size +1;
}


TEST (test,test) 
{
  vector<int> v1 = {1,2,3,5};
  vector<int> v2 = {5,2,1,3};
  vector<int> v3 = {4,2,3,5};
  vector<int> v4 = {1};
  vector<int> v5 = {2};
  vector<int> v6 = {1,2,3,4};

  EXPECT_EQ(4,solution(v1)); 
  EXPECT_EQ(4,solution(v2)); 
  EXPECT_EQ(1,solution(v3)); 
  EXPECT_EQ(2,solution(v4)); 
  EXPECT_EQ(1,solution(v5)); 
  EXPECT_EQ(5,solution(v6)); 
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
