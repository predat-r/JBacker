
import java.io.*;
import java.security.GeneralSecurityException;
import javax.crypto.Cipher;
import javax.crypto.CipherInputStream;
import javax.crypto.CipherOutputStream;
import javax.crypto.SecretKey;

public class Encryption {

    private static String ALGORITHM = "AES";
    SecretKey key;
    int mode; //0 = encryption 2= decryption

    Encryption(File fileOrDirectory, File outputDir, SecretKey secretKey, int m) {
        key = secretKey;
        mode = m;
        try {
            if (mode == 0) //came for encryption
            {
                if (fileOrDirectory.isDirectory()) {
                    encryptDirectory(fileOrDirectory, outputDir);
                } else {
                    encryptFile(fileOrDirectory, new File(outputDir, fileOrDirectory.getName()), key);
                }
            } else //came for decryption
            {
                if (fileOrDirectory.isDirectory()) {
                    decryptDirectory(fileOrDirectory, outputDir);
                } else {
                    decryptFile(fileOrDirectory, new File(outputDir, fileOrDirectory.getName()), key);
                }
            }
        } catch (GeneralSecurityException | IOException e) {
            System.out.println(e);
        }
    }

    // Encrypt a single file
    public static void encryptFile(File inputFile, File outputFile, SecretKey key)
            throws GeneralSecurityException, IOException {
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.ENCRYPT_MODE, key);

        try (FileInputStream inputStream = new FileInputStream(inputFile); FileOutputStream outputStream = new FileOutputStream(outputFile); CipherOutputStream cipherOutputStream = new CipherOutputStream(outputStream, cipher)) {
            byte[] buffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = inputStream.read(buffer)) != -1) {
                cipherOutputStream.write(buffer, 0, bytesRead);
            }
        }
    }

    // Encrypt the contents of a directory
    public void encryptDirectory(File directory, File outputDir)
            throws GeneralSecurityException, IOException {
        if (!outputDir.exists()) {
            outputDir.mkdirs();
        }

        for (File file : directory.listFiles()) {
            File outputFile = new File(outputDir, file.getName());
            if (file.isDirectory()) {
                encryptDirectory(file, outputFile);
            } else {
                encryptFile(file, outputFile, key);
            }
        }
    }

    // Decrypt a single file
    public static void decryptFile(File inputFile, File outputFile, SecretKey key)
            throws GeneralSecurityException, IOException {
        Cipher cipher = Cipher.getInstance(ALGORITHM);
        cipher.init(Cipher.DECRYPT_MODE, key);

        try (FileInputStream inputStream = new FileInputStream(inputFile); FileOutputStream outputStream = new FileOutputStream(outputFile); CipherInputStream cipherInputStream = new CipherInputStream(inputStream, cipher)) {
            byte[] buffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = cipherInputStream.read(buffer)) != -1) {
                outputStream.write(buffer, 0, bytesRead);
            }
        }
    }

    // Decrypt the contents of a directory
    public void decryptDirectory(File directory, File outputDir)
            throws GeneralSecurityException, IOException {
        if (!outputDir.exists()) {
            outputDir.mkdirs();
        }

        for (File file : directory.listFiles()) {
            File outputFile = new File(outputDir, file.getName());
            if (file.isDirectory()) {
                decryptDirectory(file, outputFile);
            } else {
                decryptFile(file, outputFile, key);
            }
        }
    }
}
