// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    struct Node* new_node = new Node(new_data, new_data1);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    
    while (temp != NULL)
    {
       printf("%d %d ", temp->coeff, temp->pow);
       temp  = temp->next;
    }
}

Node* addPolynomial(Node *p1, Node *p2);


void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = NULL;
    }
}
 

/* Driver program to test above function*/

 // } Driver Code Ends
/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};
*/

class Solution{
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
Node* addPolynomial(Node *p1, Node *p2)
    {
        //Your code here
        Node* res = NULL, *head = NULL;
        
        Node* curr1 = p1, *curr2 = p2;
        
        while(curr1 != NULL && curr2 != NULL)
        {
            if(curr1->pow == curr2->pow)
            {
                if(res == NULL)
                {
                    
                    res = new Node(curr1->coeff + curr2->coeff, curr1->pow);
                    head = res;
                }
                else
                {
                    res->next = new Node(curr1->coeff + curr2->coeff, curr1->pow);
                    res = res->next;
                }
                
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            else
            {
                while((curr1 != NULL && curr2 != NULL) && (curr1->pow > curr2->pow))
                {
                    if(res == NULL)
                    {
                        res = new Node(curr1->coeff, curr1->pow);
                        head = res;
                        curr1 = curr1->next;
                    }
                    else
                    {
                        res->next = new Node(curr1->coeff, curr1->pow);
                        res = res->next;
                        curr1 = curr1->next;
                    }
                    
                }
                
                while((curr1 != NULL && curr2 != NULL) && (curr2->pow > curr1->pow))
                {
                    if(res == NULL)
                    {
                        res = new Node(curr2->coeff, curr2->pow);
                        head = res;
                        curr2 = curr2->next;
                    }
                    else
                    {
                        res->next = new Node(curr2->coeff, curr2->pow);
                        res = res->next;
                        curr2 = curr2->next;
                    }
                    
                }
            }
            
        }
        
        while(curr1 != NULL)
        {
            if(res == NULL)
            {
                res = new Node(curr1->coeff, curr1->pow);
                head = res;
                curr1 = curr1->next;
            }
            
            else
            {
                res->next = new Node(curr1->coeff, curr1->pow);
                res = res->next;
                curr1 = curr1->next;
            }
        }
        
        
        while(curr2 != NULL)
        {
            if(res == NULL)
            {
                res = new Node(curr2->coeff, curr2->pow);
                head = res;
                curr2 = curr2->next;
            }
            else
            {
                res->next = new Node(curr2->coeff, curr2->pow);
                res = res->next;
                curr2 = curr2->next;
            }
            
        }
        
        res->next = NULL;
        
    
        return head;
    }
};


// { Driver Code Starts.
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1  = NULL,*tail2 = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly1,&tail1,x,y);
        }
        
         int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly2,&tail2,x,y);
        }
        Solution obj;
        Node *sum = obj.addPolynomial(poly1,poly2);
        for(Node* ptr=sum ; ptr ; ptr=ptr->next  )
        {
            // printing polynomial
            cout<< ptr->coeff << "x^" << ptr->pow;
            if(ptr->next) cout<<" + ";
        }
        cout<<endl;
       
    }

}
  // } Driver Code Ends