/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kalk;

import java.awt.Color;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 *
 * @author student
 */
public class NewJFrame extends javax.swing.JFrame {

    /**
     * Creates new form NewJFrame
     */
    public NewJFrame() {
        
        initComponents();
        znak.removeAll();
        znak.addItem("+");
        znak.addItem("-");
        znak.addItem("*");
        znak.addItem("/");
        znak.addItem("sqrt(a,b)");
        znak.addItem("pow(a,b)");
        
        znak.addItem("porównaj");
        
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        liczbaA = new javax.swing.JTextField();
        liczbaB = new javax.swing.JTextField();
        wynik = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        znak = new javax.swing.JComboBox<>();
        wynik1 = new javax.swing.JLabel();
        wynik2 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        liczbaA.setName(""); // NOI18N
        liczbaA.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                liczbaAMouseClicked(evt);
            }
        });

        liczbaB.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                liczbaBMouseClicked(evt);
            }
        });

        wynik.setText("=");

        jButton1.setText("Oblicz");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        znak.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                znakItemStateChanged(evt);
            }
        });

        wynik1.setText("a");

        wynik2.setText("b");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jButton1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(liczbaA, javax.swing.GroupLayout.PREFERRED_SIZE, 63, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(21, 21, 21)
                                .addComponent(znak, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(wynik1, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(23, 23, 23)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(wynik2, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(liczbaB, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(wynik)
                .addContainerGap(194, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(29, 29, 29)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(wynik1)
                    .addComponent(wynik2))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(liczbaA, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(liczbaB, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(wynik)
                    .addComponent(znak, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(29, 29, 29)
                .addComponent(jButton1)
                .addContainerGap(61, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
    private void calculate(){
        
        double a =0;
        double b =0;
        
        try {
            a=Double.parseDouble(liczbaA.getText());
            b=Double.parseDouble(liczbaB.getText());  
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "W polach mają być liczby");
            return;
        }
     
        double res=0;
           
        switch (znak.getItemAt(znak.getSelectedIndex())){
            case "+":{
                res = a+b;
                break;
            }
            case "-":{
                res = a-b;
                break;
            }
            case "*":{
                res = a*b;
                break;
            }
            case "/":{
                if(b==0){
                    JOptionPane.showMessageDialog(null, "Nie dzielimy przez zero!");
                    return;
                }
                res = a/b;
                break;
            }
            case "sqrt(a,b)":{
                if(b==0){
                    JOptionPane.showMessageDialog(null, "b nie może być zero");
                    return;
                }
                if(a<0){
                    JOptionPane.showMessageDialog(null, "a nie może być mnejsze od zera");
                    return;
                }
                res = Math.pow(a,1/b);
                break;
            }
            case "pow(a,b)":{
                res = Math.pow(a, b);
                break;
            }
            case "porównaj":{
                if(a>b){
                    wynik.setText("a>b");
                    liczbaA.setBackground(Color.GREEN);
                    liczbaB.setBackground(Color.RED);
                }else if(a<b){
                    wynik.setText("a<b");
                    liczbaA.setBackground(Color.RED);
                    liczbaB.setBackground(Color.GREEN);
                }else if(a==b){
                    wynik.setText("a==b");
                    liczbaA.setBackground(Color.GREEN);
                    liczbaB.setBackground(Color.GREEN);
                }

                
                return;
            }
            
        }
        
        wynik.setText("= "+res);
    }
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed

        if(liczbaA.getText().isEmpty()||liczbaB.getText().isEmpty()){
            JOptionPane.showMessageDialog(null, "Nie zostawiaj pustych pól!");
            
        }else{
            calculate();
        }     
    }//GEN-LAST:event_jButton1ActionPerformed

    private void liczbaBMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_liczbaBMouseClicked
        liczbaA.setBackground(Color.WHITE);
        liczbaB.setBackground(Color.WHITE);
    }//GEN-LAST:event_liczbaBMouseClicked

    private void liczbaAMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_liczbaAMouseClicked
        liczbaA.setBackground(Color.WHITE);
        liczbaB.setBackground(Color.WHITE);
    }//GEN-LAST:event_liczbaAMouseClicked

    private void znakItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_znakItemStateChanged
        if(liczbaA.getText().isEmpty()||liczbaB.getText().isEmpty()){
            
            
        }else{
            calculate();
        }  
    }//GEN-LAST:event_znakItemStateChanged

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                
                new NewJFrame().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JTextField liczbaA;
    private javax.swing.JTextField liczbaB;
    private javax.swing.JLabel wynik;
    private javax.swing.JLabel wynik1;
    private javax.swing.JLabel wynik2;
    private javax.swing.JComboBox<String> znak;
    // End of variables declaration//GEN-END:variables
}
