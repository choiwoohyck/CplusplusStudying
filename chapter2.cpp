//class Empty{}; �̷��� �����ص� �ؿ� �ִ� �͵� ���� ������
#include <string>
using namespace std;

class Empty {
public:
	Empty() {}; // �⺻ ������
	Empty(const Empty& rhs) {}; // ���� ������
	~Empty() {}; // �⺻ �Ҹ���
	Empty& operator=(const Empty& rhs) {}; // ���� ���� ������
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
// �����ڰ� �̹� �����Ǿ� �ִ� ��쿡�� �⺻ �����ڰ� �������� ���� , �ݸ� ���� �����ڳ� ���� ���� �����ڴ� �����Ϸ������� �������

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
	HomeForSale(const HomeForSale&) ;  //private�� ���� �س����� ���� ���� ������ ���� ���� ���� �ذᰡ�� (���������� ����)
	HomeForSale& operator= (const HomeForSale&) ;
};


// �ؿ� ó�� Ŭ���� �ϳ� ���� ����ϴ� �͵� ��� ������ ���߻�� ���� ����.

class Uncopyable {
private:
	Uncopyable(const Uncopyable&);  //private�� ���� �س����� ���� ���� ������ ���� ���� ���� �ذᰡ��
	Uncopyable& operator= (const Uncopyable&);
};

class HomeForSale2 : private Uncopyable {

};

// ���ܰ� �Ҹ��ڸ� ������ ���ϵ��� ����! ������ ���� �� ������ �̷��� ¥��!

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
	NameObject<int>no2(nol); // ������ ��

	string newDog("Per");
	string oldDog("Sat");

	NameObject2<int>p(newDog, 2);
	NameObject2<int>s(oldDog, 36);

	// HomeForSale h1(h2);  h1 = h2; �̰͵� ���������� ����������

	//p = s;  // ���
	return 0;

	
}

// �׸�7 �������� ���� �⺻ Ŭ���������� �Ҹ��ڸ� �ݵ�� ���� �Ҹ��ڷ� �������� �׷��� �׷��� ���� ��쿡 ���� �Ҹ��ڷ� �ϸ� ���� �߻�!