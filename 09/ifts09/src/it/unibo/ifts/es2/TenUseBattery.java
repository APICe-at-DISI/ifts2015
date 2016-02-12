package it.unibo.ifts.es2;

public class TenUseBattery implements Battery {
	
	private int charge = 10;

	public boolean isCharged() {
		return this.charge > 0;
	}

	public void discharge(int quantity) {
		this.charge = this.charge - quantity;
	}

}
