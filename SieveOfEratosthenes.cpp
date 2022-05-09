#include <iostream>
#include <math.h>
#include <vector>

/// \brief Helper func for determining the constant difference between multiples
/// of a given prime that is equal to that prime
/// \note Determines our inner loop iterator 'j'
uint32_t innerExpCoeff(unsigned int i, unsigned int coeff) {
  return (i * i) + (coeff * i);
}

/// \brief Sieve of Eratosthenes algorithm implementation
/// \note For large input N's, the range of all primes may not fit in memory.
/// For moderate input N's, this algorithm uses suboptimal cache memory. This
/// is why it's important to limit the function's input and return size by type
/// uint8_t.
std::vector<uint8_t> SieveEratosthenes(uint8_t input) {
  /// \brief Prepare
  // Convert char representation of uint8_t to unsigned int
  input = unsigned(input);
  // Create an array to hold primes
  bool isprime[input + 1];
  // Initialize all boolean values to true
  memset(isprime, true, sizeof(isprime));

  /// \brief Begin algorithm
  for (int i = 2; i < sqrt(input); i++) {
    // If the current number is set as prime
    if (isprime[i] == true) {
      /// \brief Prepare inner loop
      unsigned coeff = 0;
      uint32_t j = innerExpCoeff(i, coeff);
      /// \note 'j' will increase as such: i^2, i^2+i, i^2+2i, i^2+3i... and so
      /// on.
      while (j < input) {
        isprime[j] = false;
        coeff++;
        j = innerExpCoeff(i, coeff);
      }
    }
  }

  /// \brief Dump all indices where isprime[i] = true, excluding those which we
  /// know are prime already: 1, and 2 \note return this vector of all primes
  std::vector<uint8_t> allprimes;
  for (int p = 3; p < input; p++) {
    if (isprime[p] == true) {
      allprimes.push_back(p);
    }
  }

  return allprimes;
}

/// \brief Helper func for printing out all primes found by the sieve
inline void pprint(std::vector<uint8_t> const& allprimes) {
  unsigned size = allprimes.size();
  unsigned rowbreak = 20;
  unsigned i = 0;
  for (auto p : allprimes) {
    i++;
    std::cout << unsigned(p);
    if (i == size) {
      break;
    } else if (i == rowbreak || i == rowbreak * 2) {
      std::cout << '\n';
    } else {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
}

/// \brief Driver program to demonstrate the sieve
int main() {
  std::vector<uint8_t> primesToUpperBound = SieveEratosthenes(255);
  std::cout << "The primes up to the given limit: 255. found by Sieve of "
               "Eratosthenes\n\n";

  pprint(primesToUpperBound);
}