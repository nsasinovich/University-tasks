import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {

		System.out.println("Возможные операторы и функции: ");
		System.out.println("   sin - синус; ");
		System.out.println("   cos - косинус; ");
		System.out.println("   exp - экспонента; ");
		System.out.println("   sqrt - корень квадратный; ");
		System.out.println("   \"^\" - в степень; ");
		System.out.println("   \"+\" - сложение; ");
		System.out.println("   \"*\" - умножение; ");
		System.out.println("   \"-\" - вычитание; ");
		System.out.println("   \"/\" - деление. ");
		System.out.println("\nВведите выражение. Термы разделять пробелами: ");

		Stack<Double> stack = new Stack<Double>();
		Scanner flowIn = new Scanner(System.in);
		String expression = flowIn.nextLine();
		System.out.print(expression);
		String devidedString[] = expression.split(" ");
		Terma terms[] = new Terma[devidedString.length];
		for (int i = 0; i < devidedString.length; ++i) {
			if (devidedString[i].matches("([0-9.]+)")){
					terms[i] = new Number(devidedString[i]);}
			else if(devidedString[i].matches("([-/\\^\\+\\*])"))
					terms[i] = new Operator(devidedString[i]);
			else
				terms[i] = new Function(devidedString[i]);
			
		}
		
		for(int i = 0; i<devidedString.length; ++i){
			terms[i].process(stack);
		}
		System.out.print(" = " + stack.pop());
	}
}
