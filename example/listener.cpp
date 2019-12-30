//
//	Subscriber example
//	... with using Mosquitto class
//
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <mosquitto.hpp>		// c++ wrapper of mosquitto
#include "datastructure.hpp"	// my data structure

class MyMosq : public Mosquitto {
  protected:
	DataStructure data;
	const char* topic;
	void onConnected();
	void onError(const char* _msg) { std::cout << _msg; }
//	void onMessage(std::string _topic, std::string _message);
	void onMessage(std::string _topic, void* _data, int _len);
	struct timeval ts;

  public:
	MyMosq(const char* _topic):topic(_topic){}
};

void MyMosq::onConnected()
{
	std::cout << "Connected.\n";
	subscribe(topic);
}

#include <strings.h>
void MyMosq::onMessage(std::string _topic, void* _data, int _len)
{
	gettimeofday(&ts,NULL);
	bcopy(_data, (char*)&data, sizeof(data));		
//	int32_t diff = (ts.tv_sec-data.ts.tv_sec)*1000000 + ts.tv_usec-data.ts.tv_usec;
//	std::cout << std::setw(5) << diff << " usec,";
	data.print();
}

int main(int argc, char* argv[])
{
	char const * ip_addr  = NULL;
	if(argc>1) {
		ip_addr  = argv[1];
	} else {

		// const char* ip_addr  = "192.168.0.62";
		// const char* ip_addr  = "192.168.1.25";
		ip_addr  = "localhost";
	}

	const char* topic    = "topic1";
	const char* username = "listener1";
	const char* password = "mqtt";

	MyMosq listener1(topic);

	listener1.set_username_password(username,password);
	listener1.connect(ip_addr);
	listener1.loop_start();

	for(int i=0; i<1000000; i++) {
		std::cout << "main loop[" << i << "]\n";
		sleep(2);
	}

	listener1.cleanup_library();
}


