package mmf.bsu.sasinovich;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class MyServer {
	public static void main(String[] args) throws IOException {
		Socket socket = null;
		Scanner scanner = new Scanner(System.in);

		try {
			System.out.println("��� IP-�����:");
			InetAddress IP = InetAddress.getLocalHost();
			System.out.println(IP);
			ServerSocket server;
			server = new ServerSocket(8036);
			socket = server.accept();
			PrintStream ps = new PrintStream(socket.getOutputStream());
			BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			
			String msg = "���� ����. � '����' ���������� ��������� 25 ���������. ������ �� ������� ����� �� 1 �� 3. ����������� ���, ��� ����� ���������.";
			System.out.println(msg);
			ps.println(msg);
			ps.flush();

			Boolean game = true;
			while (game) 
			{
				if (br.ready())
				{
					msg = br.readLine();
					if (msg.equals("�� ��������! �����������!")) {
						game = false;
						System.out.println(msg);
					}
	
					else {
	
						System.out.println("���������� ��������� � '����' ����� ���� ���������: " + msg);
						System.out.print("��� ������ 1. ������� ��������� �� ������ �������? ");
						int turn = scanner.nextInt();
						while (turn < 1 || turn > 3)
							turn = scanner.nextInt();
						
						int elements = Integer.parseInt(msg) - turn;
						if (elements <= 0) {
							System.out.println("�� ���������!");
							ps.println("�� ��������! �����������!");
							ps.flush();
							game = false;
						} 
						else {
							System.out.println("���������� ��������� � '����': " + elements);
							ps.println(Integer.toString(elements));
							ps.flush();
						}
					}
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
		} catch (IOException e) {
			System.out.println("error" + e);

		} finally {
			if (socket != null)
				socket.close();
		}
	}
}
