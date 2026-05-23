#include <iostream>
#include <fstream>
using namespace std;

struct Record {
    int type;      
    float amount;
};
//structure to store all records together
struct Finance {
    Record records[50];
    int count; 
};

Finance finance;

// Create file using file handling
void createFile() {
    ofstream file("financetracker.txt", ios::app);
    file.close();
}



//function for adding records
void addRecord() {
    if (finance.count >= 50) {
        cout << "Record limit reached!" << endl;
        return;
    }
    cout << "Enter type (1 = Income, 2 = Expense): ";
    cin >> finance.records[finance.count].type;
    cout << "Enter amount: ";     // Take amount from user
    cin >> finance.records[finance.count].amount;
    
    finance.count++;
    cout << "Record added successfully!" << endl;
}

void showRecords() {
    if (finance.count == 0) {
        cout << "No records yet!" << endl;
        return;
    }
    cout << "\n--- ALL RECORDS ---" << endl;
    for (int i = 0; i < finance.count; i++) {
 cout << "Record " << i + 1 << ": " << (finance.records[i].type == 1 ? "Income" : "Expense") << " - " << finance.records[i].amount << endl;
    }
}

void showTotals() {
    float income = 0, expense = 0;
    for (int i = 0; i < finance.count; i++) {
        if (finance.records[i].type == 1) income += finance.records[i].amount;
        else expense += finance.records[i].amount;
    }
    cout << "\n--- TOTALS ---" << endl;
    cout << "Total Income  : " << income << endl;
    cout << "Total Expense : " << expense << endl;
    cout << "Net Savings   : " << income - expense << endl;
}

// this saves only the summary to your txt file
void saveSummaryToFile() {
   
    ofstream file("financetracker.txt"); 

    float income = 0, expense = 0;
    for (int i = 0; i < finance.count; i++) {
        if (finance.records[i].type == 1) income += finance.records[i].amount;
        else expense += finance.records[i].amount;
    }

    file << "--- FINAL SUMMARY ---" << endl;
    file << "Total Income  : " << income << endl;
    file << "Total Expense : " << expense << endl;
    file << "Net Savings   : " << income - expense << endl;

    file.close();
    cout<<"Your summary has been saved to 'financetracker.txt'.\n";
    
}

int main() {
    finance.count = 0; 
    createFile();
 
    int choice;
    do {
    	
    	cout<<"\n=======================================\n";
    	cout<<"      PERSONAL FINANCE TRACKER \n";
    	cout<<"=======================================";
    	
        cout << "\n1. Add Record";
        cout<<"\ntest";
        cout << "\n2. Show Record";
        cout << "\n3. Show Totals";
        cout << "\n4. Save Summary";
		cout << "\n5. Exit";
		cout<<"\nEnter Choice: ";
        cin >> choice;
//switch statement for menu options
        switch (choice) {
            case 1: addRecord(); break;
          case 2: showRecords(); break;
          case 3: showTotals(); break;
          case 4: saveSummaryToFile(); break;
          case 5:
              // Writes the summary on the txt file
  cout << "THANKS FOR USING FINANCE TRACKER!" << endl;
                break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
   
    return 0;
}
