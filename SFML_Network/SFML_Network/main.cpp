#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

int main()
{
	TcpSocket socket; // tworzymy gniazdo klienta
	IpAddress ip = IpAddress::getPublicAddress();
	char connectionType, mode;
	size_t received;
	char buffor[2000];
	string text = "Connected to: ";

	cout << "serwer czy klient? s lub k: "; cin >> connectionType; cout << endl;

	if (connectionType == 's')
	{
		cout << ip.toString() << endl;
		TcpListener listener;
		listener.listen(52000);
		listener.accept(socket);
		text += "Server";
	}
	else if (connectionType == 'k')
	{
		cout << "wpisz ip serwera: ";
		cin >> ip; cout << endl;
		socket.connect(ip, 52000);
		text += "Client";
	}
	socket.send(text.c_str(), text.length() + 1);
	socket.receive(buffor, sizeof(buffor), received);
	cout << buffor << endl;


	sf::RenderWindow window(sf::VideoMode(640, 480), "xd");


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

	}
	return 0;

}