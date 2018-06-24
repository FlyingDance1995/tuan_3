#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <ctime>

using namespace std;

void MainMenu();

int chon, confirmation;
bool cinfail;
string username, username2, password, password2, name, age, gender, CurrentResidence;

void Writetofile(string username1) {
	ofstream writefile; 
	writefile.open(username1 + ".txt", ios_base::app);

	writefile << username;
	writefile << "," << password;
	writefile << "," << name;
	writefile << "," << age;
	writefile << "," << gender;
	writefile << "," << CurrentResidence;
	writefile.close();
	MainMenu();
}


void ShowMessage(string user) {
	system("cls");

	ifstream readFile;
	readFile.open(user + "sms.txt");
	
	if(!readFile){
		cout << " ------ No Message ------" << endl;
		cout << "\n";
	}
	else {
		cout << " ------ Show Message ------" << endl;
		cout << "\n";

		char *usersend = NULL;
		char *client = NULL;
		string line;
		char *dataa;

		while (getline(readFile, line))
		{
			if (line == "")
				break;

			const char *v = line.c_str();
			dataa = (char*)malloc(1000*sizeof(line));
			strcpy(dataa, v);

			usersend = strtok(dataa, ",");
			client = strtok(NULL, ",");

			cout << usersend << "- send to -" << client << endl;
		}
		//cout << "\n";
		readFile.close();
	}
}

void ShowMessageDetail(string user) {
	system("cls");
	cout << " ------ Show Message Detail ------" << endl;
	cout << "\n";

	ifstream readFile;
	readFile.open(user + "sms.txt");

	string line;

	while (getline(readFile, line))
	{
		cout << line << endl;
	}
	cout << "\n";
	readFile.close();
}

void SendMessage(string user) {
	string user1;
	string data;

	cout << " - Nhap noi dung: " << endl;
	getline(std::cin, data);

		cout << " - Nhap Username nguoi Nhan: " << endl;
		cin >> user1;

		ifstream readfile1;
		string line, userblock;
		char *dataa;

		readfile1.open(user1 + "blockFriend.txt");

		if (readfile1) {

			while (getline(readfile1, line))
			{
				const char *v = line.c_str();
				dataa = (char*)malloc(sizeof(line));
				strcpy(dataa, v);
				userblock = strtok(dataa, ",");

				if (userblock == user) {
					system("cls");
					cout << "|----- Fall !!! You have been Blocked ----|" << endl;
					cout << "\n";
					break;
				}
			}
			readfile1.close();
		}
		else {
			ifstream readFile;
			do {
				readFile.open(user1 + ".txt");

				if (!readFile) {
					cout << "----- Fall !!! Does not exist Username ----" << endl;
				}
				readFile.close();

			} while (!readFile);


			ofstream writeFile;
			ofstream writeFile1;

			writeFile.open(user + "sms.txt", ios_base::app);
			writeFile1.open(user1 + "sms.txt", ios_base::app);

			time_t hientai = time(0);
			char* dt = ctime(&hientai);

			writeFile << user << "," << user1 << "," << "Noi dung -" << data << " - Date & Time Send: " << dt;
			writeFile.close();
			writeFile1 << user << "," << user1 << "," << "Noi dung -" << data << " - Date & Time Send: " << dt;
			writeFile1.close();

			system("cls");
			cout << "\n+------------------------------+" << endl;
			cout << "+----- Gui thanh cong !!! -----+" << endl;
			cout << "+------------------------------+\n" << endl;
		}
	
}

void AddFriend(string user) {
	system("cls");
	string user1;
	ifstream readfile;
	do {
		cout << " - Input Username want Add Friend: " << endl;
		cin >> user1;

		readfile.open(user1 + ".txt");

		if (!readfile) {
			cout << "|----- Fall !!! Does not exist Username ----|" << endl;
		}
		readfile.close();
	} while (!readfile);

	ofstream writeFile;
	writeFile.open(user + "friend.txt", ios_base::app);

	writeFile << user1 <<","<< endl;
	writeFile.close();

	system("cls");
	cout << "\n+------------------------------+" << endl;
	cout << "+--- Them ban thanh cong !!! --+" << endl;
	cout << "+------------------------------+\n" << endl;
	
}

void ListFriend(string user2) {
	string line;
	system("cls");
	cout << "------ List Friend of "<< user2 <<" ------"<< endl;
	cout << "\n";

	ifstream readfile;
		readfile.open(user2 + "friend.txt");
		if (!readfile) {
			cout << "------------ No friends ---------" << endl;
			cout << "\n";
		} else
		{
			while (getline(readfile, line))
			{
				cout << line << endl;
			}
			cout << "\n";
			readfile.close();
		}
		
}

void BlockFriend(string user2) {
	string line, blockFriend, text = user2+"friend.txt";
	char *user3 = NULL;
	char *data;

	system("cls");
	cout << "------ List Friend of " << user2 << " ------" << endl;
	cout << "\n";
 	
	ifstream readfile;
	readfile.open(text);

	if (!readfile) {
		cout << "------------ No friends ---------" << endl;
		cout << "\n";
	}
	else
	{
		while (getline(readfile, line))
		{
			cout << line << endl;
		}
		cout << "\n";

			cout << " - Input Username want Block Friend: " << endl;
			cin >> blockFriend;
			readfile.close();
			ofstream write_Block_File;
			ifstream readfile1;
			readfile1.open(text);
			write_Block_File.open(user2 + "blockFriend.txt", ios_base::app);

			while (getline(readfile1, line))
			{
				const char *v = line.c_str();
				data = (char*)malloc(sizeof(line));
				strcpy(data, v);
				user3 = strtok(data, ",");

				if (user3 == blockFriend) {
					write_Block_File << user3<<","<< endl;
					break;
				}

			}
			write_Block_File.close();
			readfile.close();
			cout << "+----- Block" << blockFriend << "thanh cong !!! -----+" << endl;
			cout << "\n";
	}
}


