#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

// Struct Records
struct Records{
	char nickname[50];
	int age;
    double score1, score2, average;
};
int main(){
	
	// FSTREAM Objects
	ifstream inFile;
	ofstream outFile;
	
	// Structs and Variables
	Records record[5];
    int i, choice, counter = 0;
    double max, min;
    bool check = false;
	
	// Recursive Menu using While - Loop
	while(1){
		cout << "\nMENU\n";
		cout << "1. Add Record\n";
		cout << "2. View Players' Records\n";
		cout << "3. Computer for the average\n";
		cout << "4. Show the player(s) who gets the max average.\n";
		cout << "5. Show the player(s) who gets the min average.\n";
		cout << "6. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;
		switch(choice){
			// Case 1 for Adding Records
			case 1:
				check = true;
				cout << "Add Record\n";
				for(i=0; i<5; i++){
			        cout << "\nPlayer " << i+1 << " Nickname: ";
			        cin.ignore();
			        cin.getline(record[i].nickname,49);
			        cout << "Player " << i+1 << " Age: ";
			        cin >> record[i].age;
			        cout << "Enter Player "<< i+1 << " Score 1: ";
					cin >> record[i].score1;
					cout << "Enter Player "<< i+1 << " Score 2: ";
					cin >> record[i].score2;
			    }
			    // Transferring to Text File
			    outFile.open("playerRecords.txt");
				outFile << "View Players' Records'\n";
				outFile << setw(10) <<"Nickname"
				     << setw(17) << "Age"
				     << setw(21) << "Score 1"
				     << setw(21) << "Score 2\n";
				for(i=0; i<5; i++){
				    outFile << endl;
				    outFile << setw(10) << record[i].nickname
						 << setw(16) << record[i].age
						 << setw(20) << record[i].score1 
						 << setw(20) << record[i].score2 << endl;
				}
				cout << "\n\nPress any key to return....";
				system("pause>0");
				system("cls");
				break;
			// Case 2 for Viewing Players' Records
			case 2:
				if(check == false){
					cout << "Add Players's Record First.\n";
				} else{
					outFile.open("playerRecords.txt");
				cout << "View Players' Records'\n";
				cout << setw(10) <<"Nickname"
				     << setw(17) << "Age"
				     << setw(21) << "Score 1"
				     << setw(21) << "Score 2\n";
				for(i=0; i<5; i++){
				    cout << endl;
				    cout << setw(10) << record[i].nickname
						 << setw(16) << record[i].age
						 << setw(20) << record[i].score1 
						 << setw(20) << record[i].score2 << endl;
				}
				// Transferring to Text File
				outFile << "View Players' Records'\n";
				outFile << setw(10) <<"Nickname"
				     << setw(17) << "Age"
				     << setw(21) << "Score 1"
				     << setw(21) << "Score 2\n";
				for(i=0; i<5; i++){
				    outFile << endl;
				    outFile << setw(10) << record[i].nickname
						 << setw(16) << record[i].age
						 << setw(20) << record[i].score1 
						 << setw(20) << record[i].score2 << endl;
				}
				}
				cout << "\n\nPress any key to return....";
				system("pause>0");
				system("cls");
				break;
			// Case 3 for Computing the Average
			case 3:
				if(check == false){
					cout << "Add Players's Record First.\n";
				} else{
					outFile.open("playerRecords.txt");
					cout << "Computer for the players average.\n";
					cout << setw(10) <<"Nickname"
					     << setw(17) << "Average\n";
					for(i=0; i<5; i++){
						record[i].average = round((record[i].score1 + record[i].score2) / 2);
					    cout << endl;
					    cout << setw(10) << record[i].nickname
						 << setw(16) << record[i].average << endl;
					}
					// Transferring to Text File
					outFile << setw(10) <<"Nickname"
					     << setw(17) << "Average\n";
					for(i=0; i<5; i++){
						record[i].average = round((record[i].score1 + record[i].score2) / 2);
					    outFile << endl;
					    outFile << setw(10) << record[i].nickname
						 << setw(16) << record[i].average << endl;
					}
				}
				cout << "\n\nPress any key to return....";
				system("pause>0");
				system("cls");
				break;
			// Case 4 for Showing the Players' with Max Average
			case 4:
				if(check == false){
					cout << "Add Players's Record First.\n";
				} else{
					outFile.open("playerRecords.txt");
					cout << "Show the player(s) who gets the max average.\n";
					cout << setw(10) <<"Nickname"
					     << setw(17) << "Average\n";
					max = record[0].average;
					counter = 0;
					for(i = 0; i < 5; i++){
						if(max < record[i].average){
							max = record[i].average;
						}
					}
					for(i = 0; i < 5; i++){
						if(max == record[i].average){
							cout << setw(10) << record[counter].nickname
					     		     << setw(15) << max << endl;
						}
						counter++;
					}
					// Transferring to Text File
					outFile << "Show the player(s) who gets the max average.\n";
					outFile << setw(10) <<"Nickname"
					     << setw(17) << "Average\n";
					max = record[0].average;
					counter = 0;
					for(i = 0; i < 5; i++){
						if(max < record[i].average){
							max = record[i].average;
						}
					}
					for(i = 0; i < 5; i++){
						if(max == record[i].average){
							outFile << setw(10) << record[counter].nickname
					     		     << setw(15) << max << endl;
						}
						counter++;
					}
				}
				cout << "\n\nPress any key to return....";
				system("pause>0");
				system("cls");
				break;
			// Case 5 for Showing the Players' with Min Average
			case 5:
				if(check == false){
					cout << "Add Players's Record First.\n";
				} else{
					outFile.open("playerRecords.txt");
					cout << "Show the player(s) who gets the min average.\n";
					cout << setw(10) <<"Nickname"
					     << setw(17) << "Average\n";
					min = record[0].average;
					counter = 0;
					for(i = 0; i < 5; i++){
						if(min > record[i].average){
							min = record[i].average;
						}
					}
					for(i = 0; i < 5; i++){
						if(min == record[i].average){
							cout << setw(10) << record[counter].nickname
					     		     << setw(15) << min << endl;
						}
						counter++;
					}
					// Transferring to Text File
					outFile << "Show the player(s) who gets the min average.\n";
					outFile << setw(10) <<"Nickname"
					     << setw(17) << "Average\n";
					min = record[0].average;
					counter = 0;
					for(i = 0; i < 5; i++){
						if(min > record[i].average){
							min = record[i].average;
						}
					}
					for(i = 0; i < 5; i++){
						if(min == record[i].average){
							outFile << setw(10) << record[counter].nickname
					     		     << setw(15) << min << endl;
						}
						counter++;
					}
				}
				cout << "\n\nPress any key to return....";
				system("pause>0");
				system("cls");
				break;
			case 6:
				cout << "Exiting...\n";
				exit(1);
				break;
			default:
				cout << "Invalid Choice.\n";
				exit(1);
		}
		inFile.close();
		outFile.close();
	}
	return 0;
}
