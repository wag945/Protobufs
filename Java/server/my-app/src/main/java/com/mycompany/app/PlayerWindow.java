package com.mycompany.app;

import com.mycompany.app.App;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class PlayerWindow extends PlayersObserver
                            implements ListSelectionListener {
    App app;

    JPanel panel;
    JFrame frame;
    JList list;
    DefaultListModel listModel;
    private JButton fireButton;
    private JTextField employeeName;
    boolean firstUpdate;

    public PlayerWindow(App app){
       this.app = app;
       this.app.attach(this);
       firstUpdate = true;
       panel = new JPanel(new BorderLayout());
       listModel = new DefaultListModel();
       //listModel.addElement("Jane Doe");
       //listModel.addElement("John Smith");
       //listModel.addElement("Kathy Green");

       list = new JList(listModel);
       list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
       list.setSelectedIndex(0);
       list.addListSelectionListener(this);
       list.setVisibleRowCount(5);
       JScrollPane listScrollPane = new JScrollPane(list);

       JButton hireButton = new JButton("Hire");
       HireListener hireListener = new HireListener(hireButton);
       hireButton.setActionCommand("Hire");
       hireButton.addActionListener(hireListener);
       hireButton.setEnabled(false);

       fireButton = new JButton("Fire");
       fireButton.setActionCommand("Fire");
       fireButton.addActionListener(new FireListener());

       employeeName = new JTextField(10);
       employeeName.addActionListener(hireListener);
       employeeName.getDocument().addDocumentListener(hireListener);
       //String name = listModel.getElementAt(list.getSelectedIndex()).toString();

       JPanel buttonPane = new JPanel();
       buttonPane.setLayout(new BoxLayout(buttonPane, BoxLayout.LINE_AXIS));

       buttonPane.add(fireButton);
       buttonPane.add(Box.createHorizontalStrut(5));
       buttonPane.add(new JSeparator(SwingConstants.VERTICAL));
       buttonPane.add(Box.createHorizontalStrut(5));
       buttonPane.add(employeeName);
       buttonPane.add(hireButton);
       buttonPane.setBorder(BorderFactory.createEmptyBorder(5,5,5,5));

       panel.add(listScrollPane, BorderLayout.CENTER);
       panel.add(buttonPane, BorderLayout.PAGE_END);
       panel.setPreferredSize(new Dimension(640, 480));
    }

    class FireListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            int index = list.getSelectedIndex();
            listModel.remove(index);

            int size = listModel.getSize();

            if (size == 0) {
                fireButton.setEnabled(false);
            } else {
                if (index == listModel.getSize()) {
                    index--;
                }
                list.setSelectedIndex(index);
                list.ensureIndexIsVisible(index);
            }
        }
    }

    class HireListener implements ActionListener, DocumentListener {
        private boolean alreadyEnabled = false;
        private JButton button;

        public HireListener(JButton button) {
            this.button = button;
        }

        public void actionPerformed(ActionEvent e) {
            String name = employeeName.getText();

            if (name.equals("") || alreadyInList(name)) {
                Toolkit.getDefaultToolkit().beep();
                employeeName.requestFocusInWindow();
                employeeName.selectAll();
                return;
            }

            int index = list.getSelectedIndex();
            if (index == -1) {
                index = 0;
            } else {
                index++;
            }

            listModel.insertElementAt(employeeName.getText(), index);

            employeeName.requestFocusInWindow();
            employeeName.setText("");

            list.setSelectedIndex(index);
            list.ensureIndexIsVisible(index);
        }

        protected boolean alreadyInList(String name) {
            return listModel.contains(name);
        }

        public void insertUpdate(DocumentEvent e) {
            enableButton();
        }

        public void removeUpdate(DocumentEvent e) {
            handleEmptyTextField(e);
        }

        public void changedUpdate(DocumentEvent e) {
            if (!handleEmptyTextField(e)) {
                enableButton();
            }
        }

        private void enableButton() {
            if (!alreadyEnabled) {
                button.setEnabled(true);
            }
        }

        private boolean handleEmptyTextField(DocumentEvent e) {
            if (e.getDocument().getLength() <= 0) {
                button.setEnabled(false);
                alreadyEnabled = false;
                return true;
            }
            return false;
        }
    }

    public void valueChanged(ListSelectionEvent e) {
        if (e.getValueIsAdjusting() == false) {
            if (list.getSelectedIndex() == -1) {
                fireButton.setEnabled(false);
            } else {
                fireButton.setEnabled(true);
            }
        }
    }

    public void createAndShowGUI() {
        JFrame frame = new JFrame("ListDemo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JComponent newContentPane = panel;
        newContentPane.setOpaque(true);
        frame.setContentPane(newContentPane);

        frame.pack();
        frame.setVisible(true);
    }
 
    @Override
    public void update() {
//       System.out.println( "Binary String: " + Integer.toBinaryString( subject.getState() ) ); 

        //System.out.println("PlayersWindow update");

        PlayersOuterClass.Players players = app.getPlayers();
 
        int listSize = listModel.getSize();

        System.out.println("PlayerWindow update listSize: " + listSize);

        boolean updateList = false;

        //if (listSize != players.getPlayerListCount())
        //{
        //    updateList = true;
            listModel.removeAllElements();
        //}

        //System.out.println("updateList: " + updateList + " firstUpdate: " + firstUpdate);
        System.out.println("PlayerWindow Players size:" + players.getPlayerListCount());
        for (int i = 0; i < players.getPlayerListCount(); i++)
        {
            PlayersOuterClass.Player player = players.getPlayerList(i);
            System.out.println(player.toString());
            //if (updateList || firstUpdate) {
            //    listModel.addElement(player.toString()+"\n");
            //}
            listModel.addElement(player.toString() + "\n");
        }

        firstUpdate = false;
    }
 }