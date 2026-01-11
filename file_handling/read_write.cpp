#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    
    // writing to a file
    ofstream fs;
    fs.open("sample.txt");
    fs<<"Hello, this is a sample file."<<endl;
    fs<<"This file is created using C++ file handling."<<endl;
    fs<<"End of file content."<<endl;
    fs.close();

    // reading from the file
    ifstream fin;
    fin.open("sample.txt");
    if(!fin){
        cout<<"Error opening file!"<<endl;
        return 1;
    }
    cout<<"File Content:"<<endl;
    string line;
    while(getline(fin, line)){
        cout<<line<<endl;
    }
    fin.close();
    return 0;
}