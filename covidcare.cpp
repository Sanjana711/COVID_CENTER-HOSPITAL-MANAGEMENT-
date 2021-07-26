#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int ID;
struct hospital {
    int id;
    string name;
    string address;
    string covidcare;
};

void addhospital() {
    hospital detail;
    cout << "\n\tEnter the name : ";
    cin.get();
    getline(cin, detail.name);
    cout << "\n\tEnter  address : ";
    cin >> detail.address;
    cout << "\n\tEnter  covid care center(y/n) : ";
    cin >> detail.covidcare;
    ID++;

    ofstream write;
    write.open("csm.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << detail.name ;
    write << "\n" << detail.address ;
    write << "\n" << detail.covidcare;
    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    cout << "\n\tData save to file";
}

void print (hospital c) {
    cout<<"\n";
    cout << "\n\t***** hospital ********";
    cout << "\n\tID  : " << c.id;
    cout << "\n\t  Name  : " << c.name;
    cout << "\n\t ADDRESS :" << c.address;
    cout << "\n\t COVID CARE Center : " << c.covidcare;

}

void readData() {
   hospital detail;
    ifstream read;
    read.open("csm.txt");
    while (!read.eof()) {
        read >> detail.id;
        read.ignore();
        getline(read, detail.name);
        read >> detail.address;
        read >> detail.covidcare;
        print(detail);
    }
    read.close();
}

int searchData() {
    int id;
    cout << "\n\n\tEnter the id you want to search : ";
    cin >> id;
    hospital detail;
    ifstream read;
    read.open("csm.txt");
    while (!read.eof()) {
         read >> detail.id;
        read.ignore();
        getline(read, detail.name);
        read >> detail.address;
        read >> detail.covidcare;
        if (detail.id == id) {
            print(detail);
            return id;
        }
    }
}

void deleteData() {
    int id = searchData();
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        hospital detail;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("csm.txt");
        while (!read.eof()) {
         read >> detail.id;
        read.ignore();
        getline(read, detail.name);
        read >> detail.address;
        read >> detail.covidcare;
            if (detail.id != id) {
                tempFile << "\n" << detail.id;
                tempFile << "\n" << detail.name;
                tempFile << "\n" << detail.address;
                tempFile << "\n" << detail.covidcare;
            }
        }
        read.close();
        tempFile.close();
        remove("csm.txt");
        rename("temp.txt", "csm.txt");
        cout << "\n\t Deleted DATA ";
    }
    else {
        cout << "\n\tRecord is not deleted";
    }
}

void updateData() {
    int id = searchData();
    cout << "\n\n\t update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        hospital newData;
        cout << "\n\tEnter the name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "\n\tEnter the address : ";
        cin >> newData.address;
        cout << "\n\tEnter Covid Care center : ";
        cin >> newData.covidcare;
        hospital detail;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("csm.txt");
        while (!read.eof()) {
	         read >> detail.id;
	        read.ignore();
	        getline(read, detail.name);
	        read >> detail.address;
	        read >> detail.covidcare;
           if (detail.id != id) {
                tempFile << "\n" << detail.id;
                tempFile << "\n" << detail.name;
                tempFile << "\n" << detail.address;
                tempFile << "\n" << detail.covidcare;
            }
            else {
                tempFile << "\n"<< detail.id;
                tempFile << "\n"<< newData.name;
                tempFile << "\n"<< newData.address;
                tempFile << "\n"<< newData.covidcare;
            }
        }
        read.close();
        tempFile.close();
        remove("csm.txt");
        rename("temp.txt", "csm.txt");
        cout << "\n\tData updated ";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

int main()
{
    ifstream read;
    cout<<"\n\n";
    cout<<"$$$$$$$$$$$   Hospital Covid Care Centers   $$$$$$$$$$$$$$";
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout<<"\n";
        cout << "\n\t\t1.Add Hospital ";
        cout << "\n\t\t2.view Hospital";
        cout << "\n\t\t3.Search Hospital";
        cout << "\n\t\t4.Delete Hospital";
        cout << "\n\t\t5.Update Hospital";
        cout << "\n\t\t6.exit";

        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addhospital();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        default:
            cout<<"Thank You";
            exit(0);
        }
    }

}


