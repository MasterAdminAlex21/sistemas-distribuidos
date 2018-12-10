
package gui;

import auxiliar.LogicaJuego;
import java.awt.BorderLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.plaf.OptionPaneUI;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.net.Socket;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import javax.swing.Icon;
import javax.swing.Timer;


public class PlayGame extends javax.swing.JFrame {

    private VFondo fondo;
    private LogicaJuego log = new LogicaJuego();
    private boolean caraUp = false;
    private ImageIcon im1;
    private ImageIcon im2;
    private JButton[] pbtn = new JButton[2];
    private boolean primerc = false;
    
    /*Cronometro*/
    private Timer t;
    private int h, m, s, cs;
   
    public PlayGame() {
        initComponents();
        fondo = new VFondo(getWidth(), getHeight());
        add(fondo, BorderLayout.CENTER);
       /* btnC1.setEnabled(false);btnC2.setEnabled(false);btnC3.setEnabled(false);btnC4.setEnabled(false);
        btnC5.setEnabled(false);btnC6.setEnabled(false);btnC7.setEnabled(false);btnC8.setEnabled(false);
        btnC9.setEnabled(false);btnC10.setEnabled(false);btnC11.setEnabled(false);btnC12.setEnabled(false);
        btnC13.setEnabled(false);btnC14.setEnabled(false);btnC15.setEnabled(false);btnC16.setEnabled(false);
        btnC17.setEnabled(false);btnC18.setEnabled(false);btnC19.setEnabled(false);btnC20.setEnabled(false);
        btnC21.setEnabled(false);btnC22.setEnabled(false);btnC23.setEnabled(false);btnC24.setEnabled(false);
        btnC25.setEnabled(false);btnC26.setEnabled(false);btnC27.setEnabled(false);btnC28.setEnabled(false);
        btnC29.setEnabled(false);btnC30.setEnabled(false);btnC31.setEnabled(false);btnC32.setEnabled(false);
        btnC33.setEnabled(false);btnC34.setEnabled(false);btnC35.setEnabled(false);btnC36.setEnabled(false);
        btnC37.setEnabled(false);btnC38.setEnabled(false);btnC39.setEnabled(false);btnC40.setEnabled(false);*/
        btnReiniciar.setEnabled(false);
    /*Cronometro*/
        setLocationRelativeTo(null);
        t= new Timer(10, acciones);
    }
    
    /*Cronomero*/
    private ActionListener acciones = new ActionListener(){

        @Override
        public void actionPerformed(ActionEvent ae) {
            ++cs; 
            if(cs==100){
                cs = 0;
                ++s;
            }
            if(s==60) 
            {
                s = 0;
                ++m;
            }
            if(m==60)
            {
                m = 0;
                ++h;
            }
            actualizarLabel();
        }
    };
    
    private void actualizarLabel() {
        String tiempo = (h<=9?"0":"")+h+":"+(m<=9?"0":"")+m+":"+(s<=9?"0":"")+s+":"+(cs<=9?"0":"")+cs;
        Lbltime.setText(tiempo);
    }

    private void setCards() {
        int[] numbers = log.getCardNumbers();
        int z;
        for(z=0;z<40;z++){
          ImageIcon foto = new ImageIcon(getClass().getResource("/imagenes/c" + numbers[z] + ".jpg"));
          ImageIcon tmpIcon = new ImageIcon(foto.getImage().getScaledInstance(120, 100, Image.SCALE_DEFAULT));
          tmpIcon.setDescription("c"+ numbers[z]);
          switch (z) {
            case 0:btnC1.setDisabledIcon(tmpIcon);break;
            case 1:btnC2.setDisabledIcon(tmpIcon);break;
            case 2:btnC3.setDisabledIcon(tmpIcon);break;
            case 3:btnC4.setDisabledIcon(tmpIcon);break;
            case 4:btnC5.setDisabledIcon(tmpIcon);break;
            case 5:btnC6.setDisabledIcon(tmpIcon);break;
            case 6:btnC7.setDisabledIcon(tmpIcon);break;
            case 7:btnC8.setDisabledIcon(tmpIcon);break;
            case 8:btnC9.setDisabledIcon(tmpIcon);break;
            case 9:btnC10.setDisabledIcon(tmpIcon);break;
            case 10:btnC11.setDisabledIcon(tmpIcon);break;
            case 11:btnC12.setDisabledIcon(tmpIcon);break;
            case 12:btnC13.setDisabledIcon(tmpIcon);break;
            case 13:btnC14.setDisabledIcon(tmpIcon);break;
            case 14:btnC15.setDisabledIcon(tmpIcon);break;
            case 15:btnC16.setDisabledIcon(tmpIcon);break;
            case 16:btnC17.setDisabledIcon(tmpIcon);break;
            case 17:btnC18.setDisabledIcon(tmpIcon);break;
            case 18:btnC19.setDisabledIcon(tmpIcon);break;
            case 19:btnC20.setDisabledIcon(tmpIcon);break;
            case 20:btnC21.setDisabledIcon(tmpIcon);break;
            case 21:btnC22.setDisabledIcon(tmpIcon);break;
            case 22:btnC23.setDisabledIcon(tmpIcon);break;
            case 23:btnC24.setDisabledIcon(tmpIcon);break;
            case 24:btnC25.setDisabledIcon(tmpIcon);break;
            case 25:btnC26.setDisabledIcon(tmpIcon);break;
            case 26:btnC27.setDisabledIcon(tmpIcon);break;
            case 27:btnC28.setDisabledIcon(tmpIcon);break;
            case 28:btnC29.setDisabledIcon(tmpIcon);break;
            case 29:btnC30.setDisabledIcon(tmpIcon);break;
            case 30:btnC31.setDisabledIcon(tmpIcon);break;
            case 31:btnC32.setDisabledIcon(tmpIcon);break;
            case 32:btnC33.setDisabledIcon(tmpIcon);break;
            case 33:btnC34.setDisabledIcon(tmpIcon);break;
            case 34:btnC35.setDisabledIcon(tmpIcon);break;
            case 35:btnC36.setDisabledIcon(tmpIcon);break;
            case 36:btnC37.setDisabledIcon(tmpIcon);break;
            case 37:btnC38.setDisabledIcon(tmpIcon);break;
            case 38:btnC39.setDisabledIcon(tmpIcon);break;
            case 39:btnC40.setDisabledIcon(tmpIcon);break;
            default:break;
          }//switch
        this.repaint();
        }//for
    }

