import java.io.*;
import java.net.*;


/**
 * @class Client
 * @brief Represents a client for communicating with a multimedia server.
 *
 * This class provides methods to send requests to the server, read responses, and close the connection.
 */
public class Client {
    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;
    private Socket sock;
    private BufferedReader input;
    private BufferedWriter output;


    /**
     * @brief Constructor for the Client class.
     * @param host The host address of the server.
     * @param port The port number for the server.
     * @throws UnknownHostException If the host is unknown.
     * @throws IOException If an I/O error occurs.
     */
    public Client(String host, int port) throws UnknownHostException, IOException {
        try {
            sock = new java.net.Socket(host, port);
            input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
        } catch (java.io.IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * @brief Sends a request to the server.
     * @param request The request string to be sent.
     */
    public void send(String request) {
        try {
            request += " \n";
            output.write(request, 0, request.length());
            output.flush();
        } catch (java.io.IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * @brief Reads a response from the server.
     * @return The response string received from the server.
     */
    public String read() {
        try {
            return input.readLine();
        } catch (java.io.IOException e) {
            e.printStackTrace();
            return null;
        }
    }

    /**
     * @brief Closes the connection with the server.
     */
    public void close() {
        try {
            sock.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    /**
     * @brief Main method to start the client.
     * @param argv Command line arguments.
     */
	public static void main(String argv[])
	{
		String host = DEFAULT_HOST;
		int port = DEFAULT_PORT;
		if (argv.length >= 1) host = argv[0];
		if (argv.length >= 2) port = Integer.parseInt(argv[1]);

		Client client = null;
		Display remoteControl = null;
		try {
			client = new Client(host, port);
			remoteControl = new Display(client);
			remoteControl.display();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}
