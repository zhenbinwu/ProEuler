// ===========================================================================
// 
//       Filename:  Pro005.C
// 
//    Description:  2520 is the smallest number that can be divided by each of
//    the numbers from 1 to 10 without any remainder.
//
//    What is the smallest positive number that is evenly divisible by all of
//    the numbers from 1 to 20?
//
// 
//        Version:  1.0
//        Created:  06/19/2012 12:35:01 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Zhenbin Wu (), benwu@fnal.gov
//        Company:  Baylor University, CDF@FNAL
// 
// ===========================================================================


#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>

#include <boost/foreach.hpp>
// ===  FUNCTION  ============================================================
//         Name:  StupidMD
//  Description:  Silly force 
// ===========================================================================
int StupidMD(int begin, int end)
{

  int smallest = end;
  bool found = false;
  while ( true )
  {
    for ( int i = begin; i <= end; ++i )
    {
      if ( smallest % i != 0 )
        break;
      if ( i == end )
      {
        found = true;
      }
    }

    if ( !found )
    {
      smallest++;
    }
    else
      break;

  }

  std::cout<< "smallest is "<< smallest << std::endl;
  return smallest;
}       // -----  end of function StupidMD  -----

// ===  FUNCTION  ============================================================
//         Name:  GetPrimeList
//  Description:  This is a function that will return a set of all the prime number
// ===========================================================================
std::set<int> GetPrimeList(int begin, int end)
{
  std::set<int> prime;
  prime.insert( 2 );

  // Looping over the range
  for ( int i = 2; i <= end; ++i )
  {
    bool isprime = true;
    for(std::set<int>::iterator it=prime.begin();
      it!=prime.end(); it++)
    {
      if ( i % *it == 0 )
      {
        isprime = false;
        break;
      }
    }
    if ( isprime ) prime.insert( i );
  }


  std::set<int> re_prime = prime;
  for(std::set<int>::iterator it=prime.begin();
      it!=prime.end(); it++)
  {
    if (*it < begin || *it > end)
    {
      re_prime.erase(*it);
    }
  }

  
  BOOST_FOREACH(int p, re_prime)
  {
    std::cout<< p <<" "; 
  }

  return prime;
}       // -----  end of function GetPrimeList  -----

// ===  FUNCTION  ============================================================
//         Name:  SmartMD
//  Description:  The smallest number can be factorized into prime factors.
//  Num = sum(p[i]^a[i])
//  For 2, 4, 8 ..., we can find out the max power of 2 by log(N)/log(2) 
//  If n^2 > N, then it should only contain has power to one
// ===========================================================================
int SmartMD(int begin, int end)
{
  std::set<int> prime = GetPrimeList(begin, end);
  int result = 1; //The result we need
  BOOST_FOREACH(int p, prime)
  {
    int a = 1;  //Default , a = 1 
    // Whether we should check a[i]
    if (pow(p, 2) < end)
    {
      // Need to calculate a[i]
      a = (int)(log(end)/ log(p));
    }

    result *= (int)pow(p, a);
  }
  std::cout<< "result : " << result << std::endl;
  return result;
}       // -----  end of function SmartMD  -----
//----------------------------------------------------------------------------
//  Need to learn a better and safer way for cast in C++
//----------------------------------------------------------------------------

  int
main ( int argc, char *argv[] )
{
  //StupidMD( 1, 10 );
  //StupidMD( 1, 20 );

  //SmartMD( 1, 10 );
  SmartMD( 1, 20 );
  return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
