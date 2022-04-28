#include <iostream>
#include <vector>
#include <math.h>

std::vector<uint32_t> SieveEratosthenes(uint32_t input)
{
  bool isprime[input + 1];
  memset(isprime, true, sizeof(isprime));

  for (int i = 2; i < sqrt(input); i++)
  {
    if (isprime[i] == true)
    {
      unsigned coeff = 0;
      for (int j = (i * i) + (coeff * i); j < input; coeff++)
      {
        isprime[j] = false;
        j = (i * i) + (coeff * i);
      }
    }
  }

  std::vector<uint32_t> allprimes;
  for (int p = 0; p < input; p++)
  {
    if (isprime[p] == true)
    {
      allprimes.push_back(p);
    }
  }

  return allprimes;
}

int main()
{
  std::vector<uint32_t> primesOf99 = SieveEratosthenes(99);
  std::cout << "The primes of 99, found by Sieve of Eratosthenes\n\n";
  for(auto p : primesOf99)
  {
    std::cout << p << ", ";
  }
  std::cout << std::endl;
}