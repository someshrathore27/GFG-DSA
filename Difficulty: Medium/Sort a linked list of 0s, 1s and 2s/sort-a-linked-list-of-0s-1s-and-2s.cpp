/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(head==NULL) return head;
        Node* p0=new Node(0);
        Node* p1=new Node(0);
        Node* p2=new Node(0);
        Node* p0s=p0;
        Node* p1s=p1;
        Node* p2s=p2;
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data==0)
            {
                p0->next=temp;
                p0=p0->next;
            }
            else if(temp->data==1)
            {
                p1->next=temp;
                p1=p1->next;
            }
            else if(temp->data==2)
            {
                p2->next=temp;
                p2=p2->next;
            }
            temp=temp->next;
        }
        p0->next = p1s->next ? p1s->next : p2s->next;
        p1->next = p2s->next;
        p2->next = nullptr; 
        
        Node* newHead = p0s->next ? p0s->next : (p1s->next ? p1s->next : p2s->next);
        
        delete p0s;
        delete p1s;
        delete p2s;
        
        return newHead;
    }
};