//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
     struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        vector<int>ans;
       while(head1!=NULL){
           ans.push_back(head1->data);
           head1=head1->next;
       }
       while(head2!=NULL){
           ans.push_back(head2->data);
           head2 =head2->next;
       }
       sort(ans.begin(),ans.end());
       set<int>ans2;
       for(int i=0;i<ans.size();i++){
          ans2.insert(ans[i]);
       }
      
       
       Node * head=new Node(-1);
       Node*tail  =head;
       for(auto i:ans2){
          Node * temp = new Node(i);
          tail->next = temp;
          tail=temp;
       }
       return head->next;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends