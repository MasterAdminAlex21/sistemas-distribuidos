import java.io.FileInputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.ObjectInputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.net.*;
import java.nio.ByteBuffer;

public class ServidorArchivos {
    static final int CREATE = 1; 
    static final int READ = 2;   
    static final int WRITE = 3;  
    static final int DELETE = 4; 

    //static final int PUERTO = 7000;
    static final int TAM_PAQUETE = 1000;

    static final int OK = 1;              
    
    public static void main(String[] args) throws UnknownHostException{
    	if(args.length == 0){
        	System.out.println("Correr primero el cleinte\nModo de uso: java ServidorArchivos PuertoCliente");
        	System.exit(0);
    	}
        String palabra = args[0];
        int puertoC = Integer.parseInt(args[1]);
        try {
            System.out.println("Servidor corriendo :)");
            DatagramSocket s = new DatagramSocket(puertoC);

            DatagramPacket l = new DatagramPacket(new byte[TAM_PAQUETE], TAM_PAQUETE);
            s.receive(l);
            MessageSC a = MessageSC.getClassFromBytes(l.getData());
            InetAddress ip = l.getAddress();
            int puerto = l.getPort();


            
            //byte b[] = new byte[50];
            byte buf[] = palabra.getBytes();
            MessageCS m = new MessageCS(2, 1, 1, palabra);
            //m.setName(palabra);
            
            DatagramPacket p2 = new DatagramPacket(m.getByteRepr(), m.getByteRepr().length, ip, puerto);
            s.send(p2);
            System.out.println("se envio palabra: "+palabra+"\n\nSe recibio:");
            while(true){
                //recibimos datos
                DatagramPacket p = new DatagramPacket(new byte[TAM_PAQUETE], TAM_PAQUETE);
                s.receive(p);
                
                MessageSC c = MessageSC.getClassFromBytes(p.getData());
                int cout = c.getCount();
                int res = c.getResult();
                int offset = c.getOffset();
                //byte b[] = new byte[c.getCount()];
                String info = c.getData();

                System.out.println(info + " ");
            }

        } catch (SocketException ex) { 
            Logger.getLogger(ServidorArchivos.class.getName()).log(Level.SEVERE, null, ex); } catch (IOException ex) {
            Logger.getLogger(ServidorArchivos.class.getName()).log(Level.SEVERE, null, ex);
        }
    }    
}
