class Solution {
public:
    string getHint(string secret, string guess) {
     
     int count[128] = { 0 }; // arr to store counbt of each char in string
        
     int bull = 0 , cow = 0;   // counter 
        
     for(auto x : secret) count[(int)x]++; // count number of char in string
        
     for(auto x = 0 ; x < size(secret) ; x++)
     {
         if(secret[x] == guess[x]) {  // cmp to string irr wise and if they are same
             
             if(count[((int)guess[x])] == 0) { // if count is already zero it means already used in
                                               // wrong  place
                cow--;  
                bull++; 
                continue; 
             }
             
             // if count is greater than zero bull++ and count--;
             bull++;      
             count[((int)secret[x])]--;
         }      
         
         else {  // if not same
             
             if(count[((int)guess[x])] == 0) continue;  // if count is zero it is not in secret or already used
             
             // if count is greater than zero cow++ and count--
             cow++;
             count[((int)guess[x])]--;
         }
     }  
    
     return to_string(bull)+'A'+to_string(cow)+'B';     //convert everthing to string
}
    
    
};