#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream>

using namespace std;

fstream write_info;

// Function Prototype 
void welcome();
void Disp_stud_info();
void Disp_teach_info();
void Disp_cours_info();
void Registration();
void Stud_register();
void Teach_register();
void Cours_register();
void Update_info();
void Update_student();
void Update_teacher();
void Update_course();
void Delete_info();
void switcher();
void Developers();
void Stud_File_reg();
void Stud_File_read();
void Stud_File_del();
// Global Variables
int user_choice,del_stud_id;
int stud_size=0,teach_size=0,cour_size=0,S=0;
int pass_del_i,k=0,fiel_stud_size=0,p_i;
bool id_found=false;

//Creating Structure
struct Students {
 int stud_size = 0;
 int id;
 string Full_name;
 char section;
 int batch;
};
//Dynamic Pointer
Students* student = new Students[100];
Students* pointAt = student;
struct Students_File{
	 int file_id;
 string file_Full_name;
 char file_section;
 int file_batch;
};

Students_File* stud_file = new Students_File[100];

struct Teachers {
	int id;
	string Full_name;
	string Edu_level;
	char Section;
};
Teachers* teacher = new Teachers[1];

struct Courses {
	int id;
	int course_name;
	int credit_hour;
};
Courses* course = new Courses[1];

// Back and Forth Switcher
void switcher(){
	switch(user_choice){
	case 1 :
	Disp_stud_info();
	break;
	case 2 :
	Disp_teach_info();
	break;
	case 3 :
	Disp_cours_info();
	break;
	case 4 :
	Registration();
	break;
	case 5 : 
	Update_info();
	break;
	case 6 :
	Delete_info();
	break;
	case 7 :
	Developers();
}
}
void Stud_File_reg(){
	write_info.open("student_management_info.txt", ios::app );
			write_info << student[S].id<<"\t\t"<<student[S].Full_name<<"\t\t"<<student[S].section<<"\t\t"<<student[S].batch<<"\n";		
		    write_info.close();
		    Stud_File_read();
}

void Stud_File_read(){
		string student_info;
		fiel_stud_size=0;
	write_info.open("student_management_info.txt", ios::in);
	  if (write_info.is_open()) {
		while(getline(write_info,student_info)) {
			fiel_stud_size++;
			k = fiel_stud_size;
		                  stringstream st(student_info);
		                  int read_id,read_batch;
		                  string read_full_name;
		                  char  read_section;
		               st>>read_id>>read_full_name>>read_section>>read_batch;
                    stud_file[k].file_id = read_id;
                    stud_file[k].file_Full_name = read_full_name;
                    stud_file[k].file_section = read_section;
                    stud_file[k].file_batch = read_batch;
                    k++;
		              }
		       write_info.close();     
}
else{
	cout << "New Data Base !"<<endl;
}
}
void Stud_File_update(){
	remove("student_management_info.txt");
	write_info.open("student_management_info.txt", ios::app );
	for (int i=1; i<=fiel_stud_size;i++){
			write_info << stud_file[i].file_id<<"\t\t"<<stud_file[i].file_Full_name<<"\t\t"<<stud_file[i].file_section<<"\t\t"<<stud_file[i].file_batch<<"\n";		
		    write_info.close();
		    Stud_File_read();
		}
}
void Stud_File_del(){
		remove("student_management_info.txt");
	write_info.open("student_management_info.txt", ios::app );
	if (del_stud_id != stud_file[pass_del_i].file_id){
	for (int i=1; i<=fiel_stud_size;i++){
			write_info << stud_file[i].file_id<<"\t\t"<<stud_file[i].file_Full_name<<"\t\t"<<stud_file[i].file_section<<"\t\t"<<stud_file[i].file_batch<<"\n";		
		    write_info.close();
		    Stud_File_read();
		}
	}

}

void welcome(){
 cout << "#############################################"<<endl;
 cout << "# Welcome to ACT Student Managment System ! #"<<endl;
 cout << "#############################################"<<endl;
 cout << " 1 . Student Information"<<endl;
 cout << " 2 . Teacher Information"<<endl;
 cout << " 3 . Course Information"<<endl;
 cout << " 4 . Registration "<<endl;
 cout << " 5 . Update Information"<<endl;
 cout << " 6 . Delete Information "<<endl;
 cout << " 7 . Developers "<<endl;
 cout << "-------------------------------------"<<endl;
 cout << " Enter your Choice No : ";
 cin >> user_choice ;
  cout << "-------------------------------------"<<endl;
 system("cls");
 switcher();
}

void Disp_stud_info(){

	bool id_Found=false;
	int disp_choice, info_id , try_back;
   cout << "############################"<<endl;
   cout << "#    STUDENT INFORMATION    #"<<endl;
   cout << "############################"<<endl;
   cout << " 1 . Search by ID"<<endl;
   cout << " 2 . All Student Information"<<endl;
   cout << " 0 . Return "<<endl;
    cout << "-------------------------------------"<<endl;
   cout << " Enter your Choice No : ";
   cin  >> disp_choice;
   system("cls");
   switch (disp_choice) {
   	case 1 :  
   cout << "##################"<<endl;
   cout << "#  SEARCH BY ID  #"<<endl;
   cout << "##################"<<endl;
   cout << " Enter the Student id : ";
   cin >> info_id;
   system("cls");
    cout << " Searching Please Wait ..."<<endl;
	sleep(1);
   int pass_i;
   for (int i=1; i <= fiel_stud_size; i++){	
   if (info_id == stud_file[i].file_id ){
   	id_Found = true;
   	pass_i = i;
   	break;
   }
  }
  if (id_Found == true){
   system("cls");
   
   cout << "############################"<<endl;
   cout << "#    STUDENT INFORMATION   #"<<endl;
   cout << "############################"<<endl;
   //for (int i=0;i<file_stud_size)
   cout << "ID : " << stud_file[pass_i].file_id << endl;
   cout << "Section : " <<stud_file[pass_i].file_section<<endl;
   cout << "Student Name : " <<stud_file[pass_i].file_Full_name << endl;
   cout << "Batch : " << stud_file[pass_i].file_batch<< endl;
   cout << "-------------------------------------"<<endl;
   cout << "1 . Try Another "<<endl;
   cout << "0 . Return "<<endl;
   cout << "-------------------------------------"<<endl;
   cout << " Enter your Choice No : ";
	cin >> try_back;
	system("cls");
	switch(try_back){
		case 1 : 
		    Disp_stud_info();
		case 0 :
		    welcome();
	}
}
else {
	cout << "----------------------------------"<<endl;
	cout << " There is No Student in this ID "<<endl;
	cout << "----------------------------------"<<endl;
	cout << " 1 . Try again " << endl;
	cout << " 0 . Return " << endl;
	 cout << "-------------------------------------"<<endl;
    cout << " Enter your Choice No : ";
	cin >> try_back;
	system("cls");
	switch(try_back){
		case 1 : 
		    Disp_stud_info();
		case 0 :
		    welcome();
	}
  }
  
      break;   
      case 2 :    
    stud_size=10;
       		if ( fiel_stud_size == 0 ){
       			int add_choice;
       	 cout << "-------------------------------------"<<endl;
       	cout << "The List is Empty , Please add some First"<<endl;
       	 cout << "-------------------------------------"<<endl;
       	cout << "1 . Add New Student"<<endl;
       	cout << "0 . Return"<<endl;
       	 cout << "-------------------------------------"<<endl;
           cout << " Enter Your Choice : ";
       	cin >> add_choice;    	
       	 cout << "-------------------------------------"<<endl;
       	system("cls");
       	switch(add_choice){
       		case 1 :
       		Stud_register();
       	}
  	}    
       else {
       	int all_stu_info_return;
   cout << "---------------------------------------"<<endl;
   cout << "##############################"<<endl;
   cout << "#  All  STUDENT INFORMATION    #"<<endl;
   cout << "##############################"<<endl;
       	for (int i = 1; i <= fiel_stud_size; i++){
   cout << "ID : " << stud_file[i].file_id << endl;
   cout << "Section : " <<stud_file[i].file_section<<endl;
   cout << "Student Name : " <<stud_file[i].file_Full_name << endl;
   cout << "Batch : " << stud_file[i].file_batch<< endl;
    cout << "-------------------------------------"<<endl;
       	}
   cout << " 1 . Back "<<endl;
   cout << " 0 . Return"<<endl;
    cout << "-------------------------------------"<<endl;
   cout << " Enter Your Choice : ";
   cin >> all_stu_info_return;
   system("cls");
   switch(all_stu_info_return){
   	case 1 : 
   	Disp_stud_info();
   	break;
   	case 0 : 
   	welcome();
   	break;
   }
    }
    case 0 :
    welcome();
    break;
   }
}

