package it.unibo.ifts.es2;

public class BrokenBattery implements Battery {

	@Override
	public boolean isCharged() {
		return false;
	}

	@Override
	public void discharge(int quantity) {
	}

}
