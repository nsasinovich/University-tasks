import java.io.IOException;
import java.util.Stack;
import java.util.logging.LogManager;

public class Main {

	public static void main(String[] args) {
		try {
			LogManager.getLogManager().readConfiguration(
					Main.class.getResourceAsStream("/logging.properties"));

			myStack testStack = new myStack();
			Stack<Integer> lol = null;
			testStack.pop();

		} catch (IOException e) {
			System.err.println("Could not setup logger configuration: "
					+ e.toString());
		} catch (myException e) {
			e.printStackTrace();
		}

	}
}
