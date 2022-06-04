#include <iostream>
#include <string>

using namespace std;


void menu(string&input);
void validInputCheckerFromOneToTen(string& input);


int main() {
	
	string input;
	menu(input);



	system("pause > 0");
}

void menu(string &input) {
	cout << "Please choose and option :";
	cout << "\n1. Yes";
	cout << "\n2. No";
	cout << "\n3. Exit\n";
	getline(cin, input);
	validInputCheckerFromOneToTen(input);
	cout << "\nContinue to to more things!\n";
	//int stringToInt = input[0]-48;
	///*(int)input[0]*/
	//switch (stringToInt) {
	//case 1:
	//	cout << "You chose option " << stringToInt << ".\n";
	//	break;
	//case 2:
	//	cout << "You chose option " << stringToInt << ".\n";
	//	break;
	//case 3:
	//	cout << "You chose option " << stringToInt <<". Exit, goodbye\n\n\n";
	//	return;
	//	break;
	//case 4:
	//case 5:
	//case 6:
	//case 7:
	//case 8:
	//case 9:
	//	cout << "This option has not been implemented yet.\n";
	//	break;
	//default:
	//	cout << "\"" <<input << "\"" << "is not valid input, please try again\n";
	//}

		menu(input);
}

 void validInputCheckerFromOneToTen(string & input){
	int stringToInt = input[0] - 48;
	if (stringToInt <1 || stringToInt > 10){
	cout << "\"" << input << "\"" << "is not valid input, please try again entering a number from 1-10\n";
	menu(input);
	}
	else {
		cout << "\"" << stringToInt << "\"" << "is valid input, Please continue\n";
	}

}



//
////convert first letter of string to int
//cout << (int)input[0];