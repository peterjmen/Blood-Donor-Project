#include <iostream>
#include <string>
#include <fstream> // includes both
#include <vector>
#include <sstream>
#include <iomanip>




//cin.ignore to prevent any left over "\n's" in the buffer preventing unintention input "spill over" or "leak through"



//1.   createDonor();
//2.   readDonorReport();
//3.   makeChangeDonor();
//4.   createRecipient();
//5.   readRecipientReport();
//6.   makeChangeRecipient();
//7.   viewDonorBloodTestReports();
//8.   editDonorBloodTestReports();
//9.   locationReport();
//10.  viewRecipientInformation();
//11.  viewDonorInformation();
//12.  bloodGroupReport();
//13.  Exit




using namespace std;

//Integer attempts made to keep to be the base counter for log in attempts
int attempts = 0;
int loggedInIdNumber = 0; //Number assigned on successful log in or account creation it is a primary key generated from either donor or recipient csv/entity file

//Function ***HARDCODED**to check if username and password is admin/admin, all lowercase, if not will no accept
void adminLogin(int& attempts);

//Function taking an int, and only accepting it between minAllowed and maxAllowed else will ask for repeating input
void intInputChecker(int& inputToCheck, int minAllowed, int maxAllowed);

//Functions with cin & getline(cin, input) writing out to csv file
//void createDonor();
void createRecipient();

//Functions reading from CSV files to create 2d vectors
void readDonorReport();
void readRecipientReport();


//Functions reading from CSV files to create 2d vectors, then allowing changes to the vector, writing out to a temporary csv file then deleting original file and replacing it with an updated one
void makeChangeDonor();
void makeChangeRecipient();

//Function for 
void printAdminMenu();

void loggedInAdminOptions();

void viewDonorBloodTestReports();
void editDonorBloodTestReports();


void viewRecipientInformation();
void viewDonorInformation();


void bloodGroupReport();
void locationReport();


//**** Ella


void printLoggedInDonorMenu();
void loggedInDonorSwitchStatement();
void makeBooking(int& loggedInIdNumber);
void donorLogin(int& loggedInIdNumber, int attempts);
void createDonor(int& loggedInIdNumber);
void printBookingSheet();

//-----------------------------MAIN
int main() {

    if (attempts > 3) { return 0; };

    cout << "\tWelcome to the bloodbank\n\n";
    cout << "Are you:\n";
    cout << "1. A new or current donor\n";
    cout << "2. A new or current recipient\n";
    cout << "3. Staff\n";


    int welcomeScreenChoice;
    cin >> welcomeScreenChoice;
    intInputChecker(welcomeScreenChoice, 1, 3); // At the moment only allowed int input of 1-3 or will cout to re-enter
    switch (welcomeScreenChoice) {
    case 1:
        cout << "You have selected new or current Donor" << endl;
        cout << "Would you like to: \n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        int input;
        cin >> input;
        switch (input) {
        case 1:
            cout << "You have chosen to log in, please proceed: (You have 3 log in attempts) \n";
            do {
                donorLogin(loggedInIdNumber, attempts);
                if (loggedInIdNumber == 0) {
                    attempts++;
                    cout << "Username and or Password are incorrect, they are case sensetive so ensure caps lock is off\n";
                    cout << "You have " << 3 - attempts << " attempts left\n";
                }
            } while (attempts < 3 && loggedInIdNumber == 0);
            if (loggedInIdNumber != 0) {
                loggedInDonorSwitchStatement();
            }
            break;
        case 2:
            cout << "You have chosen to create a new account, please proceed: \n";
            createDonor(loggedInIdNumber);
            if (loggedInIdNumber != 0) {
                loggedInDonorSwitchStatement();
            }
            break;
        }


        break;
    case 2:
        cout << "You have selected new or current Recipient" << endl;
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

    cout << "Goodbye patient " << loggedInIdNumber << endl;

    cout << "Program ended, press any key to exit";

    system("pause > 0");
}
//-----------------------------MAIN


/// <summary>
/// ***ella:)
/// </summary>
void printLoggedInDonorMenu() {

    cout << "Welcome to the Donor menu! \nWhat would you like to do?: " << endl;
    cout << "1. Benefits of blood donation" << endl;
    cout << "2. Procedure to donate blood" << endl;
    cout << "3. Managing their information - make change " << endl;
    cout << "4. Booking for donation " << endl; //Time availibility for donation*/
    cout << "5. ?View availible times for donation" << endl;
    cout << "6. Admin options" << endl;
    cout << "7. Exit" << endl;
}

///***ella:)
//Main menu for admin once logged in
void loggedInDonorSwitchStatement() {
    printLoggedInDonorMenu();
    cout << "\nChoose your option: ";
    int donorChoice;
    cin >> donorChoice;
    intInputChecker(donorChoice, 1, 7); // Menu options from 1-13 allowed
    switch (donorChoice) {
    case 1:
        cout << "1. Insert benefits of blood donation";
        loggedInDonorSwitchStatement();
        break;
    case 2:
        cout << "2. Insert procedure to donate blood" << endl;
        loggedInDonorSwitchStatement();
        break;
    case 3:
        cout << "3. Managing their information - make change " << endl;
        makeChangeDonor();
        loggedInDonorSwitchStatement();
        break;
    case 4:
        cout << "4. Booking for donation " << endl; //Time availibility for donation*/
        makeBooking(loggedInIdNumber);
        loggedInDonorSwitchStatement();
        break;
    case 5:
        cout << "5. View availible times for donation" << endl;
        printBookingSheet();
        cout << "Press any key to return to donor option menu" << endl;
        system("pause > 0");
        loggedInDonorSwitchStatement();
        break;
    case 6:
        loggedInAdminOptions(); // Only here for testing purposes
        break;
    case 7:
        return;
    }

    return;
}

void createDonor(int& loggedInIdNumber) {

    fstream fileIn;

    fileIn.open("blood_donors.csv", ios::in);
    if (!fileIn) {
        cout << "No files found\n";
        return;
    }

    string wholeLines;
    int rowCount = 0;

    while (getline(fileIn, wholeLines)) {
        wholeLines.clear();
        stringstream wholeDocument(wholeLines);
        rowCount++;
    }

    fileIn.close();

    fstream fileOut;

    fileOut.open("blood_donors.csv", ios::out | ios::app);
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }
    cout << "Enter details\n";





    int donorNumber;
    string username, password, firstName, lastName, nationality, ethnicity, dateOfBirth, gender, bloodType, underlyingConditions, location, email, contactNumber, lastDateDonation;

    donorNumber = rowCount + 1; //+1 to offset 0
    cout << "Username : ";
    cin.ignore(); getline(cin, username);
    cout << "Password : ";
    getline(cin, password);
    cout << "First Name : ";
    getline(cin, firstName);
    cout << "\nLast Name : ";
    getline(cin, lastName);
    cout << "\nNationality : ";
    getline(cin, nationality);
    cout << "\nEthnicity : ";
    getline(cin, ethnicity);
    cout << "\nDate of birth : ";
    getline(cin, dateOfBirth);
    cout << "\nGender : ";
    getline(cin, gender);
    cout << "\nBloodtype : ";
    getline(cin, bloodType);
    cout << "\nUnderlying conditions : ";
    getline(cin, underlyingConditions);
    cout << "\nEmail : ";
    getline(cin, email);
    cout << "\nContact Number : ";
    getline(cin, contactNumber);
    cout << "\nDate of last donation? (if known, enter \"unsure\" if so) : ";
    getline(cin, lastDateDonation);
    cout << "\Location : ";
    getline(cin, location);
    //scanC, printF


    fileOut
        << donorNumber << ","
        << firstName << ","
        << lastName << ","
        << nationality << ","
        << ethnicity << ","
        << dateOfBirth << ","
        << gender << ","
        << bloodType << ","
        << underlyingConditions << ","
        << email << ","
        << contactNumber << ","
        << lastDateDonation << ","
        << location << ","
        << username << ","
        << password << ","
        << "\n";

    fileOut.close();

    loggedInIdNumber = donorNumber;

    cout << "Donor added, press any key to return to admin menu";
    system("pause > 0");
    return;
}


