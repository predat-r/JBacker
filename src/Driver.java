
import java.security.GeneralSecurityException;
import java.util.Base64;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;

public class Driver {

    public static SecretKey recoverKey() throws GeneralSecurityException {
        //get key from environment variables
        String keyString = System.getenv("ENCRYPTION_KEY");
        if (keyString != null) {
            try {
                // Decode the base64 encoded key
                byte[] decodedKey = Base64.getDecoder().decode(keyString);
                // Rebuild the secret key from the decoded byte array
                return new SecretKeySpec(decodedKey, "AES");
            } catch (IllegalArgumentException e) {
                throw new GeneralSecurityException("Failed to decode the encryption key.", e);
            }
        } else {
            throw new GeneralSecurityException("SECURITY KEY COULD NOT BE RECOVERED FROM YOUR COMPUTER");
        }
    }

    public static void main(String[] args) {
        try {
            SecretKey scrt = recoverKey();
            Landing lnd = new Landing(scrt);
        } catch (GeneralSecurityException e) {
            System.err.println("Error: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
