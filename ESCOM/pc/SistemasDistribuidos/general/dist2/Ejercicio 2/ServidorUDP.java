import java.net.*;
import java.io.*;
import java.util.*;

public class ServidorUDP {

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
            long section = (n - 2) / 9;

            long[] rango = new long[(int)particion + 1];
            rango[0] = 2;
            rango[1] = section + 2;
            rango[2] =(long)( (double)section * 3.4) + rango[2];
            rango[3] = n;


            int sigPeticion = 0;

            DatagramSocket socketUDP = new DatagramSocket(6789);
            byte[] bufer = new byte[1000];
            boolean primo = true;
            for(int i = 0; i < particion - 1; i++) {
                InetAddress hostServidor = InetAddress.getByName(args[i * 2 + 2]);
                long a = rango[sigPeticion++], b = rango[sigPeticion] - 1;

                String mensaje = "" + n + "," + a + "," + b + ",";
                byte[] menSend = mensaje.getBytes();

                DatagramPacket respuesta =
                new DatagramPacket(menSend, menSend.length,
                hostServidor, Integer.parseInt(args[i * 2 + 3]));
                socketUDP.send(respuesta);
                System.out.println("Se envio el rango[" + a + ", " + b + "]");

            }

            System.out.println("Yo hago [" + rango[sigPeticion] + ", " + rango[sigPeticion + 1] + "]");
            if(isPrime(n, rango[sigPeticion++], rango[sigPeticion] - 1) == 0)
                primo = false;
            System.out.println("Yo ya acabe");
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

