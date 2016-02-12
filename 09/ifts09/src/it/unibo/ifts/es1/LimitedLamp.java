package it.unibo.ifts.es1;

public class LimitedLamp implements Lamp {
	
	private boolean state;
	private int switches;
	
	public void switchOn() {
		if (switches < 10) {
			this.state = true;
			this.switches++;
		}
	}
	
	public void switchOff(){
		this.state = false;
	}
	
	public boolean isOn(){
		return this.state;
	}

}
