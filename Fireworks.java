//Main diff: java doesn't have built in graphics library
//Still uses color rather than colour

import javax.swing.*; //for the bursts
import java.awt.*;
import java.util.Random;

public class FireworksDisplay extends JPanel
{
    Random random = new Random();
    Color[] colours = //colours arrau
    {
        Color.RED, Color.YELLOW, Color.BLUE,
        Color.GREEN, Color.ORANGE, Color.MAGENTA,
        Color.WHITE, Color.CYAN, Color.PINK
    };
    public void drawFirework(Graphics2D g, int x, int y, Color colour, int size, int particles) //one firework
{
    g.setColor(colour);
    for (int i = 0; i < particles; i++) 
    {
        double angle = Math.toRadians(random.nextInt(360)); //angle in radians
        int distance = random.nextInt(size / 2) + size / 2; //random distance from centre

        int x2 = x + (int)(Math.cos(angle) * distance); //where it ends
        int y2 = y + (int)(Math.sin(angle) * distance);

        g.drawLine(x, y, x2, y2); //draw particle line
    }
}
@Override
protected void paintComponent(Graphics g) 
{
    super.paintComponent(g);
    Graphics2D g2 = (Graphics2D) g; //cause no built in graphics library use this
    Set background
    setBackground(Color.BLACK); //black background

    int x = random.nextInt(getWidth()); //random position
    int y = random.nextInt(getHeight() / 2);

    Color colour = colours[random.nextInt(colours.length)];
    int size = random.nextInt(50) + 30;
    int particles = random.nextInt(20) + 20;

    drawFirework(g2, x, y, colour, size, particles); //draw firework
}

public static void main(String[] args) 
{
    JFrame frame = new JFrame("Fireworks Display"); //window called Fireworks display
    FireworksDisplay panel = new FireworksDisplay();

    frame.add(panel);
    frame.setSize(1000, 700);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setVisible(true);

    Timer timer = new Timer(300, e -> panel.repaint()); //timer to refresh screen
    timer.start(); //start
}
