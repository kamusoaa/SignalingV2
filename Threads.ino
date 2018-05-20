
void doInMotionSensorThread1()
{
	motionSensor1.doInThread(state, controller);
}

void doInMotionSensorThread2()
{
	motionSensor2.doInThread(state, controller);
}

void doInSoundSensorThread()
{
	soundSensor.doInThread(state, controller);
}

void doInProximitySensorThread()
{
	proximity.doInThread(state, controller);
}
void doInHallThread()
{
	hallSensor.doInThread(state, controller);
}

void sendData()
{
	String data;
	data += "imei=";
	data += moduleIMEI;
	data += "&alarm=";
	data += state.isAlarm();
	if (state.isAlarm())
	{
		data += "&sensor=";
		data += state.getName();
	}
	data += "&motion1=";
	data += motionSensor1.getValue();
	data += "&motion2=";
	data += motionSensor2.getValue();
	data += "&hall=";
	data += hallSensor.getValue();
	data += "&prox=";
	data += proximity.getValue();
	data += "&sound=";
	data += soundSensor.getValue();
	data += "&cmd=";
	data += commandResponse;

	modem.sendHttpRequest("http://gsmserver.herokuapp.com/q/modem?",data);
	_JSON = modem.readHttpRequest();
	_run = true;

}
