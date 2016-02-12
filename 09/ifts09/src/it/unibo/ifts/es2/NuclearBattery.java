package it.unibo.ifts.es2;

public class NuclearBattery implements Battery {

	@Override
	public boolean isCharged() {
		return true;
	}

	@Override
	public void discharge(int quantity) {
	}

}
