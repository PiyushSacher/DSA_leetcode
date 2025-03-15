class ListNode {
    public:
      string val;
      ListNode *next;
      ListNode *prev;
      ListNode() : val(0), next(nullptr),prev(nullptr){};
      ListNode(string x) : val(x), next(nullptr) prev(nullptr){};
      ListNode(string x, ListNode *next, ListNode *random) : val(x), next(next) prev(random){};
};
 


class BrowserHistory {
public:
    ListNode* currentPage;
    BrowserHistory(string homepage) {
        currentPage=new ListNode(homepage);                
    }
    
    void visit(string url) {
        ListNode* newNode=new ListNode(url);
        current->next=newNode;
        current=current->next;        
    }
    
    string back(int steps) {
        while(steps){
            if(currentPage->prev!=NULL) current=current->prev;
            else break;
            steps--;

        }
        return currentPage->val; 
    }
    
    string forward(int steps) {
        while(steps){
            if(currentPage->next!=NULL) current=current->next;
            else break;
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