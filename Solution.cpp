struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* reverseLL(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
  
    Node* addOne(Node* head) {
        Node* revHead= reverseLL(head);
        
        Node* res=revHead; 
        Node* temp=NULL;
        Node* prev=NULL;
        
        int sum, carry=1;
        
        while(res!=NULL){
            sum= carry + res->data;
            carry= sum/10;
            sum=sum%10;
            
            res->data=sum;
            prev=res;
            res=res->next;
        }
        
        if(carry>0){
            prev->next=new Node(carry);   
        }
        
        Node* ans= reverseLL(revHead);
        return ans;
    }
};
