package Othello;

// file: Othello.java
// CS 385 - Spring 2007 - Watts
// February 2007
// Written by Dr. Watts
// Modified by Eric Brewer
/*
Two player Othello game interface
Panel class to display and play P5Game
*/

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.lang.*;

public class Othello extends JPanel
{
	static final int SIZE = 10; 	// Size of implemented game
	DiskPane diskPane [][];		// array of panes to hold black and white
					// disks and handle mouse clicks
	OGame game = null;		// game state class object
	Othello THIS = null;

	Othello ()
	{ // Create new game
		game = new OGame (SIZE, SIZE, 5);
		THIS = this;

	  // Set up game interface
		diskPane = new DiskPane [SIZE+2][SIZE+2];
		setBackground (Color.black);
		GridLayout grid = new GridLayout (SIZE, SIZE, 2, 2);
		for (int r = 1; r <= SIZE; r++)
			for (int c = 1; c <= SIZE; c++)
			{
				diskPane[r][c] = new DiskPane (r, c);
				add (diskPane[r][c]);
			}
		setLayout (grid);
		game.makeMove (SIZE/2, SIZE/2);
		game.makeMove (SIZE/2+1, SIZE/2);
		game.makeMove (SIZE/2+1, SIZE/2+1);
		game.makeMove (SIZE/2, SIZE/2+1);
		setBorder( BorderFactory.createMatteBorder(10, 10, 10, 10, Color.black) );
		repaint ();
	}

	public void paintComponent (Graphics g)
	{// Repaint modified interface
		super.paintComponent (g);
		for (int r = 1; r < SIZE; r++)
			for (int c = 1; c < SIZE; c++)
				diskPane[r][c].repaint();
	}

	void checkForGameOver ()
	{ // Determine if there is a winner
		int winner = game.checkForWinner ();
		if (winner == 0)
			return;
		String message = "";
		switch (winner)
		{
			case 1: message = "Black wins!"; break;
			case 2: message = "White wins!"; break;
			case 3: message = "Draw!"; break;
			default : message = "Something is wrong!";
		}
		JOptionPane.showMessageDialog (null, message);
		game.reset ();
		repaint ();
	}


	class DiskPane extends JPanel implements MouseListener
	{ // Class to hold a single disk; recognizes player's mouse click

		int row, col;

		DiskPane  (int R, int C)
		{
			row = R;
			col = C;
			setBackground (new Color(26,173,82));
			addMouseListener (this);
			setPreferredSize (new Dimension(60, 60));
		}

		public void paintComponent (Graphics g)
		{ // paint this Pane
			super.paintComponent (g);

			Graphics2D g2 = (Graphics2D) g;
			g2.setRenderingHint (RenderingHints.KEY_ANTIALIASING,
						RenderingHints.VALUE_ANTIALIAS_ON);
			Color diskColor = game.getColor (row, col);
			if (diskColor != null)
			{
				g2.setPaint (diskColor);
				g2.fillOval (5,4, 50,50);
			}
		}

		public void mouseClicked (MouseEvent e)
		{ // Accept user's move; update if legal
			if (game.moveOK (row, col))
			{
				game.makeMove (row, col);
				THIS.repaint ();
				checkForGameOver ();
				game.compMove();
				THIS.repaint();
				checkForGameOver();
			}
		}

		public void mousePressed (MouseEvent event) {}
		public void mouseReleased (MouseEvent event) {}
		public void mouseEntered (MouseEvent event) {}
		public void mouseExited (MouseEvent event) {}
	}

	public static void main (String[] args)
	{ // Initialize game
		JFrame frame = new JFrame ("Othello");
		Othello oth = new Othello ();
		frame.getContentPane().add (oth);
		frame.setSize (62*SIZE+10, 62*SIZE+10);
		frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		frame.setResizable (false);
		frame.setLocation (100, 100);
		frame.setVisible (true);
	}
}