void makeChangeDonor() {
    fstream fileIn;

    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    //Assigning the file to read and flag
    fileIn.open("blood_donors.csv", ios::in); // ios in is to receive data from an external file

    if (fileIn.is_open()) { //is open checks if the file is open or not
        //While there is content to copy from fileIn to line, loop
        while (getline(fileIn, line)) { //getline is needed to get the whole line and assign it to the variable "line"
            rowOfIndividualsInfo.clear();//get string of rowOfIndividualsInfo and remove all it's content

            stringstream str(line); //sstream required to take each "line" and essentially concatenate them together for one large string, without the problem of lines being broke up by newlines

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                rowOfIndividualsInfo.push_back(word); //appending content of var WORD into rowOfIndividualsInfo

            personVector.push_back(rowOfIndividualsInfo); //Appending the rowOfIndividualsInfo content into CONTENT variable
        }
    }
    else {
        cout << "No file found\n";
    }


       cout << "What aspect of your information would you like to change?" << endl;
   
   

        cout << "donor number (cant change) :" << personVector[loggedInIdNumber - 1][0] << endl;
        cout << "1.  First Name : " << personVector[loggedInIdNumber - 1][1] << endl;
        cout << "\n2.  Last Name : " << personVector[loggedInIdNumber - 1][2] << endl;
        cout << "\n3.  Nationality : " << personVector[loggedInIdNumber - 1][3] << endl;
        cout << "\n4.  Ethnicity : " << personVector[loggedInIdNumber - 1][4] << endl;
        cout << "\n5.  Date of birth : " << personVector[loggedInIdNumber - 1][5] << endl;
        cout << "\n6.  Gender : " << personVector[loggedInIdNumber - 1][6] << endl;
        cout << "\n7.  Bloodtype : " << personVector[loggedInIdNumber - 1][7] << endl;
        cout << "\n8.  Underlying conditions : " << personVector[loggedInIdNumber - 1][8] << endl;
        cout << "\n9.  Email : " << personVector[loggedInIdNumber - 1][9] << endl;
        cout << "\n10. Contact Number : " << personVector[loggedInIdNumber - 1][10] << endl;
        cout << "\n11. Date of last donation? (if known, enter \"unsure\" if so) : " << personVector[loggedInIdNumber - 1][11] << endl;
        cout << "\n12. Location : " << personVector[loggedInIdNumber - 1][12] << endl;

        int changeColumnChoice;
        cin >> changeColumnChoice;
        intInputChecker(changeColumnChoice, 1, rowOfIndividualsInfo.size() - 2);// -1 due to making patient number inaccessible to change, changed to -3 so they cant change or read own username or password - el
        cout << "\nTo What?: ";
        string changeDataChoice;
        cin >> changeDataChoice;

        //hardcoded the outputs and changes to make it more readable also took out a few unnecicary for loops  - el :) 

        personVector[loggedInIdNumber - 1][changeColumnChoice] = changeDataChoice;//-1 to offset 0 index for patient number

        cout << "donor number (cant change) :" << personVector[loggedInIdNumber - 1][0] << endl;
        cout << "1.  First Name : " << personVector[loggedInIdNumber - 1][1] << endl;
        cout << "\n2.  Last Name : " << personVector[loggedInIdNumber - 1][2] << endl;
        cout << "\n3.  Nationality : " << personVector[loggedInIdNumber - 1][3] << endl;
        cout << "\n4.  Ethnicity : " << personVector[loggedInIdNumber - 1][4] << endl;
        cout << "\n5.  Date of birth : " << personVector[loggedInIdNumber - 1][5] << endl;
        cout << "\n6.  Gender : " << personVector[loggedInIdNumber - 1][6] << endl;
        cout << "\n7.  Bloodtype : " << personVector[loggedInIdNumber - 1][7] << endl;
        cout << "\n8.  Underlying conditions : " << personVector[loggedInIdNumber - 1][8] << endl;
        cout << "\n9.  Email : " << personVector[loggedInIdNumber - 1][9] << endl;
        cout << "\n10. Contact Number : " << personVector[loggedInIdNumber - 1][10] << endl;
        cout << "\n11. Date of last donation? (if known, enter \"unsure\" if so) : " << personVector[loggedInIdNumber - 1][11] << endl;
        cout << "\n12. Location : " << personVector[loggedInIdNumber - 1][12] << endl;

        
    

  

     //  << donorNumber << ","
     // << firstName << ","
     // << lastName << ","
     //  << nationality << ","
     //  << ethnicity << ","
     //  << nationality << ","
     //  << gender << ","
     //  << bloodType << ","
     //  << underlyingConditions << ","
     //  << email << ","
     //  << contactNumber << ","
     //  << lastDateDonation << ","
     //  << username << ","
     //  << password << ","
     
  

    cout << "\nPress any key to return to admin menu\n";
    system("pause > 0");

    fstream fileOut;

    // Create a new file to store updated data
    fileOut.open("blood_donors_new.csv", ios::out);
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
    remove("blood_donors.csv");

    // renaming the updated file with the existing file name
    rename("blood_donors_new.csv", "blood_donors.csv");

    //

    cout << "\nAction complete, returning to main admin menu\n";
    return;
}

