
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.time.LocalDate;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.crypto.SecretKey;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JFileChooser;
import javax.swing.JFrame;

/**
 * Handler for file selection and encryption/compression.
 */
public class selectorHnd implements ActionListener {

    JFileChooser filechooser; // File chooser for selecting files or directories
    SecretKey key;            // Secret key for encryption
    JFrame frame;             // Main application frame
    JPanel statusPanel;       // Panel to display status message
    int mode;

    /**
     * Constructor for selectorHnd
     *
     * @param fc File chooser instance
     * @param scrt Secret key for encryption
     * @param fr Main application frame
     * @param statusPanel Panel to display status messages
     */
    selectorHnd(JFileChooser fc, SecretKey scrt, JFrame fr, JPanel statusPanel, int m) {
        filechooser = fc;
        key = scrt;
        frame = fr;
        this.statusPanel = statusPanel;
        mode = m;
    }

    /**
     * Handles action events for file selection and encryption.
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        // Clear any previous status message
        statusPanel.removeAll();
        if (mode == 0) {
            BackupSelectedFile();
        } else {
            try {
                RecoverSelectedFile();
            } catch (IOException ex) {
                Logger.getLogger(selectorHnd.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
    }

    public void BackupSelectedFile() {
        try {
            // Getting the selected file or directory
            File selectedFile = filechooser.getSelectedFile();
            if (selectedFile == null) {
                displayErrorMsg("File not selected !");
            }           // Specifying the temporary location for the encrypted file
            File tempEncrypted = new File("Files/Backups/" + LocalDate.now() + " " + selectedFile.getName() + ".enc");

            // Encrypting the selected file or directory
            Encryption encrypt = new Encryption(selectedFile, tempEncrypted, key, mode);

            // Compressing the encrypted file
            Compressor comp = new Compressor(tempEncrypted);

            //reference to backups folder
            File Backups = new File("Files/Backups");
            // Deleting the temporary encrypted files after compression
            File[] files = Backups.listFiles();
            cleanup(files);

            // Showing backup directory
            filechooser.rescanCurrentDirectory();
            filechooser.setCurrentDirectory(Backups);

            // Displaying success message
            JLabel label = new JLabel("Backup successful!!");
            label.setForeground(Color.GREEN); // Set text color to green
            statusPanel.add(label);
            statusPanel.revalidate();
            statusPanel.repaint();

        } catch (IOException ex) {
            // Displaying error message
            displayErrorMsg("Backup Failed!!");
            System.out.println(ex);
        }
    }

    public void RecoverSelectedFile() throws IOException {
        // Get the selected ZIP file
        File selectedFile = filechooser.getSelectedFile();
        if (selectedFile == null) {
            displayErrorMsg("File not selected !");
            return;
        }

        // Create a directory for the extracted files based on the ZIP file name
        String zipFileNameWithoutExt = selectedFile.getName().replace(".zip", "");
        File outputDir = new File("Files/Restores/" + zipFileNameWithoutExt + "DECRYPTED");

        // Decompress the ZIP file into the created directory
        Decompressor decompress = new Decompressor(selectedFile);

        // Decrypt the file
        Encryption decrypt = new Encryption(new File("Files/Restores/" + zipFileNameWithoutExt),outputDir, key, mode);

        // Display success message
        JLabel label = new JLabel("Recovery successful!");
        label.setForeground(Color.GREEN); // Set text color to green
        statusPanel.add(label);
        statusPanel.revalidate();
        statusPanel.repaint();
    }

    public void displayErrorMsg(String error) {
        JLabel label = new JLabel(error);
        label.setForeground(Color.RED); // Set text color to red
        statusPanel.add(label);
        statusPanel.revalidate();
        statusPanel.repaint();
    }

    public void cleanup(File[] backups) throws IOException {
        if (backups != null) {
            for (File file : backups) {
                if (!file.getName().contains("zip")) {
                    file.delete();
                }
            }
        }
    }
}