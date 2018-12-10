import java.net.*;
import java.io.*;

public class Servidor {

    public static void main(String args[]) {

        try {
            DatagramSocket socketUDP = new DatagramSocket(7200);
            while(true){
                byte[] bufer = new byte[12];
                DatagramPacket respuesta =
                new DatagramPacket(bufer, bufer.length);
                socketUDP.receive(respuesta);
                System.out.println("Llego un mensaje");
                byte[] numbers = respuesta.getData();
                int a = 0, b = 0, c = 0;
                for(int i = 0; i < 4; i++){
                    int num = 0;
                    for(int j = 0; j < 8; j++){
                        int aux = numbers[i] & 1 << j;
                        num += aux;
                    }
                    a |= num << (8 * i);
                }
                
                for(int i = 0; i < 4; i++){
                    int num = 0;
                    for(int j = 0; j < 8; j++){
                        int aux = numbers[i + 4] & 1 << j;
                        num += aux;
                    }
                    b |= num << (8 * i);
                
                }
                for(int i = 0; i < 4; i++){
                    int num = 0;
                    for(int j = 0; j < 8; j++){
                        int aux = numbers[i + 8] & 1 << j;
                        num += aux;
                    }
                    c |= num << (8 * i);
                
                }
                int sum = a + b;
                System.out.println("a = " + a + " b = " + b + " La suma es: " + sum);
                System.out.println(c);
                byte[] mensaje = new byte[]{(byte) (sum), (byte) (sum >> 8), (byte) (sum >> 16), (byte) (sum >> 24)};
                System.out.println("Direccion del paquete: " + respuesta.getAddress());
                System.out.println("puerto: " + respuesta.getPort());

                DatagramPacket suma = new DatagramPacket(mensaje, mensaje.length, respuesta.getAddress(), respuesta.getPort());
                socketUDP.send(suma);

            }
        } catch (SocketException e) {
            System.out.println("Socket: " + e.getMessage());
        } catch (IOException e) {
            System.out.println("IO: " + e.getMessage());
        }
    }
}
