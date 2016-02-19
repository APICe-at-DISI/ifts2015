package it.unibo.ifts;

import java.util.Arrays;

public class StringList {
	
	private String[] vals = new String[0];
	private int size = 0;
	
	public void add(String val) {
		size++;
		vals = Arrays.copyOf(vals, size);
		vals[size - 1] = val;
	}
	
	public String get(int pos) {
		return vals[pos];
	}
	
	public String toString() {
		return Arrays.toString(vals);
	}

}
