#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ios>
#include <limits>
using namespace std;

int ID = 0;

struct todo 
{
    int id;
    string task;
};

void addTodo() 
{
    system("cls");
    cout<<"\t\t\t***********************************************************************"<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
	cout<<"\t\t\t               WELLCOME TO Your Productivity Tracker                    "<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
    cout<<"\t\t\t***********************************************************************"<<endl<<endl<<endl;
    
    todo todo;
    cout << "\n\tEnter new task : ";
    cin.get();
    getline(cin, todo.task); 
    ID++; 

    ofstream write;
    write.open("tasks.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task ;
    write.close();

    write.open("num.txt");
    write << ID;
    write.close();

    char ch;
    cout<<"\n\tDo you want to add more task? y or n : "; cin>> ch;

    if(ch == 'y')
    {
        addTodo();
    }
    else{
        cout << "\n\tTask has been added successfully";
        return;
    }
}

void print(todo s) 
{
    cout << endl << "\tID is : " << s.id;
    cout << "\tTask is : " << s.task;
}

void readData() 
{
    system("cls");
    cout<<"\t\t\t***********************************************************************"<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
	cout<<"\t\t\t               WELLCOME TO Your Productivity Tracker                    "<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
    cout<<"\t\t\t***********************************************************************"<<endl<<endl<<endl;
    
    todo todo;
    ifstream read;
    read.open("tasks.txt");
    cout << "\n\t\t\t------------------Your current Tasks in the list--------------------";
    
    while (!read.eof()) 
    {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        print(todo);
    }
    read.close();
}

int searchData() 
{
    system("cls");
    cout<<"\t\t\t***********************************************************************"<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
	cout<<"\t\t\t               WELLCOME TO Your Productivity Tracker                    "<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
    cout<<"\t\t\t***********************************************************************"<<endl<<endl<<endl;

    int id;
    cout << "\n\tEnter task id : ";     cin >> id;
    todo todo;
    ifstream read;
    read.open("tasks.txt");
    while (!read.eof()) 
    {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        if (todo.id == id) {
            print(todo);
            return id;
        }
    }
}

void deleteData() 
{
    system("cls");
    cout<<"\t\t\t***********************************************************************"<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
	cout<<"\t\t\t               WELLCOME TO Your Productivity Tracker                    "<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
    cout<<"\t\t\t***********************************************************************"<<endl<<endl<<endl;

    int id = searchData();
    cout << "\n\tDo you want to delete this task? y or n : ";
    char choice;
    cin >> choice;
    if (choice == 'y') 
    {
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("tasks.txt");
        while (!read.eof()) 
        {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
        }
        read.close();
        tempFile.close();
        remove("tasks.txt");
        rename("temp.txt", "tasks.txt");
        cout << "\n\tTask deleted successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

void deletealldata()
{
    system("cls");
    cout<<"\t\t\t***********************************************************************"<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
	cout<<"\t\t\t               WELLCOME TO Your Productivity Tracker                    "<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
    cout<<"\t\t\t***********************************************************************"<<endl<<endl<<endl;

    cout<<"Are you sure you want to delete all data? y or n : ";

    char choice;
    cin>>choice;

    if(choice == 'y')
    {
        fstream temp1;
        fstream temp2;
        temp1.open("num.txt", ios :: in | ios :: out | ios :: trunc);
        temp2.open("tasks.txt", ios :: in | ios :: out | ios :: trunc);
    }
    else
    {
        cout<<"Record not deleted."<<endl;
    }
}

int main()
{
    cout<<"\t\t\t***********************************************************************"<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
	cout<<"\t\t\t               WELLCOME TO Your Productivity Tracker                    "<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
    cout<<"\t\t\t***********************************************************************"<<endl<<endl<<endl;
    ifstream read;
    read.open("num.txt");
    if (!read.fail()) 
    {
        read >> ID;
    }
    else 
    {
        ID == 0;
    }
    read.close();

    int a, b = 1;
    while (b==1) 
    {
        cout<<endl<<"1. Create New Task."<<endl;
        cout<<"2. Show Tasks."<<endl;
        cout<<"3. Delete Task."<<endl;
        cout<<"4. Delete All Tasks."<<endl;
        cout<<"5. Search Task."<<endl;
        cout<<"6. Exit"<<endl;

        cout<<endl<<"Enter choice between 1 - 5."<<endl;
        cout<<endl<<"Your choice: ";
        cin>>a;

            switch(a)
            {
                case 1:
                {
                    addTodo();
                    break;
                }
                case 2:
                {
                    readData();
                    break;
                }
                case 3:
                {
                    deleteData();
                    break;
                }
                case 4:
                {
                    deletealldata();
                    break;
                }
                case 5:
                {
                    searchData();
                    break;
                }
                case 6:
                {
                    cout<<"Exiting..."<<endl;
                    b = 0;
                    break;
                }
                default:
                {
                    cout << "Enter number between 1 - 6. Try again." << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
    }
}