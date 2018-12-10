import java.io.*;
import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;
import java.util.*;

public class grafica extends JFrame{
 private int x;
 private int y;
 private int armonicos=1;
 private JPanel contentPane;
 public grafica(){
  setTitle("Graficador");
  setSize(600,400);
  setLocation(370,200);
  setDefaultCloseOperation(EXIT_ON_CLOSE);
  setResizable(false);
  contentPane = new JPanel();
  contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
  setContentPane(contentPane);
  contentPane.setLayout(null);
  x=300;
  y=200;
 }

 public void setArmonico(int arm){
  armonicos=arm;
 }

 public void paint(Graphics g){
  super.paint(g);
  g.setColor(Color.blue);
  //el tamaño del circulo sera de 2,2, la posicion se toma segun la funcion
  
  double y1=Math.PI/2,x1=0;
  int armaux;
  while(true){
   armaux=armonicos;
   for(double auxx=-1;auxx<1;auxx+=0.0001){
    for(int i=1;i<=armonicos;i++){
     y1+=((4*Math.sin(auxx*((i*2)-1)*Math.PI))/(Math.PI*((i*2)-1)));
    }//hace la sumatoria
    
    System.out.println("valor de y: "+y1);
     g.fillOval(300+(int)(auxx*300),y-100+(int)(y1*100),2,2);
    y1=Math.PI/2;
   }

   while(true){
     if(armonicos!=armaux){
      g.setColor(getBackground());
      for(double auxx=-1;auxx<1;auxx+=0.0001){
       for(int i=1;i<=armaux;i++){
        y1+=((4*Math.sin(auxx*((i*2)-1)*Math.PI))/(Math.PI*((i*2)-1)));
       }//hace la sumatoria
       g.fillOval(300+(int)(auxx*300),y-100+(int)(y1*100),2,2);
       y1=Math.PI/2;
      }
     }
    g.setColor(Color.blue);
    break;
   }

  }//fin del while
 }



 public static void main(String[] args) {
  grafica g1=new grafica();
  g1.setVisible(true);
  int armo=1;
  while(true){
   Scanner leer=new Scanner(System.in);
   //System.out.println("Ingrese numero de armonicos: ");
   //armo=leer.nextInt();
   g1.setArmonico(15);
  }
 }
}