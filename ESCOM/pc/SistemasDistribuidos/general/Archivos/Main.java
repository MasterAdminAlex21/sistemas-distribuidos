import java.util.*;
import java.math.*;

public class Main{
	public static void main(String[] args){
		Scanner lec = new Scanner(System.in);
		BigInteger aa = new BigInteger("100000000");
		System.out.println("entro");
		while(true){
			System.out.println(aa);
			if(aa.isProbablePrime(10)){
				System.out.println(aa);
				break;
			}
			aa = aa.add(BigInteger.ONE);
		}
		System.out.println("termino");
	}
		
}