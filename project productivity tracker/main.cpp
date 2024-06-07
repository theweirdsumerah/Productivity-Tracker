#include <iostream>
#include <bits/stdc++.h>
#include<conio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ios>
#include <limits>
#include<windows.h>
#include<ctime>

using namespace std;

void time_now()
{
    time_t a=time(0);
    tm *b=localtime(&a);
    cout<<b->tm_hour<<" : "<<b->tm_min<<" : "<<b->tm_sec<<" \tDate : ";
    cout<<b->tm_mday<<" / "<<b->tm_mon+1<<"  / "<<b->tm_year+1900;
}

void display_ui(string unch)
{
    cout<<"\n\n\t\t\t\t\t";
    for (char ch : unch)
    {
        cout << ch;
        Sleep(80);
    }
    // cout<<"\n\n\n\t\t\t************************************************************************"<<endl<<endl;
}

int ID = 0;

struct todo
{
    int id;
    string task;
};



void addTodo()
{
    system("cls");
    cout<<"\n\n\t\t\t\t\t";
    cout<<" WELCOME TO YOUR PRODUCTIVITY TRACKER "<<endl;
    cout<<"\n\t\t\t************************************************************************"<<endl<<endl;

    cout<<"\n\n\t\t\t\t  Time Now : ";
    time_now();
    cout<<"\n"<<endl;

    todo todo;
    display_ui("\n\tEnter new task : ");
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
    display_ui("\n\tDo you want to add more tasks? ( y or n ) : ");
    cin>> ch;

    if(ch == 'y'||ch == 'Y')
    {
        addTodo();
    }
    else
    {
        display_ui( "\n\tTask has been added successfully.... ^.^ ");
        cout<<endl<<endl;
        Sleep(1000);
        system("cls");
        cout<<"\n\n\t\t\t\t\t";
        cout<<" WELCOME TO YOUR PRODUCTIVITY TRACKER "<<endl;
        cout<<"\n\n\t\t\t************************************************************************"<<endl<<endl;

        cout<<"\n\n\t\t\t\t  Now Time : ";
        time_now();
        cout<<"\n"<<endl;
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
    cout<<"\n\n\t\t\t\t\t";
    cout<<" WELCOME TO YOUR PRODUCTIVITY TRACKER "<<endl;
    cout<<"\n\t\t\t************************************************************************"<<endl<<endl;

    cout<<"\n\n\t\t\t\t  Time Now : ";
    time_now();
    cout<<"\n"<<endl;

    todo todo;
    ifstream read;
    read.open("tasks.txt");
    cout << "\n\t\t\t------------------Your current tasks in the list--------------------\n";
    if(!read)
    {
        display_ui("   You have no tasks..... >_< ");
        read.close();
        cout<<endl;

    }
    else
    {
        while (!read.eof())
        {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            print(todo);
            cout<<"\n"<<endl;
        }
        read.close();
    }
}
int searchData()
{
    system("cls");
    cout<<"\n\n\t\t\t\t\t";
    cout<<" WELCOME TO YOUR PRODUCTIVITY TRACKER "<<endl;
    cout<<"\n\n\t\t\t************************************************************************"<<endl<<endl;

    cout<<"\n\n\t\t\t\t  Time Now : ";
    time_now();
    cout<<"\n"<<endl;

    ifstream read;
    read.open("tasks.txt");
    read.close();
    if(!read)
    {
        display_ui("   You have no tasks..... >_< ");
        cout<<endl;

    }
    else
    {
        int id;
        display_ui("\n\tEnter task id : ");
        cin >> id;
        // cout<<"Searching ";
        display_ui("\tSearching ");
        Sleep(600);
        cout<<".";
        Sleep(600);
        cout<<".";
        Sleep(600);
        cout<<".";
        Sleep(600);
        //cout<<endl;
        todo todo;
        ifstream read;
        read.open("tasks.txt");
        while (!read.eof())
        {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id == id)
            {
                display_ui("\n\tData found ...");
                cout<<endl;
                print(todo);
                cout<<endl;
                return id;
            }
            else
            {
                display_ui("\n\tData not found ...");
                cout<<endl;
                display_ui("\n\tDo you want to see all tasks ? or back to the main manu ? ");
                cout<<endl;
                cout<<"\n\tPress ""1"" for see all tasks . "<<endl;
                cout<<"\tPress ""2"" for main manu . "<<endl;
                cout<<endl<<"\tYour choice: ";
                int a=0;
                cin>>a;
                switch(a)
                {
                case 1:
                {
                    readData();
                    cout<<endl;
                    return 0;
                    break;
                }
                default:
                {
                    system("cls");
                    cout<<"\n\n\t\t\t\t\t";
                    cout<<" WELCOME TO YOUR PRODUCTIVITY TRACKER "<<endl;
                    cout<<"\n\n\t\t\t************************************************************************"<<endl<<endl;

                    cout<<"\n\n\t\t\t\t  Now Time : ";
                    time_now();
                    cout<<"\n"<<endl;
                    return 0;
                    break;
                }
                }
            }
        }
        read.close();
    }
    return 0;
}

