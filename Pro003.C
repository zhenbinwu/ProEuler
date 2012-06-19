// ===========================================================================
// 
//       Filename:  Pro003.C
// 
//    Description:  The prime factors of 13195 are 5, 7, 13 and 29. What is the
//largest prime factor of the number 600851475143 ?  
//
//        Version:  1.0
//        Created:  06/18/2012 08:10:11 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Zhenbin Wu (), benwu@fnal.gov
//        Company:  Baylor University, CDF@FNAL
// 
// ===========================================================================


#include	<cstdlib>
#include <vector>
#include <iostream>
#include <cmath>


  long int
StupidMD ( long long num )
{
  std::vector<long int> prime_factors;
  for (long long  i = 1; i <= num; ++i)
  {
    if (num % i == 0)
    {
      // Find out whether it is a prime factor
      std::vector<long int> factors;
      for (long int j = 1; j <= i; ++j)
      {
        if ( i % j == 0 )
        {
          factors.push_back(j);
        }

      }
      if ((int)factors.size() == 2)
      {
        std::cout<< "Prime Factor:  " << i << std::endl;
        prime_factors.push_back(i);

      }

    }
  }

  long int max=0;
  for(std::vector<long int>::iterator it=prime_factors.begin(); 
      it!=prime_factors.end(); it++)
  {
    max = max > *it ? max : *it;
  }
  std::cout<< "Max Prime Factor : "<< max << std::endl;

  return max;
}		// -----  end of function BruteFroce  -----

long int SmartMD(long long num) 
{
  //Factor out 2 first
  while (num % 2 == 0)
  {
    num = num / 2;
  }

  // Key: n can at most have one prime factor > then sqrt(n)
  int max = 0;
  for (int i = 3; i <= sqrt(num); i+=2)
  {
    if (num % i == 0)
    {
      num = num / i;
      std::cout<< "num :" << num << std::endl;
    }
    max = i;
  }
  max = max > num ? max : num;


  std::cout<< "Prime :" << max << std::endl;

  return max;
  

}

int
main ( int argc, char *argv[] )
{
  //StupidMD(13195);
  //StupidMD(600851475143LL);

  //SmartMD(13195);
  SmartMD(600851475143LL);
  return EXIT_SUCCESS;
}				// ----------  end of function main  ----------

