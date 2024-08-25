
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.crypto.SecretKey;
import javax.swing.*;

public class Landing {

    JFrame fr;
    JPanel panel;
    JButton startBtn,restore;
    JLabel label;
    SecretKey secret;

    Landing(SecretKey scrt) {
        secret = scrt;
        initGUI();
    }

    void initGUI() {
        // Create JFrame
        fr = new JFrame("Secure Backup Manager");
        fr.setSize(600, 400);
        fr.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fr.setLayout(new BorderLayout());

        // Create JPanel with custom settings
        panel = new JPanel();
        panel.setBackground(new Color(33, 150, 243)); // Light blue background
        panel.setLayout(new GridBagLayout()); // Centering components using GridBagLayout
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(10, 10, 10, 10); // Add padding around components
        gbc.anchor = GridBagConstraints.CENTER; // Center components in the cell

        // Create and configure JLabel
        label = new JLabel("JBacker");
        label.setFont(new Font("Sans Serif", Font.BOLD, 36));
        label.setForeground(Color.WHITE); // White text color

        // Create and configure JButton
        startBtn = new JButton("Backup");
        startBtn.setFont(new Font("Sans Serif", Font.BOLD, 18));
        startBtn.setBackground(new Color(76, 175, 80)); // Green background
        startBtn.setForeground(Color.WHITE); // White text color
        startBtn.setFocusPainted(false); // Remove focus paint on click
        startBtn.setPreferredSize(new Dimension(150, 50)); // Set button size
        startBtn.addActionListener(new ActionListener() { // Anonymous inner class for ActionListener
            @Override
            public void actionPerformed(ActionEvent e) {
                // Action when button is clicked
                View_FrameOne vf = new View_FrameOne(secret,0);
                fr.setVisible(false); // Hide the current frame
            }
        });
        //restore btn to see and restore previous backups
          restore = new JButton("Restore");
        restore.setFont(new Font("Sans Serif", Font.BOLD, 18));
        restore.setBackground(new Color(76, 175, 80)); // Green background
        restore.setForeground(Color.WHITE); // White text color
        restore.setFocusPainted(false); // Remove focus paint on click
        restore.setPreferredSize(new Dimension(150, 50)); // Set button size
        restore.addActionListener(new ActionListener() { // Anonymous inner class for ActionListener
            @Override
            public void actionPerformed(ActionEvent e) {
                // Action when button is clicked
                View_FrameOne vf = new View_FrameOne(secret,1);
                fr.setVisible(false); // Hide the current frame
            }
        });
        // Add components to JPanel
        gbc.gridx = 0;
        gbc.gridy = 0;
        panel.add(label, gbc);

        gbc.gridy = 1;
        panel.add(startBtn, gbc);
         gbc.gridy = 2;
        panel.add(restore, gbc);

        // Add JPanel to JFrame
        fr.add(panel, BorderLayout.CENTER);

        // Center the frame on screen
        fr.setLocationRelativeTo(null);

        // Make JFrame visible
        fr.setVisible(true);
    }

}
