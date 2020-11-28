/*
Quadratic primes

Problem 27
Euler discovered the remarkable quadratic formula:

n2 + n + 41
It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 412 + 41 + 41 is clearly divisible by 41.

The incredible formula  n2 - 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, -79 and 1601, is -126479.

Considering quadratics of the form:

n² + an + b, where |a| < 1000 and |b| < 1000
where |n| is the modulus/absolute value of ne.g. |11| = 11 and |-4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
Answer:
    -59231
CPU:
    700000    microseconds 
MEMORY:
    33676KB    kb
*/

class euler
{
	public static void main (String [] args)
	{
		short a, b;
		short max_a = 0, max_b = 0;
		short maxPrimes = 0;
		short numPrimes;
		
		for(a = -999; a < 1000; a++)
		{
			for(b = -999; b < 1000; b++)
			{
				numPrimes = getPrimes(a,b);//get number of primes
				if(maxPrimes < numPrimes)
				{
					max_a =  a;
					max_b =  b;
					maxPrimes = numPrimes;
				}
			}
		}
		
		System.out.println(max_a*max_b);//Product
	}
	
	public static short getPrimes(short a, short b)
	{
		short n = 0;
		
		while(true)//while  n² + an + b is prime
		{
			if( isPrime( Math.abs((n*n) + a*n + b)) )//if not prime break while
				break;
			n++;
		}
		return n;
	}
	
	public static boolean isPrime(int num)
	{
		for(int div = 2; div < (num/2); div++)
		{
			if(num%div == 0)//if is divisible, return true and break while 
				return true;
		}
		return false;//if is prime, return false
	}
}
