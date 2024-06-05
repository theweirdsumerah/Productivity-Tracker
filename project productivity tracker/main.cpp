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
        Sleep(100);
    }
    cout<<"\n\n\n\t\t\t************************************************************************"<<endl<<endl;
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
    cout<<"\n\n\n\t\t\t\t\t";
    cout<<" WELLCOME TO Your Productivity Tracker "<<endl;
    cout<<"\n\n\t\t\t************************************************************************"<<endl<<endl;

    cout<<"\n\n\t\t\t\t  Now Time : ";
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
    display_ui("\n\tDo you want to add more task? y or n : ");
    cin>> ch;

    if(ch == 'y'||ch == 'Y')
    {
        addTodo();
    }
    else
    {
        display_ui( "\n\tTask has been added successfully.... ^.^ ");
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
    cout<<"\n\n\n\t\t\t\t\t";
    cout<<" WELLCOME TO Your Productivity Tracker "<<endl;
    cout<<"\n\n\t\t\t************************************************************************"<<endl<<endl;

    cout<<"\n\n\t\t\t\t  Now Time : ";
    time_now();
    cout<<"\n"<<endl;

    todo todo;
    ifstream read;
    read.open("tasks.txt");
    cout << "\t\t\t------------------Your current Tasks in the list--------------------\n\n";
    if(!read)
    {
        display_ui("\n\tYou have no tasks..... >_< ");
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
    cout<<"\n\n\n\t\t\t\t\t";
    cout<<" WELLCOME TO Your Productivity Tracker "<<endl;
    cout<<"\n\n\t\t\t************************************************************************"<<endl<<endl;

    cout<<"\n\n\t\t\t\t  Now Time : ";
    time_now();
    cout<<"\n"<<endl;

    ifstream read;
    read.open("tasks.txt");

    if(!read)
    {
        display_ui("\n\tYou have no tasks..... >_< ");
    }
    else
    {
        int id;
        cout << "\n\tEnter task id : ";
        cin >> id;
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
                print(todo);
                return id;
            }
        }
    }
    return 0;
}

void deleteData()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t";
    cout<<" WELLCOME TO Your Productivity Tracker "<<endl;
    cout<<"\n\n\t\t\t************************************************************************"<<endl<<endl;

    cout<<"\n\n\t\t\t\t  Now Time : ";
    time_now();
    cout<<"\n"<<endl;

    ifstream read;
    read.open("tasks.txt");

    if(!read)
    {
        display_ui("\n\tYou have no tasks..... >_< ");
    }

    else
    {
        int id = searchData();
        display_ui("\n\tDo you want to delete this task? y or n : ");
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
        display_ui("\n\tTask deleted successfuly..... +_+ *_* ");
        }
        else
        {
        display_ui("\n\tRecord not deleted ..... >_< ");
        }
    }
}

void deletealldata()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t";
    cout<<" WELLCOME TO Your Productivity Tracker "<<endl;
    cout<<"\n\n\t\t\t************************************************************************"<<endl<<endl;

    cout<<"\n\n\t\t\t\t  Now Time : ";
    time_now();
    cout<<"\n"<<endl;

    ifstream read;
    read.open("tasks.txt");

    if(!read)
    {
        display_ui("\n\tYou have no tasks..... >_< ");
    }

    else
    {
        display_ui("\n\tAre you sure you want to delete all data? y or n : ");

        char choice;
        cin>>choice;

        if(choice == 'y')
        {
            remove("tasks.txt");
            remove("num.txt");
            display_ui("Record deleted successfully ...... ^_^ ");

        }
        else
        {
        display_ui("\n\tRecord not deleted...... >_< ");
        }
    }
}

int main()
{
    string unch = "  WELLCOME TO OUR PRODUCTIVITY TRACKER ";
    display_ui(unch);
    cout<<"\t\t\t\t\t Press Enter to Enter the System  ^.^ .....";
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
    cout<<"\n\n\n\t\t\t\t  Now Time : ";
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

        cout<<endl<<"\t\tEnter choice between 1 - 6."<<endl;
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
            cout<<"\t\t\t\t\t\t\t\t Developed By"<<endl<<"\n\t\t\t\t\t\t\t           -- Team HUMMINGBIRD\n\n "<<endl;
            b = 0;
            Sleep(2000);
            cout<<endl;
            break;
        }
        default:
        {
            display_ui( "Enter number between 1 - 6. Try again.... >_< " );
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        }
    }
    return 0;
}
