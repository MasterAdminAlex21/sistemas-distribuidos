import java.util.*;
import java.net.*;
class cliente{
   public static void main(String K[]){
      //LECTURA
      Scanner sc = new Scanner(System.in);
      //SOCKET
      DatagramSocket socketUDP;
      int serverPuerto = 5000;
      byte[] S, T = new byte[(1 << 10)];
      InetAddress direccionIP;
      socketUDP = null;
      direccionIP = null;
      try{
         socketUDP = new DatagramSocket();
         //ARRAYS QUE CONTENDRAN LA INFORMACIÓN
         //DIRECCION LOCAL
         direccionIP = InetAddress.getByName("localhost");
      }catch(Exception e){
         e.printStackTrace();
      }
      System.out.println("Dame la palabra a buscar: ");
      String query = sc.nextLine();
      //STRING a BYTE ARRAY.
      S = query.getBytes();
      //CONSTRUCCION Y ENVIO
      DatagramPacket paqueteENVIAR = new DatagramPacket(S, S.length, direccionIP, serverPuerto);
      try{
         socketUDP.send(paqueteENVIAR);
      }catch(Exception e){
         e.printStackTrace();
      }
      //CONSTRUCCION Y RECIBO
      DatagramPacket paqueteRECIBE = new DatagramPacket(T, T.length);
      try{
         socketUDP.receive(paqueteRECIBE);   
      }catch(Exception e){
         e.printStackTrace();
      }
      //OBTENER INFORMACION DEL RESULTADO DE LA BUSQUEDA
      System.out.println("SE ENCONTRO EN :");
      String ans = new String(paqueteRECIBE.getData());
      System.out.println( ans);
      socketUDP.close();
   }
}