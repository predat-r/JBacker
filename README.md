# BackupTool

A Java desktop application for securely backing up files and directories. It compresses your data into ZIP archives and encrypts them using AES, keeping your backups safe at rest.

---

## Features

- Compress individual files or entire directory trees into ZIP archives
- AES encryption and decryption of files and directories
- Swing-based GUI for easy file selection and operation management
- Encryption key loaded securely from an environment variable — never hardcoded

---

## Requirements

- Java 8 or higher
- NetBeans IDE (recommended) or any Java-compatible build tool
- An AES secret key stored as a Base64-encoded environment variable

---

## Setup

1. Generate a Base64-encoded AES-128 or AES-256 key and set it as an environment variable:

   - On Linux/macOS: export ENCRYPTION_KEY=your_base64_key_here
   - On Windows: set ENCRYPTION_KEY=your_base64_key_here

2. Open the project in NetBeans or compile the source files in the src/ directory manually.

3. Run the Driver class as the entry point.

---

## Project Structure

- src/Driver.java — Entry point; recovers the AES key from the environment and launches the GUI
- src/Landing.java — Main landing window of the application
- src/Compressor.java — Handles ZIP compression of files and directories
- src/Decompressor.java — Handles ZIP decompression
- src/Encryption.java — AES encryption for files and directories
- src/View_FrameOne.java — Primary GUI frame
- src/openHnd.java — File open action handler
- src/selectorHnd.java — File selection handler
- nbproject/ — NetBeans project configuration
- build.xml — Ant build file

---

## Security Notes

- The encryption key is never stored in the codebase. It must be provided via the ENCRYPTION_KEY environment variable at runtime.
- Backups are written to a local Files/Backups/ directory, which is excluded from version control via .gitignore.

---

## License

This project is unlicensed. All rights reserved by the author.
