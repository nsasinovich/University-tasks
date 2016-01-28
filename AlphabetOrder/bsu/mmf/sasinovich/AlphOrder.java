package bsu.mmf.sasinovich;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.regex.*;

public class AlphOrder {
	
	public static void main(String[] args) {
		String text = "Congratulations, you've been added to the ZuzuStudio organization!\n"
				+ "Here are some quick tips for a first-time organization member:)";
		System.out.println(text);
		
		Pattern p = Pattern.compile(",+|-+|\\d+|\\.+|\\(+|\\)+|!+|\\?+|:+");
        Matcher m = p.matcher(text);
        text = m.replaceAll("");
		
		text = text.toLowerCase();

		ArrayList<String> words = new ArrayList<String>(Arrays.asList(text.split(" ")));
        Collections.sort(words);
        System.out.println("\nResult:\n " + words);
        
	}

}
