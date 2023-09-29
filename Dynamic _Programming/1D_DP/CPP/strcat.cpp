// Implement you own strcat() function. Dont use string header.
#include<iostream>
using namespace std;


void strcat(char *string,const char* add){
    
    /* get to last point of string */
    int i;
    for(i = 0 ; string[i] != '\0' ; i++);

    /* add curr string to new string */
    int j;
    for(j = 0 ; add[j] != '\0'; j++){
        string[i+j] = add[j];
    }
    string[i+j] = '\0';
    
    return;
}


int main(){
    char *string = new char[100];
    string[0] = '\0';
    strcat(string,"Abhishek ");
    strcat(string,"add this.");
    cout<<string<<"\n";
    return 0;
}