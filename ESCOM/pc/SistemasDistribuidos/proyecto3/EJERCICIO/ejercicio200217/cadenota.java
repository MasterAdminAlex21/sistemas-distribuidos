import java.util.*;

public class cadenota{

	public static int veces(String cadenota){
		int count=0;
		for(int i =0;i<cadenota.length();i++){
			if(cadenota.charAt(i) == 'I' && cadenota.charAt(i+1) == 'P' && cadenota.charAt(i+2) == 'N')
				count++;
			i+=3;	
		}
		return count;
	}

	public cadenota(){

		double longitud=1000000;
		String cadena="";
		long azar = new java.util.GregorianCalendar().getTimeInMillis();
		Random r = new Random(azar);
		double i = 0;
		double y=0;

		while ( i < longitud){
			int c = r.nextInt(26) +65;
			cadena += (char)c;
			i ++;
			c = r.nextInt(26) +65;
			cadena += (char)c;
			i ++;
			c = r.nextInt(26) +65;
			cadena += (char)c;
			i ++;
			cadena += " ";
			i++;
		}

		System.out.println(veces(cadena));
	}

	public static void main(String []args){
		cadenota cade=new cadenota();
	}

}
