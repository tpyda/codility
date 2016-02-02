// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>

using namespace std;

int solution(int N) 
{
   if (N < 5) return 0;
   while ( 1 != N % 2 ) N /= 2;

   int gap =0;
   int maxgap = 0;
   while (N != 0)
   {
     cout << N %2 << " ";
     cout << gap << endl;
     if ( 1 == N % 2 )
     {
        if (gap > maxgap) maxgap = gap;
        gap = 0;
     }
     else
     {
       gap++;
     }
     N /= 2;
   }

   cout << endl;
   return maxgap;
}



int main(int argc, char * argv[])
{
  cout << solution(51712) << endl;
}
