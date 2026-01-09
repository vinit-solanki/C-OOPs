#include<iostream>
using namespace std;

int main(){
    try{
        cout<<"Enter the size of array for dynamic allocation: ";
        int size;
        cin>>size;
        if(size<=0){
            throw length_error("Size must be positive");
        } else if(size>1000000){
            throw "Size too large to allocate";
        }
    } catch(length_error& e){
        cout<<"Length Error: "<<e.what()<<endl;
    } catch(const overflow_error& e){
        cout<<"Overflow Error: "<<e.what()<<endl;
    } catch(const exception& e){
        cout<<"An unexpected error occurred during allocation: "<<e.what()<<endl;
    } catch(const char *e){
        cout<<"Caught an exception: "<<e<<endl;
    } catch(...){
        cout<<"An unknown error occurred."<<endl;
    }

    cout<<"Program continues after exception handling."<<endl;
    return 0;
}