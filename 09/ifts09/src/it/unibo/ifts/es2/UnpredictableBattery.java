package it.unibo.ifts.es2;

public class UnpredictableBattery implements Battery {
	
	private final double probability;
	
	public UnpredictableBattery(final double probability) {
		this.probability = probability;
	}

	@Override
	public boolean isCharged() {
		return Math.random() < this.probability;
	}

	@Override
	public void discharge(int quantity) {
	}

}
