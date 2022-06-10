#include <iostream>
#include <string>
#include <fstream> // includes both
#include <vector>
#include <sstream>

using namespace std;

int attempts = 0;

//void menu(string& input, int& stringToInt);
//void validInputCheckerFromOneToNine(string& input, int& stringToInt);
void validInputChecker(string& input, int& stringToInt, int& noOfOptions);
void adminLogin(int& attempts);



void createDonor();

void createRecipient();

void readDonorReport();
void readRecipientReport();

void makeChangeDonor();
void makeChangeRecipient();


void printAdminMenu();
void loggedInAdminOptions(string& input, int& stringToInt, int& noOfOptions);








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
	validInputChecker(input, stringToInt, noOfOptions);
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
        noOfOptions = 6;
        loggedInAdminOptions(input,stringToInt,noOfOptions);
		//printAdminMenu();
		//noOfOptions = 6;
		//cout << "Choose your option: " << endl;
		//cin.ignore(); getline(cin, input);
		//validInputChecker(input, stringToInt, noOfOptions);
  //      adminMenuDecision(stringToInt);
	};



	system("pause > 0");
}

void validInputChecker(string& input, int& stringToInt, int& noOfOptions) {
    stringToInt = input[0] - 48;
    if (stringToInt < 1 || stringToInt > noOfOptions || input.size() > 1) {
        cout << "\"" << input << "\"" << "is not valid input, you needed to enter a number from 1-" << noOfOptions << "\n";
        cout << "Please try again: ";
        getline(cin, input);
        validInputChecker(input, stringToInt, noOfOptions);
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

void loggedInAdminOptions(string& input, int& stringToInt, int& noOfOptions) {
    printAdminMenu();
    cout << "Choose your option: " << endl;
    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); getline(cin, input);
    validInputChecker(input, stringToInt, noOfOptions);
    switch (stringToInt) {
    case 1:
        createDonor();
        break;
    case 2:
        readDonorReport();
        break;
    case 3:
        makeChangeDonor();
        break;
    case 4:
        createRecipient();
        break;
    case 5:
        readRecipientReport();
        break;
    case 6:
        makeChangeRecipient();
        break;
    default:
        cout << input << " please make a selection from the list";
        loggedInAdminOptions(input, stringToInt, noOfOptions);
    }
}

void createDonor() {
    fstream fileIn;

    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    fileIn.open("pete_blood_donors.csv", ios::in);

    while (getline(fileIn, line)) {
        rowOfIndividualsInfo.clear();

        stringstream str(line);

        while (getline(str, word, ','))
            rowOfIndividualsInfo.push_back(word);

        personVector.push_back(rowOfIndividualsInfo);
    }

    fstream fileOut;

    fileOut.open("pete_blood_donors.csv", ios::out | ios::app);
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }
    cout << "Enter name and bloodtype \n";




    int donorNumber;
    string name, bloodType;
    cout << "Name :";
    donorNumber = personVector.size() + 1;
    cin >> name;
    cout << "\nBloodtype :";
    cin >> bloodType;


    fileOut
        << donorNumber << ","
        << name << ","
        << bloodType
        << "\n";


}
void createRecipient() {
    fstream fileIn;

    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    fileIn.open("pete_blood_recipients.csv", ios::in);

    while (getline(fileIn, line)) {
        rowOfIndividualsInfo.clear();

        stringstream str(line);

        while (getline(str, word, ','))
            rowOfIndividualsInfo.push_back(word);

        personVector.push_back(rowOfIndividualsInfo);
    }

    fstream fileOut;

    fileOut.open("pete_blood_recipients.csv", ios::out | ios::app);
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }
    cout << "Enter name and bloodtype \n";




    int donorNumber;
    string name, bloodType;
    cout << "Name :";
    donorNumber = personVector.size() + 1;
    cin >> name;
    cout << "\nBloodtype :";
    cin >> bloodType;


    fileOut
        << donorNumber << ","
        << name << ","
        << bloodType
        << "\n";


}

void readDonorReport() {


    fstream fileIn;


    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    fileIn.open("pete_blood_donors.csv", ios::in);

    if (fileIn.is_open()) {

        while (getline(fileIn, line)) {
            rowOfIndividualsInfo.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                rowOfIndividualsInfo.push_back(word);

            personVector.push_back(rowOfIndividualsInfo);
        }
    }
    else {
        cout << "No file found\n";
    }



    cout << "This is the data: \n";

    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << personVector[j][i] << ",";
        }
        cout << endl;
    }

    cout << "\n\n";

    return;
}
void readRecipientReport() {


    fstream fileIn;


    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    fileIn.open("pete_blood_recipients.csv", ios::in);

    if (fileIn.is_open()) {

        while (getline(fileIn, line)) {
            rowOfIndividualsInfo.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                rowOfIndividualsInfo.push_back(word);

            personVector.push_back(rowOfIndividualsInfo);
        }
    }
    else {
        cout << "No file found\n";
    }



    cout << "This is the data: \n";

    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << personVector[j][i] << ",";
        }
        cout << endl;
    }

    cout << "\n\n";

    return;
}

