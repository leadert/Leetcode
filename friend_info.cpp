#include<iostream>
using namespace std;


//class A {
//private:
//	int aa;
//	static int saa;
//
//public:
//	A();
//	void setA(int x);
//	friend void printA(A a);
//	friend class B;
//};
//
//
//class B {
//public:
//	void printB();
//};
//
//
//int A::saa = 20;
//A::A() {
//	aa = 0;
//	A::saa++;
//}
//
//void A::setA(int x) {
//	aa = x;
//}
//
//void printA(A a) {
//	cout << a.aa << endl;
//	cout << A::saa << endl;
//}
//
//void B::printB() {
//	cout << ++A::saa << endl;
//}


//int main() {
//	A obja;
//	obja.setA(5);
//	printA(obja);
//	
//	B ojbb;
//	ojbb.printB();
//	return 0;
//}