import java.io.FileInputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.net.*;

public class ServidorArchivos {
    static final int CREATE = 1; 
    static final int READ = 2;   
    static final int WRITE = 3;  
    static final int DELETE = 4; 

    static final int PUERTO = 7000;
    static final int MAXTAM = 1000;

    static final int OK = 1;              
    
    public static void main(String[] args) {
        int cont = 0;
        int num_bytes = 0;
        try {
            DatagramSocket socket = new DatagramSocket(PUERTO);
            System.out.println("Servicio iniciado ...");
            while(true){
                DatagramPacket p = new DatagramPacket(new byte[MAXTAM], MAXTAM);
                socket.receive(p);
                
                if(cont == 0)
                    System.out.println("Se recibió una petición");

                MessageCS c = MessageCS.getClassFromBytes(p.getData());
                int opcion = c.getOpcode();
                InetAddress direccion_cliente = p.getAddress();
                int puerto_cliente = p.getPort();
                
                switch(opcion){
                    case CREATE: 
                        break;

                    case READ:                        
                        byte b[] = new byte[c.getCount()];
                        FileInputStream f = new FileInputStream(c.getName());
                       
                        f.available();
                        f.skip(c.getOffset());
                        
                        num_bytes = f.read(b, 0, c.getCount());
                    
                        MessageSC m = new MessageSC(num_bytes, OK, b);
                        DatagramPacket p2 = new DatagramPacket(m.getByteRepr(), m.getByteRepr().length, direccion_cliente, puerto_cliente);
                        socket.send(p2);
                        break;

                    case WRITE:
                        break;

                    case DELETE:
                        break;                       
                }
                cont++;

                if(num_bytes < 1000){
                    System.out.println("Se envió todo el paquete");
                    cont = 0;
                }
            }

        } catch (SocketException ex) { 
            Logger.getLogger(ServidorArchivos.class.getName()).log(Level.SEVERE, null, ex); } catch (IOException ex) {
            Logger.getLogger(ServidorArchivos.class.getName()).log(Level.SEVERE, null, ex);
        }
    }    
}
