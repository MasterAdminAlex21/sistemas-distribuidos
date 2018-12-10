import java.io.*;
import java.net.*;
import java.nio.ByteBuffer;
import java.nio.*;

public class server_udp{
 public static void main(String[] args) {
  try{
   DatagramSocket s=new DatagramSocket(9876);
   System.out.println("Servidor listo...");
   while(true){
    

    DatagramPacket p=new DatagramPacket(new byte[2000],2000);
    s.receive(p);
    //aqui algo que hacer con el datagrama
    byte[] buffer=new byte[1024];
    buffer=p.getData();
    ByteBuffer bf=ByteBuffer.wrap(buffer);
    bf.order(ByteOrder.LITTLE_ENDIAN);
    String data=new String(buffer);
    //int num=Integer.parseInt(data);
    int num1=bf.getInt();
    double num2=bf.getDouble(8);
    float num3=bf.getFloat(16);
    long num4=bf.getLong(24);

    System.out.println("mensaje recibido: "+data+"\nbuffer: "+buffer+" tamaño: "+data.length()+"\nnum1: "+num1+"\tnum2: "+num2);
    System.out.println("num3: "+num3+"\tnum4: "+num4);
   }//aqui todo el desmadre
  }catch(Exception e){
   e.printStackTrace();

  }//fin catch
 }
}