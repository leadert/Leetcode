#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

class Singleton {
private:
	Singleton() {
		cout << "construct obj!" << endl;
	}
	static Singleton* instance;
	static mutex mtx;
public:
	static Singleton* get_Instance(){
		if(instance == NULL) {
			if(mtx.try_lock()) {
				if (instance == NULL) {
					instance = new Singleton();
				}
				mtx.unlock();
			}
		}
		return instance;
	}
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

//int main() {
//	Singleton* instance1 = Singleton::get_Instance();
//	Singleton* instance2 = Singleton::get_Instance();
//	return 0;
//}