void Disp_teach_info(){
	
	int disp_choice;
	int info_id ;
	int try_back;
	cout << "Coming Soon ..."<<endl;
	sleep(2);
	system("cls");
	welcome();

	/*
   cout << " 1 . Search by ID"<<endl;
   cout << " 2 . All Teacher Information"<<endl;
   cin  >> disp_choice;
   system("cls");
   switch (disp_choice) {
   	case 1 :  
   cout << " Enter the Teachers id "<<endl;
   cin >> info_id;
   system("cls");
   for (int i=0; i <= sizeof(student); i++){	
   if (info_id == student[i].id){
   cout << "ID : " << student[i].id << endl;
   cout << "Section : " <<student[i].section<<endl;
   cout << "Student Name : " << student[i].Full_name << endl;
   cout << "Batch : " << student[i].batch<< endl;
   cout << " 1 . Try again " << endl;
   cout << " 0 . Return " << endl;
	cin >> try_back;
	system("cls");
	switch(try_back){
		case 1 : 
		    Disp_teach_info();
		case 0 :
		    welcome();
	}
}
else {
	cout << " There is No Student in this ID "<<endl;
	cout << " 1 . Try again " << endl;
	cout << " 0 . Return " << endl;
	cin >> try_back;
	system("cls");
	switch(try_back){
		case 1 : 
		    Disp_stud_info();
		case 0 :
		    welcome();
	}
  }
}
      break;   
       case 2 :    
       		if ( stud_size == 0 ){
       			int add_choice;
       	cout << "The List is Empty , Please add some First"<<endl;
       	cout << "1 . Add New Student"<<endl;
       	cin >> add_choice;    	
       	system("cls");
       	switch(add_choice){
       		case 1 :
       		Stud_register();
       	}
  	}    
       else {
       	for (int i = 1; i <= stud_size; i++){
   cout << "ID : " << student[i].id << endl;
   cout << "Section : " <<student[i].section<<endl;
   cout << "Student Name : " << student[i].Full_name << endl;
   cout << "Batch : " << student[i].batch<< endl;   	
     }
    }
  } */
}

void Disp_cours_info(){
	cout << "Coming Soon ..."<<endl;
	sleep(2);
	system("cls");
	welcome();
}



void Registration(){
	int Reg_choice;
	cout << "##############################"<<endl;
    cout << "#    STUDENT REGISTRATION    #"<<endl;
    cout << "##############################"<<endl;
	cout << " 1 . Student Registration " << endl;
	cout << " 2 . Teacher Registration " << endl;
	cout << " 3 . Add New Course " << endl;
	cout << "---------------------------------------"<<endl;
	cout <<" Enter yor choice : ";
	cin >> Reg_choice;
	cout << "---------------------------------------"<<endl;
	system("cls");
	switch (Reg_choice){
		case 1 :
		Stud_register();
		break;
		case 2 :
		Teach_register();
		break;
		case 3 :
		Cours_register();
		break;		
	}
}

