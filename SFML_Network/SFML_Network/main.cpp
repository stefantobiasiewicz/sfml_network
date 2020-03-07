#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include "funkcje.h"
#include <conio.h>

using namespace sf;
using namespace std;

int main()
{
	TcpSocket socket; // tworzymy gniazdo klienta
	IpAddress ip = IpAddress::getLocalAddress();
	char connectionType, mode;
	size_t received;
	char buffor[2000];
	string p;
	string text = "Connected to: ";

	cout << "serwer czy klient? s lub k: "; cin >> connectionType; cout << endl;

	if (connectionType == 's')
	{
		cout << ip.toString() << endl;
		TcpListener listener;
		listener.listen(1410);
		listener.accept(socket);
		text += "Server";

	}
	else if (connectionType == 'k')
	{
		cout << ip.toString() << endl;
		cout << "wpisz ip serwera: ";
		cin >> ip; cout << endl;
		socket.connect(ip, 1410);
		text += "Client";
	}

	socket.receive(buffor, sizeof(buffor), received);
	socket.send(text.c_str(), text.length() + 1);
	cout << buffor << endl;

	bool on = 1;

	while (on)
	{
		czysc_buffor(buffor);
		if (socket.receive(buffor, sizeof(buffor), received) == Socket::Status::Done)
		{
			cout << buffor << endl;
			czysc_buffor(buffor);
		}
		else
		{

		}

		if (_kbhit())
		{
			cin >> buffor;
			socket.send(buffor, text.length() + 1);
			cin.clear();
			//cout << buffor << endl;
		}
		else
		{

		}
	}


	/*sf::RenderWindow window(sf::VideoMode(640, 480), "xd");


	while (window.isOpen())
	{
		sf::Event iwent;
		//handle events
		while (window.pollEvent(iwent))
		{
			// Close window: exit
			if (iwent.type == sf::Event::Closed)
				window.close();
		}

		//update

		window.clear();

		//drawing objects


		window.display();

	}*/
	return 0;

}