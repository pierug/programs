
package projektadampiasecki;

import java.awt.Color;
import java.awt.Dimension;
import javax.swing.JPanel;

public class SnakeGraphicPanel extends JPanel {

    private final int xPanelSize = 500;
    private final int yPanelSize = 500;
    
    public SnakeGraphicPanel() {
        this.setPreferredSize(new Dimension(xPanelSize,yPanelSize));
        this.setBackground(Color.white);
    }
    
    private class Snake{
        
    }
    
}
