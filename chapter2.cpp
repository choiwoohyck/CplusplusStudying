//class Empty{}; 이렇게 생성해도 밑에 있는 것들 전부 생성됨
#include <string>
using namespace std;

class Empty {
public:
	Empty() {}; // 기본 생성자
	Empty(const Empty& rhs) {}; // 복사 생성자
	~Empty() {}; // 기본 소멸자
	Empty& operator=(const Empty& rhs) {}; // 복사 대입 연산자
};

template<typename T>
class NameObject {
public:
	NameObject(const char* name, const T& value) {};
	NameObject(string& name, const T& value) {};

private:
	std::string nameValue;
	T ObjectValue;


};
// 생성자가 이미 생성되어 있는 경우에는 기본 생성자가 생성되지 않음 , 반면 복사 생성자나 복사 대입 연산자는 컴파일러에의해 만들어짐

template<typename t2>
class NameObject2 {
public:
	NameObject2(string& name, const t2& value) {};

private:
	std::string& nameValue;
	const t2 ObjectValue;


};



class HomeForSale {

private:
	HomeForSale(const HomeForSale&) ;  //private로 정의 해놓으면 복사 대입 문제나 복사 생성 문제 해결가능 (하지마세요 문제)
	HomeForSale& operator= (const HomeForSale&) ;
};


// 밑에 처럼 클래스 하나 만들어서 상속하는 것도 깔끔 하지만 다중상속 문제 있음.

class Uncopyable {
private:
	Uncopyable(const Uncopyable&);  //private로 정의 해놓으면 복사 대입 문제나 복사 생성 문제 해결가능
	Uncopyable& operator= (const Uncopyable&);
};

class HomeForSale2 : private Uncopyable {

};

// 예외가 소멸자를 떠나지 못하도록 하자! 문제가 생길 수 있으니 이렇게 짜자!

class DBConnect {
public:
	void close() {};
};



class DBConn {
public:
	void close()
	{
		db.close();
		closed = true;
	}

	~DBConn() {
		if (!closed)
			try {
			db.close();
		}
		catch (...) {

		}
	};
private:
	bool closed;
	DBConnect db;
};
////////////////////////////////////////////
int main()
{
	NameObject<int> nol("Smallest Prime number", 2);
	NameObject<int>no2(nol); // 가능은 함

	string newDog("Per");
	string oldDog("Sat");

	NameObject2<int>p(newDog, 2);
	NameObject2<int>s(oldDog, 36);

	// HomeForSale h1(h2);  h1 = h2; 이것도 하지마세요 하지마세요

	//p = s;  // 멸망
	return 0;

	
}

// 항목7 다형성을 가진 기본 클래스에서는 소멸자를 반드시 가상 소멸자로 선언하자 그러나 그렇지 않은 경우에 가상 소멸자로 하면 문제 발생!