
#include <iostream>
#include <fstream> // includes both
#include <string>
#include <vector>
#include <sstream>
//#include <ifstream>
//#include <ofstream>


using namespace std;


void Create() {
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
    donorNumber = personVector.size()+1;
    cin >> name;
        cout << "\nBloodtype :";
        cin >> bloodType;


        fileOut
            << donorNumber << ","
        << name << ","
        << bloodType
        << "\n";


}


void read() {


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

    for (int j = 0; j < rowOfIndividualsInfo.size(); j++) {
        for (int i = 0; i < personVector.size(); i++) {
            cout << personVector[j][i] << ",";
        }
        cout << endl;
    }

    cout << "\n\n";

    return;

}






void makeChange() {
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

    for (int j = 0; j < rowOfIndividualsInfo.size(); j++) {
        for (int i = 0; i < personVector.size(); i++) {
            cout << personVector[j][i] << ",";
        }
        cout << endl;
    }

    cout << "\n\n";



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

    cout << "The changed Datais : \n";

    for (int j = 0; j < rowOfIndividualsInfo.size(); j++) {
        for (int i = 0; i < personVector.size(); i++) {
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

    for (int j = 0; j < rowOfIndividualsInfo.size(); j++) {
        for (int i = 0; i < personVector.size(); i++) {
            fileOut << personVector[j][i] << ",";
        }
        fileOut << "\n";
    }

    fileIn.close();
    fileOut.close();

    // removing the existing file
    remove("pete_blood_donors.csv");

    // renaming the updated file with the existing file name
    rename("pete_blood_donorsnew.csv", "pete_blood_donors.csv");

    return;
}











int main()
{


    int input;
    cout << "Please select your operation: \n1. Create/Write\n2. Read\n3. Make change";
    cin >> input;
    switch (input) {
    case 1:
        Create();
        break;
    case 2:
        read();
        break;
    case 3:
        makeChange();
        break;
    }
}






