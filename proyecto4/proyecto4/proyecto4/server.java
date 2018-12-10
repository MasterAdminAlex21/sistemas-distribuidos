//graficador server
package proyecto4;
import java.io.*;
import java.net.*;
import java.nio.ByteBuffer;
import java.nio.*;

public class server{
 public static void main(String[] args) {
  try{
   DatagramSocket s=new DatagramSocket(9876);
   System.out.println("Servidor listo...");
   //while(true){
    

    DatagramPacket p=new DatagramPacket(new byte[2000],2000);
    double cx,cy;
    byte[] buffer=new byte[1024];
    while(true){
     s.receive(p);
     //aqui algo que hacer con el datagrama
     
     buffer=p.getData();
     ByteBuffer bf=ByteBuffer.wrap(buffer);
     bf.order(ByteOrder.LITTLE_ENDIAN);
     //cada dato numerico se trata con 8 bytes
     cx=bf.getDouble();
     cy=bf.getDouble(8);

     System.out.println("Datos recibidos: ("+cx+","+cy+")");
    }
   //}//aqui todo el desmadre
  }catch(Exception e){
   e.printStackTrace();

  }//fin catch
 }
}