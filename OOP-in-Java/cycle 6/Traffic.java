import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class Traffic 
{
    JRadioButton[] b;
    Traffic()
    {
        JFrame f = new JFrame("Traffic light");
         b = new JRadioButton[3];
        ButtonGroup bg = new ButtonGroup();

        for(int i=0;i<3;i++)
        {
            b[i]=new JRadioButton("");
            b[i].setBackground(Color.GRAY);
        }
        bg.add(b[0]);
        bg.add(b[1]);
        bg.add(b[2]);

        f.add(b[0]);
        f.add(b[1]);
        f.add(b[2]);

        f.setSize(130,300);
        f.setLayout(new GridLayout(3,1));
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        b[0].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                b[0].setBackground(Color.RED);
                b[1].setBackground(Color.GRAY);
                b[2].setBackground(Color.GRAY);
                
            }
        });
        b[1].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                b[1].setBackground(Color.YELLOW);
                b[0].setBackground(Color.GRAY);
                b[2].setBackground(Color.GRAY);
                
            }
        });
        b[2].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                b[2].setBackground(Color.GREEN);
                b[1].setBackground(Color.GRAY);
                b[0].setBackground(Color.GRAY);
                
            }
        });
        

    }
    
    

    public static void main(String args[])
    {
        new Traffic();
    }
    
    
}
