import java.util.*;

public class Number extends Terma{
	public Number(String substring){
		super(substring);
	}
	
	public void process(Stack <Double> stack){
		stack.push(Double.parseDouble(getSubstring()));
	}
}
