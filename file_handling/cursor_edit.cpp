#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ofstream fs;
    fs.open("cursor_sample.txt");
    fs<<"1234567890"<<endl;
    fs.seekp(0); // Move cursor to the beginning
    fs.seekp(-3, ios::end); // Move cursor 3 positions before the end
    fs<<"XYZ"; // Overwrite last 3 characters
    fs.close();

    ifstream fin;
    fin.open("cursor_sample.txt");
    if(!fin){
        cout<<"Error opening file!"<<endl;
        return 1;
    }
    cout<<"Modified File Content:"<<endl;
    string line;
    while(getline(fin, line)){
        cout<<line<<endl;
    }
    fin.close();
    return 0;
}