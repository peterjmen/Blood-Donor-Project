#include <iostream>
#include <string>
#include <fstream> // includes both
#include <vector>
#include <sstream>

using namespace std;

int attempts = 0;

//void menu(string& input, int& stringToInt);
//void validInputCheckerFromOneToNine(string& input, int& stringToInt);
//void validInputChecker(string& input, int& stringToInt, int& noOfMenuOptions);
void adminLogin(int& attempts);

void intInputChecker(int& inputToCheck, int maxAllowed);


void createDonor();
void createRecipient();

void readDonorReport();
void readRecipientReport();

void makeChangeDonor();
void makeChangeRecipient();

void printAdminMenu();
void loggedInAdminOptions();

void viewDonorBloodTestReports() {

    fstream fileIn;


    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    //Assigning the file to read and flag
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
    fileIn.close();


    //cout << "This is the data: \n";

    //for (int j = 0; j < personVector.size(); j++) {
    //    for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
    //        cout << personVector[j][i] << ",";
    //    }
    //    cout << endl;
    //}



    //Read donor_reports file and make vector

    fileIn.open("pete_blood_donors_reports.csv", ios::in);

    vector<vector<string>> patientNumber;
    vector<string> iDnum0Report1;
    string row, value;

    if (fileIn.is_open()) {

        while (getline(fileIn, row)) {
            iDnum0Report1.clear();

            stringstream str(row);

            while (getline(str, value, ','))
                iDnum0Report1.push_back(value);

            patientNumber.push_back(iDnum0Report1);
        }
    }
    else {
        cout << "No file found\n";
    }


    //vector<vector<string>> patientNumber;
    //vector<string> iDnum0Report1;
    //string row, value;

    //    for (int j = 0; j < personVector.size(); j++) {
    //        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
    //            cout << personVector[j][i] << ",";
    //        }
    //        cout << endl;
    //    }

    //for (int i = 0; i < personVector.size(); i++) {
    //    donorPatientNumber.push_back(personVector[i][0]);
    //    cout << donorPatientNumber[i] << ",";
    //    if (donorReportInfo.size() < personVector.size()) {
    //        donorReportInfo.push_back("No report info");
    //    cout << donorReportInfo[i];
    //    }
    //    cout << "\n";
    //}


    //****updates blood donors report - checks donor file for number of patients and appends looping depending on the differece

    fstream fileOut;

    fileOut.open("pete_blood_donors_reports.csv", ios::app);
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }

    int patientNumberDifference = personVector.size() - patientNumber.size();

    for (int i = 0; i < patientNumberDifference; i++) {
        fileOut << personVector[personVector.size() - patientNumberDifference + i][0] << ",";
        fileOut << "No report entered" << "\n";
    }




    //updating/appending done - stop here to print
    /// i .e cout loop

    cout << "This is the data: \n\n";
    cout << "********************DONOR BLOOD TEST RESULTS REPORT*******************\n";
    cout << "Patient #\t" << "Report:\t\t\n";


    for (int j = 0; j < patientNumber.size(); j++) {
        for (int i = 0; i < iDnum0Report1.size(); i++) {
            cout << patientNumber[j][i] << "\t\t";
        }
        cout << endl;
    }
    cout << "********************DONOR BLOOD TEST RESULTS REPORT*******************\n\n";









    fileOut.close();
    fileIn.close();
}
void editDonorBloodTestReports() {

    fstream fileIn;


    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    //Assigning the file to read and flag
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
    fileIn.close();


    //Read donor_reports file and make vector

    fileIn.open("pete_blood_donors_reports.csv", ios::in);

    vector<vector<string>> patientNumber;
    vector<string> iDnum0Report1;
    string row, value;

    if (fileIn.is_open()) {

        while (getline(fileIn, row)) {
            iDnum0Report1.clear();

            stringstream str(row);

            while (getline(str, value, ','))
                iDnum0Report1.push_back(value);

            patientNumber.push_back(iDnum0Report1);
        }
    }
    else {
        cout << "No file found\n";
    }

    //vector<vector<string>> patientNumber;
    //vector<string> iDnum0Report1;
    //string row, value;

    //    for (int j = 0; j < personVector.size(); j++) {
    //        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
    //            cout << personVector[j][i] << ",";
    //        }
    //        cout << endl;
    //    }

    //for (int i = 0; i < personVector.size(); i++) {
    //    donorPatientNumber.push_back(personVector[i][0]);
    //    cout << donorPatientNumber[i] << ",";
    //    if (donorReportInfo.size() < personVector.size()) {
    //        donorReportInfo.push_back("No report info");
    //    cout << donorReportInfo[i];
    //    }
    //    cout << "\n";
    //}


    //****updates blood donors report - checks donor file for number of patients and appends looping depending on the differece

    fstream fileOut;

    fileOut.open("pete_blood_donors_reports.csv", ios::out);
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }

    int patientNumberDifference = personVector.size() - patientNumber.size();

    for (int i = 0; i < patientNumberDifference; i++) {
        fileOut << personVector[personVector.size() - patientNumberDifference + i][0] << ",";
        fileOut << "No report entered" << "\n";
    }




    //updating/appending done - stop here to print
    /// i .e cout loop


    cout << "This is the data: \n\n";
    cout << "********************DONOR BLOOD TEST RESULTS REPORT*******************\n";
    cout << "Patient #\t" << "Report:\t\t\n";


    for (int j = 0; j < patientNumber.size(); j++) {
        for (int i = 0; i < iDnum0Report1.size(); i++) {
            cout << patientNumber[j][i] << "\t\t";
        }
        cout << endl;
    }
    cout << "********************DONOR BLOOD TEST RESULTS REPORT*******************\n\n";




    //Old file printed now to change and print new data

    fstream fileOutNew;

    //make new donor report file
    fileOutNew.open("pete_blood_donors_reports_new.csv", ios::out);
    if (!fileOutNew) {
        cout << "No files found\n";
        return;
    }

    //make changes to vectors


        //for (int i = 0; i < patientNumber.size(); i++) {
        //    fileOut << patientNumber[i][0] << ",";
        //    fileOut << patientNumber[i][1]<< "\n";
        //}

    cout << "Choose patient number to edit report: ";
    int n;
    cin >> n;
    intInputChecker(n, patientNumber.size());

    cout << "Change the report to what? ";
    string reportUpdate;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); getline(cin, reportUpdate); cin.clear();
    patientNumber[n - 1][1] = reportUpdate; //-1 too offset 0 index



    //populates file with changes

    for (int j = 0; j < patientNumber.size(); j++) {
        for (int i = 0; i < 2; i++) {
            fileOutNew << patientNumber[j][i] << ",";
        }
        fileOutNew << endl;
    }

    //prints changes



    cout << "The changed Details : \n";
    cout << "********************DETAILS CHANGE REPORT*******************\n";
    cout << "Patient #\t" << "Report:\t\t\n";
    cout << n  << "\t\t" << patientNumber[n-1][1]; // -1 to offset 0 index

    cout << "\n********************CHANGE REPORT END*******************\n\n";







    fileIn.close();
    fileOut.close();
    fileOutNew.close();

    // removing the existing file
    remove("pete_blood_donors_reports.csv");

    // renaming the updated file with the existing file name
    rename("pete_blood_donors_reports_new.csv", "pete_blood_donors_reports.csv");



    return;
}





