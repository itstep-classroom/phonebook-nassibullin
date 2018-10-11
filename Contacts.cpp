#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int size = 0;
char bookname[30];
bool saved = true;

struct Contact {
	string name, phone;
};

vector <Contact> contacts;

void add(Contact x) {
	size++;
	contacts.push_back(x);
	saved = false;
}

void remove(string param) {
	for (int i = 0; i < size; i++)
		if (contacts[i].name == param || contacts[i].phone == param) {
			contacts.erase (contacts.begin() + i);
			--size;
			break;
		}
	saved = false;
}

void search(string param) {
	for (int i = 0; i < size; i++)
		if (contacts[i].name == param || contacts[i].phone == param) {
			cout << contacts[i].name << ' ' << contacts[i].phone;
			break;
		}
}

bool cmpByName(Contact a, Contact b) {
	return a.name < b.name;
}

bool cmpByPhone(Contact a, Contact b) {
	return a.phone < b.phone;
}

void sortContacts() {
	int option;
	cout << "Sort by name(0) or number(1)?\n";
	cin >> option;
	if (option == 0) {
		sort(contacts.begin(), contacts.end(), &cmpByName);
	} else {
		sort(contacts.begin(), contacts.end(), &cmpByPhone);
	}
	saved = false;
}

void load() {
	ifstream fin(bookname);
	int n;
	fin >> n;
	
	if (size > 0)
		contacts.clear();
	size = 0;
	for (int i = 0; i < n; i++) {
		Contact x;
		fin >> x.name >> x.phone;
		add(x);
	}
	
	cout << bookname << " loaded" << endl;
	fin.close();
}

void save() {
	ofstream fout(bookname);
	fout << size << endl;
	for (int i = 0; i < size; i++) {
		fout << contacts[i].name << " " << contacts[i].phone << endl;
	}
	cout << "saved as " << bookname << endl;
	fout.close();
}

void create() {
	cout << bookname << " was created." << endl;
}

void show() {
	cout << bookname << (saved ? " saved" : " not saved") << endl;
	for(int i = 0; i < size; i++)
		cout << contacts[i].name << " " << contacts[i].phone << endl;
}

void help() {
	cout << endl << "-------------------\n";
	cout << "-create" << endl;
	cout << "-add" << endl;
	cout << "-save / saveas" << endl;
	cout << "-load" << endl;
	cout << "-show" << endl;
	cout << "-search" << endl;
	cout << "-sort" << endl;
	cout << "-remove" << endl;
	cout << "-exit" << endl;
	cout << "-------------------\n";
}

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
