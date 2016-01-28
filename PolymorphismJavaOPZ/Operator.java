import java.util.Stack;

public class Operator extends Terma{
	public Operator(String substring) {
		super(substring);
	}

	public void process(Stack <Double> stack){
		switch(getSubstring()){
			case "+":
				stack.push(stack.pop()+stack.pop());
			break;
			case "/":{
				double a = stack.pop();
				double b = stack.pop();
				stack.push(b/a);
				}
			break;
			case "*":
				stack.push(stack.pop()*stack.pop());
			break;
			case "-":{
				double a = stack.pop();
				double b = stack.pop();
				stack.push(b-a);
				}
			break;
			case "^":{
				double power = stack.pop();
				double num = stack.pop();
				stack.push(Math.pow(num, power)); 
			break;
		}
		}
	}
}
