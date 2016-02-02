// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
   size_t vSize = A.size();
   if (0 == vSize) return A;
   K = K % vSize;
   vector<int> P = A;
   for (int i = 0; i < vSize; ++i)
   {
     P[(i+K) % vSize] = A[i];
   }
   return P;
}

TEST (test,test) {
   std::vector<int> v = {1, 2, 3, 4}; 
   std::vector<int> v1 = {4,1,2,3};
   std::vector<int> e = {};


   EXPECT_EQ(v,solution(v,0));
   EXPECT_EQ(v1,solution(v,1)); 
   EXPECT_EQ(e,solution(e,100));
   EXPECT_EQ(v,solution(v,40));
   EXPECT_EQ(v1,solution(v,5)); 
   
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
