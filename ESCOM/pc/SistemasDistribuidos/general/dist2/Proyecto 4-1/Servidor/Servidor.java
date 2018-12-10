import java.io.FileInputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.net.*;

public class Servidor {

    static final int PUERTO = 7000;
    static final int MAXTAM = 1000;

    static final int READ = 2;   


    static final int OK = 0;              
    
    public static void main(String[] args) {
        

        try {
            DatagramSocket socket = new DatagramSocket(PUERTO);
            System.out.println("Servicio iniciado ...");
            boolean newService = true;

            while(true){

                DatagramPacket packReceive = new DatagramPacket(new byte[MAXTAM], MAXTAM);
                socket.receive(packReceive);
                
                InetAddress IPCliente = packReceive.getAddress();
                int PortCliente = packReceive.getPort();

                if(newService){
                    System.out.println("Inicio un servicio...");
                    System.out.println("IP: " + IPCliente + "   PUERTO: " + PortCliente);
                    newService = false;
                }

                MensajeClienteServidor petition = MensajeClienteServidor.getClassFromBytes(packReceive.getData());
                int opcion = petition.getOpcode();

                switch(opcion){

                    case READ:                        
                        byte aux[] = new byte[MAXTAM];
                        FileInputStream fileBuffer = new FileInputStream(petition.getName());
                       
                        fileBuffer.available();
                        fileBuffer.skip(petition.getOffset());
                        int bytesRead = fileBuffer.read(aux, 0, MAXTAM); 
                        if(bytesRead <= 1000)
                            newService = true;
                        
                        System.out.println(petition.getCount() + " ::  " + bytesRead);
                        MensajeServidorCliente message = new MensajeServidorCliente((bytesRead == -1 ? 0 : bytesRead), OK, petition.getOffset(), aux);
                        DatagramPacket packSend = new DatagramPacket(message.getByteRepr(), message.getByteRepr().length, IPCliente, PortCliente);
                        socket.send(packSend);
                        break;                      
                }
                if(newService)
                    System.out.println("Termino de enviar el archivo.");
                
            }

        } catch (IOException e) { 
            e.printStackTrace();
        }
    }    
}

