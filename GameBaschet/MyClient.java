package mmf.bsu.sasinovich;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;

public class MyClient {
	public static void main(String[] args) {
		Socket socket = null;
		Scanner scanner = new Scanner(System.in);
		try {
			System.out.println("Введите IP-адрес:");
			String IP = scanner.nextLine();
			socket = new Socket(IP, 8036);
			
			PrintStream ps = new PrintStream(socket.getOutputStream());
			BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			
			while (true)
			{
				if (br.ready())
				{
					String msg = br.readLine();
					System.out.println(msg);
					msg = "25";
		
					ps.println(msg);
					ps.flush();
					
					Boolean game = true;
					while (game) 
					{
						while (!br.ready())
						{
							try {
								Thread.sleep(100);
							} catch (InterruptedException e) {
								// TODO Auto-generated catch block
								e.printStackTrace();
							}
						}
						
						msg = br.readLine();
						if (msg.equals("Вы победили! Поздравляем!")) {
							game = false;
							System.out.println(msg);
						}
						else {
							System.out.println("Количество элементов в 'куче'  после хода соперника: " + msg);
							System.out.print("Ход игрока 2. Сколько элементов вы хотите удалить? ");
							int turn = scanner.nextInt();
							while (turn < 1 || turn > 3)
								turn = scanner.nextInt();
							
							int elements = Integer.parseInt(msg) - turn;
							if (elements <= 0) {
								System.out.println("Вы проиграли!");
								ps.println("Вы победили! Поздравляем!");
								game = false;
								ps.flush();
								
							} 
							else {
								System.out.println("Количество элементов в 'куче': " + elements);
								ps.println(Integer.toString(elements));
								ps.flush();
							}
						}
					}
					
					break;
				}
				else
				{
					try {
						Thread.sleep(100);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}

			ps.close();
			socket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