void Stud_register(){
	int add_option,Dup_check;
	bool Bol_dup_check;
	cout << "##############################"<<endl;
    cout << "#    STUDENT REGISTRATION    #"<<endl;
    cout << "##############################"<<endl;
	cout << "Enter Student ID : ";
	cin  >> student[S].id;
		int dup_Count = 0;
	Dup_check = student[S].id;
		for (int i=0; i <= stud_size;i++ ){
		while (Dup_check == student[i].id  ){
			dup_Count++;
			break;
		}
		}
		if (dup_Count == 2){
			system("cls");
	 cout << "-------------------------------------"<<endl;
	cout << " This ID Already Exists !!! "<<endl;
	cout << "---------------------------------------"<<endl;
	sleep(2);
	system("cls");
	Stud_register();
		}
		else {
	cout << "Enter Student Name : ";
	cin >> student[S].Full_name;
	cout << "Enter Student section : ";
	cin >> student[S].section;
	cout << "Enter Student Batch : ";
	cin>> student[S].batch;
	stud_size++;
	Stud_File_reg();
	Stud_File_read();
	S++;
	cout << "---------------------------------------"<<endl;
	cout <<" 1 .  Add Another Student"<<endl;
	cout << "0 . Exist : "<<endl;
	cout << "---------------------------------------"<<endl;
	cout << " Enter Your Choice : ";
	cin >> add_option;
	cout << "---------------------------------------"<<endl;
	system("cls");
	switch (add_option){
		case 0 : 
		welcome();
		case 1 :
		Stud_register();
}
}
}
void Teach_register(){
		cout << "Coming Soon ..."<<endl;
	sleep(2);
	system("cls");
	welcome();
}
void Cours_register(){
		cout << "Coming Soon ..."<<endl;
	sleep(2);
	system("cls");
	welcome();
}
void Update_info(){
	int upd_choice;
	cout << "############################"<<endl;
    cout << "#    UPDATE INFORMATION    #"<<endl;
    cout << "############################"<<endl;
	cout << "1 . Update Student info"<<endl;
	cout << "2 . Update Teacher info "<<endl;
	cout << "3 . Update Course info"<<endl;
	 cout << "-------------------------------------"<<endl;
	cout << " Enter your Choice No : ";
	cin >> upd_choice;
	cout << "---------------------------------------"<<endl;
	system("cls");
	switch(upd_choice){
		case 1 :
		Update_student();
		break;
		case 2 : 
		Update_teacher();
		break;
		case 3 :
		Update_course();
		break;
	}
}
void Update_student(){
	int new_ID;
	string New_fullName;
	int new_Batch;
	char new_Section;
	int upd_type,old_stu_id;
	
	cout << "############################"<<endl;
    cout << "#    UPDATE INFORMATION    #"<<endl;
    cout << "############################"<<endl;
	cout << "Enter the Student ID : ";
	cin >> old_stu_id;
	cout << "---------------------------------------"<<endl;
	system("cls");
cout <<fiel_stud_size;
	for (int i=1; i <= fiel_stud_size;i++ ){
		if (old_stu_id == stud_file[i].file_id){
			id_found=true;
			p_i=i;
		cout<<stud_file[i].file_id<<endl;
	}
}
		if(id_found==true){
	cout << "############################"<<endl;
    cout << "#    UPDATE INFORMATION    #"<<endl;
    cout << "############################"<<endl;
	cout << "What did You want to Update"<<endl;
	cout << "1 . ID"<<endl;
	cout << "2 . Full Name"<<endl;
	cout << "3 . Batch"<<endl;
	cout << "4 . Section"<<endl;
	cout << "5 . All"<<endl;
	cout << "---------------------------------------"<<endl;
	cout << " Enter Your Choice : ";
	cin >> upd_type;
	system("cls");
	cout << "---------------------------------------"<<endl;
	switch (upd_type){
	case 1 :
	cout << "############################"<<endl;
    cout << "#    UPDATE INFORMATION    #"<<endl;
    cout << "############################"<<endl;
	cout << "Enter New Student ID : ";
	cin >> new_ID;
	stud_file[p_i].file_id = new_ID;
	cout << "Updating ...."<<endl;
   sleep(2);
	cout << "New ID is Successfully Updated ..."<<endl;
	sleep(2);
	system("cls");
	
	welcome();
	break;
	case 2 : 
	cout << "############################"<<endl;
    cout << "#    UPDATE INFORMATION    #"<<endl;
    cout << "############################"<<endl;
	cout << "Enter New Student Full Name : ";
	cin >> New_fullName;
	stud_file[p_i].file_Full_name = New_fullName;
	cout << "Updating ...."<<endl;
    sleep(2);
	cout << "New Full Name is Successfully Updated !!!"<<endl;
	sleep(2);
	cout <<"/n";
	system("cls");
	welcome();
	break;
	case 3 :
	cout << "############################"<<endl;
    cout << "#   UPDATE  INFORMATION    #"<<endl;
    cout << "############################"<<endl;
	cout << " Enter New Batch "<<endl;
	cin >> new_Batch;
	stud_file[p_i].file_batch = new_Batch;
	cout << "Updating ...."<<endl;
	 sleep(2);
	cout << "New Batch is Successfully Updated ..."<<endl;
	sleep(2);
	system("cls");
	welcome();
	break;
	case 4 :
	cout << "############################"<<endl;
    cout << "#   UPDATE  INFORMATION    #"<<endl;
    cout << "############################"<<endl;
	cout << " Enter New Section : ";
	cin >> new_Section;
	cout << endl;
	stud_file[p_i].file_section = new_Section;
	cout << "Updating ...."<<endl;
    sleep(2);
	cout << "New Information is Successfully Updated ..."<<endl;
	sleep(2);
	system("cls");
	welcome();
	break;
	case 5 :
	cout << "############################"<<endl;
    cout << "#   UPDATE  INFORMATION    #"<<endl;
    cout << "############################"<<endl;
	cout << "Enter New Student ID : ";
	cin >> new_ID;
	stud_file[p_i].file_id=new_ID;
	cout << "Enter New Full Name : ";
	cin >>New_fullName;
	stud_file[p_i].file_Full_name=New_fullName;
	cout << "Enter New Batch : ";
	cin >>new_Batch;
	stud_file[p_i].file_batch=new_Batch;
	cout << "Enter New Section : ";
	cin >>new_Section;
	stud_file[p_i].file_section = new_Section;
	cout << "Updating ...."<<endl;
    sleep(2);
	cout << "New Information is Successfully Updated ..."<<endl;
	sleep(2);
	system("cls");
	welcome();
	break;
		}
		}
	else 
	{
		/*	ID_notMuched << new_ID << New_fullName << new_Batch << new_Batch << new_Section; */
			int st_in_return;
			cout << "############################"<<endl;
            cout << "#   UPDATE  INFORMATION    #"<<endl;
            cout << "############################"<<endl;
			cout << "This ID is Not Found !"<<endl;
			cout << "---------------------------------------"<<endl;
			cout << " 1 . Try again "<<endl;
			cout << " 0 . Go Back "<<endl;
			cout << "---------------------------------------"<<endl;
			cout << " Enter Your Choice : ";
			cin >> st_in_return;
			cout << "---------------------------------------"<<endl;
			system("cls");
			switch (st_in_return){
				case 1 : 
			Update_info();
			break;
			    case 0 :
			welcome();
			break;
			}
	}
}
void Update_teacher(){
}
void Update_course(){
}
void Delete_info(){
	int del_choice,id_Found_del;
	cout << "############################"<<endl;
    cout << "#   DELETE  INFORMATION    #"<<endl;
    cout << "############################"<<endl;
    cout <<" 1 . Delete by ID"<<endl;
    cout <<" 2 . Delet All "<<endl;
    cout <<" 0 . Return "<<endl;
    cout << "---------------------------------------"<<endl;
	cout << " Enter Your Choice : ";
	cin >> del_choice;
	cout << "---------------------------------------"<<endl;
	system("cls");
	switch (del_choice){
		case 1 : 
	cout << "############################"<<endl;
    cout << "#    DELETE INFORMATION    #"<<endl;
    cout << "############################"<<endl;
	cout << "Enter Student ID : ";
	cin >> del_stud_id;
	system("cls");
    cout << " Searching Please Wait ..."<<endl;
	sleep(2);
	for (int i=1; i <= fiel_stud_size; i++){	
   if (del_stud_id == stud_file[i].file_id){
   	id_Found_del = true;
   	pass_del_i = i;
   	break;
   }
  }
  if (id_Found_del == true) {
  	cout<<" Deleting  Student Information ..."<<endl;
  	sleep(2);
    //  Students = delete Students;
  	Stud_File_del();
  	cout << " Seccesfully Deleted "<<endl;
  	sleep(1);
  	Stud_File_read();
  	system("cls");
  	welcome();
  }
  else {
  	cout << "---------------------------------------"<<endl;
  	cout << "There is no Student in this ID ! "<<endl;
  	cout << "---------------------------------------"<<endl;
  	sleep(2);
  	system("cls");
  	welcome();
  }
  case 2 :
  cout<<" Deleting All Student Information ..."<<endl;
  	remove("student_management_info.txt");
  	Stud_File_read();
	  sleep(2);
  system("cls");
  welcome();
  break;
  
	}
}
void Developers(){
	int dev_back;
	cout << "############################"<<endl;
    cout << "#   PROGRAMME  DEVELOPERS  #"<<endl;
    cout << "############################"<<endl;
	cout << " 1 . Abdulhakim Mohammed"<<endl;
	cout << " 2 . Amanuel Addisu"<<endl;
	cout << " 3 . Bamlak Tachbele"<<endl;
	cout << " 4 . Bethel Wondwossen"<<endl;
	cout << " 5 . Natnael Demile"<<endl;
	cout << "---------------------------------------"<<endl;
	cout << " THANK YOU !!! "<<endl;
	cout << "---------------------------------------"<<endl;
	cout << " 0 . Return "<<endl;
	cout << "----------------------"<<endl;
	cout << " Enter Your Choice : ";
	cin >> dev_back;
	system("cls");
	switch (dev_back){
		case 0 : 
		welcome();
	}
}


int main() {
		Stud_File_read();
	welcome();
}