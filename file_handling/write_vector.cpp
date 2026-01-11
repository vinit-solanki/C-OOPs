#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements in the vector: ";
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>vec[i];
    }
    // for wrting a vector to a file
    ofstream fout;
    fout.open("vector_data.txt");
    fout<<"Original Vector Data:"<<endl;
    for(int i=0;i<n;i++){
        fout<<vec[i]<<" ";
    }
    fout<<endl;
    fout<<"Sorted Vector Data:"<<endl;
    sort(vec.begin(), vec.end());
    for(int i=0;i<n;i++){
        fout<<vec[i]<<" ";
    }
    fout<<endl;

    fout.close();
    cout<<"Vector data written to file successfully."<<endl;
    return 0;
}