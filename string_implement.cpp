#pragma warning(disable : 4996)

#include<iostream>
using namespace std;


class stringMine {
private:
	char* str;
	int len;
	static int num_string;

public:
	stringMine();
	stringMine(const char* s);
	stringMine(const stringMine& st);
	stringMine& operator=(const stringMine& st);
	~stringMine();

	friend ostream& operator<<(ostream& os, const stringMine& st);
};


int stringMine::num_string = 0;
stringMine::stringMine() {
	len = 4;
	str = new char[len];
	strcpy(str, "C++");
	num_string++;
	cout << num_string << ":" << str << " created by default construction" << endl;
}

stringMine::stringMine(const char* s) {
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	num_string++;
	cout << num_string << ":" << str << " created by assignment construction" << endl;
}

stringMine::stringMine(const stringMine& st) {
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	num_string++;
	cout << num_string << ":" << str << " created by assignment copy construction" << endl;
}

stringMine& stringMine::operator=(const stringMine& st) {
	if (this == &st)
		return *this;
	delete[]str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	num_string++;
	cout << num_string << ":" << str << " created by assignment copy operator" << endl;
	return *this;
}

stringMine::~stringMine() {
	cout << str << " is deleted" << endl;
	num_string--;
	delete[]str;
}

ostream& operator<<(ostream& os, const stringMine& st) {
	os << st.str;
	return os;
}


//int main() {
//	stringMine s1;
//	stringMine s2("Hello, C++");
//	stringMine s3 = s2;
//	stringMine s4;
//	s4 = s2;
//	cout << "s1:" << s1 << endl;
//	cout << "s2:" << s2 << endl;
//	cout << "s3:" << s3 << endl;
//	cout << "s4:" << s4 << endl;
//	return 0;
//}