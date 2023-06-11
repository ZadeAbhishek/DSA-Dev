#include <iostream>
#include <map>
#include <iterator>
#include<map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> linker;
        Node* pointer = head;
        while (pointer!=NULL)
        {
         Node* newNode = new Node(pointer->val);
         linker.insert(pair<Node*,Node*>(pointer,newNode));
         pointer = pointer->next;   
        }
        pointer = head;
        while(pointer!=NULL){
            linker[pointer]->next = linker[pointer->next];
            linker[pointer]->random = linker[pointer->random];
            pointer=pointer->next;
        }
        // cout<<linker[head]<<" VALUE "<<endl;

        // //Printing 
        // map<Node*,Node*>:: iterator itr;
        // for(itr = linker.begin();itr!=linker.end();++itr){
        //     cout<<itr->first<<" "<<itr->second<<endl;
        // }

      return linker[head];

    }
    map<Node*,Node*> linker;
    Node* RecurrsivecopyRandomList(Node* head) {
      if(head==NULL){return head;}
      if(linker[head]!=NULL){return linker[head];}
      linker[head] = new Node(head->val);
      linker[head]->next = RecurrsivecopyRandomList(head->next);
      linker[head]->random = RecurrsivecopyRandomList(head->random);
      return linker[head];
 }
};


Node* createList(int a[5][2]){
Node* list = new Node(a[0][0]);
Node* ptr = list;
 for(int i=1;i<5;i++){
  Node* newNode = new Node(a[i][0]);
  ptr->next = newNode;
  ptr=ptr->next;
 }
Node* ptr2 = list;
for(int i=0;i<5;i++){
    Node* ptr3 = list;
    for(int j=0;j<a[i][1];++j){
        if(ptr3!=NULL){
        ptr3 = ptr3->next;
        }
        else{
            ptr3 =NULL;
        }
    }
    ptr2->random = ptr3;

    ptr2 = ptr2->next;
}
return list;
}

int main(){
    int a[5][2] = {{7,NULL},{13,0},{11,4},{10,2},{1,0}};
    Node* list = createList(a);
    Node* head = list;
    while(list!=NULL){
        if(list->random != NULL){
        cout<<list->val<<" "<<list->random->val<<endl;
        }
        else{
            cout<<list->val<<" "<<"NULL"<<endl;
        }
        list = list->next;
    }
    Solution* solve = new Solution();
    Node* finalList =  solve->RecurrsivecopyRandomList(head);
     while(finalList!=NULL){
        if(finalList->random != NULL){
        cout<<finalList->val<<" "<<finalList->random->val<<endl;
        }
        else{
            cout<<finalList->val<<" "<<"NULL"<<endl;
        }
        finalList = finalList->next;
    }
 return 0;
}