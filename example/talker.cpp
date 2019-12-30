//
//	Publisher example
//	... with using Mosquitto class
//
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include "mosquitto.hpp"		// c++ wrapper for mosquitto
#include "datastructure.hpp"	// my data types

int main(int argc, char* argv[])
{
	Mosquitto talker1;

	char const * ip_addr  = NULL;
	if(argc>1) {
		ip_addr  = argv[1];
	} else {
		ip_addr  = "localhost";
	}
	const char* topic    = "topic1";
	const char* username = "talker1";
	const char* password = "mqtt";
//	struct timeval ts;

	talker1.set_username_password(username,password);

	talker1.connect(ip_addr);
	talker1.subscribe(topic);

	std::cout << "\ndatasize = " << sizeof(DataStructure) << " bytes\n";

	for(int i=0; i<10000; i++) {
		float x = i/100.0F;	// test data
		//gettimeofday(&ts, NULL);
		DataStructure data = {
			i, x,x+1,x+2,  x+3,x+4,x+5,  x+6, x+7, x+8, x+9, x+10, x+11
		};

		talker1.publish(topic,(void*)&data,sizeof(data));
		data.print();
		usleep(100*1000);
	}
	sleep(1);

	talker1.cleanup_library();
}