void makeBooking(int& loggedInIdNumber) {
    fstream fileIn;

    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    //Assigning the file to read and flag
    fileIn.open("blood_donors_booking.csv", ios::in); // ios in is to receive data from an external file

    if (fileIn.is_open()) { //is open checks if the file is open or not
        //While there is content to copy from fileIn to line, loop
        while (getline(fileIn, line)) { //getline is needed to get the whole line and assign it to the variable "line"
            rowOfIndividualsInfo.clear();//get string of rowOfIndividualsInfo and remove all it's content

            stringstream str(line); //sstream required to take each "line" and essentially concatenate them together for one large string, without the problem of lines being broke up by newlines

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                rowOfIndividualsInfo.push_back(word); //appending content of var WORD into rowOfIndividualsInfo

            personVector.push_back(rowOfIndividualsInfo); //Appending the rowOfIndividualsInfo content into CONTENT variable
        }
    }
    else {
        cout << "No file found\n";
    }


    //string day = "day";

    cout << "What day would you like to book on? Please pick from July 1-31\n"; // does this double up >?
    //lets user chose what csv line to book on 


    //int loggedInPersonsNumber = iteration if password and usernname match
    ///!!!to be added
    cout << "What day in july would you like to book on? (enter a number 1-31)\n";
    cout << "July : ";
    int chosenDateOfAppointment; // should not be able to choose this, will work on this later
    cin >> chosenDateOfAppointment;
    cout << endl;
    intInputChecker(chosenDateOfAppointment, 1, 31); // 1-31 as 31 days in july

    

    string changeDataChoice = "booked" ;
    
    stringstream ss;

    ss << loggedInIdNumber;

    string convertedInt;

    ss >> convertedInt;


    
    ///!!!to be added
    cout << "What time would you like to book? between 9am and 4pm\n";
    cout << "Time : ";
    int appointmentTime;
    cin >> appointmentTime;

 
    switch (appointmentTime) {
    case 9:

        if (personVector[chosenDateOfAppointment - 1][3] == "open") {
            personVector[chosenDateOfAppointment - 1][3] = "booked by " + convertedInt;

            cout << "you are booked for the " << chosenDateOfAppointment  << " at 9am, we cant wait to see you \n\n";
        }
        else {
            cout << "That slot is already taken, please select another date";
            makeBooking(loggedInIdNumber);
            return;
        }

        break;
    case 10:

        if (personVector[chosenDateOfAppointment - 1][4] == "open") {
            personVector[chosenDateOfAppointment - 1][4] = changeDataChoice;//-1 to offset 0 index for patient number
            cout << "you are booked for the " << chosenDateOfAppointment  << " at 10am, we cant wait to see you \n\n";
            
        }
        else {
            cout << "That slot is already taken, please select another date";
            makeBooking(loggedInIdNumber);
            return;
        }

        break;
    case 11:

        if (personVector[chosenDateOfAppointment - 1][5] == "open") {
            personVector[chosenDateOfAppointment - 1][5] = changeDataChoice;//-1 to offset 0 index for patient number
            cout << "you are booked for the " << chosenDateOfAppointment  << " at 11am, we cant wait to see you \n\n";
        }
        else {
            cout << "That slot is already taken, please select another date";
            makeBooking(loggedInIdNumber);
            return;
        }

        break;
    case 12:

        if (personVector[chosenDateOfAppointment - 1][6] == "open") {
            personVector[chosenDateOfAppointment - 1][6] = changeDataChoice;
            cout << "you are booked for the " << chosenDateOfAppointment  << " at 12pm, we cant wait to see you \n\n";
            //-1 to offset 0 index for patient number
        }
        else {
            cout << "That slot is already taken, please select another date";
            makeBooking(loggedInIdNumber);
            return;
        }
        
        break; 
    case 1:

        if (personVector[chosenDateOfAppointment - 1][7] == "open") {
            personVector[chosenDateOfAppointment - 1][7] = changeDataChoice;//-1 to offset 0 index for patient number
            cout << "you are booked for the " << chosenDateOfAppointment  << " at 1pm, we cant wait to see you \n\n";
        }
        else {
            cout << "That slot is already taken, please select another date";
            makeBooking(loggedInIdNumber);
            return;
        }

        break;
    case 2:

        if (personVector[chosenDateOfAppointment - 1][8] == "open") {
            personVector[chosenDateOfAppointment - 1][8] = changeDataChoice;//-1 to offset 0 index for patient number
            cout << "you are booked for the " << chosenDateOfAppointment  << " at 2pm, we cant wait to see you \n\n";
        }
        else {
            cout << "That slot is already taken, please select another date";
            makeBooking(loggedInIdNumber);
            return;
        }

        break;
    case 3:

        if (personVector[chosenDateOfAppointment - 1][9] == "open") {
            personVector[chosenDateOfAppointment - 1][9] = changeDataChoice;//-1 to offset 0 index for patient number
            cout << "you are booked for the " << chosenDateOfAppointment  << " at 3pm, we cant wait to see you \n\n";
        }
        else {
            cout << "That slot is already taken, please select another date";
            makeBooking(loggedInIdNumber);
            return;
        }

        break;
    case 4: 

        if (personVector[chosenDateOfAppointment - 1][10] == "open") {
            personVector[chosenDateOfAppointment - 1][10] = changeDataChoice;//-1 to offset 0 index for patient number
            cout << "you are booked for the " << chosenDateOfAppointment  << " at 4pm, we cant wait to see you \n\n";
        }
        else {
            cout << "That slot is already taken, please select another date";
            makeBooking(loggedInIdNumber);
            return;
        }

        break;
    default:
        cout << "please input an available time we are open 9am - 4pm ";
        cout << "That slot is already taken, please select another date";
        makeBooking(loggedInIdNumber);
        return;
      
    }


    if (personVector[chosenDateOfAppointment - 1][appointmentTime] == "open") {
        personVector[chosenDateOfAppointment - 1][appointmentTime] = changeDataChoice;//-1 to offset 0 index for patient number
    }
    else {
        cout << "That slot is already taken, please select another date";
        makeBooking(loggedInIdNumber);
        return;
    }

    //!!! need to adjust print out to have right headings
   

    fstream fileOut;

    // Create a new file to store updated data
    fileOut.open("blood_donors_booking_new.csv", ios::out);
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
    remove("blood_donors_booking.csv");

    // renaming the updated file with the existing file name
    rename("blood_donors_booking_new.csv", "blood_donors_booking.csv");


    cout << "Action complete, returning to main admin menu";
    return;
}

