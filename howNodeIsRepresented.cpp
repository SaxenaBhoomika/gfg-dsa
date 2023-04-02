class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        int n=arr.size();
        Node* head=new Node(arr[0]);
        Node* last=head;
        for(int i=1;i<n;i++){
            Node* newNode=new Node(arr[i]);
            last->next=newNode;
            last=newNode;
        }
        return head;
    }
};