void deleteData()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t";
    cout<<" WELCOME TO YOUR PRODUCTIVITY TRACKER "<<endl;
    cout<<"\n\n\t\t\t************************************************************************"<<endl<<endl;

    cout<<"\n\n\t\t\t\t  Now Time : ";
    time_now();
    cout<<"\n"<<endl;

    ifstream read;
    read.open("tasks.txt");
    read.close();

    if(!read)
    {
        display_ui("   You have no tasks..... >_< ");
        cout<<endl;
    }

    else
    {
        int id = searchData();
        if(id!=0)
        {
            display_ui("\n\tDo you want to delete this task? ( y or n ) : ");
            char choice;
            cin >> choice;
            if (choice == 'y'||choice == 'Y')
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
                    if (todo.id != id)
                    {
                        tempFile << "\n" << todo.id;
                        tempFile << "\n" << todo.task;
                    }
                }
                read.close();
                tempFile.close();
                remove("tasks.txt");
                rename("temp.txt", "tasks.txt");
                display_ui("   Task deleted successfuly..... +_+ *_* ");
                cout<<endl;

            }
            else
            {
                display_ui("   Record not deleted ..... >_< ");
                cout<<endl;

            }
        }
    }
}

void deletealldata()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t";
    cout<<" WELCOME TO YOUR PRODUCTIVITY TRACKER "<<endl;
    cout<<"\n\n\t\t\t************************************************************************"<<endl<<endl;

    cout<<"\n\n\t\t\t\t  Time Now : ";
    time_now();
    cout<<"\n"<<endl;

    ifstream read;
    read.open("tasks.txt");
    read.close();

    if(!read)
    {
        display_ui("   You have no tasks..... >_< ");
        cout<<endl;

    }


    else
    {
        display_ui("\n\tAre you sure you want to delete all data? ( y or n ) : ");

        char choice;
        cin>>choice;
        if(choice == 'y')
        {
            remove("num.txt");
            remove("tasks.txt");
            remove("temp.txt");
            display_ui("   Record deleted successfully ...... ^_^ ");
            cout<<endl;

        }
        else
        {
            display_ui("   Record not deleted...... >_< ");
            cout<<endl;

        }
    }
}

int main()
{
    system("cls");
    string unch = "  WELCOME TO OUR PRODUCTIVITY TRACKER ";
    display_ui(unch);
    cout<<endl;
    cout<<"\n\t\t\t************************************************************************"<<endl<<endl;

    cout<<"\t\t\t\t\tPress Enter to Start the System  ^.^ ...";
    getch();
    ifstream read;
    read.open("num.txt");
    if (!read.fail())
    {
        read >> ID;
    }
    else
    {
        ID = 0;
    }
    read.close();
    cout<<"\n\n\n\t\t\t\t  Time Now : ";
    time_now();
    cout<<endl<<endl;
    int a, b = 1;
    while (b==1)
    {
        cout<<endl<<"\t\t1. Create New Task."<<endl;
        cout<<"\t\t2. Show Tasks."<<endl;
        cout<<"\t\t3. Delete Task."<<endl;
        cout<<"\t\t4. Delete All Tasks."<<endl;
        cout<<"\t\t5. Search Task."<<endl;
        cout<<"\t\t6. Exit"<<endl;

        display_ui("   Enter choice between ( 1 - 6 )... ");
        cout<<endl;

        cout<<endl<<"\t\tYour choice: ";
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
            cout<<endl;
            break;
        }
        case 3:
        {
            deleteData();
            cout<<endl;
            break;
        }
        case 4:
        {
            deletealldata();
            cout<<endl;
            break;
        }
        case 5:
        {
            searchData();
            cout<<endl;
            break;
        }
        case 6:
        {
            string unch ="\n\tExiting...\n\t\t\t\t THANK YOU FOR USING OUR PRODUCTIVITY TRACKER...  ^_^ ";
            display_ui(unch);
            cout<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t Developed By"<<endl<<"\n\t\t\t\t\t\t\t           -- Team HUMMINGBIRD\n\n "<<endl;
            b = 0;
            Sleep(2000);
            cout<<endl;
            break;
        }
        default:
        {
            display_ui( "Enter number between ( 1 - 6 ). Try again.... >_< " );
            cout<<endl<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        }
    }
    return 0;
}
