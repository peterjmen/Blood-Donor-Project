#include <iostream>
#include <string>

using namespace std;

int attempts = 0;

//void menu(string& input, int& stringToInt);
//void validInputCheckerFromOneToNine(string& input, int& stringToInt);
void validInputChecker(string& input, int& stringToInt, int& noOfOptions, int& attempts);
void adminLogin(int& attempts);
void adminMenu();

int main() {

	string input;
	int stringToInt = input[0] - 48;
	

	if (attempts > 3) { return 0; };

	cout << "\tWelcome to the bloodbank\n\n";
	cout << "Are you:\n";
	cout << "1. A new or current donor\n";
	cout << "2. A new or current recipient\n";
	cout << "3. Staff\n";
	int noOfOptions = 3;
	getline(cin, input); 
	validInputChecker(input, stringToInt, noOfOptions, attempts);
	switch (stringToInt) {
	case 1:
		cout << "You have selected new or current donor" << endl;
		cout << "Would you like to: \n";
		cout << "1. Login\n";
		cout << "2. Register\n";
		cout << "Any key you press will end program as this is out of pete's scope" << endl;
		break;
	case 2:
		cout << "You have new or current recipient" << endl;
		cout << "Would you like to: \n";
		cout << "1. Login\n";
		cout << "2. Register\n";
		cout << "Any key you press will end program as this is out of pete's scope" << endl;
		break;
	case 3:
		adminLogin(attempts);
		if (attempts > 3) { return 0; };
		adminMenu();
		noOfOptions = 7;
		cout << "Choose your option: " << endl;
		cin.ignore(); getline(cin, input);
		validInputChecker(input, stringToInt, noOfOptions, attempts);
		switch (stringToInt) {
		case 1:
			cout << "1. View recipient information " << endl;
			cout << "But nothing further has been implement, goodbye (press any key to exit) " << endl;
			break;
		case 2:
			cout << "2. View donor information" << endl;
			cout << "But nothing further has been implement, goodbye (press any key to exit) " << endl;
			break;
		case 3:
			cout << "3. Report based on blood group" << endl;
			cout << "But nothing further has been implement, goodbye (press any key to exit) " << endl;
			break;
		case 4:
			cout << "4. Report based on location " << endl;
			cout << "But nothing further has been implement, goodbye (press any key to exit) " << endl;
			break;
		case 5:
			cout << "5. Recipient report" << endl;
			cout << "But nothing further has been implement, goodbye (press any key to exit) " << endl;
			break;
		case 6:
			cout << "6. Donor report " << endl;
			cout << "But nothing further has been implement, goodbye (press any key to exit) " << endl;
			break;
		case 7:
			cout << "7. Update donor's blood testing reports" << endl;
			cout << "But nothing further has been implement, goodbye (press any key to exit) " << endl;
			break;
		}
	};




	
	//menu(input);


	system("pause > 0");
}

//void menu(string& input, int& stringToInt) {
//	cout << "Please choose and option :";
//	cout << "\n1. Yes";
//	cout << "\n2. No";
//	cout << "\n3. Exit\n";
//	
//	getline(cin, input);
//	validInputCheckerFromOneToNine(input, stringToInt);
//	cout << "\nContinue to more things!\n";
//
//
//	menu(input, stringToInt);
//}

//void validInputCheckerFromOneToNine(string& input, int& stringToInt) {
//	if (stringToInt < 1 || stringToInt > 9 || input.size() > 1) { //errors if anything except numbers from 1-9 are entered.
//	cout << "\"" << input << "\"" << "is not valid input, please try again entering a number from 1 to 0\n";
//	menu(input, stringToInt);
//	}
//	else {
//		cout << "\"" << stringToInt << "\"" << "is valid input, Please continue\n";
//	}
//}

void validInputChecker(string& input, int& stringToInt, int& noOfOptions, int& attempts) {
	stringToInt = input[0] - 48;
	if (stringToInt < 1 || stringToInt > noOfOptions || input.size() > 1) {
		cout << "\"" << input << "\"" << "is not valid input, you needed to enter a number from 1-" << noOfOptions <<"\n";
		cout << "You're going to need to start again\n";
		attempts = 0;
		main();
	}
	else {
		cout << "\"" << stringToInt << "\"" << "is valid input, Please continue\n";
	}
}




void adminLogin(int& attempts) {
	cout << "You have selected Staff, Please enter Login" << endl;
	attempts++;
	if (attempts > 3) {
		cout << "\nThat is 3 failed attempts, program terminated" << endl;
		return;
	}
	cout << "\nUsername: " << endl;
	string userName;
	cin >> userName;
	cout << "\nPassword: " << endl;
	string password;
	cin >> password;
	if (userName == "admin" && password == "admin") {
		cout << "\nsuccess! You have access, here's the menu: " << endl;
	}
	else {
		cout << "\n" << userName << " & " << password << " are not a valid username an password, please try again" << endl;
		adminLogin(attempts);
	}

}

void adminMenu() {
	cout << "1. View recipient information " << endl;
	cout << "2. View donor information" << endl;
	cout << "3. Report based on blood group" << endl;
	cout << "4. Report based on location "<< endl;
	cout << "5. Recipient report" << endl;
	cout << "6. Donor report " << endl;
	cout << "7. Update donor's blood testing reports" << endl;

}