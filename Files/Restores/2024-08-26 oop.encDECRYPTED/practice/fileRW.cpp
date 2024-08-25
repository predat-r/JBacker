#include <iostream>
#include <fstream>
using namespace std;
void writefile(ofstream &file, int x); // file writing function
int readfile(ifstream &file);          // file reading function that returns an integer after reading
int main()
{
    ofstream ofile("integer.txt"); // opening file to output to  ( this file must be created by you and ideally kept in same folder as code)
    writefile(ofile, 54);          // writing to file
    ofile.close();                 //closing file

    ifstream infile("integer.txt"); // opening and creating refernece to file
    int y = readfile(infile);       // reading file
    cout << y;
    infile.close();                  //closing file
}

void writefile(ofstream &file, int x)
{
    file << x; // writing x integer that came from main to file
}
int readfile(ifstream &file)
{
    int x;     // creating integer x
    file >> x; // storing value read from file to x

    return x; // return x
}