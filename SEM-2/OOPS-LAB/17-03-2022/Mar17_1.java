import java.awt.*;
import java.awt.event.*;

class MyButtons extends Frame implements ActionListener,ItemListener{
    Button b1,b2;
    String msg;
    Choice ch;

    MyButtons(){
        setLayout(new FlowLayout());
        b1= new Button("blue");
        b2= new Button("red");
        add(b1);
        add(b2);
        b1.addActionListener(this);
        b2.addActionListener(this);
        this.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        setLayout(new FlowLayout());
        ch= new Choice();
        ch.add("OOP");
        ch.add("DS");
        ch.add("DBMS");
        ch.add("MTP");
        add(ch);
        ch.addItemListener((ItemListener) this);

    }
    public void actionPerformed(ActionEvent ae) {
        String str=ae.getActionCommand();
        if(str.equals ("blue"))
            setBackground(Color.BLUE);
        if(str.equals("red"))
            setBackground(Color.RED);
    }

    public void itemStateChanged(ItemEvent ie) {
        repaint();
    }
    public void paint(Graphics g) {
        g.drawString("Selected Subject ",10,100);
        msg=ch.getSelectedItem();
        g.drawString(msg,10,120);
    }
}
public class Mar17_1{
    public static void main(String[] args) {
        MyButtons m = new MyButtons();
        m.setTitle("Buttons");
        m.setSize(600,600);
        m.setVisible(true);
    }
}