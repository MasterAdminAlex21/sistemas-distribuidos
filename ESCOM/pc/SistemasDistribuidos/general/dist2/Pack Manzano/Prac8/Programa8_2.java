import java.io.*;
import java.util.*;
import java.lang.Math.*;
class Programa8_2{
	
	static int Max = 10000;
	
	public static void main(String args[]){
		double sen = 0.00;
		double cose = 0.00;
		double tg = 0.00;
		double loga = 0.00;
		double raiz = 0.00;
		int i=1;
		
		while(i < Max){
			sen = sen + Math.sin(i);
			cose = cose + Math.cos(i);
			tg = tg + Math.tan(i);
			loga = loga + Math.log10(i);
			raiz = raiz + Math.sqrt(i);
			i++;	
		}
		/*System.out.println(""+sen);
		System.out.println(""+cose);
		System.out.println(""+tg);
		System.out.println(""+loga);
		System.out.println(""+raiz);*/
		
	}
}