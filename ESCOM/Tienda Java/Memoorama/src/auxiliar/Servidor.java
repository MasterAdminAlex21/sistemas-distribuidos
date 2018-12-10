/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package auxiliar;
import java.net.*;
import java.io.*;
import javax.swing.JFileChooser;

public class Servidor{
    
    public static void main(String[] args){
        try{
            ServerSocket s = new ServerSocket(9000);
            System.out.println("Esperando Cliente...");
            for(;;){ //Empieza el loop de escuchar
                Socket cl= s.accept(); //se queda escuchando hasta que establece conexión
                System.out.println("Conexión establecida desde:"+cl.getInetAddress()+":"+cl.getPort());
               
                DataOutputStream dos = new DataOutputStream( cl.getOutputStream() );  
                String path = "F:\\Exámen\\imagenesServ\\";

                String files;
                File folder = new File(path);
                File[] listOfFiles = folder.listFiles();
                
               // System.out.println(listOfFiles[0].getName());
                //System.out.println(listOfFiles[0].length());

                for(int i=0;i<23;i++){//24
                   // DataOutputStream dos = new DataOutputStream( cl.getOutputStream());
                    String f=listOfFiles[i].getAbsolutePath();
                    String nombre= listOfFiles[i].getName();
                    Long tam = listOfFiles[i].length();                    
                    DataInputStream dis = new DataInputStream(new FileInputStream(listOfFiles[i]));                    
                    dos.flush();
                    dos.writeUTF(nombre);
                    dos.flush();
                    dos.writeLong(tam);
                    dos.flush();
                                                 
                            byte[] b=new byte [1024];
                    long enviados=0;
                    int porcentaje,n;
                    while (enviados<tam){
                        n=dis.read(b);
                        dos.write(b,0,n);
                        dos.flush();
                        enviados=enviados+n;
                        porcentaje=(int)(enviados*100/tam);
                        }//while
                    System.out.print("Archivo "+nombre+" enviado ("+(i+1)+"/"+listOfFiles[i].length()+")\n");                   
                    dis.close();
                }//for
                dos.close();                
                cl.close();
            }//for loop
                }catch (Exception e){
            e.printStackTrace();
	}//Trt Catch
    }// main
}//class
