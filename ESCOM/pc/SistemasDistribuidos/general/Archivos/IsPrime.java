public class IsPrime{
	public static int isPrime(long n, long a, long b){
		for(long i = a; i <= b; i++)
			if(n % i == 0)
				return 0;
		return 1;
	}
}