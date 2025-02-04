Amar 1 ta matrix ase amar diagonal e largest prime check
steps:
1.First iterate 2 for loop nested for traverse the full matrix.
2.Then check diagonal by this 
   if(i==j||(i+j==nums.size()-1))
  for prime checking implement a function 
bool isPrime(int num) 
 {
        if (num <= 1) 
        return false;
        if (num <= 3)
         return true;
        if (num % 2 == 0 || num % 3 == 0) 
        return false;
        for (int i = 5; i * i <= num; i += 6) 
        {
            if (num % i == 0 || num % (i + 2) == 0) 
            return false;
        }
        return true;
    }
then call it 

            if(i==j||(i+j==nums.size()-1))
            {
                 if (isPrime(nums[i][j])) {
                        prime = nums[i][j];
                        primes.push_back(prime);
                    }
            }
i take a vector array to save the record of prime number in diagonal 
check largest prime
 if (!primes.empty()) 
        {
            largestPrime = primes[0];
            for (int prime : primes) 
            {
                if (prime > largestPrime)
                 {
                    largestPrime = prime;
                }
            }
        }
         return largestPrime;
    }
