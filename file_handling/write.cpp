#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream fout;
    // if file does not exist, it will be created
    fout.open("example.txt");
    fout<<"This is a sample text written to the file."<<endl;
    fout<<"Writing another line to the file."<<endl;
    fout.close();
    cout<<"Data written to file successfully."<<endl;
    return 0;
}