    private void btnEnabled(JButton btn) {
        if (!caraUp) {
            btn.setEnabled(false);
            im1 = (ImageIcon) btn.getDisabledIcon();
            pbtn[0] = btn;
            caraUp = true;
            primerc = false;
        } else {
            btn.setEnabled(false);
            im2 = (ImageIcon) btn.getDisabledIcon();
            pbtn[1] = btn;
            primerc = true;
            pregwin();
        }
    }

    private void compare() {
        if (caraUp && primerc) {
           /* System.out.println(im1.getDescription());
            System.out.println(im2.getDescription());*/
            if (im1.getDescription().compareTo(im2.getDescription()) != 0){
                pbtn[0].setEnabled(true);
                pbtn[1].setEnabled(true);
            }
            caraUp = false;
        }
    }

    private void iniciar(){
        setCards();
        btnC1.setEnabled(true);btnC2.setEnabled(true);btnC3.setEnabled(true);btnC4.setEnabled(true);
        btnC5.setEnabled(true);btnC6.setEnabled(true);btnC7.setEnabled(true);btnC8.setEnabled(true);
        btnC9.setEnabled(true);btnC10.setEnabled(true);btnC11.setEnabled(true);btnC12.setEnabled(true);
        btnC13.setEnabled(true);btnC14.setEnabled(true);btnC15.setEnabled(true);btnC16.setEnabled(true);
        btnC17.setEnabled(true);btnC18.setEnabled(true);btnC19.setEnabled(true);btnC20.setEnabled(true);
        btnC21.setEnabled(true);btnC22.setEnabled(true);btnC23.setEnabled(true);btnC24.setEnabled(true);
        btnC25.setEnabled(true);btnC26.setEnabled(true);btnC27.setEnabled(true);btnC28.setEnabled(true);
        btnC29.setEnabled(true);btnC30.setEnabled(true);btnC31.setEnabled(true);btnC32.setEnabled(true);
        btnC33.setEnabled(true);btnC34.setEnabled(true);btnC35.setEnabled(true);btnC36.setEnabled(true);
        btnC37.setEnabled(true);btnC38.setEnabled(true);btnC39.setEnabled(true);btnC40.setEnabled(true);
        btniniciar.setEnabled(false);
    }
    
    private void reiniciar() {
        setCards();
        primerc = false;
        caraUp = false;
        btnReiniciar.setEnabled(false);
        
    }//reiniciar

    private void pregwin() {
        if (!btnC1.isEnabled() && !btnC2.isEnabled() && !btnC3.isEnabled() && !btnC4.isEnabled() && !btnC5.isEnabled() && !btnC6.isEnabled()
                && !btnC7.isEnabled() && !btnC8.isEnabled() && !btnC9.isEnabled() && !btnC10.isEnabled() && !btnC11.isEnabled()
                && !btnC12.isEnabled() && !btnC13.isEnabled() && !btnC14.isEnabled() && !btnC15.isEnabled() && !btnC16.isEnabled() && !btnC17.isEnabled()
                && !btnC18.isEnabled() && !btnC19.isEnabled() && !btnC20.isEnabled() && !btnC21.isEnabled() && !btnC22.isEnabled() && !btnC23.isEnabled() 
                && !btnC24.isEnabled() && !btnC25.isEnabled() && !btnC26.isEnabled() && !btnC27.isEnabled() && !btnC28.isEnabled() && !btnC29.isEnabled()
                && !btnC30.isEnabled() && !btnC31.isEnabled() && !btnC32.isEnabled() && !btnC33.isEnabled() && !btnC34.isEnabled() && !btnC35.isEnabled()
                && !btnC36.isEnabled() && !btnC37.isEnabled() && !btnC38.isEnabled() && !btnC39.isEnabled() && !btnC40.isEnabled()) {
            JOptionPane.showMessageDialog(this, "Enhorabuena, usted ha ganado. Su tiempo es de: "+Lbltime.getText(), "Felicidades!!", JOptionPane.INFORMATION_MESSAGE);
            if(t.isRunning()) 
        {
            t.stop();
        }
        h=0; m=0; s=0; cs=0;
        actualizarLabel();
        }
    }
    
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jPanel1 = new javax.swing.JPanel();
        btnC1 = new javax.swing.JButton();
        btnC2 = new javax.swing.JButton();
        btnC3 = new javax.swing.JButton();
        btnC4 = new javax.swing.JButton();
        btnC8 = new javax.swing.JButton();
        btnC7 = new javax.swing.JButton();
        btnC6 = new javax.swing.JButton();
        btnC5 = new javax.swing.JButton();
        btnC12 = new javax.swing.JButton();
        btnC11 = new javax.swing.JButton();
        btnC10 = new javax.swing.JButton();
        btnC9 = new javax.swing.JButton();
        btnC16 = new javax.swing.JButton();
        btnC15 = new javax.swing.JButton();
        btnC14 = new javax.swing.JButton();
        btnC13 = new javax.swing.JButton();
        btnC17 = new javax.swing.JButton();
        btnC18 = new javax.swing.JButton();
        btnC19 = new javax.swing.JButton();
        btnC20 = new javax.swing.JButton();
        btnC21 = new javax.swing.JButton();
        btnC22 = new javax.swing.JButton();
        btnC23 = new javax.swing.JButton();
        btnC24 = new javax.swing.JButton();
        btnC25 = new javax.swing.JButton();
        btnC26 = new javax.swing.JButton();
        btnC27 = new javax.swing.JButton();
        btnC28 = new javax.swing.JButton();
        btnC29 = new javax.swing.JButton();
        btnC30 = new javax.swing.JButton();
        btnC31 = new javax.swing.JButton();
        btnC32 = new javax.swing.JButton();
        btnC33 = new javax.swing.JButton();
        btnC34 = new javax.swing.JButton();
        btnC35 = new javax.swing.JButton();
        btnC36 = new javax.swing.JButton();
        btnC37 = new javax.swing.JButton();
        btnC38 = new javax.swing.JButton();
        btnC39 = new javax.swing.JButton();
        btnC40 = new javax.swing.JButton();
        btnReiniciar = new javax.swing.JButton();
        btniniciar = new javax.swing.JButton();
        Lbltime = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Juego Dos Caras");

