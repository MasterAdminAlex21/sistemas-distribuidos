public class dos{

	static final double MAX=3000000;

	public dos(){

		double seno=0;
		double coseno=0;
		double tangente=0;
		double logaritmo=0;
		double raizCuad=0;
		double i=0;

		while(i<MAX)
		{
			seno+=Math.sin(i);
			coseno+=Math.cos(i);
			tangente+=Math.tan(i);
			logaritmo+=Math.log10(i);
			raizCuad+=Math.sqrt(i);
			i++;
		}

	}

	public static void main(String []args){
		dos Dos= new dos();
	}

}
