//
//	Publisher example
//	... with using Mosquitto class
//
#include <iostream>
#include "mosquitto.hpp"

int main()
{
	Mosquitto talker1;

	const char* ip_addr  = "192.168.0.62";
	const char* topic    = "topic1";
	const char* username = "talker1";
	const char* password = "mqtt";
	char  message[100];

	talker1.set_username_password(username,password);

	talker1.connect(ip_addr);
	talker1.subscribe(topic);

	for(int i=0; i<10000; i++) {
		sprintf(message,"Hello %05d",i);
		talker1.publish(topic,message);
		std::cout << username << " say ["<< message << "] to " << topic << std::endl;
		sleep(1);
	}

	talker1.cleanup_library();
}