void Login() {

	string username1;
	ifstream readfile;
	char *user = NULL;
	char *passw = NULL;

	do {
		do {
			cout << " - Invites you to enter Username:" << endl;
			cin >> username1;

			readfile.open(username1 + ".txt");

			if (!readfile) {
				cout << " ----- Sorry invalid !!! ---- \n" << endl;
			}
		} while (!readfile);

		string data;
		char *dataa;

		while (getline(readfile, data))
		{
			const char *v = data.c_str();
			dataa = (char*)malloc(sizeof(data));
			strcpy(dataa, v);

			user = strtok(dataa, ",");
			passw = strtok(NULL, ",");
		}
		readfile.close();

		if (username1 == user) {
			username2 = username1;
			break;
		}
		else
		{
			printf(" ----- Sorry invalid !!! ---- \n");
		}

	} while (username1 != user);

	cout << "- Please enter the Password:" << endl;
	cin >> password2;

	if (password2 == passw) {
		cin.clear();
		cin.ignore(10000, '\n');

		system("cls");
		cout << "	             +------------------------------+" << endl;
		cout << "                     +----- Login Thanh Cong -------+" << endl;
		cout << "                     +------------------------------+\n" << endl;
	}
	else {
		cout << "Sorry invalid Password , Please try again !!! \n" << endl;
		Login();
	}
}

void RegisterPassword() {

	cout << "- Please enter the Name:" << endl;
	cin >> name;
	cout << "- Please enter the Age:" << endl;
	cin >> age;
	cout << "- Please enter the Gender:" << endl;
	cin >> gender;

	cin.ignore();  // thêm vào để xoá bộ nhớ đệm, tránh bị trôi lệnh
	cout << " - Please enter the Current Residence:" << endl;
	getline(std::cin, CurrentResidence);

	cout << " - Please enter the Password:" << endl;
	cin >> password;
	cout << " - Please renter your Password:" << endl;
	cin >> password2;

	system("cls");
	if (password == password2) {
		cout << "              +---------------------------------------+" << endl;
		cout << "              +--- Account successfully created !!! --+" << endl;
		cout << "              +---------------------------------------+\n" << endl;
		cin.clear();
		cin.ignore(1000, '\n');

		Writetofile(username);
		exit(1);
	}
	else {
		cout << "Sorry invalid !!!" << endl;
		RegisterPassword();
	}
}


void RegisterMe() {

	ifstream readfile;
	do {
	cout << "Please enter your username: " << endl;
	getline(cin, username);
		
		readfile.open(username + ".txt");

		if (readfile) {
			cout << "----- Sorry invalid !!! Already exists Username ----" << endl;
		}
		readfile.close();

	} while (readfile);

	cout << "\n --------- Username -------  \"" << username << "\"\nAre you sure? \n\n - [1] Yes\n - [2] No" << endl;
	cin >> confirmation;
	if (confirmation == 1) {
		RegisterPassword();
	}
	else {
		cout << " -- Please enter try again !!! --" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		RegisterMe();
	}
}

void Logout() {
	system("cls");
	cout << "\n----------- Logout Success --------\n" << endl;
}

void Exit() {
	exit(0);
}


void MenuUser() {
	cout << "+---------- Please enter the Number !!! ----------+\n\n[1] Hien thi tin nhan da gui\n[2] Hien thi thong tin chi tiet cua tin nhan \n[3] Gui tin nhan \n[4] Them Ban \n[5] Hien Thi Danh Sach Ban Be \n[6] Block \n[7] Logout"<< endl;
	cin >> chon;
	do {
		cinfail = cin.fail();
		cin.clear();
		cin.ignore(10000, '\n');

	} while (cinfail == true); {
		switch (chon) {
		case 1:
			ShowMessage(username2);
			MenuUser();
			break;

		case 2:
			ShowMessageDetail(username2);
			MenuUser();
			break;

		case 3:
			SendMessage(username2);
			MenuUser();
			break;

		case 4:
			AddFriend(username2);
			MenuUser();
			break;

		case 5:
			ListFriend(username2);
			MenuUser();
			break;

		case 6:
			BlockFriend(username2);
			MenuUser();
			break;

		case 7:
			Logout();
			MainMenu();
			break;
		 default:
			 cout << " Sorry invalid input, Please try again !!!" << endl;
			MenuUser();
			break;
		}
	}
}

void MainMenu() {
	//system("cls");
	cout << "Hello, Would you like to Login or Register !!! \n - [1] Login\n - [2] Register\n - [3] Exit" << endl; 
	cin >> chon; 
	do {
		cinfail = cin.fail();
		cin.clear();
		cin.ignore(10000, '\n');

	} while (cinfail == true); {
		switch (chon) {
		case 1:
			Login();
			MenuUser();
			break;

		case 2:
			RegisterMe();
			break;

		case 3:
			Exit();

		default:
			cout << "Sorry invalid input, Please try again !!!" << endl;
			MainMenu();
			break;
		}
	}
}

int main() {
	MainMenu();
}
