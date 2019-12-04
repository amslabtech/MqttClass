//
//	Subscriber example
//	... with using Mosquitto class
//
#include <iostream>
#include "mosquitto.hpp"

class MyMosq : public Mosquitto {
  protected:
	const char* topic;
	void onConnected();
	void onError(const char* _msg) { std::cout << _msg; }
	void onMessage(std::string _topic, std::string _message);

  public:
	MyMosq(const char* _topic):topic(_topic){}
};

void MyMosq::onConnected()
{
	std::cout << "Connected.\n";
	subscribe(topic);
}

void MyMosq::onMessage(std::string _topic, std::string _message)
{
	std::cout << _message << std::endl;
}

int main()
{
	const char* ip_addr  = "192.168.0.62";
	const char* topic    = "topic1";
	const char* username = "listener1";
	const char* password = "mqtt";

	MyMosq listener1(topic);

	listener1.set_username_password(username,password);
	listener1.connect(ip_addr);


	for(int i=0; i<10000; i++) {
		listener1.loop(false);
		std::cout << "listener main loop " << i << std::endl;
		sleep(1);
	}

	listener1.cleanup_library();
}


