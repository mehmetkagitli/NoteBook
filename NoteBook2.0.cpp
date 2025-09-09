#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

void addNote() {
	string note;
	cout << "Enter your note: ";
	getline(cin, note);
	ofstream file("notes.txt", ios::app);

	time_t now = time(0);
	char date[26];
	ctime_s(date, sizeof(date), &now);
	date[strcspn(date, "\n")] = 0;

	if (file.is_open()) {

		file << "[" << date << "] " << note << endl;
		cout << "Note added successfully." << endl;
	}
	else {
		cout << "Unable to open file." << endl;
	}
	file.close();
}


void listNotes() {
	ifstream file("notes.txt");
	string note;
	if (file.is_open()) {

		int count = 1;
		cout << "Your Notes: " << endl;
		while (getline(file, note)) {
			cout << count << ". " << note << endl;
			count++;
		}
		cout << endl;
	}
	else {
		cout << "Unable to open file." << endl;
	}
	file.close();
}

void findNote() {
	string keyword;
	cout << "Enter keyword to search: ";
	getline(cin, keyword);

	ifstream file("notes.txt");
	string note;

	bool found = false;

	if (file.is_open()) {
		while (getline(file, note)) {
			if (note.find(keyword) != string::npos) {
				cout << note << endl;
				found = true;
			}
		}
	}
	else {
		cout << "Unable to open file." << endl;
	}
	if (!found) {
		cout << "No notes found with the keyword: " << keyword << endl;
	}
}

int main() {


	while (true) {
		cout << "1- Add Note\n";
		cout << "2- List Notes\n";
		cout << "3- Find Note\n";
		cout << "4- Exit\n";
		cout << endl;
		cout << "Choose an option: ";
		string input;
		getline(cin, input);
		stringstream ss(input);
		int choice;

		if (!(ss >> choice)) {
			cout << "Invalid input! Please enter a number." << endl;
			continue;
		}


		switch (choice) {
		case 1:
			addNote();
			break;
		case 2:
			listNotes();
			break;
		case 3:
			findNote();
			break;
		case 4:
			cout << "Exiting..." << endl;
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}

	}
}
