#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <locale>

using namespace std;

class Users
{
public:
	Users();
	string userName;
	string accessR;
};

Users::Users()
{
	userName[20]='\0';

}

class Files
{
public:
	string fileName;
	list<Users> users;
	Files();
};
Files::Files()
{
	fileName[20]='\0';
}

list<Files> files;
list<Files>::iterator f;
list<Users>::iterator u;
list<Users> users;


void addUser(string userName,string fileName,string accessR);

void show_menu();

void show_Files();



void RemoveUsersForFile(string fileName, string userName);
void RemoveFile(string fileName);
void RemoveUser(string userName);

//main program
int main()
{

	string userName;
	string fileName;
	string accessR;
	string option;


	while(true)
	{
		system("cls");
		show_menu();
		cin>>option;
		while(option!="1" && option!="2" && option!="3" && option!="4" && option!="5" && option!="6")
		{
			system("cls");
			cout<<"\nWrong input selected!\n";
			show_menu();
			cin>>option;
		}
		if(option=="1")
		{
			system("cls");
            cout<<"\nInput user name : ";
            cin>>userName;
            cout<<"\nInput file name : ";
            cin>>fileName;
            cout<<"\nInput access Right : ";
            cin>>accessR;
            addUser(userName,fileName,accessR);
            cout<<endl<<endl;
            system("pause");


		}
		if(option=="2")
		{
			system("cls");
			show_Files();
			cout<<endl;
			system("pause");
		}

		if(option=="3")
		{
			system("cls");
			cout<<"Specify file name: ";
			cin>>fileName;
			cout<<"Specify user name: ";
			cin>>userName;
			RemoveUsersForFile(fileName,userName);
			cout<<endl<<endl;
			system("pause");
		}

		if(option=="4")
        {
            system("cls");
            cout<<"Enter file name: ";
            cin>>fileName;
            RemoveFile(fileName);
            cout<<endl<<endl;
            system("pause");
        }

        if(option =="5")
        {
            system("cls");
            cout<<"Enter user name: ";
            cin>>userName;
           // RemoveUser(userName);
            cout<<endl<<endl;
            system("pause");
        }

		if(option=="6")
		{
			break;
		}
	}
	return 0;
	system("pause");
}
//end of main
void RemoveUser(string userName, string fileName)
{
    list<Users>::iterator u;
	bool found_user=false, found_file=false;
    for(u=f->users.begin(); u!=f->users.end(); u++)
    {
        if(u->userName==userName)
        {
            users.erase(u);
           // users.erase(files);
            found_user=true;
            break;
        }
    }
        found_file=true;
//        break;


	if(found_file==false)
		cout<<"\n No file with name : "<<fileName<<" exists.";
	if(found_file==true && found_user==false)
		cout<<"\n File with name : "<<fileName<<" contains no user with name : "<<userName;
	if(found_file==true && found_user==true)
		cout<<"\n User with name : "<<userName<<" deleted from file with name : "<<fileName;

}
void RemoveUsersForFile(string fileName, string userName)
{
	list<Users>::iterator u;
	bool found_user=false, found_file=false;
	for(f=files.begin(); f!= files.end(); f++)
	{
		if(f->fileName == fileName)
		{
			for(u=f->users.begin(); u!=f->users.end(); u++)
			{
				if(u->userName==userName)
				{
					f->users.erase(u);
					found_user=true;
					break;
				}
			}
			found_file=true;
			break;
		}
	}
	if(found_file==false)
		cout<<"\n No file with name : "<<fileName<<" exists.";
	if(found_file==true && found_user==false)
		cout<<"\n File with name : "<<fileName<<" contains no user with name : "<<userName;
	if(found_file==true && found_user==true)
		cout<<"\n User with name : "<<userName<<" deleted from file with name : "<<fileName;
}

void RemoveFile(string fileName)
{
    list<Files>::iterator f;
    for(f=files.begin(); f!= files.end(); f++)
	{
		if(f->fileName == fileName)
		{
		    files.erase(f);
		}

}
}

void show_Files()
{
	list<Users>::iterator u;
	for(f=files.begin(); f!=files.end(); f++)
	{
		cout<<"File name : "<<f->fileName<<endl;
		cout<<"==================="<<endl;
		for(u = f->users.begin(); u!=f->users.end(); u++)
		{
			cout<<"User Name : "<<u->userName<<endl;
			cout<<"Access Right : "<<u->accessR<<endl;
			if(++u!=f->users.end())
				cout<<"-------------------"<<endl;
			--u;
		}
		cout<<endl;
	}
}


void show_menu()
{
	cout<<"\n1. Add new user";
	cout<<"\n2. View all files and users";
	cout<<"\n3. Remove user from existing file";
	cout<<"\n4. Exit";
	cout<<"\n\nChoose (1-4) -> ";
}


void addUser(string userName,string fileName,string accessR)
{
	bool file_found=false;
	bool user_found=false;
	string confirm ="";
	list<Users>::iterator u;
	f = files.begin();
	while(f!=files.end())
	{
		if(f->fileName==fileName)
		{
			file_found=true;
			break;
		}
		f++;
	}
	if(file_found==false)
	{
		Files* newF = new Files;
		newF->fileName = fileName;
		Users* newU = new Users;
		newU->userName = userName;
		newU->accessR = accessR;
		newF->users.push_back(*newU);
		files.push_back(*newF);
		delete newF;
		delete newU;
		cout<<"\nNew file created successfully. Specified user added.";
	}
	if(file_found==true)
	{
		u = f->users.begin();
		while(u!=f->users.end())
		{
			if(u->userName==userName)
			{
				user_found = true;
				break;
			}
			u++;
		}
		if(user_found==false)
		{
			cout<<"\nFile with name : "<<f->fileName<<" exists. No user with name : "
				<<userName<<" found"<<endl<<endl;
			cout<<"Add new user with name : "<<userName<<" ? (type 'y' or 'Y' to confirm) : ";
			cin>>confirm;
			if(confirm == "y" || confirm == "Y")
			{
				Users* newU = new Users;
				newU->userName = userName;
				newU->accessR = accessR;

				f->users.push_back(*newU);
				delete newU;
				cout<<"\nNew user added inside the existing file.";
			}
		}
		if(user_found==true)
		{
			cout<<"\nFile with name : "<<f->fileName<<" exists."<<endl;
			cout<<"User with name : "<<u->userName<<" exists."<<endl;
			cout<<"\n=====User information is as follows=====\n\n";
			cout<<"Username : "<<u->userName<<endl;
			cout<<"Access Right: "<<u->accessR<<endl;

			cout<<"\n===New user information is as follows===\n\n";
			cout<<"Username : "<<userName<<endl;
			cout<<"Access Right: "<<accessR<<endl;
			cout<<"\nUpdate this user? (type 'y' or 'Y' to confirm) : ";
			cin>>confirm;
			if(confirm == "y" || confirm == "Y")
			{
				Users* newU = new Users;
				newU->userName = userName;
				newU->accessR= accessR;


				f->users.push_back(*newU);
				delete newU;

				cout<<"\nUser updated successfully.";
			}
		}
	}
}
