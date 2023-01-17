int ans=0,tempgcd=0;

int gcd(int a,int b){
    if(!a)return b;
    if(!b)return a;
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        if(b>a){
            b=b-a;
        }
    }
    return b;
}

void solve_postorder(Node*root){
    if(!root){return;}
    solve_postorder(root->left);
    solve_postorder(root->right);

    if(root->left!=NULL && root->right!=NULL){
        int a=gcd(root->left->data,root->right->data);
        if(a>tempgcd){
            tempgcd=a;
            ans=root->data;
            
        }
    }
}
    
