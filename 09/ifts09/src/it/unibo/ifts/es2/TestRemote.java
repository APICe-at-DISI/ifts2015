package it.unibo.ifts.es2;

public class TestRemote {
	
	private static void pressButtons(Remote r, int nButtons){
		for(int i = 0; i < nButtons; i++) {
			r.pressButton("button " + i);
		}
	}

	public static void main(String[] args) {
		final Battery batt = new NuclearBattery();
		Remote remote = new Remote(batt);
		TestRemote.pressButtons(remote, 100);
		final Battery batt2 = new UnpredictableBattery(0.1);
		final Battery oldBatt = remote.changeBattery(batt2);
		if (oldBatt.isCharged()) {
			System.out.println("Batteria ancora carica");
		}
		TestRemote.pressButtons(remote, 100);
	}

}
