
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
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
public class fileChooseHandler implements PropertyChangeListener {

    fileChooseHandler() {

    }

    @Override
    public void propertyChange(PropertyChangeEvent evt) {
        JFileChooser filechooser = (JFileChooser) evt.getSource();
        String propertyChanged = evt.getPropertyName();

        if (filechooser.SELECTED_FILE_CHANGED_PROPERTY.equals(propertyChanged)) {
            File selectedFile = filechooser.getSelectedFile();

            if (selectedFile != null) {
                if (selectedFile.isDirectory()) {
                    System.out.println("user selected a directory " + selectedFile.getAbsolutePath());
                } else {
                    System.out.println("User clicked on: " + selectedFile.getAbsolutePath());
                }
            }

        }
         else if (JFileChooser.DIRECTORY_CHANGED_PROPERTY.equals(propertyChanged)) {
         System.out.println("here");}
    }
}