void printBookingSheet() {
    fstream fileIn;

    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    //Assigning the file to read and flag
    fileIn.open("blood_donors_booking.csv", ios::in); // ios in is to receive data from an external file

    if (fileIn.is_open()) { //is open checks if the file is open or not
        //While there is content to copy from fileIn to line, loop
        while (getline(fileIn, line)) { //getline is needed to get the whole line and assign it to the variable "line"
            rowOfIndividualsInfo.clear();//get string of rowOfIndividualsInfo and remove all it's content

            stringstream str(line); //sstream required to take each "line" and essentially concatenate them together for one large string, without the problem of lines being broke up by newlines

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                rowOfIndividualsInfo.push_back(word); //appending content of var WORD into rowOfIndividualsInfo

            personVector.push_back(rowOfIndividualsInfo); //Appending the rowOfIndividualsInfo content into CONTENT variable
        }
    }
    else {
        cout << "No file found\n";
    }


    //string day = "day";

    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << left << setfill(' ') << setw(15) << personVector[j][i];
        }
        cout << endl;
    }
   
}

void donorLogin(int& loggedInIdNumber, int attempts) {

    fstream fileIn;
    vector<vector<string>> personVector; // Vector of entities (persons), vector containing vector of attributes
    vector<string> rowOfIndividualsInfo; // Vector of attributes/columns containing strings
    string line, word;

    fileIn.open("blood_donors.csv", ios::in); // ios in is to receive data from an external file

    if (fileIn.is_open()) { //is open checks if the file is open or not
        //While there is content to copy from fileIn to line, loop
        while (getline(fileIn, line)) { //getline is needed to get the whole line and assign it to the variable "line"
            rowOfIndividualsInfo.clear();//get string of rowOfIndividualsInfo and remove all it's content

            stringstream str(line); //sstream required to take each "line" and essentially concatenate them together for one large string, without the problem of lines being broke up by newlines

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                rowOfIndividualsInfo.push_back(word); //appending content of var WORD into rowOfIndividualsInfo

            personVector.push_back(rowOfIndividualsInfo); //Appending the rowOfIndividualsInfo content into CONTENT variable
        }
    }
    else {
        cout << "No file found\n";
    }



    string loginUsername, loginPassword;
    cout << "Please enter username and password\n";
    cout << "Username : ";
    cin >> loginUsername;
    cout << "\nPassword : ";
    cin >> loginPassword;


    for (int i = 0; i < personVector.size(); i++) {
        if (loginUsername == personVector[i][rowOfIndividualsInfo.size() - 2
        ] && loginPassword == personVector[i][rowOfIndividualsInfo.size() - 1]) {
            loggedInIdNumber = i + 1;
            cout << "Thank you for loggin in, your patient number is : " << loggedInIdNumber << "\n";
        }
    };

    if (loggedInIdNumber == 0)
    {
        cout << "That Username and Password combination does not exist\n";
    };

}


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
    return;
}


//Main menu for admin once logged in
void loggedInAdminOptions() {
    printAdminMenu();
    cout << "\nChoose your option: ";
    int adminMenuChoice;
    cin >> adminMenuChoice;
    intInputChecker(adminMenuChoice, 1, 14); // Menu options from 1-13 allowed
    switch (adminMenuChoice) {
    case 1:
        createDonor(loggedInIdNumber);
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
        locationReport();
        loggedInAdminOptions();
        break;
    case 10:
        viewRecipientInformation();
        loggedInAdminOptions();
        break;
    case 11:
        viewDonorInformation();
        loggedInAdminOptions();
        break;
    case 12:
        bloodGroupReport();
        loggedInAdminOptions();
        break;
    case 13:
        cout << "\n\nYou have chosen exit, Goodbye" << endl;
        cout << "\n\nPress any key to terminate program\n\n";
        return;
        break;
    case 14:
        loggedInDonorSwitchStatement();
    }
    return;
}



