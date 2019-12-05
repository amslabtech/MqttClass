//
//	Publisher example
//	... with using Mosquitto class
//
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include "mosquitto.hpp"
#include "datastruct.hpp"

int main()
{
	Mosquitto talker1;

	// const char* ip_addr  = "192.168.0.62";
	const char* ip_addr  = "localhost";
	const char* topic    = "topic1";
	const char* username = "talker1";
	const char* password = "mqtt";
	// char  message[100];
	struct timeval ts;

	talker1.set_username_password(username,password);

	talker1.connect(ip_addr);
	talker1.subscribe(topic);

	for(int i=0; i<10000; i++) {
		float x = i/100.0F;
		gettimeofday(&ts, NULL);
		DataStructure data = { i, ts, x,x+1,x+2,  x+3,x+4,x+5,  x+6, x+7, x+8 };

		talker1.publish(topic,(void*)&data,sizeof(data));
		data.print();
		sleep(1);
	}
	sleep(1);

	talker1.cleanup_library();
}


