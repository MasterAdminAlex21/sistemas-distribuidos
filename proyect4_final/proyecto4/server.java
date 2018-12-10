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
    graficador g=new graficador();
    g.setVisible(true);

    DatagramPacket p=new DatagramPacket(new byte[2000],2000);
    double cx,cy;
    int limpia;
    byte[] buffer=new byte[1024];
    while(true){
     s.receive(p);
     //aqui algo que hacer con el datagrama
     
     buffer=p.getData();
     ByteBuffer bf=ByteBuffer.wrap(buffer);
     bf.order(ByteOrder.LITTLE_ENDIAN);
     //cada dato numerico se trata con 8 bytes
     limpia=bf.getInt();
     cx=bf.getDouble(8);
     cy=bf.getDouble(16);

     if(limpia==0){
       g.setClean(true);
     }else{
      g.setClean(false);
     }

     g.coord(cx,cy);

     //enviamos una confirmacion
     byte[] b="reply".getBytes();
     DatagramPacket r=new DatagramPacket(b,b.length,p.getAddress(),p.getPort());
     s.send(r);//*/

    // System.out.println("Datos recibidos: ("+cx+","+cy+")");*/
    }
   //}//aqui todo el desmadre
  }catch(Exception e){
   e.printStackTrace();

  }//fin catch
 }
}