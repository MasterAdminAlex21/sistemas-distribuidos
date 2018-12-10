
public class TiempoOperaciones
{
    public static void main(String[] args)
    {
        int i = 0;
	int max = 50000000;
	double seno = 0, coseno = 0, tangente = 0, logaritmo = 0, raizCuad = 0;

	while(i < max) {
            seno += Math.sin(i);
            coseno += Math.cos(i);
            tangente += Math.tan(i);
            logaritmo += Math.log10(i);
            raizCuad += Math.sqrt(i);
            
            i++;
	}
    }
    
}