void printAdminMenu() {
    cout << "\n\nPlease select your operation:" << endl;
    cout << "1.  Register Donor" << endl;
    cout << "2.  View donor report" << endl;
    cout << "3.  Make change to donor" << endl;
    cout << "4.  Register Recipient" << endl;
    cout << "5.  View Recipient Report" << endl;
    cout << "6.  Make change to recipient " << endl;
    cout << "7.  View donor's blood testing reports" << endl;
    cout << "8.  Update donor's blood testing report" << endl;
    cout << "9.  Location report" << endl;
    cout << "10. View recipient information" << endl;
    cout << "11. View donor information" << endl;
    cout << "12. Blood group report" << endl;
    cout << "13. Exit" << endl;
    cout << "14. Go to donor menu" << endl;
    return;

}


void intInputChecker(int& inputToCheck, int minAllowed, int maxAllowed) {
    if (inputToCheck < minAllowed || inputToCheck > maxAllowed) {
        cout << "Invalid input, please re-enter choice: ";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear to clear error flag for future input. cin.ignore the current content of sstream
        cin >> inputToCheck;
        intInputChecker(inputToCheck, minAllowed, maxAllowed); //Runs int checker again in a loop until input between min and max
        return;
    }
}

//Admin menu item 1
/*
void createDonor() {

    fstream fileIn;

    fileIn.open("blood_donors.csv", ios::in);
    if (!fileIn) {
        cout << "No files found\n";
    }

    string wholeLines;
    int rowCount = 0;

    while (getline(fileIn, wholeLines)) {
        wholeLines.clear();
        stringstream wholeDocument(wholeLines);
        rowCount++;
    }

    fileIn.close();

    fstream fileOut;

    fileOut.open("blood_donors.csv", ios::out | ios::app);
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }
    cout << "Enter name, bloodtype and location \n";
    //Above code is purely to generate "donorNumber" as a Primary key (synthetic/surrogate key). It has redundant segments but is recycled code to achieve the goal




    int donorNumber;
    string firstName, lastName, nationality, ethnicity, dateOfBirth, gender, bloodType, underlyingConditions, location, email, contactNumber, lastDateDonation;

    donorNumber = rowCount + 1; //+1 to offset 0
    cout << "First Name : ";
    cin.ignore(); getline(cin, firstName);
    cout << "\nLast Name : ";
    getline(cin, lastName);
    cout << "\nNationality : ";
    getline(cin, nationality);
    cout << "\nEthnicity : ";
    getline(cin, ethnicity);
    cout << "\nDate of birth : ";
    getline(cin, dateOfBirth);
    cout << "\nGender : ";
    getline(cin, gender);
    cout << "\nBloodtype : ";
    getline(cin, bloodType);
    cout << "\nUnderlying conditions : ";
    getline(cin, underlyingConditions);
    cout << "\nEmail : ";
    getline(cin, email);
    cout << "\nContact Number : ";
    getline(cin, contactNumber);
    cout << "\nDate of last donation? (if known, enter \"unsure\" if so) : ";
    getline(cin, lastDateDonation);
    cout << "\Location : ";
    getline(cin, location);
    //scanC, printF


    fileOut
        << donorNumber << ","
        << firstName << ","
        << lastName << ","
        << nationality << ","
        << ethnicity << ","
        << nationality << ","
        << gender << ","
        << bloodType << ","
        << underlyingConditions << ","
        << email << ","
        << contactNumber << ","
        << lastDateDonation
        << "\n";

    cout << "Donor added, press any key to return to admin menu";
    system("pause > 0");
    return;
}
*/

//Admin menu item 2
void readDonorReport() {

    fstream fileIn;
    vector<vector<string>> personVector; // Vector of entities (persons), vector containing vector of attributes
    vector<string> rowOfIndividualsInfo; // Vector of attributes/columns containing strings
    string line, word;

    fileIn.open("blood_donors.csv", ios::in); // ios in is to receive data from an external file

    if (fileIn.is_open()) { //is open checks if the file is open or not
        //While there is content to copy from fileIn to line, loop
        while (getline(fileIn, line)) { //getline is needed to get the whole line and assign it to the variable "line"
            rowOfIndividualsInfo.clear();//get string of rowOfIndividualsInfo and remove all it's content

            stringstream str(line); //sstream required to take each "line" and essentially concatenate them together for one large string, without the problem of lines being broke up by newlines

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                rowOfIndividualsInfo.push_back(word); //appending content of var WORD into rowOfIndividualsInfo

            personVector.push_back(rowOfIndividualsInfo); //Appending the rowOfIndividualsInfo content into CONTENT variable
        }
    }
    else {
        cout << "No file found\n";
    }



    cout << "This is the data: \n\n";
    cout << "********************DONOR REPORT*******************\n";
    cout << left << setfill(' ') << setw(15) << "Patient #" << left << setfill(' ') << setw(15) << "Name" << left << setfill(' ') << setw(15) << "Bloodtype" << left << setfill(' ') << setw(15) << "ethnicity"  << left << setfill(' ') << setw(15) << "" << endl;



    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << left << setfill(' ') << setw(15) << personVector[j][i];
        }
        cout << endl;
    }
    cout << "********************DONOR END*******************\n\n";
    cout << "Press any key to return to admin menu";
    system("pause > 0");

    return;
}
//Admin menu item 3

