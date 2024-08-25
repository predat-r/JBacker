
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import javax.swing.JFileChooser;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author mhari
 */
public class openHnd implements ActionListener{
    
    JFileChooser filechooser;
    openHnd(JFileChooser fc){
        filechooser = fc;
    }
    @Override
    public void actionPerformed(ActionEvent e){
        
        File folderToOpen = filechooser.getSelectedFile();
        if((folderToOpen!=null)&&(folderToOpen.isDirectory())){
            filechooser.setCurrentDirectory(folderToOpen); 
        }
        
    }
    
}
