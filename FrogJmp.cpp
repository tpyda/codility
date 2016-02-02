// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>

using namespace std;


int solution(int X, int Y, int D) {
 int jumps = (Y - X ) / D;
 if ((Y-X) % D) ++jumps;
 return jumps;
}

TEST (test,test) {

   EXPECT_EQ(1,solution(1,2,1));
   EXPECT_EQ(2,solution(1,3,1));
   EXPECT_EQ(1,solution(1,3,2));
   EXPECT_EQ(2,solution(1,4,2));
   EXPECT_EQ(2,solution(1,5,2));
   EXPECT_EQ(3,solution(1,6,2));

   

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
