// Department maintains a student information.
// The file contains roll number, name, division and address.
// Allow user to add, delete information of student. Display information of particular employee.
// If record of student does not exist an appropriate message is displayed.
// If it is, then the system displays the student details.
// Use sequential file to main the data


#include<iostream>
#include<fstream>
using namespace std;

class student{
    public: 
        char name[10];
        int roll;
        void getdata(){
            cout<<"Enter the roll no and name "<<endl;
            cin>>roll>>name;
        }

        void putdata(){
            cout<<"The rollNo. : "<<roll<<" ,Name : "<<name<<endl;
        }
};

class file{

    fstream fp;

    public:
        void create(){
            student s;
            int choice ;
            fp.open("stu.dat",ios::out);
            do{
                s.getdata();
                fp.write((char * )&s, sizeof(s));
                cout<<"Add more : ";
                cin>>choice;
            }while(choice);
            fp.close();
        }

        void append(){
            int choice;
            student s;
            fp.open("stu.dat",ios::app);
            do{
                s.getdata();
                fp.write((char *)&s, sizeof(s));
                cout<<"add more: ";
                cin>>choice;
            }while(choice);
            fp.close();

        }

        void display(){
            student s;
            fp.open("stu.dat",ios::in);
            while(!fp.eof()){
                fp.read((char *)&s,sizeof(s));
                if(!fp.eof()){
                    s.putdata();
                }
            }
            fp.close(); 
        }

        void search(){
            student s;
            int flag = 0;
            int r;
            cout<<"Enter the rollNo. to be searched : ";cin>>r;
            fp.open("stu.dat",sizeof(s));
            while(!fp.eof()){
                fp.read((char *)&s, sizeof(s));
                if(!fp.eof() && s.roll == r){
                    flag = 1;
                    cout<<"Entered RollNo, found"<<endl;
                    s.putdata();
                    break;
                }
            }
        if(!flag){
            cout<<"Not found "<<endl;
            fp.close();
        }
        }

        void update(){
            student s;
            int flag = 0;
            cout<<"Enter the rollNo. to be updated : ";
            int r; cin>>r;
            fp.open("stu.dat",ios::in | ios::out);
            while(!fp.eof()){
                fp.read((char *)&s, sizeof(s));
                if(!fp.eof() && s.roll == r){
                    flag = 1;
                    cout<<" Enter the new data "<<endl;
                    s.getdata();
                    fp.seekp(-1*sizeof(s),ios::cur);
                    fp.write((char *)&s, sizeof(s));
                    break;
                }
            }
            if(!flag){
                cout<<"Not Found"<<endl;
            }
            fp.close();
        }

        void delete(){
            student s;
            int flag = 0;
            fstream fp1;
            cout<<"Enter rollNo. to be deleted";
            int r; cin>>r;
            fp.open("stu.dat",ios::in);
            fp1.open("temp.dat",ios::out);
            while(fp.read((char *)&s,sizeof(s))){
                if(s.roll != r){
                    flag = 1;
                    fp1.write((char *)&s, sizeof(s));
                }
            }
            if(!flag){
                cout<<"Not found"<<endl;
            }
            fp.close();
            fp1.close();
            remove("stu.dat");
            rename("temp.dat","stu.dat");
        }
};
int main()
{
    file f;
    int choice;
    do
    {
        cout << "\n1 create \n 2 display \n 3 Search \n 4 Append";
        cout << " \n 6 delete \n 7 Update";
        cout << "\n Enter choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            f.create();
            break;
        case 2:
            f.display();
            break;
        case 3:
            f.search();
            break;
        case 4:
            f.append();
            break;
        case 6:
            f.delete1();
            break;
        case 7:
            f.update();
            break;
        }
    } while (choice < 8);
}