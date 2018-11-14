/*
* Authors:			Zak Francis, HONORS
* Class: 		    CS-2250-TJAC
* Last Modified:	November 2018
*
* Description: This program is a menu driven application for
* Small Troy University. It has three options. A grade calculator
* which takes input from the user and outputs the averages to a
* file. A bookstore function that will tell you what you can
* afford based on a user input price. Lastly, a lowest grade
* calculator that will return the lowest grade from an input file
*/
#include <iostream>
#include <fstream>

using namespace std;

void grade_calculator(int,int,int); //function prototype
void bookstore(int);                //function prototype
int lowest_grade();                 //function prototype

int main()
{
    int menuInput;                  //Stores the menu number that the user inputs
    char yesNo;                     //do-while controller variable

    //this do-while loop allows the program to be re-ran as many times as the user wants
    do{
        //Displays the program welcome text
        cout<<"================================================================"<<endl;
        cout<<"=========== Small Trojan University Employee Program ==========="<<endl;
        cout<<"================================================================"<<endl;
        cout<<"\n Please choose one of the options below"<<endl;
        cout<<"1. Grade Calculator\n";
        cout<<"2. Book Store\n";
        cout<<"3. University Lowest Grade\n\n";

        cin>>menuInput; //assigns user input to menuInput

        //Input validation for menuInput
        while(menuInput < 1 || menuInput > 3){
            cout<<"Invalid input: Please choose option 1, 2, or 3 : ";
            cin>>menuInput;
        }

        //Switch menu for the 3 different menu options
        switch(menuInput){
        case 1: //case 1 is for Grade Calculator
            int classrooms, stuPerClass, gradesPerStu;  //variables to hold user input
            cout<<"Please enter how many classrooms you have (1-2): ";
            cin>>classrooms;

            //Input validation for classrooms
            while(classrooms<1||classrooms>2){
                cout<<"Invalid Input: Please enter a number between 1 and 2: ";
                cin>>classrooms;
            }

            cout<<"Please enter how many students you have in each class (1-2): ";
            cin>>stuPerClass;

            //Input validation for stuPerClass
            while(stuPerClass<1||stuPerClass>2){
                cout<<"Invalid Input: Please enter a number between 1 and 2: ";
                cin>>stuPerClass;
            }

            cout<<"Please enter the amount of grades you need to enter for each student (1-3): ";
            cin>>gradesPerStu;

            //Input validation for gradesPerStu
            while(gradesPerStu<1||gradesPerStu>3){
                cout<<"Invalid Input: Please enter a number between 1 and 3: ";
                cin>>gradesPerStu;
            }

            grade_calculator(classrooms,stuPerClass,gradesPerStu);  //function call to grade_calculator()
            break;

        case 2: //case 2 is for the bookstore
            int money;  //variable to hold user input
            cout<<"Please enter how much money you are willing to spend: ";
            cin>>money; //assign input to variable

            //Input validation for money
            while(money<0){
                cout<<"Invalid Input: Please enter a positive number: ";
                cin>>money;
            }

            bookstore(money);   //function call to bookstore()
            break;

        case 3: //case 3 is for the lowest grade
            cout<<"The lowest grade in the university is "<<lowest_grade(); //cout with a function call to lowest_grade()
            break;
        }

        //do-while controller input
        cout<<"\n Would you like to run the program again? (Y/N): ";
        cin>>yesNo;
    }while(toupper(yesNo)=='Y');    //do-while loop end
    return 0;
}

/*
* The grade_calculator() function takes three arguments and takes user
* input for certain students grades. It then writes the results to a
* file
*/
void grade_calculator(int cls,int stuPerCls, int graPerStu){

    ofstream outfile;
    outfile.open("Gradesinfo.txt");
    int grade,studentAcc=0,classAcc=0,universityAcc=0;
    for(int i=1;i<=cls;i++){
        for(int j=1;j<=stuPerCls;j++){
            for(int k=1;k<=graPerStu;k++){
                cout<<"Classroom "<<i<<" Introduce grade "<<k<<" of student "<<j<<":";
                cin>>grade;
                studentAcc+=grade;
            }
            classAcc+=studentAcc;
            outfile<<"Average grade of student "<<j<<" in class "<<i<<": "<<studentAcc/graPerStu<<endl;
            studentAcc=0;
        }
        universityAcc+=classAcc;
        outfile<<"Average grade of class "<<i<<": "<<classAcc/(stuPerCls*graPerStu)<<endl;
        classAcc=0;
    }
    outfile<<"Average grade of the university: "<<universityAcc/(stuPerCls*cls)<<endl;
    outfile.close();
}

/*
* The bookstore() function will print out what you
* are able to buy based on the argument sent to the
* function
*/
void bookstore(int cash){

    // if-elseif loop that will printout the correct statement based on cash value
    if(cash < 1)
        cout<<"You can not buy anything\n";
    else if(cash<2)
        cout<<"You can buy a comic book $1\n";
    else if(cash<10)
        cout<<"You can buy a comic book $1 or Sports Journal $2\n";
    else if(cash<15)
        cout<<"You can buy a Comic Book $1, Sports Journal $2, or Novel $10\n";
    else
        cout<<"You can buy a Comic Book $1, Sports Journal $2, Novel $10, or Science Book $15\n";
}

/*
* The lowest_grade() function reads integers in
* from a file and returns the lowest value
*/
int lowest_grade(){
    int lowestGrade=100,input;  //lowestGrade is variable that holds the current lowest grade, input is used to store file input
    ifstream infile;            //input file
    infile.open("grades.txt");

    infile>>lowestGrade;
    while(infile>>input){
        if(input<lowestGrade)
            lowestGrade=input;
    }

    infile.close();
    return lowestGrade;
}
