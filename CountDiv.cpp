// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include "common.h"

using namespace std;

int solution(int A, int B, int K) {
    // write your code in C++11 (g++ 4.8.2)
   int dB = B / K;
   int dA = A / K;
   if (0 == A%K) --dA;
   return dB-dA;
}


TEST (test,test) {

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
