//Count Common Subsequence in two Strings
#include <iostream>
#include <string.h>
using namespace std;

//Function to count the number of subsequences in the string.
  int countsequences(char str[], char str1[])
  {
    int l1 = strlen(str);
    int l2 = strlen(str1);
    int cnt[l1+1][l2+1];
    for (int i = 0; i <= l1; i++)
    {
      for (int j = 0; j <= l2; j++)
       {
       cnt[i][j] = 0; 
       }
    }
//Taking each character from first string.
    for (int i = 1; i <= l1; i++)
   {
//Taking each character from second string.
    for (int j = 1; j <= l2; j++)
    {
    //If characters are same in both the string.

    if(str[i-1] == str1[j-1])
    {
      cnt[i][j] = 1 + cnt[i][j-1] + cnt[i-1][j];
    }
    else
    {
      cnt[i][j] = cnt[i][j-1] + cnt[i-1][j] - cnt[i-1][j-1];
    }
  }
}
return cnt[l1][l2];
}
//Main function for printing the result.
  int main()
 {
    char str[100]="Prep" ,str1[100] = "Prepinsta";

  cout<<"Number of common subsequence is: "<<countsequences(str, str1);
  return 0;
}