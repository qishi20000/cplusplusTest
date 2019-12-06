#include "addressbook.pb.h"
#include <string>
#include <iostream>

using namespace std;
void PromptForAddress(tutorial::Person* person)
{
	std::cout<<"Enter person ID number";
	int id;
	cin >> id;
	person->set_id(id);
	cin.ignore(256, '\n');

	std::cout << "Enter name:";
	getline(cin, *person->mutable_name());

	std::cout << "Enter email address (blank for none):";
    std::string email;
	getline(cin, email);
	if (!email.empty())
	{
		person->set_email(email);
	}

	while (true) {
		cout << "Enter a phone number (or leave blank to finish): ";
		string number;
		getline(cin, number);
		if (number.empty()) {
			break;
		}

		tutorial::Person::PhoneNumber* phone_number = person->add_phones();
		phone_number->set_number(number);

		cout << "Is this a mobile, home, or work phone? ";
		string type;
		getline(cin, type);
		if (type == "mobile") {
			phone_number->set_type(tutorial::Person::MOBILE);
		}
		else if (type == "home") {
			phone_number->set_type(tutorial::Person::HOME);
		}
		else if (type == "work") {
			phone_number->set_type(tutorial::Person::WORK);
		}
		else {
			cout << "Unknown phone type.  Using default." << endl;
		}
	}
}

int main()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	tutorial::AddressBook address_book;

	PromptForAddress(address_book.add_people());

}