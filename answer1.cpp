#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node*right;
};

struct node* make_node(int data)
{
    struct node* nit=new struct node();
    nit->data=data;
    nit->left=NULL;
    nit->right=NULL;
    return nit;
}



struct node* k=NULL;
int x=0;

void  search_leaf(struct node* root,int data)
{
   if(root->data==data&&root->left==NULL&&root->right==NULL)
      {
          k= root;
          return;
      }
   if(root->left!=NULL)
      search_leaf(root->left,data);
   if(root->right!=NULL)
     search_leaf(root->right,data);
}

void add_node(struct node* &root,int data1,int data2,int data3)
{
   // k=NULL;
   // search_leaf(root,data1);
    struct node* nit=make_node(data1);




    if(data2==0)
    {
        struct node* nit2=make_node(-1);
        nit->left=nit2;
    }
    else
    {
        struct node* nit2=make_node(data2);
        nit->left=nit2;
    }
    if(data3==0)
    {
        struct node* nit2=make_node(-1);
        nit->right=nit2;
    }
    else
    {
        struct node* nit2=make_node(data3);
        nit->right=nit2;
    }
    if(x==0)
       {
           //nit=make_node(data1);
           root->left=nit;
       }
       if(x==1)
       {
           //nit=make_node(data1);
           root->right=nit;
       }
       x++;

}

void inorder(struct node* root)
{
    if(root==NULL||root->data==-1)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       x=0;
       k=NULL;
       string s;
       cin>>s;
       struct node* root=NULL;
       //cout<<int(s[1]-'a')<<endl;
       root=make_node(int(s[1]-'0'));
       for(int i=4;i<s.length();)
       {
           add_node(root,int(s[i]-'0'),int(s[i+2]-'0'),int(s[i+4]-'0'));
           i=i+8;
       }
       inorder(root);
       cout<<endl;

   }

   return  0;
}
