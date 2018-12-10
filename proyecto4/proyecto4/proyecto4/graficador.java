package proyecto4;

import java.io.*;
import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;
import java.util.*;

public class graficador extends JFrame{
 private int x;
 private int y;
 private int armonicos=1;
 private double cx;
 private double cy;
 private JPanel contentPane;
 public graficador(){
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

 public void coord(double cox,double coy){
  cx=cox;
  cy=coy;
 }

 public void paint(Graphics g){
  super.paint(g);
  g.setColor(Color.blue);
  //el tamaño del circulo sera de 2,2, la posicion se toma segun la funcion
    double auxx,auxy;
  while(true){
    auxx=cx;
    auxy=cy;
    while(auxx==cx || auxy==cy);
    g.fillOval(300+(int)(auxx*300),y-100+(int)(y1*100),2,2);
  }//fin del while
 }



 /*public static void main(String[] args) {
  grafica g1=new grafica();
  g1.setVisible(true);
  int armo=1;
  while(true){
   Scanner leer=new Scanner(System.in);
   //System.out.println("Ingrese numero de armonicos: ");
   //armo=leer.nextInt();
   g1.setArmonico(15);
  }
 }*/
}