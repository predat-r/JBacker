import java.io.*;
import java.util.*;
import java.util.zip.*;

/**
 * Class for decompressing files and directories from a ZIP file.
 */
public class Decompressor {

    private File fileToBeDecompressed;

    /**
     * Constructor that takes a ZIP file to decompress.
     *
     * @param file the ZIP file to be decompressed
     * @throws IOException if an I/O error occurs
     */
    public Decompressor(File file) throws IOException {
        fileToBeDecompressed = file;
        decompress();
    }

    /**
     * Decompresses the specified ZIP file into the output directory.
     *
     * @throws IOException if an I/O error occurs
     */
    public void decompress() throws IOException {
        String outputDirPath = "Files/Restores/";
        File outputDir = new File(outputDirPath);

        // Create a directory for the extracted files based on the ZIP file name
        String zipFileNameWithoutExt = fileToBeDecompressed.getName().replace(".zip", "");
        File targetDir = new File(outputDir, zipFileNameWithoutExt);
        if (!targetDir.exists() && !targetDir.mkdirs()) {
            System.err.println("Failed to create target directory: " + targetDir.getAbsolutePath());
            return;
        }

        try (FileInputStream fis = new FileInputStream(fileToBeDecompressed);
             ZipInputStream zis = new ZipInputStream(fis)) {

            ZipEntry zipEntry;
            System.out.println(zis.getNextEntry());
            while ((zipEntry = zis.getNextEntry()) != null) {
                System.out.println("Processing entry: " + zipEntry.getName());

                File newFile = new File(targetDir, zipEntry.getName());

                if (zipEntry.isDirectory()) {
                    // Create directories
                    if (!newFile.exists() && !newFile.mkdirs()) {
                        System.err.println("Failed to create directory: " + newFile.getAbsolutePath());
                    }
                } else {
                    // Ensure parent directories exist
                    File parentDir = newFile.getParentFile();
                    if (parentDir != null && !parentDir.exists() && !parentDir.mkdirs()) {
                        System.err.println("Failed to create parent directories for file: " + newFile.getAbsolutePath());
                    }

                    // Extract the file
                    try (FileOutputStream fos = new FileOutputStream(newFile)) {
                        byte[] buffer = new byte[1024];
                        int bytesRead;
                        while ((bytesRead = zis.read(buffer)) != -1) {
                            fos.write(buffer, 0, bytesRead);
                        }
                        System.out.println("Extracted file: " + newFile.getAbsolutePath());
                    } catch (IOException e) {
                        System.err.println("Error writing file: " + newFile.getAbsolutePath() + " - " + e.getMessage());
                        throw e;
                    }
                }
                zis.closeEntry();
            }

            System.out.println("Decompression completed.");
        } catch (IOException e) {
            System.err.println("Error during decompression: " + e.getMessage());
            throw e;
        }
    }
}