int main() {

    if (attempts > 3) { return 0; };

    cout << "\tWelcome to the bloodbank\n\n";
    cout << "Are you:\n";
    cout << "1. A new or current donor\n";
    cout << "2. A new or current recipient\n";
    cout << "3. Staff\n";

    
    int welcomeScreenChoice;
    cin >> welcomeScreenChoice;
    intInputChecker(welcomeScreenChoice, 3);
    switch (welcomeScreenChoice) {
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
        cout << "You have selected Staff, Please enter Login, you have " << 3 - attempts << " attempts to log in or the program will terminate" << endl;
        adminLogin(attempts);
        if (attempts > 3) { return 0; };
        loggedInAdminOptions();
    };



    system("pause > 0");
}





//void validInputChecker(string& input, int& stringToInt, int& noOfMenuOptions) {
//    stringToInt = input[0] - 48;
//    if (stringToInt < 1 || stringToInt > noOfMenuOptions || input.size() > 1) {
//        cout << "\"" << input << "\"" << "is not valid input, you needed to enter a number from 1-" << noOfMenuOptions << "\n";
//        cout << "Please try again: ";
//        getline(cin, input);
//        validInputChecker(input, stringToInt, noOfMenuOptions);
//    }
//    else {
//        cout << "\n\"" << stringToInt << "\"" << "is valid input, Please continue\n";
//    }
//}