void createRecipient() {

    fstream fileIn;

    //reading file to count number of lines to create primary key for recipients
    fileIn.open("blood_recipients.csv", ios::in);
    if (!fileIn) {
        cout << "No files found\n";
        return;
    }

    string wholeLines;
    int rowCount = 0;

    while (getline(fileIn, wholeLines)) {
        wholeLines.clear();
        stringstream wholeDocument(wholeLines);
        rowCount++;
    }

    fileIn.close();


    fstream fileOut;

    fileOut.open("blood_recipients.csv", ios::out | ios::app);
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }


    cout << "Enter name, bloodtype and location \n";

    int recipientNumber;
    string name, bloodType, location;
    cout << "Name :";
    recipientNumber = rowCount + 1; //+1 as first number starts at 1 rather than 0
    cin.ignore(); //cin.ignore to prevent any left over "\n's" in the buffer preventing unintention input "spill over" or "leak through"
    getline(cin, name); // Getline to take the whole input as a string - incase of person entering two things such as first and second name
    cout << "\nBloodtype :";
    getline(cin, bloodType);
    cout << "\Location :";
    getline(cin, location);


    fileOut
        << recipientNumber << ","
        << name << ","
        << bloodType << ","
        << location
        << "\n";

    cout << "Recipient added, press any key to return to admin menu";
    system("pause > 0");
}


//Admin menu item 4
void readRecipientReport() {


    fstream fileIn;


    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    fileIn.open("blood_recipients.csv", ios::in);

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
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\t\t" << "Location\n";


    for (int j = 0; j < personVector.size(); j++) {
        for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
            cout << personVector[j][i] << "\t\t";
        }
        cout << endl;
    }
    cout << "********************RECIPIENT REPORT END*******************\n\n";
    cout << "Press any key to return to admin menu";
    system("pause > 0");


    return;
}

//Admin menu item 5 - was make change donor
/*
void makeChangeDonor() {
    fstream fileIn;

    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    //Assigning the file to read and flag
    fileIn.open("blood_donors.csv", ios::in); // ios in is to receive data from an external file

    if (fileIn.is_open()) { //is open checks if the file is open or not
        //While there is content to copy from fileIn to line, loop
        while (getline(fileIn, line)) { //getline is needed to get the whole line and assign it to the variable "line"
            rowOfIndividualsInfo.clear();//get string of rowOfIndividualsInfo and remove all it's content

            stringstream str(line); //sstream required to take each "line" and essentially concatenate them together for one large string, without the problem of lines being broke up by newlines

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                rowOfIndividualsInfo.push_back(word); //appending content of var WORD into rowOfIndividualsInfo

            personVector.push_back(rowOfIndividualsInfo); //Appending the rowOfIndividualsInfo content into CONTENT variable
        }
    }
    else {
        cout << "No file found\n";
    }


    cout << "Who's data would you like to change? Enter person ID number:";
    int changerowOfIndividualsInfoChoice;
    cin >> changerowOfIndividualsInfoChoice;
    intInputChecker(changerowOfIndividualsInfoChoice, 1, personVector.size());
    cout << "\nWhat type of information of theirs would you like to change?: ";
    cout << "\n1. Name: ";
    cout << "\n2. Bloodtype: ";
    cout << "\n3. Location: ";

    int changeColumnChoice;
    cin >> changeColumnChoice;
    intInputChecker(changeColumnChoice, 1, rowOfIndividualsInfo.size() - 1);// -1 due to making patient number inaccessible to change
    cout << "\nTo What?: ";
    string changeDataChoice;
    cin >> changeDataChoice;


    personVector[changerowOfIndividualsInfoChoice - 1][changeColumnChoice] = changeDataChoice;//-1 to offset 0 index for patient number

    cout << "The changed Details : \n";
    cout << "********************DETAILS CHANGE REPORT*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\t\t" << "Location\n";


    for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
        cout << personVector[changerowOfIndividualsInfoChoice - 1][i] << "\t\t";
    }
    cout << "\n********************CHANGE REPORT END*******************\n\n";
    cout << "Press any key to return to admin menu";
    system("pause > 0");

    fstream fileOut;

    // Create a new file to store updated data
    fileOut.open("blood_donors_new.csv", ios::out);
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
    remove("blood_donors.csv");

    // renaming the updated file with the existing file name
    rename("blood_donors_new.csv", "blood_donors.csv");


    cout << "Action complete, returning to main admin menu";
    return;
}
*/

//Admin menu item 6
void makeChangeRecipient() {
    fstream fileIn;


    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    //Assigning the file to read and flag
    fileIn.open("blood_recipients.csv", ios::in); // ios in is to receive data from an external file

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
        cout << "No recipients have been entered yet (no file has been made)\n";
    }


    cout << "Who's data would you like to change? Enter person ID number:\n";
    int changerowOfIndividualsInfoChoice;
    cin >> changerowOfIndividualsInfoChoice;
    intInputChecker(changerowOfIndividualsInfoChoice, 1, personVector.size());
    cout << "\nWhat type of information of theirs would you like to change?: ";
    cout << "\n1. Name: ";
    cout << "\n2. Bloodtype: ";
    cout << "\n3. Location: ";


    int changeColumnChoice;
    cin >> changeColumnChoice;
    intInputChecker(changeColumnChoice, 1, rowOfIndividualsInfo.size() - 1);// -1 due to making patient number inaccessible to change
    cout << "\nTo What?: ";
    string changeDataChoice;
    cin >> changeDataChoice;


    personVector[changerowOfIndividualsInfoChoice - 1][changeColumnChoice] = changeDataChoice;//-1 to offset 0 index for patient number

    cout << "The changed Details : \n";
    cout << "********************DETAILS CHANGE REPORT*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\t\t" << "Location\n";


    for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
        cout << personVector[changerowOfIndividualsInfoChoice - 1][i] << "\t\t";
    }
    cout << "\n********************CHANGE REPORT END*******************\n\n";



    fstream fileOut;

    // Create a new file to store updated data
    fileOut.open("blood_recipients_new.csv", ios::out);
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
    remove("blood_recipients.csv");

    // renaming the updated file with the existing file name
    rename("blood_recipients_new.csv", "blood_recipients.csv");


    cout << "Data changed, press any key to return to admin menu";
    system("pause > 0");
    return;
}


