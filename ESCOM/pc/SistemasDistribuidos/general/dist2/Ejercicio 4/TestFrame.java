import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.Shape;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.awt.geom.Line2D;

import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFrame;
import java.util.*;

import java.awt.Color;

public class TestFrame extends JFrame {

    final Design d=new Design();
    Graphics2D g2d;
    int cont=0;

    public TestFrame() {
        System.out.println("as".equalsIgnoreCase(null));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        init();


        pack();
        setVisible(true);

        d.addRect(400,0,400,600);

        int x,y;
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<100;i++){
            x=sc.nextInt();
            y=sc.nextInt();
            d.addRect(x,y,x,y);
            cont++;
        }


    }

    private void init() {
  
        d.addRect(0,0,10,20);

/*        JButton b = new JButton("add");
        b.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                Random r = new Random();
                int w = r.nextInt(800);
                int h = r.nextInt(600);
                d.addRect(w,w,w,w);
            }
        });*/
        add(d);
        //add(b,BorderLayout.SOUTH);
    }

    public static void main(String... strings) {
        new TestFrame();
    }

    private class Design extends JComponent {
        private static final long serialVersionUID = 1L;

        private List<Shape> shapes = new ArrayList<Shape>();

        public void paint(Graphics g) {
            super.paintComponent(g);
            g2d = (Graphics2D) g;
            if(cont%2==0){
                g2d.setColor(Color.red);
            }else g2d.setColor(Color.green);
            for(Shape s : shapes){
                g2d.draw(s);
            }
        }

        public void addRect(int xPos, int yPos, int width, int height) {
            shapes.add(new Line2D.Double(xPos,xPos,xPos,xPos)/*new Rectangle(xPos,yPos,1,1)*/);
            repaint();
        }

        @Override
        public Dimension getPreferredSize() {
            return new Dimension(800,600);
        }

    }

}