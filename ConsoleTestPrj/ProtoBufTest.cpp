#include "stdafx.h"
#include "ProtoBufTest.h"
#include <fstream>
#include "acctest.pb.h"
#include "person.pb.h"

using namespace std;
using namespace myPbMsg;


//#ifdef NDEBUG
//#pragma comment(lib, "../google/bin/Release64/libprotobuf.lib")  //x64版本
//#else
//#pragma comment(lib, "../google/bin/Debug64/libprotobufd.lib")
//#endif

CProtoBufTest::CProtoBufTest()
{
	person_serialize();
	person_unSerialize();
}

CProtoBufTest::~CProtoBufTest()
{

}

//Person序列化
void person_serialize()
{
	Person person;
	person.set_name("Mike Jordon");
	person.set_id(1001);
	person.set_email("MikeJD@email.com");
	Person_PhoneNumber *pPhone = person.add_phone();
	pPhone->set_type(Person_PhoneType::Person_PhoneType_MOBILE);
	pPhone->set_number("13800138000");

	fstream output("myfile.serial", ios::out | ios::binary);
	person.SerializeToOstream(&output);
}

//Person反序列化
void person_unSerialize()
{
	fstream input("myfile.serial", ios::in | ios::binary);
	Person person;
	person.ParseFromIstream(&input);
	cout << "ID: " << person.id() << endl;
	cout << "Name: " << person.name() << endl;
	cout << "E-mail: " << person.email() << endl;
	if (person.phone().size()) cout << "Phone: " << person.phone().at(0).number() << endl;
}

int testProtoBuf()
{
	IM::Account account1;
	account1.set_id(1);
	account1.set_name("windsun");
	account1.set_password("123456");

	string serializeToStr;
	account1.SerializeToString(&serializeToStr);
	cout << "序列化后的字节：" << serializeToStr << endl;


	IM::Account account2;
	if (!account2.ParseFromString(serializeToStr))
	{
		cerr << "failed to parse student." << endl;
		return -1;
	}
	cout << "反序列化：" << endl;
	cout << account2.id() << endl;
	cout << account2.name() << endl;
	cout << account2.password() << endl;

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}