void makeChangeDonor() {
    fstream fileIn;


    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    //Assigning the file to read and flag
    fileIn.open("pete_blood_donors.csv", ios::in); // ios in is to receive data from an external file

    if (fileIn.is_open()) { //is open checks if the file is open or not
        //WHile there is content to copy from fileIn to line, loop
        while (getline(fileIn, line)) {
            rowOfIndividualsInfo.clear();//get string of rowOfIndividualsInfo and remove all it's content

            stringstream str(line); //sstream requires it's own pre-processor initialization. converfts file data to string format

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                rowOfIndividualsInfo.push_back(word); //appending content of var WORD into rowOfIndividualsInfo

            personVector.push_back(rowOfIndividualsInfo); //Appending the rowOfIndividualsInfo content into CONTENT variable
        }
    }
    else {
        cout << "No file found\n";
    }


    cout << "This is the data: \n";

    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << personVector[j][i] << ",";
        }
        cout << endl;
    }



    cout << "What would you like to change? person number: ";
    int changerowOfIndividualsInfoChoice;
    cin >> changerowOfIndividualsInfoChoice;
    cout << "\nDetail number: ";
    int changeColumnChoice;
    cin >> changeColumnChoice;
    cout << "\nTo What?: ";
    string changeDataChoice;
    cin >> changeDataChoice;


    personVector[changerowOfIndividualsInfoChoice - 1][changeColumnChoice - 1] = changeDataChoice;

    cout << "The changed Datails : \n";

    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << personVector[j][i] << ",";
        }
        cout << endl;
    }

    cout << "\n\n";


    fstream fileOut;

    // Create a new file to store updated data
    fileOut.open("pete_blood_donorsnew.csv", ios::out);
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }


    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            fileOut << personVector[j][i] << ",";
        }
        fileOut << endl;
    }


    fileIn.close();
    fileOut.close();

    // removing the existing file
    remove("pete_blood_donors.csv");

    // renaming the updated file with the existing file name
    rename("pete_blood_donorsnew.csv", "pete_blood_donors.csv");

    return;
}
void makeChangeRecipient() {
    fstream fileIn;


    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    //Assigning the file to read and flag
    fileIn.open("pete_blood_recipients.csv", ios::in); // ios in is to receive data from an external file

    if (fileIn.is_open()) { //is open checks if the file is open or not
        //WHile there is content to copy from fileIn to line, loop
        while (getline(fileIn, line)) {
            rowOfIndividualsInfo.clear();//get string of rowOfIndividualsInfo and remove all it's content

            stringstream str(line); //sstream requires it's own pre-processor initialization. converfts file data to string format

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                rowOfIndividualsInfo.push_back(word); //appending content of var WORD into rowOfIndividualsInfo

            personVector.push_back(rowOfIndividualsInfo); //Appending the rowOfIndividualsInfo content into CONTENT variable
        }
    }
    else {
        cout << "No file found\n";
    }


    cout << "This is the data: \n";

    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << personVector[j][i] << ",";
        }
        cout << endl;
    }



    cout << "What would you like to change? person number: ";
    int changerowOfIndividualsInfoChoice;
    cin >> changerowOfIndividualsInfoChoice;
    cout << "\nDetail number: ";
    int changeColumnChoice;
    cin >> changeColumnChoice;
    cout << "\nTo What?: ";
    string changeDataChoice;
    cin >> changeDataChoice;


    personVector[changerowOfIndividualsInfoChoice - 1][changeColumnChoice - 1] = changeDataChoice;

    cout << "The changed Datails : \n";

    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << personVector[j][i] << ",";
        }
        cout << endl;
    }

    cout << "\n\n";


    fstream fileOut;

    // Create a new file to store updated data
    fileOut.open("pete_blood_recipients_new.csv", ios::out);
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }


    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            fileOut << personVector[j][i] << ",";
        }
        fileOut << endl;
    }


    fileIn.close();
    fileOut.close();

    // removing the existing file
    remove("pete_blood_recipients.csv");

    // renaming the updated file with the existing file name
    rename("pete_blood_recipients_new.csv", "pete_blood_recipients.csv");

    return;
}


void printAdminMenu() {
    cout << "Please select your operation: <<\n1. Register Donor\n2. View donor report\n3. Make change to donor\n4. RegisterRecipient\n5. View Recipient Report\n6. Make change to recipient ";

}
