import java.io.*;
import java.nio.file.*;
import java.util.*;
import java.util.zip.*;

/**
 * Compressor class for compressing a specified file or directory into a ZIP file.
 */
public class Compressor {

    private File fileToBeCompressed;

    /**
     * Constructor that takes a file or directory to compress.
     *
     * @param file the file or directory to be compressed
     * @throws IOException if an I/O error occurs
     */
    public Compressor(File file) throws IOException {
        this.fileToBeCompressed = file;
        compress();
    }

    /**
     * Compresses the specified file or directory into a ZIP file.
     *
     * @throws IOException if an I/O error occurs
     */
    public void compress() throws IOException {
        String outputDir = "Files/Backups/";
        File outputDirectory = new File(outputDir);

        // Ensure the output directory exists
        if (!outputDirectory.exists()) {
            outputDirectory.mkdirs(); // Create directory if they do not exist
        }

        String outputFilePath = outputDir + fileToBeCompressed.getName() + ".zip"; // Change to .zip
        try (FileOutputStream fos = new FileOutputStream(outputFilePath); ZipOutputStream zos = new ZipOutputStream(fos)) {

            // if the file is a directory/folder
            if (fileToBeCompressed.isDirectory()) {
                // Compress the whole directory 
                compressDirectory(fileToBeCompressed, zos, fileToBeCompressed.getName());
            } else {
                // Compress the single file
                compressFile(fileToBeCompressed, zos, fileToBeCompressed.getName());
            }

        } catch (IOException e) {
            if (e.getMessage().contains("duplicate entry")) {
                System.err.println("Duplicate entry detected. Skipping: " + e.getMessage());
            } else {
                throw e;
            } // Rethrow the exception after logging
        }
    }

    /**
     * Compresses a single file and adds it to the ZIP output stream.
     *
     * @param file the file to compress
     * @param zos the ZIP output stream
     * @param entryName the name of the entry in the ZIP file
     * @throws IOException if an I/O error occurs
     */
    private void compressFile(File file, ZipOutputStream zos, String entryName) throws IOException {
        ZipEntry zipEntry = new ZipEntry(entryName);
        zos.putNextEntry(zipEntry);
        Files.copy(file.toPath(), zos); // copying file content
        zos.closeEntry();
    }

    /**
     * Compresses a directory and adds its contents to the ZIP output stream.
     *
     * @param folder the directory to compress
     * @param zos the ZIP output stream
     * @param baseName the base name for directory entries
     * @throws IOException if an I/O error occurs
     */
    private void compressDirectory(File folder, ZipOutputStream zos, String baseName) throws IOException {
        // Keep track of added directories to avoid duplicates
        Set<String> addedDirectories = new HashSet<>();
        
        // Stack to hold directories to be processed
        Stack<File> stack = new Stack<>();
        stack.push(folder);

        while (!stack.isEmpty()) {
            File current = stack.pop();
            File[] files = current.listFiles();

            if (files != null) {
                for (File file : files) {
                    if (file.isDirectory()) {
                        // Add the directory to the stack for later processing
                        stack.push(file);

                        // Add the directory entry if it hasn't been added yet
                        String dirEntryName = getRelativePath(folder, file) + "/";
                        if (addedDirectories.add(dirEntryName)) {
                            zos.putNextEntry(new ZipEntry(dirEntryName));
                            zos.closeEntry();
                        }
                    } else {
                        // Compress the file
                        String zipEntryName = getRelativePath(folder, file);
                        compressFile(file, zos, zipEntryName);
                    }
                }
            }
        }
    }

    /**
     * Gets the relative path of the file with respect to the base directory.
     *
     * @param base the base directory
     * @param file the file to get the relative path for
     * @return the relative path as a String
     */
    private String getRelativePath(File base, File file) {
        return base.toURI().relativize(file.toURI()).getPath().replace("\\", "/");
    }
}
