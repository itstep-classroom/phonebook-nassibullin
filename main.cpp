#include <iostream>
#include <cstring>
#include "Contacts.hpp"

using namespace std;

int main() {
	char com[20];
	cout << "Welcome to PhoneBook Management System" << endl;
	cout << "\nEnter your command: ";
	while (cin >> com) {
		if (strcmp(com, "create") == 0) {
			strcpy(bookname, "noname_book.txt");
			create();
		}
		if (strcmp(com, "load")==0) {
			cin >> bookname;
			load();
		}
		if (strcmp(com, "exit")==0) {
			break;
		}
		if (strcmp(com, "save")==0) {
			save();				
		}
		if (strcmp(com, "saveas") == 0) {
			cin >> bookname;
			save();
		}
		if (strcmp(com, "show") == 0) {
			show();
		}
		if (strcmp(com, "add") == 0) {
			Contact x;
			cin >> x.name >> x.phone;
			add(x);
		}
		if (strcmp(com, "sort") == 0) {
			sortContacts();
		}
		if (strcmp(com, "remove") == 0) {
			string param;
			cout << "Enter Contact's name or phone number\n";
			cin >> param;
			remove(param);
		}
		if (strcmp(com, "search") == 0) {
			string param;
			cout << "Enter Contact's name or phone number\n";
			cin >> param;
			search(param);
		}
		if (strcmp(com, "help") == 0) {
			help();
		}
		cout << "\nEnter your command: ";
	}

}
