#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<fstream>
#include<string>
#include<stdlib.h>



using namespace std;
class student
{
	private:
		string name,roll_no,course,contact,mail,skill, address;
	public:
		
		void enter();           //use this to enter details of student
		void show();            //use this to see details of student
		void delete_record();   //use this to delete the details of student
		void update();          //use this to update the details of any student
		void search();          // use this to search the specific student through their roll no
		

};

void student::enter()
{
    system("cls");
    fstream inFile;
    cout << "Please enter student details .." << endl;
    cout << " " << endl;
    cout << " Enter Student Name : ";
    cin >> name;
    cout << " Enter Roll No. : ";
    cin >> roll_no;
    cout << " Enter Course : ";
    cin >> course;
    cout << " Enter mail Id : ";
    cin >> mail;
    cout << " Enter Contact No.: ";
    cin >> contact;
    cout << " Enter skill : ";
    cin >>skill;
    cout << " Enter Address: ";
    cin >> address;
    inFile.open("studentRecord.txt", ios::app | ios::out);//use this to open file in append mode or write mode
    inFile << "  " << name << "  " << roll_no << "  " << course << "  " << mail << "  " << contact << "  " << skill<< "  " << address <<"\n";  //add all details in file
    inFile.close();  //after open any file we need to close file so file closed here
}
void student::show()
{
    system("cls");
    fstream inFile;
    int total = 0;
    cout << "Student Recorded Data is" << endl;
    inFile.open("studentRecord.txt", ios::in);
    if (!inFile)
    {
        cout << "\n\n Data not found....";
        inFile.close();
    }
    else
    {
        inFile >> name >> roll_no >> course >> mail >> contact >> skill >> address;
        while (!inFile.eof())
        {
            cout<<"\n Student No. :" << total++ << endl;
            cout<<"\n Student Name : " << name << endl;
            cout<<"\n Student Roll No.: " << roll_no << endl;
            cout<<"\n Student Course : " << course << endl;
            cout<<"\n Student mail Id : " << mail << endl;
            cout<<"\n Student Contact No.: " << contact <<endl;
            cout<<"\n Student Skill : " << skill << endl;
            cout<<"\n Student Address : " << address << endl;
            inFile >> name >> roll_no >> course >> mail >> contact >> skill >> address;
        }
        if (total == 0)
        {
            cout << "\n\t\t Data not found....";
        }
    }
    inFile.close();
}
void student::update()
{
    system("cls");
    fstream file, file1;
    string rollno;
    int match = 0;
    cout << "Edit Student Details" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t No Data is Found....";  // id data not found then this message shown there
        file.close();
    }
    else
    {
        cout << "\n Enter the Student's Roll No. you wish to edit: ";
        cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> mail >> contact >> skill >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << mail << " " << contact << " " << skill << " " << address << "\n";
            }
            else
            {
                cout << "\n Enter Student Name: ";
                cin >> name;
                cout << "\n Enter Roll No.: ";
                cin >> roll_no;
                cout << "\n Enter Course: ";
                cin >> course;
                cout << "\n Enter E-mail Id: ";
                cin >> mail;
                cout << "\n Enter Contact No.: ";
                cin >> contact;
                cout<<"\n Student Skill : " ;
                cin>>skill;
                cout << "\n Enter Address: ";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << course << " " << mail << " " << contact << " " << skill << " " << address << "\n";
                match++;
            }
            file >> name >> roll_no >> course >> mail >> contact >> skill >> address;
            if (match == 0)
            {
                cout << "\n\t\t Student Not found, Invalid data!";
            }
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt");
    }
}
void student::search()
{
    system("cls");
    fstream file;
    int match = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "Search Student" << endl;
        cout << "\n No data Found...";
    }
    else
    {
        string rollno;
        cout << "Search Student" << endl;
        cout << "\n Enter Roll No. you wish to Search Student: ";
        cin >> rollno;
        file >> name >> roll_no >> course >> mail >> contact >> skill >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout<<" Student Name : " << name << endl;
                cout<<" Student Roll No. : " << roll_no << endl;
                cout<<" Student Course: " << course << endl;
                cout<<" Student E-mail Id: " << mail << endl;
                cout<<" Student Contact No. : " << contact <<endl;
                cout<<" Student Skillset : "<< skill << endl;
                cout<<" Student Address: " << address << endl;
                match++;
            }
            file >> name >> roll_no >> course >> mail >> contact >> skill >> address;
        }
        if (match == 0)
        {
            cout << (" Sorry ! Student Data Not Found.");
        }
        file.close();
    }
}
void student::delete_record()
{
    system("cls");
    fstream file, file1;
    string roll;
    int match = 0;
    cout << "Delete Student Details" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t Data not found.";
    }
    else
    {
        cout << "\n Enter Roll No. of Student which you want to delete data: ";
        cin >> roll;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> mail >> contact >> skill >> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << mail << " " << contact << " " << skill << " " << address << "\n";
            }
            else
            {
                match++;
                cout << "\n\t\t Operation Deletion Done";
            }
            file >> name >> roll_no >> course >> mail >> contact >> skill >> address;
        }
        if (match == 0)
        {
            cout << "\n\t\t Sorry ! Record not found.";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt");
    }
}
int main()
{
    
    student pr;
	int value;
	while(true)         // i created this because this gives benefit to not run program again and again you can entered value till you not exit program
	{
	cout<<"\n\n\n\n----Please Choose any Option----"<<endl;
	cout<<"\n   Press 1 to enter data"<<endl;
	cout<<"   Press 2 to show data"<<endl;
	cout<<"   Press 3 to search data"<<endl;
	cout<<"   Press 4 to update data"<<endl;
	cout<<"   Press 5 to delete data"<<endl;
	cout<<"   Press 6 to exit"<<endl;
	cin>>value;
	switch(value)
	{
		case 1:
			 pr.enter();
			break;
		case 2:
			pr.show();
			break;
		case 3:
			pr.search();
			break;
		case 4:
			pr.update();
			break;
		case 5:
			pr.delete_record();
			break;
		case 6:
			exit(0);
			break;
				
		default:
			cout<<"Invalid input...!!\n\n\n\n Please Press again Between [1 to 6].."<<endl;
			break;
	}	
}    
}
