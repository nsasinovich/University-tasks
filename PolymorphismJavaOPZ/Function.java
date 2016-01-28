import java.util.Stack;

public class Function extends Terma {

	public Function(String substring) {
		super(substring);
	}

	public void process(Stack<Double> stack) {
		switch (getSubstring()) {
		case "sin":
			stack.push(Math.sin(stack.pop()));
			break;
		case "cos":
			stack.push(Math.cos(stack.pop()));
			break;
		case "exp":
			stack.push(Math.exp(stack.pop()));
			break;
		case "sqrt":
			stack.push(Math.sqrt(stack.pop()));
			break;
		}
	}
}
