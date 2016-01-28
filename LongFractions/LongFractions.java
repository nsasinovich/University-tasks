package bsu.mmf.sasinovich;

import java.math.BigInteger;

public class LongFractions {
	private int intPart;
	private BigInteger numerator;
	private BigInteger denominator;

	// --------------- ŒÕ—“–” “Œ–----------------//

	public LongFractions(BigInteger num, BigInteger den, int intP) {
		numerator = num;
		denominator = den;
		intPart = intP;
	}

	// ---------------------------------------------//

	public void toImpFraction() {
		/*
		 * if (this.intPart < 0) { this.numerator = (this.numerator).negate();
		 * this.intPart = (-1) * (this.intPart); }
		 */
		this.numerator = (this.numerator).add(BigInteger.valueOf(this.intPart)
				.multiply(this.denominator));
		this.intPart = 0;
	}

	public void toComDenominator(LongFractions fraction2) {
		if ((this.denominator).equals(fraction2.denominator))
			;
		else {
			this.numerator = (this.numerator).multiply(fraction2.denominator);
			fraction2.numerator = (fraction2.numerator)
					.multiply(this.denominator);
			this.denominator = (this.denominator)
					.multiply(fraction2.denominator);
			fraction2.denominator = this.denominator;
		}
	}

	public void reduce() {
		int intPartTemp = ((this.numerator).mod(this.denominator)).intValue();
		this.intPart = this.intPart
				+ ((this.numerator).mod(this.denominator)).intValue();
		this.numerator = (this.numerator).subtract((this.denominator)
				.multiply(BigInteger.valueOf(intPartTemp)));
	}

	public void addition(LongFractions summand) {
		if ((this.denominator).equals(summand.denominator)) {
			this.numerator = (this.numerator).add(summand.numerator);
			this.intPart = this.intPart + summand.intPart;
			this.reduce();
			
		} 
		else {
			this.toComDenominator(summand);
			this.numerator = (this.numerator).add(summand.numerator);
			this.intPart = this.intPart + summand.intPart;
			this.reduce();
		}
	}

	public void subtraction(LongFractions subtrahend) {
		this.toComDenominator(subtrahend);
		this.toImpFraction();
		subtrahend.toImpFraction();
		this.numerator = (this.numerator).subtract(subtrahend.numerator);
		this.reduce();
	}

	public void multiplication(LongFractions number2) {
		this.toImpFraction();
		number2.toImpFraction();
		this.numerator = (this.numerator).multiply(number2.numerator);
		this.denominator = (this.denominator).multiply(number2.denominator);
		this.reduce();
	}

	public void division(LongFractions number2) {
		this.toImpFraction();
		number2.toImpFraction();
		this.numerator = (this.numerator).multiply(number2.denominator);
		this.denominator = (this.denominator).multiply(number2.numerator);
		this.reduce();
	}
	
	public void Show(){
		System.out.println(intPart + " " + this.numerator.toString() + "/" + this.denominator.toString());
	}
}
//this.toString();