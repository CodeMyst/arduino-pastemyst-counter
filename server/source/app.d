import std.stdio;
import std.process;
import std.bitmanip;
import core.thread;
import onyx.serial;
import pastemyst.data;

void main()
{
	auto port = environment.get("PM_PORT");

	if (port is null)
	{
		throw new Exception("Environment PM_PORT is not set.");
	}

	auto serialPort = OxSerialPort(port, Speed.S9600, Parity.none, 1000);

	serialPort.open();
	scope(exit) serialPort.close();

	while (true)
	{
		long pastes = getNumPastes();

		writeln("Sending: ", pastes);

		ubyte[8] packet = nativeToBigEndian(pastes);

		serialPort.write(packet);

		writeln("Waiting one minute...");

		Thread.sleep(dur!("minutes")(1));
	}
}
