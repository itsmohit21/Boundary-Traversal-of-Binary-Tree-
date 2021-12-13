class Solution {
public:
    bool f=0,c=0;
    void helL(Node *r,vector<int>&v)
    {
        if(!r)
            return ;
        if(r->left==NULL&&r->right==NULL)
        {
            f=1;
            return;
        } 
        if(f==0)
            v.push_back(r->data);
        hel1(r->left,v);
        hel1(r->right,v);
    }
    void helI(Node *r,vector<int>&v)
    {
        if(!r)
            return ;
        if(r->left==NULL&&r->right==NULL)
           v.push_back(r->data); 
        helper(r->left,v);
        helper(r->right,v);
    }
    void helR(Node *r,vector<int>&a)
    {
        if(!r)
            return ;
        if(r->left==NULL&&r->right==NULL)
        {
            c=1;
            return;
        } 
        if(c==0)
            a.push_back(r->data);
        hel(r->right,a);
        hel(r->left,a);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>v,a;
        v.push_back(root->data);
        if(root->left)
            hel1(root->left,v);
        if(root->left!=NULL||root->right!=NULL)
            helper(root,v);
        if(root->right)
        {
            hel(root->right,a);
            for(int j=a.size()-1;j>=0;j--)
                v.push_back(a[j]);
        }
        return v;
    }
};
