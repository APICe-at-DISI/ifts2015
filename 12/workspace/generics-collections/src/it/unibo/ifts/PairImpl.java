package it.unibo.ifts;

public class PairImpl<X, Y> implements Pair<X, Y> {
	
	private final X o1;
	private final Y o2;

	public PairImpl(X o1, Y o2) {
		this.o1 = o1;
		this.o2 = o2;
	}
	
	public X getFirst() {
		return o1;
	}
	
	public Y getSecond() {
		return o2;
	}
	
	public String toString() {
		return "{" + this.getFirst() + ", " + this.getSecond() + "}";
	}
	
	public boolean equals(Object obj) {
		if (obj instanceof Pair) {
			final Pair<?, ?> p = (Pair<?, ?>) obj;
			final X first = this.getFirst();
			final Y second = this.getSecond();
			return first.equals(p.getFirst()) && second.equals(p.getSecond());
		}
		return false;
	}
	
}
