#include <iostream>
#include <string>

using namespace std;


void menu(string& input);
void validInputCheckerFromOneToNine(string& input);


int main() {

	string input;
	menu(input);


	system("pause > 0");
}

void menu(string& input) {
	cout << "Please choose and option :";
	cout << "\n1. Yes";
	cout << "\n2. No";
	cout << "\n3. Exit\n";
	
	getline(cin, input);
	validInputCheckerFromOneToNine(input);
	cout << "\nContinue to more things!\n";


	menu(input);
}

void validInputCheckerFromOneToNine(string& input) {
	int stringToInt = input[0] - 48;
	if (stringToInt < 1 || stringToInt > 9 || input.size() > 1) { //errors if anything except numbers from 1-9 are entered.
	cout << "\"" << input << "\"" << "is not valid input, please try again entering a number from 1-10\n";
	menu(input);
	}
	else {
		cout << "\"" << stringToInt << "\"" << "is valid input, Please continue\n";
	}

}
