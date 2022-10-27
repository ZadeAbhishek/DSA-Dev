#include<bits/stdc++.h>
using namespace std;

class Tries{
   private:
   Tries* child[26] = {};
   bool isword = false;

       
     void insert2(string word,Tries* prev) {
          if(word.size() == 0){
              prev->isword = true;
              return;
          }
        Tries* curr = this;
        int it = word[0] - 'a';
        if(curr->child[it] == nullptr)
            curr->child[it] = new Tries();
        insert2(word.substr(1),curr);
     }

   void insertChar(string word){
      Tries* current = this;
      for(auto pt : word){
        pt -= 'a';
        if(current->child[pt] == nullptr)
        current->child[pt] = new Tries();

        current = current->child[pt];
      }
      current->isword = true;
   }
   bool seachWord(string word){
       Tries* current = this;
      for(auto pt : word){
        pt -= 'a';
        if(current->child[pt] == nullptr) return false;

        current = current->child[pt];
      }
      if(current->isword)
      return true;
      else
      return false;
   }
  bool searchprefix(string word){
    Tries* current = this;
    for(auto pt : word){
        pt -= 'a';
        if(current->child[pt] == nullptr) return false;

        current = current->child[pt];
      }
      return true;
  }



   public:
    void insert(string s){
         //insertChar(s);
         insert2(s,this);
    }
    bool search(string s){
        return seachWord(s);
    }

    bool preficCheck(string s){
        return searchprefix(s);
    }   
};


int main (){

Tries *t = new Tries();
t->insert("abhi");
cout<<t->search("abhi");
cout<<t->preficCheck("ab");
cout<<t->preficCheck("abhi");
cout<<t->preficCheck("abhishek");

}