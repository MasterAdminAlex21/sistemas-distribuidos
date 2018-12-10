import java.util.*;
class Busca{

	public static void main(String args[]){
		int N = 20000, cont = 0;
		String cad = "";
		Random rand = new Random();

		//srand( time(NULL) );

		for( int i = 0; i < N; i++ ){
			cad += (char)(( rand.nextInt(27) % 26 ) + 65);
			cad += (char)(( rand.nextInt(27) % 26 ) + 65);
			cad += (char)(( rand.nextInt(27) % 26 ) + 65);
			cad += ' ';
		}

		int id = -1;
		while ((id = cad.indexOf("IPN", id+1)) != -1) {
		  	cont++;
		}
		System.out.println( cont );
		//string aux = cad;
		//cout << cad<<endl;
	}
}