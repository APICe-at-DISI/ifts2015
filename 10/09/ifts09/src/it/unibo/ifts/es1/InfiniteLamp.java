package it.unibo.ifts.es1;

public class InfiniteLamp implements Lamp {
	
	private boolean state;
	
	public void switchOn() {
		this.state = true;
	}
	
	public void switchOff(){
		this.state = false;
	}
	
	public boolean isOn(){
		return this.state;
	}

}
