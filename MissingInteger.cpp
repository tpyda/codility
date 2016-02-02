// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>


#include <algorithm>
using namespace std;


int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
  A.push_back(0);
  sort(A.begin(),A.end());
  for (auto it = A.begin(); it < A.end()-1; ++it)
  {
    if ((*it+1 >0) &&  (*(it+1) > (*it+1))) return *it+1;
  }
  return A.back() +1;    

}

TEST (test,test) {

  vector<int> v1 = {1,2,4};
  vector<int> v2 = {1};
  vector<int> v3 = {1,2,3};
  vector<int> v4 = {2,2,2};
  vector<int> v5 = {1,1,4};
  vector<int> v6 = {1,2,2,4};
  vector<int> v7 = {1,1,1};
  vector<int> v8 = {1,1,2,2,2};
  vector<int> v9 = {-1};

  EXPECT_EQ(3,solution(v1));
  EXPECT_EQ(2,solution(v2));
  EXPECT_EQ(4,solution(v3));
  EXPECT_EQ(1,solution(v4));
  EXPECT_EQ(2,solution(v5));
  EXPECT_EQ(3,solution(v6));
  EXPECT_EQ(2,solution(v7));
  EXPECT_EQ(3,solution(v8));
  EXPECT_EQ(1,solution(v9));

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
