package it.unibo.ifts.es2;

public class Remote {

	private Battery battery;
	
	public Remote(final Battery batt) {
		this.battery = batt;
	}
	
	public void pressButton(final String button) {
		if(battery.isCharged()) {
			battery.discharge(1);
			System.out.println(button);
		}
	}
	
	public Battery changeBattery(final Battery newBattery) {
		final Battery oldBattery = this.battery;
		this.battery = newBattery;
		return oldBattery;
	}
	
}
