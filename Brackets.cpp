// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <gtest/gtest.h>
#include "common.h"

#include <stack>
using namespace std;

int solution(string &S) {
  // write your code in C++11 (g++ 4.8.2)

  stack<char> k;
  for (int i = 0; i < S.size(); ++i) {
    char c = S[i];
    //    cout << c << endl;
    if ('(' == c || '{' == c || '[' == c) {
      k.push(c);
    } else {
      if (k.empty()) return 0;
      char t = k.top();

      if ('}' == c && '{' != t) return 0;
      if (']' == c && '[' != t) return 0;
      if (')' == c && '(' != t) return 0;
      k.pop();
    }
  }
  if (k.empty())
    return 1;
  else
    return 0;
}

TEST(test, test) {
  string s;

  s = "{[()()]}";
  EXPECT_EQ(1, solution(s));

  s = "([)()]";
  EXPECT_EQ(0, solution(s));

  s = "";
  EXPECT_EQ(1, solution(s));

  s = "{";
  EXPECT_EQ(0, solution(s));

  s = "}";
  EXPECT_EQ(0, solution(s));

  s = "{}";
  EXPECT_EQ(1, solution(s));

  s = "{}}";
  EXPECT_EQ(0, solution(s));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
