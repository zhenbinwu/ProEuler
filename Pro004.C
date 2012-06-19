// ===========================================================================
// 
//       Filename:  Pro004.C
// 
//    Description:  A palindromic number reads the same both ways. The largest
//    palindrome made from the product of two 2-digit numbers is 9009 = 91 ×
//    99.
//
//    Find the largest palindrome made from the product of two 3-digit
//    numbers.
//
// 
//        Version:  1.0
//        Created:  06/18/2012 09:37:39 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Zhenbin Wu (), benwu@fnal.gov
//        Company:  Baylor University, CDF@FNAL
// 
// ===========================================================================

#include <cmath>

#include <iostream>

void StupidMD(const int max)
{
  long int maxrange = max * max;

  for (int palin = maxrange; palin > 1; palin--)
  {
    int rank =0;
    for (int i = 1; i < max; ++i)
    {
      if ((int)(palin / pow(10, i)) == 0)
      {
        rank = i-1;
        break;
      }
    }

    bool palindromic = false;
    for (int i = 0; i < rank; ++i)
    {
      int first =(palin / (int)pow(10,i)) % 10 ;
      int last =  (palin / (int)pow(10,rank-i)) % 10 ;

      if (first != last)
        break;
      if (i == rank -1)
        palindromic = true;
      
    }
    if (palindromic)
    {
      bool found = false;
      for (int i = max; i > 1; i--)
      {
        if (palin % i == 0 )
        {
          //std::cout<< "palindrome " << palin <<" factors :" << i <<" " << palin / i<< std::endl;
          if (((i / (max/10)) != 0 && (i / max) == 0)
           && ((palin/ i )/ (max/ 10)) != 0 && ((palin/ i)/ max == 0))
           {
          std::cout<< "palindrome " << palin <<" factors :" << i <<" " << palin / i<< std::endl;
          found = true;
          break;
          }
        }
      }
      if (found) break;
    }
  }


  return ;
  
}


  int
main(int argc, char **argv)
{
  
  StupidMD(1000);
  //StupidMD(100);
  return 0;
}
