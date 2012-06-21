// ===========================================================================
// 
//       Filename:  Pro006.C
// 
//    Description:  
//    The sum of the squares of the first ten natural numbers is,
//    1^2 + 2^2 + ... + 10^2 = 385
//
//    The square of the sum of the first ten natural numbers is, 
//    (1 + 2 + ... + 10)^2 = 55^2 = 3025
//
//    Hence the difference between the sum of the squares of the first ten natural
//    numbers and the square of the sum is 3025 − 385 = 2640.
//
//    Find the difference between the sum of the squares of the first one hundred
//    natural numbers and the square of the sum.
//
// 
//        Version:  1.0
//        Created:  06/21/2012 04:25:08 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Zhenbin Wu (benwu), benwu@fnal.gov
//        Company:  Baylor University, CDF@FNAL
// 
// ===========================================================================
#include <iostream>
#include <cstdlib>
#include <cmath>

// ===  FUNCTION  ============================================================
//         Name:  StupidMD
//  Description:  What we need is sum(i)^2 - sum(i^2), but I forgot the math..
//  Maybe it should be 2*i*j 
// ===========================================================================
int StupidMD(int range)
{
  int result = 0;
  for (int i = 1; i <= range; ++i)
  {
    for (int j = i+1; j <= range; ++j)
    {
      if (i == j)
      {
        continue;
      }
      result += i*j;
    }
  }
  result *= 2;

  std::cout<< "result : "<< result << std::endl;

  return result;
}       // -----  end of function StupidMD  -----

// ===  FUNCTION  ============================================================
//         Name:  SmartMD
//  Description:  From the Q, we already know that the sqare sum can be
//  shorten as (n(n+1)/2)^2. What about the sum of square. (This is the key)
//  By simple induction (now I remember), we can prove that the sum of square
//  is (2n+1)(n+1)n/6 
// ===========================================================================
int SmartMD(int limit) 
{
  int sum = limit*(limit+1)/2;
  int sum_sq = (2*limit+1)*(limit+1)*limit/6;

  int result = (int)pow(sum, 2) - sum_sq;

  std::cout<< "result : "<< result << std::endl;
  return result;
  
}       // -----  end of function SmartMD  -----

int
main ( int argc, char *argv[] )
{
  StupidMD(10);
  StupidMD(100);

  //SmartMD(10);
  //SmartMD(100);
	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
