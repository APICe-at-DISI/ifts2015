package it.unibo.ifts;

import java.util.Arrays;

public class GenericList<T> {
	
	private T[] vals = (T[]) new Object[0];
	private int size = 0;
	
	public void add(T val) {
		size++;
		vals = Arrays.copyOf(vals, size);
		vals[size - 1] = val;
	}
	
	public T get(int pos) {
		return vals[pos];
	}
	
	public String toString() {
		return Arrays.toString(vals);
	}

}
