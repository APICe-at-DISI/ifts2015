package it.unibo.ifts;

public class UseGenericList {

	public static void main(String[] args) {
		
		final GenericList<Integer> l = new GenericList<Integer>();
		l.add(1);
		l.add(2);
		l.add(1561);
		int val = l.get(0);
		System.out.println(l);
		System.out.println(val);
		
		final GenericList<String> ls = new GenericList<String>();
		ls.add("ciao");
		ls.add("ciao");
		ls.add("mare");
		System.out.println(ls);

		final GenericList<Pair<String, Integer>> lll = new GenericList<>();
		final Pair<String, Integer> age0 = new PairImpl<>("Mario Rossi", 36);
		final Pair<String, Integer> age1 = new PairImpl<>("Gina Bianchi", 22);
		lll.add(age0);
		lll.add(age1);
		lll.add(new PairImpl<>("ciao", 4));
		System.out.println(lll);
		
		final Pair<String, String> p1 = new StringPair("asd", "efdew");
		final Pair<String, String> p2 = new StringPair("asd", "efdew");
		if (p1 == p2) {
			System.out.println("STESSO OGGETTO!");
		} else {
			System.out.println("OGGETTI DIVERSI!");
		}
		if (p1.equals(p2)) {
			System.out.println("Sono considerati uguali");
		} else {
			System.out.println("Sono considerati diversi");
		}
		
		final GenericList<Object> lo = new GenericList<Object>();
		lo.add(new Object());
		lo.add("ciao");
		lo.add(1);
		lo.add(true);
		String val2 = (String) lo.get(1);
//		String val3 = (String) lo.get(2);
		System.out.println(lo);
	}

}