//Admin menu item 7
void viewDonorBloodTestReports() {

    fstream fileIn;

    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    //Assigning the file to read and flag
    fileIn.open("blood_donors.csv", ios::in);

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

    fileIn.open("blood_donors_reports.csv", ios::in);

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

    fileIn.close();



    //updates blood donors report - checks donor file for number of patients and appends looping depending on the differece

    fstream fileOut;

    fileOut.open("blood_donors_reports.csv", ios::app);
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }

    int patientNumberDifference = personVector.size() - patientNumber.size();

    for (int i = 0; i < patientNumberDifference; i++) {
        fileOut << personVector[personVector.size() - patientNumberDifference + i][0] << ",";
        fileOut << "No report entered" << "\n";
    }

    fileOut.close();
    /////print out contents
    fileIn.close();

    fileIn.open("blood_donors_reports.csv", ios::in);


    vector<vector<string>> updatedPatientNumber;
    vector<string> updatediDnum0Report1;
    string updatedRow, updatedValue;

    if (fileIn.is_open()) {

        while (getline(fileIn, updatedRow)) {
            updatediDnum0Report1.clear();

            stringstream str(updatedRow);

            while (getline(str, updatedValue, ','))
                updatediDnum0Report1.push_back(updatedValue);

            updatedPatientNumber.push_back(updatediDnum0Report1);
        }
    }
    fileIn.close();


    //updating/appending done - now to print change

    cout << "This is the data: \n\n";
    cout << "********************DONOR BLOOD TEST RESULTS REPORT*******************\n";
    cout << "Patient #\t" << "Report:\t\t\n";


    for (int j = 0; j < updatedPatientNumber.size(); j++) {
        for (int i = 0; i < updatediDnum0Report1.size(); i++) {
            cout << updatedPatientNumber[j][i] << "\t\t";
        }
        cout << endl;
    }
    cout << "********************DONOR BLOOD TEST RESULTS REPORT*******************\n\n";


    fileOut.close();
    fileIn.close();

    cout << "Press any key to return to admin menu";
    system("pause > 0");
    return;
}
//Admin menu item 8

void editDonorBloodTestReports() {



    fstream fileIn;


    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    //Assigning the file to read and flag
    fileIn.open("blood_donors.csv", ios::in);

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

    cout << "Choose Donor patient number to edit report: ";
    int n;
    cin >> n;
    intInputChecker(n, 1, personVector.size());

    //Read donor_reports file and make vector

    fileIn.open("blood_donors_reports.csv", ios::in);

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

    //****updates blood donors report - checks donor file for number of patients and appends looping depending on the differece

    fstream fileOut;

    fileOut.open("blood_donors_reports.csv", ios::out);
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }

    int patientNumberDifference = personVector.size() - patientNumber.size();

    for (int i = 0; i < patientNumberDifference; i++) {
        fileOut << personVector[personVector.size() - patientNumberDifference + i][0] << ",";
        fileOut << "No report entered" << "\n";
    }

    fileOut.close();


    fstream fileOutNew;

    //make new donor report file
    fileOutNew.open("blood_donors_reports_new.csv", ios::out);
    if (!fileOutNew) {
        cout << "No files found\n";
        return;
    }


    cout << "Change the report to what? ";
    string reportUpdate;
    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); getline(cin, reportUpdate); cin.clear();
    patientNumber[n - 1][1] = reportUpdate; //-1 too offset 0 index


    //populates file with changes

    for (int j = 0; j < patientNumber.size(); j++) {
        for (int i = 0; i < 2; i++) {
            fileOutNew << patientNumber[j][i] << ",";
        }
        fileOutNew << endl;
    }

    //prints changes


    fileOut.close();
    /////print out contents
    fileIn.close();

    fileIn.open("blood_donors_reports.csv", ios::in);


    vector<vector<string>> updatedPatientNumber;
    vector<string> updatediDnum0Report1;
    string updatedRow, updatedValue;

    if (fileIn.is_open()) {

        while (getline(fileIn, updatedRow)) {
            updatediDnum0Report1.clear();

            stringstream str(updatedRow);

            while (getline(str, updatedValue, ','))
                updatediDnum0Report1.push_back(updatedValue);

            updatedPatientNumber.push_back(updatediDnum0Report1);
        }
    }

    fileIn.close();





    cout << "The changed Details : \n";
    cout << "********************DETAILS CHANGE REPORT*******************\n";
    cout << "Patient #\t" << "Report:\t\t\n";
    cout << n << "\t\t" << patientNumber[n - 1][1]; // -1 to offset 0 index

    cout << "\n********************CHANGE REPORT END*******************\n\n";


    fileIn.close();
    fileOut.close();
    fileOutNew.close();

    // removing the existing file
    remove("blood_donors_reports.csv");

    // renaming the updated file with the existing file name
    rename("blood_donors_reports_new.csv", "blood_donors_reports.csv");

    cout << "Press any key to return to admin menu";
    system("pause > 0");

    return;
}

