/**
 * 
 */
package it.unibo.ifts.es1;

/**
 * @author danysk
 *
 */
public class UseLamp {
	
	
	public static void printArray(Lamp[] larray) {
		for (int i = 0; i < larray.length; i++) {
			System.out.println("Lampadina " + i + "esima: " + larray[i].isOn());
		}
	}
	
//	public static void printArray(InfiniteLamp[] larray) {
//		for (int i = 0; i < larray.length; i++) {
//			System.out.println("Lampadina " + i + "esima: " + larray[i].isOn());
//		}
//	}
//	
	public static void main(String[] args) {
		final int size = 10;
		final LimitedLamp[] larray = new LimitedLamp[size];
		
		for (int i = 0; i < larray.length; i++) {
			larray[i] = new LimitedLamp();
		}

		for (int i = 0; i < larray.length; i++) {
			larray[i].switchOn();
		}
		printArray(larray);
	}
}
