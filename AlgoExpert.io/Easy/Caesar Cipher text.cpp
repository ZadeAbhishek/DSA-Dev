using namespace std;

int shift(int x, int y){
 //
 while(y--){
   if(x == 25) x = 0;
   else x++;  
}
 return (char)x + 'a';   
} 

string caesarCypherEncryptor(string str, int key) {
    // Write your code here.
    string temp = "";
    for(auto chr : str){
        int ascki =  chr - 'a';
        char nextChar = shift(ascki,key);
        temp.push_back(nextChar);
     }
  return temp;
}