//Admin menu item 9
void locationReport() { //identical to blood group, however index is 3 becuase location is currently set to 3
    fstream fileIn;

    string input;
    cout << "Donors & recipients matching what location type would you like to see?";
    cin >> input;

    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    fileIn.open("blood_donors.csv", ios::in);

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
    cout << "********************DONOR Location REPORT*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\t\t" << "Location\n";

    int matches = 0;

    for (int j = 0; j < personVector.size(); j++) {
        if (personVector[j][3] == input) { //3 becuse location is index 3
            matches++;
            for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
                cout << personVector[j][i] << "\t\t";
            }
            cout << endl;
        }

    }
    if (matches > 0) {
        cout << matches << " matches\n";
    }
    else {
        cout << "no matches, check spelling\n";
    }
    cout << "********************DONOR Location END*******************\n\n";

    matches = 0;

    fileIn.close();

    ////recipients

    fileIn.open("blood_recipients.csv", ios::in);


    vector<vector<string>> recipientPersonVector;
    vector<string> recipientRowOfIndividualsInfo;
    string row, column;


    if (fileIn.is_open()) {

        while (getline(fileIn, line)) {
            recipientRowOfIndividualsInfo.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                recipientRowOfIndividualsInfo.push_back(word);
            recipientPersonVector.push_back(recipientRowOfIndividualsInfo);
        }
    }
    else {
        cout << "No file found\n";
    }



    cout << "This is the data: \n\n";
    cout << "********************Recipients Location REPORT*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\t\t" << "Location\n";


    for (int j = 0; j < recipientPersonVector.size(); j++) {
        if (recipientPersonVector[j][3] == input) {  //3 becuse location is index 3
            matches++;
            for (int i = 0; i < recipientRowOfIndividualsInfo.size(); i++) {
                cout << recipientPersonVector[j][i] << "\t\t";
            }
            cout << endl;
        }
    }
    if (matches > 0) {
        cout << matches << " matches\n";
    }
    else {
        cout << "no matches, check spelling\n";
    }
    cout << "********************Recipients Location END*******************\n\n";

    cout << "Press any key to return to main menu";
    system("pause > 0");
    return;

}

//item 10
void viewRecipientInformation() {
    fstream fileIn;


    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    fileIn.open("blood_recipients.csv", ios::in);

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
        cout << "No Recipients in database, press any key to return to admin menu\n";
        system("pause > 0");
        return;
    }

    cout << "Which recipient Data would you like to view?\n";
    int individualRecipientNumber;
    cin >> individualRecipientNumber;
    intInputChecker(individualRecipientNumber, 1, personVector.size());

    cout << "This is the data: \n\n";
    cout << "********************RECIPIENT INFORMATION*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\t\t" << "Location\n";


    for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
        cout << personVector[individualRecipientNumber - 1][i] << "\t\t"; //-1 to offset 0 index
    }
    cout << endl;

    cout << "********************RECIPIENT INFORMATION END*******************\n\n";
    cout << "Press any key to return to admin menu";
    system("pause > 0");

    return;
}

//item 11
void viewDonorInformation() {
    fstream fileIn;


    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    fileIn.open("blood_donors.csv", ios::in);

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
        cout << "No Donors in database, press any key to return to admin menu\n";
        system("pause > 0");
        return;
    }


    cout << "Which donor Data would you like to view?\n";
    int individualDonorNumber;
    cin >> individualDonorNumber;

    intInputChecker(individualDonorNumber, 1, personVector.size()); //input checker only allows patient to enter a number from rows 1-row size, avoids vector being out of range

    cout << "This is the data: \n\n";
    cout << "********************DONOR INFORMATION*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\t\t" << "Location\n";


    for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
        cout << personVector[individualDonorNumber - 1][i] << "\t\t"; //-1 to offset 0 index
    }
    cout << endl;

    cout << "********************DONOR INFORMATION END*******************\n\n";
    cout << "Press any key to return to main menu";
    system("pause > 0");

    return;
}


//item 12
void bloodGroupReport() {
    fstream fileIn;

    string input;
    cout << "Donors & recipients matching what blood type would you like to see?";
    cin >> input;

    vector<vector<string>> personVector;
    vector<string> rowOfIndividualsInfo;
    string line, word;

    fileIn.open("blood_donors.csv", ios::in);

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
    cout << "********************DONOR Bloodtype REPORT*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\t\t" << "Location\n";

    int matches = 0;

    for (int j = 0; j < personVector.size(); j++) {
        if (personVector[j][2] == input) { //2 becuse location is index 3
            matches++;
            for (int i = 0; i < rowOfIndividualsInfo.size(); i++) {
                cout << personVector[j][i] << "\t\t";
            }
            cout << endl;
        }

    }
    if (matches > 0) {
        cout << matches << " matches\n";
    }
    else {
        cout << "no matches, check spelling\n";
    }
    cout << "********************DONOR Bloodtype report END*******************\n\n";

    fileIn.close();
    matches = 0;
    ////recipients


    fileIn.open("blood_recipients.csv", ios::in);


    vector<vector<string>> recipientPersonVector;
    vector<string> recipientRowOfIndividualsInfo;
    string row, column;


    if (fileIn.is_open()) {

        while (getline(fileIn, line)) {
            recipientRowOfIndividualsInfo.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                recipientRowOfIndividualsInfo.push_back(word);
            recipientPersonVector.push_back(recipientRowOfIndividualsInfo);
        }
    }
    else {
        cout << "No file found\n";
    }



    cout << "This is the data: \n\n";
    cout << "********************Recipients REPORT*******************\n";
    cout << "Patient #\t" << "Name\t\t" << "Bloodtype\t\t" << "Location\n";


    for (int j = 0; j < recipientPersonVector.size(); j++) {
        if (recipientPersonVector[j][2] == input) {//2 becuse location is index 3
            matches++;
            for (int i = 0; i < recipientRowOfIndividualsInfo.size(); i++) {
                cout << recipientPersonVector[j][i] << "\t\t";
            }
            cout << endl;
        }
    }
    if (matches > 0) {
        cout << matches << " matches\n";
    }
    else {
        cout << "no matches, check spelling\n";
    }
    cout << "********************Recipients END*******************\n\n";

    cout << "Press any key to return to main menu";
    system("pause > 0");
    return;

} //compared to index 2 as blood group is currently index 2











