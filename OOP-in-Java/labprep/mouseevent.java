import java.awt.FlowLayout; 
import javax.swing.JFrame; 
import javax.swing.JButton; 
import java.awt.event.MouseListener; 
import java.awt.event.MouseEvent; 

public class mouseevent extends JFrame { 
    JButton mouseButton = new JButton("No Mouse Movement Yet!"); 

    public mouseevent() { 
        super("Mouse Event"); 
        this.setDefaultCloseOperation(EXIT_ON_CLOSE); 
        this.setLayout(new FlowLayout()); 
        this.getContentPane().add(mouseButton); 
        // Add a MouseListener to the JButton 
        mouseButton.addMouseListener(new MouseListener() { 
            @Override 
            public void mouseClicked(MouseEvent e) { 
                mouseButton.setText("Mouse has clicked!"); 
            } 

            @Override 
            public void mousePressed(MouseEvent e) { 
                mouseButton.setText("Mouse has pressed!"); 
            } 

            @Override 
            public void mouseReleased(MouseEvent e) {
                mouseButton.setText("Mouse has released!"); 
            } 

            @Override 
            public void mouseEntered(MouseEvent e) { 
                mouseButton.setText("Mouse has entered!"); 
            } 

            @Override 
            public void mouseExited(MouseEvent e) { 
                mouseButton.setText("Mouse has exited!"); 
            } 
        }); 
    } 

    public static void main(String[] args) { 
        mouseevent frame = new mouseevent(); 
        frame.pack(); 
        frame.setVisible(true); 
    } 
}