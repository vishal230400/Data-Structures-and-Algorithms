#include<iostream>
using namespace std;
class tree{
	public:
		int data;
		tree *right,*left;

	tree(int data)
	{
		this->data=data;
		this->left = NULL; 
     	this->right = NULL; 
	}	

	tree()
	{
		this->left = NULL; 
     	this->right = NULL;
	}
};

int findPosition(int inOrder[],int ii,int ij,int data)
{
	for(int i=ii;i<=ij;i++)
		if(inOrder[i]==data)
			return i;	
}
	
tree * treeBuilder(int postOrder[],int pi,int pj,int inOrder[],int ii,int ij)
{
	tree *root=new tree();
	int d=postOrder[pj];
	root->data=d;
	int temp;
	if(pi==pj)
	{
		root->right=NULL;
		root->left=NULL;
		return root;
	}
	else
	{
		temp=findPosition(inOrder,ii,ij,postOrder[pj]);
		int pj_1=temp-1-ii+pi;
		if(pj_1>=0)
		    root->left=treeBuilder(postOrder,pi,pj_1,inOrder,ii,temp-1);
		if(temp+1<=ij)
		root->right=treeBuilder(postOrder,pj_1+1,pj-1,inOrder,temp+1,ij);	
	    
		return root;
	}
}


void preOrder(tree* node) 
{ 
     if (node == NULL) 
          return; 
  
    cout<<node->data<<" ";
    preOrder(node->left);   
  	preOrder(node->right); 
}     
  

int main()
{
	tree *root;
	int n;
	cout<<"Enter no of nodes"<<endl;
	cin>>n;
	int inOrder[n],postOrder[n];
	cout<<"Enter inOrder"<<endl;
	for(int i=0;i<n;i++)
		cin>>inOrder[i];
	cout<<"Enter preOrder"<<endl;
	for(int i=0;i<n;i++)
		cin>>postOrder[i];
	root=treeBuilder(postOrder,0,n-1,inOrder,0,n-1);
	cout<<"Pre-Order transversal of given tree is "<<endl;
	preOrder(root);
	return 0;
}
