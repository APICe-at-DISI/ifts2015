package it.unibo.ifts;

import java.util.Arrays;

public class IntList {
	
	private int[] vals = new int[0];
	private int size = 0;
	
	public void add(int val) {
		size++;
		vals = Arrays.copyOf(vals, size);
		vals[size - 1] = val;
	}
	
	public int get(int pos) {
		return vals[pos];
	}
	
	public String toString() {
		return Arrays.toString(vals);
	}

}
