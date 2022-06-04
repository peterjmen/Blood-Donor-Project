// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> // includes both
#include <string>
#include <vector>
#include <sstream>
//#include <ifstream>
//#include <ofstream>


using namespace std;


void Create() {
    fstream fileOut;

    fileOut.open("grades.csv", ios::out | ios::app); //ios out allows us to asing data to an external file, this is what allows us to save out to something ios app is appending to the file
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }
    cout << "Enter the details of 5 students: " << " roll(int) name(string) maths(int) phys(int) chem(int), bio(int)";
    int i, rollNum, phys, chem, math, bio;
    string name;
    for (int i = 0; i < 5; i++) {
        cout << "Please enter the details of student " << i + 1 << "\n\n";
        cin >> rollNum
            >> name
            >> math
            >> phys
            >> chem
            >> bio;

        fileOut << rollNum << ","
            << name << ","
            << math << ","
            << phys << ","
            << bio << ","
            << "\n";

    }
}





void read() {
  /*  fstream fileIn;


    vector<string> row;
    string line, word;

    int howManyRows = 5;
    int howManyColumns = 5;
    int wordToPrintIndexCounter = 0;

        //Assigning the file to read and flag
    fileIn.open("grades.csv", ios::in); // ios in is to receive data from an external file

    if (fileIn.is_open()) { //is open checks if the file is open or not
        //WHile there is content to copy from fileIn to line, loop
        while (getline(fileIn, line)) {
            stringstream str(line); //sstream requires it's own pre-processor initialization. converfts file data to string format

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                row.push_back(word); //appending content of var WORD into row
        }
    }
    else {
        cout << "No file found\n";
    }

    row[1] = "Jimbo";


    cout << "Current info is: \n";
    for (int j = 0; j < howManyColumns; j++) {
        
        for (int i = 0; i < howManyRows; i++) { //5 is row.size() if I want all numbers
            cout << row[i + wordToPrintIndexCounter] << ",";
        }
        cout << endl;
        wordToPrintIndexCounter += howManyRows;
    }
   */

    fstream fileIn;


    vector<vector<string>> vec2dContent;
    vector<string> row;
    string line, word;

    //Assigning the file to read and flag
    fileIn.open("grades.csv", ios::in); // ios in is to receive data from an external file

    if (fileIn.is_open()) { //is open checks if the file is open or not
        //WHile there is content to copy from fileIn to line, loop
        while (getline(fileIn, line)) {
            row.clear();//get string of row and remove all it's content

            stringstream str(line); //sstream requires it's own pre-processor initialization. converfts file data to string format

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                row.push_back(word); //appending content of var WORD into row

            vec2dContent.push_back(row); //Appending the ROW content into CONTET variable
        }
    }
    else {
        cout << "No file found\n";
    }


    cout << "This is the data: \n";
    
    for (int j = 0; j < row.size(); j++) {
        for (int i = 0; i < vec2dContent.size(); i++) {
            cout << vec2dContent[j][i] << ",";
        }
        cout << endl;
    }

    cout << "\n\n";

    return;

}






void makeChange() {
    fstream fileIn;


    vector<vector<string>> vec2dContent;
    vector<string> row;
    string line, word;

    //Assigning the file to read and flag
    fileIn.open("grades.csv", ios::in); // ios in is to receive data from an external file

    if (fileIn.is_open()) { //is open checks if the file is open or not
        //WHile there is content to copy from fileIn to line, loop
        while (getline(fileIn, line)) {
            row.clear();//get string of row and remove all it's content

            stringstream str(line); //sstream requires it's own pre-processor initialization. converfts file data to string format

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                row.push_back(word); //appending content of var WORD into row

            vec2dContent.push_back(row); //Appending the ROW content into CONTENT variable
        }
    }
    else {
        cout << "No file found\n";
    }


    cout << "This is the data: \n";

    for (int j = 0; j < row.size(); j++) {
        for (int i = 0; i < vec2dContent.size(); i++) {
            cout << vec2dContent[j][i] << ",";
        }
        cout << endl;
    }

    cout << "\n\n";

 

    cout << "What would you like to change? Row: ";
    int changeRowChoice;
    cin >> changeRowChoice;
    cout << "\nColumn: ";
    int changeColumnChoice;
    cin >> changeColumnChoice;
    cout << "\nTo What?: ";
    string changeDataChoice;
    cin >> changeDataChoice;


    vec2dContent[changeRowChoice-1][changeColumnChoice-1] = changeDataChoice;

    cout << "The changed Datais : \n";

    for (int j = 0; j < row.size(); j++) {
        for (int i = 0; i < vec2dContent.size(); i++) {
            cout << vec2dContent[j][i] << ",";
        }
        cout << endl;
    }

    cout << "\n\n";


    fstream fileOut;
    
    // Create a new file to store updated data
    fileOut.open("gradesnew.csv", ios::out);
    if (!fileOut) {
        cout << "No files found\n";
        return;
    }

    for (int j = 0; j < row.size(); j++) {
        for (int i = 0; i < vec2dContent.size(); i++) {
            fileOut << vec2dContent[j][i] << ",";
        }
        fileOut << "\n";
    }

    fileIn.close();
    fileOut.close();

    // removing the existing file
    remove("grades.csv");

    // renaming the updated file with the existing file name
    rename("gradesnew.csv", "grades.csv");
    
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






