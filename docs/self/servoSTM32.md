## Running servo motor with STM32

*  Servo runs at 20ms(50Hz) with '0' position having 1ms HIGH and '180' position having 2ms HIGH
<https://www.microcontroller-project.com/interfacing-servo-motor-with-stm32.html>
*  We have to change the pwm frequency of stm using the command `timer.setPeriod(20000)` (20000us)
* ```c
    HardwareTimer timer(3);

	float pos = 0;
	double pwm = 0.0;

	void setup()
	{
	  timer.setPeriod(20000);
	  pinMode(PB1,PWM);
	}

	void loop(){
	  //pwm = (1.0 + pos/180.0)*3276.8;
	  pwmWrite(PB1,4733); //pos = 80
	  delay(1000);
	  pwmWrite(PB1,6553); //pos = 180
	  delay(1000);
	}
```