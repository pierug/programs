
package paint;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JToolBar;

public class Paint extends JFrame{

    public static void main(String[] args) {
        JFrame jFrame=new JFrame("Paint");
        jFrame.setBackground(Color.WHITE);
        jFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        jFrame.setPreferredSize(new Dimension(800, 800));      
        JPanel mainPanel = new JPanel(new BorderLayout());
        PaintPanel paintPanel = new PaintPanel();
        paintPanel.setPreferredSize(new Dimension(800, 700));
        mainPanel.add(paintPanel,BorderLayout.SOUTH);       
        JToolBar toolbar = makeSimpleToolPanel(paintPanel);
        mainPanel.add(toolbar);
        jFrame.setContentPane(mainPanel);
        jFrame.pack();
        jFrame.setVisible(true);
    }
    static private JToolBar makeSimpleToolPanel(PaintPanel paintPanel){
       
        
        JToolBar toolbar = new JToolBar();
        toolbar.setRollover(true);

        JButton saveAsBtn = new JButton("Zapisz jako");
        saveAsBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                paintPanel.savaImage();
            }
        });
        toolbar.add(saveAsBtn);
        toolbar.addSeparator();
        JButton chooseColorBtn = new JButton("Wybiesz kolor");
        chooseColorBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                paintPanel.setPenColor(JColorChooser.showDialog(null, "JColorChooser Sample", paintPanel.getPenColor()));
            }
        });
        
        toolbar.add(chooseColorBtn);
        
        
        toolbar.addSeparator();
        toolbar.add(new JLabel("Wybiesz grubość"));
        
        JComboBox penSizeComBox = new JComboBox(new String[]{"1","2","3","4","5","6","7","8","9"});
        
        toolbar.add(penSizeComBox);
        penSizeComBox.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                paintPanel.setPenSize(Integer.parseInt((String) penSizeComBox.getSelectedItem()));
            }
        });
        return toolbar;
    }
}
