

public class numerico
{
	static final double MAX=3000000;

	public numerico()
	{
		double cose=0;
		double seno=0;
		double tang=0;
		double loga=0;
		double raiz=0;
		double i=0;



		while(i<MAX)
		{
			cose+=Math.cos(i);
			seno+=Math.sin(i);
			tang+=Math.tan(i);
			loga+=Math.log10(i);
			raiz+=Math.sqrt(i);
			i++;

		}
	}
		public static void main (String[] args) 
		{
			numerico Numerico= new numerico();
		
		} 
}