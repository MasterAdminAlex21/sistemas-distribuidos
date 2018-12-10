import java.net.*;
import java.io.*;
import java.util.*;

public class ServidorUDP2 {

    public static int isPrime(long n, long a, long b){
        for(long i = a; i <= b; i++)
            if(n % i == 0)
                return 0;
        return 1;
    }


    public static void main (String args[]) {

        try {
            long n = Long.parseLong(args[0]);
            long particion = Long.parseLong(args[1]);
            long section = (n - 2) / particion;

            long[] rango = new long[(int)particion + 1];
            rango[0] = 2;
            for(int i = 1; i <= particion; i++)
                rango[i] = section;
            for(int i = 1; i <= (n - 3) % particion; i++)
                rango[i]++;
            for(int i = 1; i <= particion; i++)
                rango[i] += rango[i - 1];

            int sigPeticion = 0;

            DatagramSocket socketUDP = new DatagramSocket(6789);
            byte[] bufer = new byte[1000];
            boolean primo = true;
            for(int i = 0; i < particion - 1; i++) {
                InetAddress hostServidor = InetAddress.getByName(args[i * 2 + 2]);
                long a = rango[sigPeticion++], b = rango[sigPeticion] - 1;

                String mensaje = "" + n + "," + a + "," + b + ",";
                System.out.println("Se envio el rango[" + a + ", " + b + "]");
                byte[] menSend = mensaje.getBytes();

                DatagramPacket respuesta =
                new DatagramPacket(menSend, menSend.length,
                hostServidor, Integer.parseInt(args[i * 2 + 3]));
                socketUDP.send(respuesta);

            }
            if(isPrime(n, rango[sigPeticion++], rango[sigPeticion] - 1) == 0)
                primo = false;
            System.out.println("yo ya acabe");
            for(int i = 0; i < particion - 1; i++){
                DatagramPacket messagePack = new DatagramPacket(bufer, bufer.length);
                socketUDP.receive(messagePack);
                String message = new String(messagePack.getData());
                System.out.println(message.charAt(0));
                if(message.charAt(0) == '0')
                    primo = false;
            }
            if(primo){
                System.out.println("El numero es primo");
            }else{
                System.out.println("El numero no es primo");
            }
        } catch (SocketException e) {
          System.out.println("Socket: " + e.getMessage());
      } catch (IOException e) {
          System.out.println("IO: " + e.getMessage());
      }
  }

}
