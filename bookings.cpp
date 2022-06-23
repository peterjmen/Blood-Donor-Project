

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void ReadFile(int input/*std::string myFile, std::string search*/);
int a;
using namespace std;
vector<vector<string>> lines;

int main()
{


   
    std::cout << "****Book an Appointment****\n";
    std::cout << "   ****times available**** \n\n";

    

    std::cout << "what date would you like to check availability on?   \n\n";
    std::cout << "date : ";

    std::cin>> a;
    std::cout << "\n\n";   

    ReadFile(a);
  
}

void ReadFile(int a) {


    vector<vector<string>> lines;
    vector<string> coolums; // Vector of attributes/columns containing strings
    string line, word;

    fstream file;
    file.open("booking_database.csv", ios::in); // ios in is to receive data from an external file

    if (file.is_open()) { //is open checks if the file is open or not
        //While there is content to copy from fileIn to line, loop
        while (getline(file, line)) { //getline is needed to get the whole line and assign it to the variable "line"
            coolums.clear();//get string of rowOfIndividualsInfo and remove all it's content

            stringstream str(line); //sstream required to take each "line" and essentially concatenate them together for one large string, without the problem of lines being broke up by newlines

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                coolums.push_back(word); //appending content of var WORD into rowOfIndividualsInfo

            lines.push_back(coolums); //Appending the rowOfIndividualsInfo content into CONTENT variable
        }
    }
    else {
        cout << "No file found\n";
    }
    


    //**** end of 2d vector




     std::cout << lines[a-1][0] << " " << lines[a][1] << "\n";
     
   



    if (lines[a][2] == "") {

        char input2;
        std::cout << "\n\nthis date is available would you like to book this date ? \n\ny) yes\nn) no ";
        std::cin >> input2;

        switch (input2) {
        case 'y' | 'Y':
            
            break;
        case 'n' | 'N':

            std::cout << "works";

            break;

        default:
            std::cout << "\n\nplease use a propper input ";
            break;

        }

    }


}

    
void writetofile(int a) {

    ofstream file("booking_data.csv");

    vector<vector<string>> lines;
    vector<string> coolums; // Vector of attributes/columns containing strings
    string line, word;

    fstream file;

    file.open("booking_database.csv", ios::in, ios::app); // ios in is to receive data from an external file

    if (file.is_open()) { //is open checks if the file is open or not
        //While there is content to copy from fileIn to line, loop
        while (getline(file, line)) { //getline is needed to get the whole line and assign it to the variable "line"
            coolums.clear();//get string of rowOfIndividualsInfo and remove all it's content

            stringstream str(line); //sstream required to take each "line" and essentially concatenate them together for one large string, without the problem of lines being broke up by newlines

            //while there is content within the string, copy to WORD and stop at each comma
            while (getline(str, word, ','))
                coolums.push_back(word); //appending content of var WORD into rowOfIndividualsInfo

            lines.push_back(coolums); //Appending the rowOfIndividualsInfo content into CONTENT variable
        }
    }
    else {
        cout << "No file found\n";
    }

    std::cout << "please input the name you sould like to save your booking under";


}


   
     
    







