import java.net.*;
import java.io.*;

public class ClienteUDP {

    public static int isPrime(long n, long a, long b){
        for(long i = a; i <= b; i++)
            if(n % i == 0)
                return 0;
        return 1;
    }

    public static void main(String args[]) {

        try {

            DatagramSocket socketUDP = new DatagramSocket(Integer.parseInt(args[0]));
            while(true){
                byte[] bufer = new byte[1000];
                DatagramPacket respuesta =
                new DatagramPacket(bufer, bufer.length);
                socketUDP.receive(respuesta);

                String message = new String(respuesta.getData());
                String[] alLMessage = message.split(",");
                long n = Long.parseLong(alLMessage[0]);
                long a = Long.parseLong(alLMessage[1]);
                long b = Long.parseLong(alLMessage[2]);

                System.out.println("Llego la peticion de n = " + n + " [" + a + ", " + b + "]");
                int ans = isPrime(n, a, b);

                System.out.println(ans);
                String num = "" + ans + ",";
                byte[] mensaje = num.getBytes();
                DatagramPacket primo = new DatagramPacket(mensaje, mensaje.length, respuesta.getAddress(), respuesta.getPort());
                socketUDP.send(primo);

            }
        } catch (SocketException e) {
            System.out.println("Socket: " + e.getMessage());
        } catch (IOException e) {
            System.out.println("IO: " + e.getMessage());
        }
    }
}
