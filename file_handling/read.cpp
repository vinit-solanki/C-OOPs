#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ifstream fin;
    fin.open("example.txt");
    if(!fin){
        cout<<"Error opening file!"<<endl;
        return 1;
    }
    cout<<"-----------------------"<<endl;
    cout<<"Reading file character by character:"<<endl;
    char c;
    c = fin.get();
    while(!fin.eof()){
        cout<<c;
        c = fin.get();
    }
    cout<<"File reading completed."<<endl;
    fin.close();

    cout<<"-----------------------"<<endl;
    string line;
    fin.open("example.txt");
    cout<<"Reading file line by line:"<<endl;
    while(getline(fin, line)){
        cout<<line<<endl;
    }
    cout<<"File reading completed."<<endl;
    fin.close();
    return 0;
}