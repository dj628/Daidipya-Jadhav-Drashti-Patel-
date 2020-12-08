void setup()
{
	Serial.begin(9600);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	digitalWrite(9, HIGH);
	delay(500);
	digitalWrite(10, HIGH);
	delay(500);
	digitalWrite(11, HIGH);
	delay(500);
}

void loop()
{
	if (analogRead(A0) > 624)
	{
		digitalWrite(11, HIGH);
	}
	else
	{
		digitalWrite(11, LOW);
	}
	if (analogRead(A0) > 621)
	{
		digitalWrite(9, HIGH);
	}
	else
	{
		digitalWrite(9, LOW);
	}
	if (analogRead(A0) >625)
	{
		digitalWrite(10, HIGH);
	}
	else
	{
		digitalWrite(10, LOW);
	}

	Serial.println(analogRead(A0));
	delay(20);
}
