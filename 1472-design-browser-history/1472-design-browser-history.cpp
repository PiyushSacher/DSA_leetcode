class Node {
    public:
      string val;
      Node *next;
      Node *prev;
      Node(): val(""), next(nullptr),prev(nullptr){}
      Node(string x) : val(x), next(nullptr), prev(nullptr){}
      Node(string x, Node *next, Node *random) : val(x), next(next), prev(random){}
};
 


class BrowserHistory {
public:
    Node* currentPage;
    BrowserHistory(string homepage) {
        currentPage=new Node(homepage);                
    }
    
    void visit(string url) {
        Node* newNode=new Node(url);
        currentPage->next=newNode;
        newNode->prev=currentPage;
        currentPage=currentPage->next;        
    }
    
    string back(int steps) {
        while(steps){
            if(currentPage->prev!=NULL) currentPage=currentPage->prev;
            else {
                break;
            }
            steps--;

        }
        return currentPage->val; 
    }
    
    string forward(int steps) {
        while(steps){
            if(currentPage->next!=NULL) currentPage=currentPage->next;
            else {
                break;
            }
            steps--;

        }
        return currentPage->val; 
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */