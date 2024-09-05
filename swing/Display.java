import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.*;
import java.awt.Dimension;
import java.awt.Color;

/**
 * @class Remote_Control
 * @brief Represents a graphical user interface for a multimedia application.
 *
 * This class extends JFrame and provides a GUI to interact with a multimedia server.
 */
public class Display extends JFrame {
    private static final long serialVersionUID = 1L;
    private static JTextField textField;
    private static JTextArea textArea;

    private Client client;


    /**
     * @brief Constructor for Remote_Control class.
     * @param client The client used to communicate with the multimedia server.
     */
    public Display(Client client) {
        this.client = client;
    }


    /**
     * @brief Displays the graphical user interface.
     */
    public void display() {

        setTitle("Multimedia App");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        textArea = new JTextArea(50, 50);
        textArea.setBackground(new Color(255, 250, 250));
        textArea.setForeground(Color.BLACK);

        textField = new JTextField("");
        textField.setColumns(30);
        textField.setBackground(Color.WHITE);
        textField.setForeground(Color.BLACK);

        JScrollPane scrollPane = new JScrollPane(textArea);
        JToolBar bar = new JToolBar();
        JPanel panel = new JPanel();

        ListAllMultimediaAction listAllMultimediaAction = new ListAllMultimediaAction("List all Multimedia files");
        SearchMultimediaAction searchMultimediaAction = new SearchMultimediaAction("Search a Multimedia");
	SearchGroupAction searchGroupAction = new SearchGroupAction("Search a Group");
        PlayAction playAction = new PlayAction("Play");
        CloseAction closeAction = new CloseAction("Close");
        
        JButton listAllButton = new JButton(listAllMultimediaAction);
        		listAllButton.setBackground(Color.GREEN);
        JButton searchMultimediaButton = new JButton(searchMultimediaAction);
	JButton searchGroupButton = new JButton(searchGroupAction);
        JButton playButton = new JButton(playAction);
		playButton.setBackground(Color.BLUE);
        JButton closeButton = new JButton(closeAction);
		closeButton.setBackground(Color.RED);


        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("Menu");
        menu.setForeground(Color.WHITE);
        menuBar.setBackground(new Color(33, 33, 33));
        menu.add(new JMenuItem(listAllMultimediaAction));
        menu.add(new JMenuItem(searchMultimediaAction));
	menu.add(new JMenuItem(searchGroupAction));
        menu.add(new JMenuItem(playAction));
        menu.add(new JMenuItem(closeAction));

        menuBar.add(menu);

        setJMenuBar(menuBar);

        listAllButton.setPreferredSize(new Dimension(180, 30));
        searchMultimediaButton.setPreferredSize(new Dimension(180, 30));
	searchGroupButton.setPreferredSize(new Dimension(150, 30));
        playButton.setPreferredSize(new Dimension(100, 30));
        closeButton.setPreferredSize(new Dimension(100, 30));

        bar.add(listAllButton);
        bar.add(searchMultimediaButton);
		bar.add(searchGroupButton);
        bar.add(playButton);
        bar.add(closeButton);
		bar.add(new JLabel("                               Search:      "));
        bar.add(textField);
		textField.setBackground(Color.WHITE);


        add(bar, BorderLayout.NORTH);
        add(scrollPane, BorderLayout.SOUTH);

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }


    /**
     * @class ListAllMultimediaAction
     * @brief Represents the action to list all multimedia objects.
     */
    class ListAllMultimediaAction extends AbstractAction {
        private static final long serialVersionUID = 201811031717L;

        /**
         * @brief Constructor for ListAllMultimediaAction.
         * @param name The name of the action.
         */
        public ListAllMultimediaAction(String name) {
            super(name);
        }

        /**
         * @brief Performs the action to list all multimedia objects.
         * @param e The action event.
         */
        @Override
        public void actionPerformed(ActionEvent e) {
            client.send("LIST_ALL");
            String response = client.read();
			response= parseResult(response);
            textArea.append(response);
			textArea.append("-------------------------------------------------------------------------------------------------------------------------------- \n");
        }
    }

    /**
     * @class SearchMultimediaAction
     * @brief Represents the action to search for a multimedia object.
     */
    class SearchMultimediaAction extends AbstractAction {
        private static final long serialVersionUID = 201811031717L;

        public SearchMultimediaAction(String name) {
            super(name);
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            client.send("SEARCH_MULTIMEDIA " + textField.getText());
            String response = client.read();
			response= parseResult(response);
            textArea.append(response);
			textArea.append("-------------------------------------------------------------------------------------------------------------------------------- \n");
        }
    }


    /**
     * @class SearchGroupAction
     * @brief Represents the action to search for a group.
     */
	class SearchGroupAction extends AbstractAction {
        private static final long serialVersionUID = 201811031717L;

        public SearchGroupAction(String name) {
            super(name);
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            client.send("SEARCH_GROUP " + textField.getText());
            String response = client.read();
			response= parseResult(response);
            textArea.append(response);
			textArea.append("-------------------------------------------------------------------------------------------------------------------------------- \n");

        }
    }


    /**
     * @class PlayAction
     * @brief Represents the action to play a multimedia.
     */
    class PlayAction extends AbstractAction {
        private static final long serialVersionUID = 201811031718L;

        public PlayAction(String name) {
            super(name);
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            client.send("PLAY " + textField.getText());
            String response = client.read();
			response= parseResult(response);
            textArea.append(response );
        }
    }



    /**
     * @class CloseAction
     * @brief Represents the action to close the client.
     */
    class CloseAction extends AbstractAction {
        private static final long serialVersionUID = 201811031719L;

        public CloseAction(String name) {
            super(name);
        }

        @Override
        public void actionPerformed(ActionEvent e) {
			client.close();
            System.exit(0);
        }
    }


    /**
     * @brief Parses the result to improve readability in the GUI.
     * @param result The result string to be parsed.
     * @return The parsed response string.
     */
	String parseResult(String result) {
		String response = result.replace(" |", "\n");
		return response;
	}
}