void adminLogin(int& attempts) {
    if (attempts > 0) {
        cout << "You have " << 3 - attempts << " remaining until you are locked out" << endl;
    }
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

void loggedInAdminOptions() {
    printAdminMenu();
    cout << "\nChoose your option: ";
    int adminMenuChoice;
    cin >> adminMenuChoice;
    intInputChecker(adminMenuChoice, 9);
    switch (adminMenuChoice) {
    case 1:
        createDonor();
        loggedInAdminOptions();
        break;
    case 2:
        readDonorReport();
        loggedInAdminOptions();
        break;
    case 3:
        makeChangeDonor();
        loggedInAdminOptions();
        break;
    case 4:
        createRecipient();
        loggedInAdminOptions();
        break;
    case 5:
        readRecipientReport();
        loggedInAdminOptions();
        break;
    case 6:
        makeChangeRecipient();
        loggedInAdminOptions();
        break;
    case 7:
        viewDonorBloodTestReports();
        loggedInAdminOptions();
        break;
    case 8:
        editDonorBloodTestReports();
        loggedInAdminOptions();
        break;
    case 9:
        cout << "\n\nYou have chosen exit, Goodbye" << endl;
        cout << "\n\nPress any key to terminate program\n\n";
        return;
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
            cout << "Patient #\t" << "Report:\t\t\n";
            personVector.push_back(rowOfIndividualsInfo);
        }
    }
    else {
        cout << "No file found\n";
    }



    cout << "This is the data: \n\n";
    cout << "********************DONOR REPORT*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\n";


    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << personVector[j][i] << "\t\t";
        }
        cout << endl;
    }
    cout << "********************DONOR END*******************\n\n";

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



    cout << "This is the data: \n\n";
    cout << "********************RECIPIENT REPORT*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\n";


    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << personVector[j][i] << "\t\t";
        }
        cout << endl;
    }
    cout << "********************RECIPIENT REPORT END*******************\n\n";
    

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



    cout << "\n\n********************DONOR REPORT*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\n";


    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << personVector[j][i] << "\t\t";
        }
        cout << endl;
    }
    cout << "********************DONOR END*******************\n\n";

    cout << "Who's data would you like to change? Enter person ID number: ";
    int changerowOfIndividualsInfoChoice;
    cin >> changerowOfIndividualsInfoChoice;
    intInputChecker(changerowOfIndividualsInfoChoice, personVector.size());
    cout << "\nWhat type of information of theirs would you like to chagne?: ";
    cout << "\n1. Name: ";
    cout << "\n2. Bloodtype: ";
    
    int changeColumnChoice;
    cin >> changeColumnChoice;
    intInputChecker(changeColumnChoice, rowOfIndividualsInfo.size()-1);// -1 due to making patient number inaccessible to change
    cout << "\nTo What?: ";
    string changeDataChoice;
    cin >> changeDataChoice;


    personVector[changerowOfIndividualsInfoChoice - 1][changeColumnChoice] = changeDataChoice;//-1 to offset 0 index for patient number

    cout << "The changed Details : \n";
    cout << "********************DETAILS CHANGE REPORT*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\n";


    for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << personVector[changerowOfIndividualsInfoChoice-1][i] << "\t\t";
        }
    cout << "\n********************CHANGE REPORT END*******************\n\n";


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


    cout << "Action complete, returning to main admin menu";
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




    cout << "\n\n********************RECIPIENT REPORT*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\n";


    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << personVector[j][i] << "\t\t";
        }
        cout << endl;
    }
    cout << "********************RECIPIENT REPORT END*******************\n\n";

    cout << "Who's data would you like to change? Enter person ID number: ";
    int changerowOfIndividualsInfoChoice;
    cin >> changerowOfIndividualsInfoChoice;
    intInputChecker(changerowOfIndividualsInfoChoice, personVector.size());
    cout << "\nWhat type of information of theirs would you like to chagne?: ";
    cout << "\n1. Name: ";
    cout << "\n2. Bloodtype: ";

    int changeColumnChoice;
    cin >> changeColumnChoice;
    intInputChecker(changeColumnChoice, rowOfIndividualsInfo.size() - 1);// -1 due to making patient number inaccessible to change
    cout << "\nTo What?: ";
    string changeDataChoice;
    cin >> changeDataChoice;


    personVector[changerowOfIndividualsInfoChoice - 1][changeColumnChoice] = changeDataChoice;//-1 to offset 0 index for patient number

    cout << "The changed Details : \n";
    cout << "********************DETAILS CHANGE REPORT*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\n";


    for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
        cout << personVector[changerowOfIndividualsInfoChoice - 1][i] << "\t\t";
    }
    cout << "\n********************CHANGE REPORT END*******************\n\n";



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
    cout << "\n\nPlease select your operation:" << endl;
    cout << "1. Register Donor" << endl;
    cout << "2. View donor report" << endl;
    cout << "3. Make change to donor" << endl;
    cout << "4. Register Recipient" << endl;
    cout << "5. View Recipient Report" << endl;
    cout << "6. Make change to recipient " << endl;
    cout << "7. View donor's blood testing reports" << endl;
    cout << "8. Update donor's blood testing report" << endl;
    cout << "9. Exit" << endl;
    //cout << "1. View recipient information " << endl;             enter patient number who's report you would like to view
    //cout << "2. View donor information" << endl;                  enter patient number who's report you would like to view
    //cout << "3. Report based on blood group" << endl;             Show all users of certian blood type
    //cout << "4. Report based on location " << endl;               Show all users of a certian location
    //cout << "5. Recipient report" << endl;                        done
    //cout << "6. Donor report " << endl;                           done
    //cout << "7. Update donor's blood testing reports" << endl;    make file called donor blood test reports, have it update from donor file, then choose which number to edit


}


void intInputChecker(int& inputToCheck, int maxAllowed) {
    if (inputToCheck < 1 || inputToCheck > maxAllowed) {
        cout << "Invalid input, please re-enter choice: ";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> inputToCheck;
        intInputChecker(inputToCheck, maxAllowed);

    }
}