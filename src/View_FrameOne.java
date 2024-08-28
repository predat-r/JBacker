
import java.awt.FlowLayout;
import java.io.File;
import javax.crypto.SecretKey;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * Main application frame for selecting files and performing backup operations.
 */
public class View_FrameOne {

    JFrame fr;               // Main application frame
    JFileChooser filechooser; // File chooser for selecting files or directories
    JButton selectBtn;      // Button to select a file for backup
    selectorHnd SlcHnd;     // Handler for file selection and backup
    JButton openDirBtn;     // Button to open the selected directory
    openHnd openHnd;        // Handler for opening directory
    SecretKey key;          // Secret key for encryption
    JPanel statusPanel;    // Panel to display status messages
    int mode;          //0 = creating backups, 1 == restoring backups

    /**
     * Constructor for View_FrameOne
     *
     * @param scrt Secret key for encryption
     */
    View_FrameOne(SecretKey scrt, int m) {
        key = scrt;
        mode = m;
        initGUI();
    }

    /**
     * Initializes the graphical user interface.
     */
    public void initGUI() {
        // Create and configure the main frame
        fr = new JFrame("Backup Application");
        fr.setLayout(new FlowLayout());
        fr.setSize(500, 500);
        fr.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create file chooser and handlers
        filechooser = new JFileChooser();
        openHnd = new openHnd(filechooser);

        // Create buttons
        String btnText = mode == 0 ? "Select for backup" : "select for recovery";
        selectBtn = new JButton(btnText);
        openDirBtn = new JButton("Open Folder");

        // Create and configure status panel
        statusPanel = new JPanel();
        statusPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
        fr.add(statusPanel);

        // Configure file chooser
        filechooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
        filechooser.setControlButtonsAreShown(false);
        String currDir = mode == 0 ? "C:/Users/mhari/OneDrive/Documents" : "Files/Backups";
        filechooser.setCurrentDirectory(new File(currDir));
        // Configure select button
        selectBtn.setSize(100, 50);
        SlcHnd = new selectorHnd(filechooser, key, fr, statusPanel, mode);
        selectBtn.addActionListener(SlcHnd);

        // Configure open directory button
        openDirBtn.setSize(100, 50);
        openDirBtn.addActionListener(openHnd);

        // Add components to the frame
        fr.add(filechooser);
        fr.add(selectBtn);
        fr.add(openDirBtn);
        fr.setLocationRelativeTo(null);
        // Make the frame visible
        fr.setVisible(true);
    }
}
