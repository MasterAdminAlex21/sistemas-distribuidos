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
 private double cx=-5;
 private double cy=-5;
 private boolean limpia=false;
 private JPanel contentPane;
 public graficador(){
  setTitle("Graficador");
  setSize(800,600);
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

 public void setClean(boolean clean){
  limpia=clean;
 }

 public void paint(Graphics g){
  super.paint(g);
  g.setColor(Color.blue);
  System.out.println("estoy en paint");
  //el tamaño del circulo sera de 2,2, la posicion se toma segun la funcion
    double auxx=-5,auxy=-5;
  while(true){
    if(limpia){
      g.setColor(getBackground());
    }else{
      g.setColor(Color.blue);
    }
      //System.out.println("cx "+cx+" cy "+cy);
      g.fillOval(400+(int)(cx*400),y-200+(int)(cy*200),2,2);
      
  }//fin del while
 }


}