        jLabel1.setFont(new java.awt.Font("Cyrodiil", 1, 36)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(102, 102, 102));
        jLabel1.setText("MEMORAMA");

        jPanel1.setBackground(new java.awt.Color(0, 0, 0));
        jPanel1.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        btnC1.setBackground(new java.awt.Color(0, 0, 0));
        btnC1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC1.setAutoscrolls(true);
        btnC1.setBorder(null);
        btnC1.setBorderPainted(false);
        btnC1.setContentAreaFilled(false);
        btnC1.setEnabled(false);
        btnC1.setFocusable(false);
        btnC1.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC1.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC1.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC1.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC1MouseExited(evt);
            }
        });
        btnC1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC1ActionPerformed(evt);
            }
        });

        btnC2.setBackground(new java.awt.Color(0, 0, 0));
        btnC2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC2.setBorder(null);
        btnC2.setBorderPainted(false);
        btnC2.setContentAreaFilled(false);
        btnC2.setEnabled(false);
        btnC2.setFocusable(false);
        btnC2.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC2.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC2.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC2.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC2.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC2MouseExited(evt);
            }
        });
        btnC2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC2ActionPerformed(evt);
            }
        });

        btnC3.setBackground(new java.awt.Color(0, 0, 0));
        btnC3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC3.setBorder(null);
        btnC3.setBorderPainted(false);
        btnC3.setContentAreaFilled(false);
        btnC3.setEnabled(false);
        btnC3.setFocusable(false);
        btnC3.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC3.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC3.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC3.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC3.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC3MouseExited(evt);
            }
        });
        btnC3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC3ActionPerformed(evt);
            }
        });

        btnC4.setBackground(new java.awt.Color(0, 0, 0));
        btnC4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC4.setBorder(null);
        btnC4.setBorderPainted(false);
        btnC4.setContentAreaFilled(false);
        btnC4.setEnabled(false);
        btnC4.setFocusable(false);
        btnC4.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC4.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC4.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC4.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC4.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC4MouseExited(evt);
            }
        });
        btnC4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC4ActionPerformed(evt);
            }
        });

        btnC8.setBackground(new java.awt.Color(0, 0, 0));
        btnC8.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC8.setBorder(null);
        btnC8.setBorderPainted(false);
        btnC8.setContentAreaFilled(false);
        btnC8.setEnabled(false);
        btnC8.setFocusable(false);
        btnC8.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC8.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC8.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC8.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC8.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC8MouseExited(evt);
            }
        });
        btnC8.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC8ActionPerformed(evt);
            }
        });

        btnC7.setBackground(new java.awt.Color(0, 0, 0));
        btnC7.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC7.setBorder(null);
        btnC7.setBorderPainted(false);
        btnC7.setContentAreaFilled(false);
        btnC7.setEnabled(false);
        btnC7.setFocusable(false);
        btnC7.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC7.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC7.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC7.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC7.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC7MouseExited(evt);
            }
        });
        btnC7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC7ActionPerformed(evt);
            }
        });

        btnC6.setBackground(new java.awt.Color(0, 0, 0));
        btnC6.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC6.setBorder(null);
        btnC6.setBorderPainted(false);
        btnC6.setContentAreaFilled(false);
        btnC6.setEnabled(false);
        btnC6.setFocusable(false);
        btnC6.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC6.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC6.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC6.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC6.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC6MouseExited(evt);
            }
        });
        btnC6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC6ActionPerformed(evt);
            }
        });

        btnC5.setBackground(new java.awt.Color(0, 0, 0));
        btnC5.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC5.setBorder(null);
        btnC5.setBorderPainted(false);
        btnC5.setContentAreaFilled(false);
        btnC5.setEnabled(false);
        btnC5.setFocusable(false);
        btnC5.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC5.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC5.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC5.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC5.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC5MouseExited(evt);
            }
        });
        btnC5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC5ActionPerformed(evt);
            }
        });

        btnC12.setBackground(new java.awt.Color(0, 0, 0));
        btnC12.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC12.setBorder(null);
        btnC12.setBorderPainted(false);
        btnC12.setContentAreaFilled(false);
        btnC12.setEnabled(false);
        btnC12.setFocusable(false);
        btnC12.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC12.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC12.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC12.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC12.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC12MouseExited(evt);
            }
        });
        btnC12.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC12ActionPerformed(evt);
            }
        });

        btnC11.setBackground(new java.awt.Color(0, 0, 0));
        btnC11.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC11.setBorder(null);
        btnC11.setBorderPainted(false);
        btnC11.setContentAreaFilled(false);
        btnC11.setEnabled(false);
        btnC11.setFocusable(false);
        btnC11.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC11.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC11.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC11.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC11.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC11MouseExited(evt);
            }
        });
        btnC11.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC11ActionPerformed(evt);
            }
        });

        btnC10.setBackground(new java.awt.Color(0, 0, 0));
        btnC10.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC10.setBorder(null);
        btnC10.setBorderPainted(false);
        btnC10.setContentAreaFilled(false);
        btnC10.setEnabled(false);
        btnC10.setFocusable(false);
        btnC10.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC10.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC10.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC10.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC10.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC10MouseExited(evt);
            }
        });
        btnC10.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC10ActionPerformed(evt);
            }
        });

        btnC9.setBackground(new java.awt.Color(0, 0, 0));
        btnC9.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC9.setBorder(null);
        btnC9.setBorderPainted(false);
        btnC9.setContentAreaFilled(false);
        btnC9.setEnabled(false);
        btnC9.setFocusable(false);
        btnC9.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC9.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC9.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC9.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC9.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC9MouseExited(evt);
            }
        });
        btnC9.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC9ActionPerformed(evt);
            }
        });

        btnC16.setBackground(new java.awt.Color(0, 0, 0));
        btnC16.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC16.setBorder(null);
        btnC16.setBorderPainted(false);
        btnC16.setContentAreaFilled(false);
        btnC16.setEnabled(false);
        btnC16.setFocusable(false);
        btnC16.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC16.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC16.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC16.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC16.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC16MouseExited(evt);
            }
        });
        btnC16.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC16ActionPerformed(evt);
            }
        });

        btnC15.setBackground(new java.awt.Color(0, 0, 0));
        btnC15.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC15.setBorder(null);
        btnC15.setBorderPainted(false);
        btnC15.setContentAreaFilled(false);
        btnC15.setEnabled(false);
        btnC15.setFocusable(false);
        btnC15.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC15.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC15.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC15.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC15.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC15MouseExited(evt);
            }
        });
        btnC15.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC15ActionPerformed(evt);
            }
        });

        btnC14.setBackground(new java.awt.Color(0, 0, 0));
        btnC14.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC14.setBorder(null);
        btnC14.setBorderPainted(false);
        btnC14.setContentAreaFilled(false);
        btnC14.setEnabled(false);
        btnC14.setFocusable(false);
        btnC14.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC14.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC14.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC14.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC14.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC14MouseExited(evt);
            }
        });
        btnC14.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC14ActionPerformed(evt);
            }
        });

        btnC13.setBackground(new java.awt.Color(0, 0, 0));
        btnC13.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC13.setBorder(null);
        btnC13.setBorderPainted(false);
        btnC13.setContentAreaFilled(false);
        btnC13.setEnabled(false);
        btnC13.setFocusable(false);
        btnC13.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC13.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC13.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC13.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC13.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC13MouseExited(evt);
            }
        });
        btnC13.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC13ActionPerformed(evt);
            }
        });

        btnC17.setBackground(new java.awt.Color(0, 0, 0));
        btnC17.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC17.setBorder(null);
        btnC17.setBorderPainted(false);
        btnC17.setContentAreaFilled(false);
        btnC17.setEnabled(false);
        btnC17.setFocusable(false);
        btnC17.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC17.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC17.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC17.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC17.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC17MouseExited(evt);
            }
        });
        btnC17.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC17ActionPerformed(evt);
            }
        });

        btnC18.setBackground(new java.awt.Color(0, 0, 0));
        btnC18.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC18.setBorder(null);
        btnC18.setBorderPainted(false);
        btnC18.setContentAreaFilled(false);
        btnC18.setEnabled(false);
        btnC18.setFocusable(false);
        btnC18.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC18.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC18.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC18.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC18.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC18MouseExited(evt);
            }
        });
        btnC18.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC18ActionPerformed(evt);
            }
        });

        btnC19.setBackground(new java.awt.Color(0, 0, 0));
        btnC19.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC19.setBorder(null);
        btnC19.setBorderPainted(false);
        btnC19.setContentAreaFilled(false);
        btnC19.setEnabled(false);
        btnC19.setFocusable(false);
        btnC19.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC19.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC19.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC19.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC19.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC19MouseExited(evt);
            }
        });
        btnC19.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC19ActionPerformed(evt);
            }
        });

        btnC20.setBackground(new java.awt.Color(0, 0, 0));
        btnC20.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC20.setBorder(null);
        btnC20.setBorderPainted(false);
        btnC20.setContentAreaFilled(false);
        btnC20.setEnabled(false);
        btnC20.setFocusable(false);
        btnC20.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC20.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC20.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC20.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC20.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC20MouseExited(evt);
            }
        });
        btnC20.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC20ActionPerformed(evt);
            }
        });

        btnC21.setBackground(new java.awt.Color(0, 0, 0));
        btnC21.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC21.setBorder(null);
        btnC21.setBorderPainted(false);
        btnC21.setContentAreaFilled(false);
        btnC21.setEnabled(false);
        btnC21.setFocusable(false);
        btnC21.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC21.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC21.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC21.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC21.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC21MouseExited(evt);
            }
        });
        btnC21.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC21ActionPerformed(evt);
            }
        });

        btnC22.setBackground(new java.awt.Color(0, 0, 0));
        btnC22.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC22.setBorder(null);
        btnC22.setBorderPainted(false);
        btnC22.setContentAreaFilled(false);
        btnC22.setEnabled(false);
        btnC22.setFocusable(false);
        btnC22.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC22.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC22.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC22.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC22.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC22MouseExited(evt);
            }
        });
        btnC22.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC22ActionPerformed(evt);
            }
        });

        btnC23.setBackground(new java.awt.Color(0, 0, 0));
        btnC23.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC23.setBorder(null);
        btnC23.setBorderPainted(false);
        btnC23.setContentAreaFilled(false);
        btnC23.setEnabled(false);
        btnC23.setFocusable(false);
        btnC23.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC23.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC23.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC23.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC23.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC23MouseExited(evt);
            }
        });
        btnC23.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC23ActionPerformed(evt);
            }
        });

        btnC24.setBackground(new java.awt.Color(0, 0, 0));
        btnC24.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC24.setBorder(null);
        btnC24.setBorderPainted(false);
        btnC24.setContentAreaFilled(false);
        btnC24.setEnabled(false);
        btnC24.setFocusable(false);
        btnC24.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC24.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC24.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC24.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC24.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC24MouseExited(evt);
            }
        });
        btnC24.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC24ActionPerformed(evt);
            }
        });

        btnC25.setBackground(new java.awt.Color(0, 0, 0));
        btnC25.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC25.setBorder(null);
        btnC25.setBorderPainted(false);
        btnC25.setContentAreaFilled(false);
        btnC25.setEnabled(false);
        btnC25.setFocusable(false);
        btnC25.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC25.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC25.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC25.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC25.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC25MouseExited(evt);
            }
        });
        btnC25.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC25ActionPerformed(evt);
            }
        });

        btnC26.setBackground(new java.awt.Color(0, 0, 0));
        btnC26.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC26.setBorder(null);
        btnC26.setBorderPainted(false);
        btnC26.setContentAreaFilled(false);
        btnC26.setEnabled(false);
        btnC26.setFocusable(false);
        btnC26.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC26.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC26.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC26.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC26.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC26MouseExited(evt);
            }
        });
        btnC26.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC26ActionPerformed(evt);
            }
        });

        btnC27.setBackground(new java.awt.Color(0, 0, 0));
        btnC27.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC27.setBorder(null);
        btnC27.setBorderPainted(false);
        btnC27.setContentAreaFilled(false);
        btnC27.setEnabled(false);
        btnC27.setFocusable(false);
        btnC27.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC27.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC27.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC27.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC27.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC27MouseExited(evt);
            }
        });
        btnC27.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC27ActionPerformed(evt);
            }
        });

        btnC28.setBackground(new java.awt.Color(0, 0, 0));
        btnC28.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC28.setBorder(null);
        btnC28.setBorderPainted(false);
        btnC28.setContentAreaFilled(false);
        btnC28.setEnabled(false);
        btnC28.setFocusable(false);
        btnC28.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC28.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC28.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC28.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC28.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC28MouseExited(evt);
            }
        });
        btnC28.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC28ActionPerformed(evt);
            }
        });

        btnC29.setBackground(new java.awt.Color(0, 0, 0));
        btnC29.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC29.setBorder(null);
        btnC29.setBorderPainted(false);
        btnC29.setContentAreaFilled(false);
        btnC29.setEnabled(false);
        btnC29.setFocusable(false);
        btnC29.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC29.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC29.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC29.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC29.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC29MouseExited(evt);
            }
        });
        btnC29.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC29ActionPerformed(evt);
            }
        });

        btnC30.setBackground(new java.awt.Color(0, 0, 0));
        btnC30.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC30.setBorder(null);
        btnC30.setBorderPainted(false);
        btnC30.setContentAreaFilled(false);
        btnC30.setEnabled(false);
        btnC30.setFocusable(false);
        btnC30.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC30.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC30.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC30.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC30.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC30MouseExited(evt);
            }
        });
        btnC30.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC30ActionPerformed(evt);
            }
        });

        btnC31.setBackground(new java.awt.Color(0, 0, 0));
        btnC31.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC31.setBorder(null);
        btnC31.setBorderPainted(false);
        btnC31.setContentAreaFilled(false);
        btnC31.setEnabled(false);
        btnC31.setFocusable(false);
        btnC31.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC31.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC31.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC31.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC31.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC31MouseExited(evt);
            }
        });
        btnC31.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC31ActionPerformed(evt);
            }
        });

        btnC32.setBackground(new java.awt.Color(0, 0, 0));
        btnC32.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC32.setBorder(null);
        btnC32.setBorderPainted(false);
        btnC32.setContentAreaFilled(false);
        btnC32.setEnabled(false);
        btnC32.setFocusable(false);
        btnC32.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC32.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC32.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC32.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC32.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC32MouseExited(evt);
            }
        });
        btnC32.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC32ActionPerformed(evt);
            }
        });

        btnC33.setBackground(new java.awt.Color(0, 0, 0));
        btnC33.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC33.setBorder(null);
        btnC33.setBorderPainted(false);
        btnC33.setContentAreaFilled(false);
        btnC33.setEnabled(false);
        btnC33.setFocusable(false);
        btnC33.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC33.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC33.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC33.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC33.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC33MouseExited(evt);
            }
        });
        btnC33.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC33ActionPerformed(evt);
            }
        });

        btnC34.setBackground(new java.awt.Color(0, 0, 0));
        btnC34.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC34.setBorder(null);
        btnC34.setBorderPainted(false);
        btnC34.setContentAreaFilled(false);
        btnC34.setEnabled(false);
        btnC34.setFocusable(false);
        btnC34.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC34.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC34.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC34.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC34.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC34MouseExited(evt);
            }
        });
        btnC34.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC34ActionPerformed(evt);
            }
        });

        btnC35.setBackground(new java.awt.Color(0, 0, 0));
        btnC35.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC35.setBorder(null);
        btnC35.setBorderPainted(false);
        btnC35.setContentAreaFilled(false);
        btnC35.setEnabled(false);
        btnC35.setFocusable(false);
        btnC35.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC35.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC35.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC35.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC35.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC35MouseExited(evt);
            }
        });
        btnC35.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC35ActionPerformed(evt);
            }
        });

        btnC36.setBackground(new java.awt.Color(0, 0, 0));
        btnC36.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC36.setBorder(null);
        btnC36.setBorderPainted(false);
        btnC36.setContentAreaFilled(false);
        btnC36.setEnabled(false);
        btnC36.setFocusable(false);
        btnC36.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC36.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC36.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC36.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC36.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC36MouseExited(evt);
            }
        });
        btnC36.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC36ActionPerformed(evt);
            }
        });

        btnC37.setBackground(new java.awt.Color(0, 0, 0));
        btnC37.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC37.setBorder(null);
        btnC37.setBorderPainted(false);
        btnC37.setContentAreaFilled(false);
        btnC37.setEnabled(false);
        btnC37.setFocusable(false);
        btnC37.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC37.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC37.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC37.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC37.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC37MouseExited(evt);
            }
        });
        btnC37.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC37ActionPerformed(evt);
            }
        });

        btnC38.setBackground(new java.awt.Color(0, 0, 0));
        btnC38.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC38.setBorder(null);
        btnC38.setBorderPainted(false);
        btnC38.setContentAreaFilled(false);
        btnC38.setEnabled(false);
        btnC38.setFocusable(false);
        btnC38.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC38.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC38.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC38.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC38.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC38MouseExited(evt);
            }
        });
        btnC38.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC38ActionPerformed(evt);
            }
        });

        btnC39.setBackground(new java.awt.Color(0, 0, 0));
        btnC39.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC39.setBorder(null);
        btnC39.setBorderPainted(false);
        btnC39.setContentAreaFilled(false);
        btnC39.setEnabled(false);
        btnC39.setFocusable(false);
        btnC39.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC39.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC39.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC39.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC39.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC39MouseExited(evt);
            }
        });
        btnC39.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC39ActionPerformed(evt);
            }
        });

        btnC40.setBackground(new java.awt.Color(0, 0, 0));
        btnC40.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/c0.jpg"))); // NOI18N
        btnC40.setBorder(null);
        btnC40.setBorderPainted(false);
        btnC40.setContentAreaFilled(false);
        btnC40.setEnabled(false);
        btnC40.setFocusable(false);
        btnC40.setMaximumSize(new java.awt.Dimension(120, 100));
        btnC40.setMinimumSize(new java.awt.Dimension(120, 100));
        btnC40.setPreferredSize(new java.awt.Dimension(120, 100));
        btnC40.setRolloverIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/cr.jpg"))); // NOI18N
        btnC40.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                btnC40MouseExited(evt);
            }
        });
        btnC40.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnC40ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(btnC9, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC10, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC11, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC12, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC13, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC14, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC15, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC16, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(btnC17, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC18, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC19, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC20, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC21, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC22, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC23, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC24, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(btnC1, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC2, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC5, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC6, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC7, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnC8, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(btnC25, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnC26, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnC27, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnC28, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(btnC33, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnC34, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnC35, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnC36, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(btnC29, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnC30, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnC31, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnC32, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                                .addComponent(btnC37, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnC38, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnC39, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(btnC40, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))))
                .addContainerGap(13, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(23, 23, 23)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnC2, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC5, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC6, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC7, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC8, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(6, 6, 6)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnC9, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC10, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC11, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC12, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC13, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC14, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC15, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC16, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnC24, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC23, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC22, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC21, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC20, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC19, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC18, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC17, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnC32, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC31, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC30, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC29, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC28, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC27, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC26, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC25, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnC40, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC39, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC38, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC37, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC36, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC35, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC34, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnC33, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        btnReiniciar.setFont(new java.awt.Font("Cyrodiil", 1, 24)); // NOI18N
        btnReiniciar.setForeground(new java.awt.Color(0, 204, 0));
        btnReiniciar.setText("Reiniciar Juego");
        btnReiniciar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnReiniciarActionPerformed(evt);
            }
        });

        btniniciar.setFont(new java.awt.Font("Cyrodiil", 1, 24)); // NOI18N
        btniniciar.setForeground(new java.awt.Color(0, 204, 0));
        btniniciar.setText("Iniciar Juego");
        btniniciar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btniniciarActionPerformed(evt);
            }
        });

        Lbltime.setText("00:00:00");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addContainerGap(20, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addGap(60, 60, 60)
                .addComponent(btniniciar)
                .addGap(46, 46, 46)
                .addComponent(Lbltime)
                .addGap(98, 98, 98)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(btnReiniciar)
                .addGap(47, 47, 47))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(btnReiniciar)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(btniniciar)
                        .addComponent(jLabel1)
                        .addComponent(Lbltime)))
                .addGap(18, 18, 18)
                .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        setSize(new java.awt.Dimension(1073, 684));
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void btnC1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC1ActionPerformed
        btnEnabled(btnC1);
    }//GEN-LAST:event_btnC1ActionPerformed

    private void btnC2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC2ActionPerformed
        btnEnabled(btnC2);
    }//GEN-LAST:event_btnC2ActionPerformed

    private void btnC3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC3ActionPerformed
        btnEnabled(btnC3);
    }//GEN-LAST:event_btnC3ActionPerformed

    private void btnC4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC4ActionPerformed
        btnEnabled(btnC4);
    }//GEN-LAST:event_btnC4ActionPerformed

    private void btnC5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC5ActionPerformed
        btnEnabled(btnC5);
    }//GEN-LAST:event_btnC5ActionPerformed

    private void btnC6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC6ActionPerformed
        btnEnabled(btnC6);
    }//GEN-LAST:event_btnC6ActionPerformed

    private void btnC7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC7ActionPerformed
        btnEnabled(btnC7);
    }//GEN-LAST:event_btnC7ActionPerformed

    private void btnC8ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC8ActionPerformed
        btnEnabled(btnC8);
    }//GEN-LAST:event_btnC8ActionPerformed

    private void btnC9ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC9ActionPerformed
        btnEnabled(btnC9);
    }//GEN-LAST:event_btnC9ActionPerformed

    private void btnC10ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC10ActionPerformed
        btnEnabled(btnC10);
    }//GEN-LAST:event_btnC10ActionPerformed

    private void btnC11ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC11ActionPerformed
        btnEnabled(btnC11);
    }//GEN-LAST:event_btnC11ActionPerformed

    private void btnC12ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC12ActionPerformed
        btnEnabled(btnC12);
    }//GEN-LAST:event_btnC12ActionPerformed

    private void btnC13ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC13ActionPerformed
        btnEnabled(btnC13);
    }//GEN-LAST:event_btnC13ActionPerformed

    private void btnC14ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC14ActionPerformed
        btnEnabled(btnC14);
    }//GEN-LAST:event_btnC14ActionPerformed

    private void btnC15ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC15ActionPerformed
        btnEnabled(btnC15);
    }//GEN-LAST:event_btnC15ActionPerformed

    private void btnC16ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC16ActionPerformed
        btnEnabled(btnC16);
    }//GEN-LAST:event_btnC16ActionPerformed
        
    private void btnC1MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC1MouseExited
        compare();
    }//GEN-LAST:event_btnC1MouseExited

    private void btnC2MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC2MouseExited
        compare();
    }//GEN-LAST:event_btnC2MouseExited

    private void btnC3MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC3MouseExited
        compare();
    }//GEN-LAST:event_btnC3MouseExited

    private void btnC4MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC4MouseExited
        compare();
    }//GEN-LAST:event_btnC4MouseExited

    private void btnC5MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC5MouseExited
        compare();
    }//GEN-LAST:event_btnC5MouseExited

    private void btnC6MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC6MouseExited
        compare();
    }//GEN-LAST:event_btnC6MouseExited

    private void btnC7MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC7MouseExited
        compare();
    }//GEN-LAST:event_btnC7MouseExited

    private void btnC8MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC8MouseExited
        compare();
    }//GEN-LAST:event_btnC8MouseExited

    private void btnC9MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC9MouseExited
        compare();
    }//GEN-LAST:event_btnC9MouseExited

    private void btnC10MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC10MouseExited
        compare();
    }//GEN-LAST:event_btnC10MouseExited

    private void btnC11MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC11MouseExited
        compare();
    }//GEN-LAST:event_btnC11MouseExited

    private void btnC12MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC12MouseExited
        compare();
    }//GEN-LAST:event_btnC12MouseExited

    private void btnC13MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC13MouseExited
        compare();
    }//GEN-LAST:event_btnC13MouseExited

    private void btnC14MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC14MouseExited
        compare();
    }//GEN-LAST:event_btnC14MouseExited

    private void btnC15MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC15MouseExited
        compare();
    }//GEN-LAST:event_btnC15MouseExited

    private void btnC16MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC16MouseExited
        compare();
    }//GEN-LAST:event_btnC16MouseExited

    private void btnReiniciarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnReiniciarActionPerformed
        reiniciar();
        btniniciar.setEnabled(true);
        if(t.isRunning()) 
        {
            t.stop();
        }
        h=0; m=0; s=0; cs=0;
        actualizarLabel();
    }//GEN-LAST:event_btnReiniciarActionPerformed

    private void btnC17MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC17MouseExited
        compare();
    }//GEN-LAST:event_btnC17MouseExited

    private void btnC17ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC17ActionPerformed
        btnEnabled(btnC17);
    }//GEN-LAST:event_btnC17ActionPerformed

    private void btnC18MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC18MouseExited
        compare();
    }//GEN-LAST:event_btnC18MouseExited

    private void btnC18ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC18ActionPerformed
        btnEnabled(btnC18);
    }//GEN-LAST:event_btnC18ActionPerformed

    private void btnC19MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC19MouseExited
        compare();
    }//GEN-LAST:event_btnC19MouseExited

    private void btnC19ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC19ActionPerformed
        btnEnabled(btnC19);
    }//GEN-LAST:event_btnC19ActionPerformed

    private void btnC20MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC20MouseExited
        compare();
    }//GEN-LAST:event_btnC20MouseExited

    private void btnC20ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC20ActionPerformed
        btnEnabled(btnC20);
    }//GEN-LAST:event_btnC20ActionPerformed

    private void btnC21MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC21MouseExited
        compare();
    }//GEN-LAST:event_btnC21MouseExited

    private void btnC21ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC21ActionPerformed
        btnEnabled(btnC21);
    }//GEN-LAST:event_btnC21ActionPerformed

    private void btnC22MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC22MouseExited
        compare();
    }//GEN-LAST:event_btnC22MouseExited

    private void btnC22ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC22ActionPerformed
        btnEnabled(btnC22);
    }//GEN-LAST:event_btnC22ActionPerformed

    private void btnC23MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC23MouseExited
        compare();
    }//GEN-LAST:event_btnC23MouseExited

    private void btnC23ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC23ActionPerformed
        btnEnabled(btnC23);
    }//GEN-LAST:event_btnC23ActionPerformed

    private void btnC24MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC24MouseExited
        compare();
    }//GEN-LAST:event_btnC24MouseExited

    private void btnC24ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC24ActionPerformed
        btnEnabled(btnC24);
    }//GEN-LAST:event_btnC24ActionPerformed

    private void btnC25MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC25MouseExited
        compare();
    }//GEN-LAST:event_btnC25MouseExited

    private void btnC25ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC25ActionPerformed
        btnEnabled(btnC25);
    }//GEN-LAST:event_btnC25ActionPerformed

    private void btnC26MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC26MouseExited
        compare();
    }//GEN-LAST:event_btnC26MouseExited

    private void btnC26ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC26ActionPerformed
        btnEnabled(btnC26);
    }//GEN-LAST:event_btnC26ActionPerformed

    private void btnC27MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC27MouseExited
        compare();
    }//GEN-LAST:event_btnC27MouseExited

    private void btnC27ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC27ActionPerformed
        btnEnabled(btnC27);
    }//GEN-LAST:event_btnC27ActionPerformed

    private void btnC28MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC28MouseExited
        compare();
    }//GEN-LAST:event_btnC28MouseExited

    private void btnC28ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC28ActionPerformed
        btnEnabled(btnC28);
    }//GEN-LAST:event_btnC28ActionPerformed

    private void btnC29MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC29MouseExited
        compare();
    }//GEN-LAST:event_btnC29MouseExited

    private void btnC29ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC29ActionPerformed
        btnEnabled(btnC29);
    }//GEN-LAST:event_btnC29ActionPerformed

    private void btnC30MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC30MouseExited
        compare();
    }//GEN-LAST:event_btnC30MouseExited

    private void btnC30ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC30ActionPerformed
        btnEnabled(btnC30);
    }//GEN-LAST:event_btnC30ActionPerformed

    private void btnC31MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC31MouseExited
        compare();
    }//GEN-LAST:event_btnC31MouseExited

    private void btnC31ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC31ActionPerformed
        btnEnabled(btnC31);
    }//GEN-LAST:event_btnC31ActionPerformed

    private void btnC32MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC32MouseExited
        compare();
    }//GEN-LAST:event_btnC32MouseExited

    private void btnC32ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC32ActionPerformed
        btnEnabled(btnC32);
    }//GEN-LAST:event_btnC32ActionPerformed

    private void btnC33MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC33MouseExited
        compare();
    }//GEN-LAST:event_btnC33MouseExited

    private void btnC33ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC33ActionPerformed
        btnEnabled(btnC33);
    }//GEN-LAST:event_btnC33ActionPerformed

    private void btnC34MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC34MouseExited
        compare();
    }//GEN-LAST:event_btnC34MouseExited

    private void btnC34ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC34ActionPerformed
        btnEnabled(btnC34);
    }//GEN-LAST:event_btnC34ActionPerformed

    private void btnC35MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC35MouseExited
        compare();
    }//GEN-LAST:event_btnC35MouseExited

    private void btnC35ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC35ActionPerformed
        btnEnabled(btnC35);
    }//GEN-LAST:event_btnC35ActionPerformed

    private void btnC36MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC36MouseExited
        compare();
    }//GEN-LAST:event_btnC36MouseExited

    private void btnC36ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC36ActionPerformed
        btnEnabled(btnC36);
    }//GEN-LAST:event_btnC36ActionPerformed

    private void btnC37MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC37MouseExited
        compare();
    }//GEN-LAST:event_btnC37MouseExited

    private void btnC37ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC37ActionPerformed
        btnEnabled(btnC37);
    }//GEN-LAST:event_btnC37ActionPerformed

    private void btnC38MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC38MouseExited
        compare();
    }//GEN-LAST:event_btnC38MouseExited

    private void btnC38ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC38ActionPerformed
        btnEnabled(btnC38);
    }//GEN-LAST:event_btnC38ActionPerformed

    private void btnC39MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC39MouseExited
        compare();
    }//GEN-LAST:event_btnC39MouseExited

    private void btnC39ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC39ActionPerformed
        btnEnabled(btnC39);
    }//GEN-LAST:event_btnC39ActionPerformed

    private void btnC40MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btnC40MouseExited
        compare();
    }//GEN-LAST:event_btnC40MouseExited

    private void btnC40ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnC40ActionPerformed
        btnEnabled(btnC40);
    }//GEN-LAST:event_btnC40ActionPerformed

    private void btniniciarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btniniciarActionPerformed
        iniciar();
        /*Cronometro*/
        t.start();
        btniniciar.setEnabled(false);
        btnReiniciar.setEnabled(true);
        
    }//GEN-LAST:event_btniniciarActionPerformed

    public static void main(String args[]) {
        
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(PlayGame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(PlayGame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(PlayGame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(PlayGame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        
        //Conectarse
        try{
            String host="127.0.0.1";
            int pto = 9000;
            //Creamos el Socket
            Socket cl= new Socket(host,pto);
            //recibir archivos
            int j;
            // Crea el flujo de entrada para leer los datos que envia el cliente 
               DataInputStream dis = new DataInputStream( cl.getInputStream() );
               //File []archivos=jf.getSelectedFiles();
            for(j=0;j<23;j++){//24
               byte[] b= new byte[1024];
                    String nombre= dis.readUTF();
                    long tam= dis.readLong();
                    DataOutputStream dos = new DataOutputStream(new FileOutputStream(nombre));
                    long recibidos=0;
                    int n, porcentaje;
                    while (recibidos<tam){
                        n=dis.read(b,0,(int)Math.min(1024, tam-recibidos));
                        dos.write(b,0,n);
                        dos.flush();
                        recibidos=recibidos+n;
                        porcentaje=(int)(recibidos*100/tam);
                    }//while
                    System.out.print("Se recibió el archivo: "+nombre+"\n");
                    dos.close();
                    /**/
                    Path origen = FileSystems.getDefault().getPath("F:\\Exámen\\Memoorama\\"+nombre);
                    Path destino = FileSystems.getDefault().getPath("F:\\Exámen\\Memoorama\\build\\classes\\imagenes\\"+nombre);
                    Files.move(origen, destino, StandardCopyOption.REPLACE_EXISTING);
                    /**/
                    
                }//for         
            dis.close();
            cl.close();
        }catch(Exception e){
        e.printStackTrace();
        }
        
        /*INICIA EL JUEGO*/
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new PlayGame().setVisible(true);
            }
        });
        
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Lbltime;
    private javax.swing.JButton btnC1;
    private javax.swing.JButton btnC10;
    private javax.swing.JButton btnC11;
    private javax.swing.JButton btnC12;
    private javax.swing.JButton btnC13;
    private javax.swing.JButton btnC14;
    private javax.swing.JButton btnC15;
    private javax.swing.JButton btnC16;
    private javax.swing.JButton btnC17;
    private javax.swing.JButton btnC18;
    private javax.swing.JButton btnC19;
    private javax.swing.JButton btnC2;
    private javax.swing.JButton btnC20;
    private javax.swing.JButton btnC21;
    private javax.swing.JButton btnC22;
    private javax.swing.JButton btnC23;
    private javax.swing.JButton btnC24;
    private javax.swing.JButton btnC25;
    private javax.swing.JButton btnC26;
    private javax.swing.JButton btnC27;
    private javax.swing.JButton btnC28;
    private javax.swing.JButton btnC29;
    private javax.swing.JButton btnC3;
    private javax.swing.JButton btnC30;
    private javax.swing.JButton btnC31;
    private javax.swing.JButton btnC32;
    private javax.swing.JButton btnC33;
    private javax.swing.JButton btnC34;
    private javax.swing.JButton btnC35;
    private javax.swing.JButton btnC36;
    private javax.swing.JButton btnC37;
    private javax.swing.JButton btnC38;
    private javax.swing.JButton btnC39;
    private javax.swing.JButton btnC4;
    private javax.swing.JButton btnC40;
    private javax.swing.JButton btnC5;
    private javax.swing.JButton btnC6;
    private javax.swing.JButton btnC7;
    private javax.swing.JButton btnC8;
    private javax.swing.JButton btnC9;
    private javax.swing.JButton btnReiniciar;
    private javax.swing.JButton btniniciar;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    // End of variables declaration//GEN-END:variables
}
