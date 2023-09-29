// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int val;
  Node * prev;
  Node * next;
  Node * child;
};

//brute force approch using stack
// imagine DFS 
class Solution
{
  public: Node* flatten(Node *head)
  {
    if (head == NULL) return head;
    Node *d = new Node();
    Node *dummy = d;
    stack<Node*> q;
    q.push(head);
    while (!q.empty())
    {
      Node *temp = q.top();
      q.pop();
      if (temp)
      {
        dummy->next = temp;
        temp->prev = dummy;
      }

      if (temp->next)
      {
        q.push(temp->next);
      }

      if (temp->child)
      {
        q.push(temp->child);
        temp->child = NULL;
      }

      dummy = temp;
    }

    dummy = d->next;
    dummy->prev = NULL;
    return dummy;
  }
};

// Recrusive not my solution but learn it will help you in interview 
class Solution
{
  public:
    Node* flat(Node *head)
    {
      if (!head)
        return NULL;
      Node *temp1 = NULL;
      while (head)
      {
        if (head->child)
        {
          Node *tail = flat(head->child);
          Node *temp = head->next;
          head->next = head->child;
          head->child->prev = head;
          head->child = NULL;
          if (tail)
          {
            tail->next = temp;
            if (temp)
              temp->prev = tail;
          }

          temp1 = tail;
          head = temp;
        }
        else
        {
          temp1 = head;
          head = head->next;
        }
      }

      return temp1;
    }

  Node* flatten(Node *head)
  {
    flat(head);
    return head;
  }
};

int main() {}