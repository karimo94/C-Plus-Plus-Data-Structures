#include <stdio.h>//input output operations like printf
#include <iostream>//working with text files
#include <fstream>//same deal as above
#include <math.h>//this includes math operations.


#define PI 3.14159265//pi is defined here for later use


using namespace std;

//classes...
/*lets create a class object called triangle.
In this class, we will be able to create a new Traingle and define its lengths and angles.
So that below in main(), if one angle is missing, or certain lengths are missing or given
we will be able to calculate anything for any condition.*/

/*the triangle class, will be abstract*/
class Triangle
{
    //constructors for any class in C++ are as follows.
    //this is a default constructor: Triangle();

//fields in c++ are as follows
    //syntax
    public:
    double sideA;//3 sides
    double sideB;
    double sideC;

    public: //3 angles
    double angleA;
    double angleB;
    double angleC;
    //here write virtual abstract methods



    public:
        virtual double CalculateAngle();
        virtual double CalculateLength();


};

//Also, to practise inheritance and polymorhpism, we will create another class called Right Traingle that derives from triangle
class RightTriangle::Triangle//done!
{

    //angleC = 90;//with right triangle trig, its only a matter of opposite/hyp (sin), adj/hyp (cos), opp/adj (tangent)

};



//functions...
    //these methods are to test reading and writing from textfiles using c++
    //A NOTE ON FUNCTIONS: ALL FUNCTIONS MUST BE DECLARED & INITIALISED BEFORE THE MAIN FUNCTION
    void Write()//methods in c++ are like this: type <name>(anything passed to it)
    {
        //lets try some reading, and writing with a text file...
        //open textfile
        ofstream textFile;
        textFile.open("c++demo.txt");//ios::out == ofstream myFile;...
        //if theres any existing text already, move to the next line and write so as to not overwrite the textfile
        //write to file
        textFile << "This is working!\n";
        textFile << "C++ is a very robust and powerful language, yet its very complex\n";
        textFile << "Another line you know... ;)";
        //close link
        textFile.close();
    }
    void Read()
    {
        //reading is done a bit weird...
        //create a string to assign to the text
        string line;
        ifstream txtFile("c++demo.txt");//open the file (ios::in)
        //if its open which is true...
        if(txtFile.is_open())
        {
            while(txtFile.good())//while file != null...
            {
                getline(txtFile, line);//getline gets the next line in the text file
                cout<<line<<endl;//writing the contents to the console window.
            }
            txtFile.close();//close the link.
        }
        else
        {
            cout<<"No such file exists";
        }
    }

int main()//main file of the program
{

//    for(int x = 0; x < 10; x++)
//    {
//        printf("aomar guerchaoui\n",x);//printf prints n times
//    }
//
//    int *pointer;//this is a pointer to an integer
//
//
//    int a ;//this is a new integer declaration/variable
//    int b = 64;
//
////    cout<<c + "\n";//this prints once
//    pointer = &a;//pointer points to variable a
//    *pointer = 10;//a is equal to the pointer
//
//    int c =  a*b;/*this should be after the pointer(s)
//                 since if you place it below "b", a has no reference*/
//    cout<<c;
//    cin.get();//keeps the window open
//    string->Contains() //the .Contains method
//    printf("Answer: %f, answer); -> %f is like {0}

    int i = 0;
    while(i<1)
    {
        double A;
        cout<<"Enter a side length A: ";
        cin>>A;//this line declaration is like int.Parse(Console.ReadLine());



        double B;
        cout<<"\nEnter a side length B: ";
        cin >>B;

        double C;
        cout<<"\nEnter a side length C: ";
        cin >>C;

        //double C = sqrt(pow(A,2)+pow(B,2));
        //finding angles...trig functions...law of cosines first

        double angleC = acos((pow(A,2) + pow(B,2) - pow(C,2))/(2*A*B))*180/PI;//*180/Pi is rad to deg conversion

        //cout<<"The longest side of the triangle is: "<<C;//pythagorean thm success!
        printf("The angle of side C is %f degrees\n", angleC);//law of cosines success!

        cout<<"::Now testing the text file writing and reading::\n";

        //testing the I/O functions
        Write ();
        Read ();
        //------------------------
        i++;
        if (i == 1)
        {
            string response;
            cout<<"\nwant to run again? y/n  ";
            cin>>response;
            if(response=="y")
            {
                i=0;
            }
            else
            {
                return 0;//exiting the program
            }
        }
    }

}

