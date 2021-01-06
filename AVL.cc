#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
	node *left;
	int data;
	node *right;
	node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
int DFS(node *root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	int lc,rc;
	lc=rc=1;
	lc+=DFS(root->left);
	rc+=DFS(root->right);
	if(lc>rc)
		return lc;
	return rc;
}
/*void Balance(node **root,node *temp,int key,string str)
{
	if(str.length()==2 || temp->data==key)
	{
		if(str[0]=='L' && str[1]=='R')
		{
			temp=(*root)->left;
			node *p=temp->right;
			(*root)->left=p->right;
			temp->right=p->left;
			p->left=temp;
			p->right=(*root);
			(*root)=p;
		}
		else if(str[0]=='L' && str[1]=='L')
		{
			temp=(*root)->left;
			(*root)->left=temp->right;
			temp->right=(*root);
			(*root)=temp;
		}
		else if(str[0]=='R' && str[1]=='R')
		{
			temp=(*root)->right;
			(*root)->right=temp->left;
			temp->left=(*root);
			(*root)=temp;
		}
		else if(str[0]=='R' && str[1]=='L')
		{
			temp=(*root)->right;
			node *p=temp->left;
			(*root)->right=p->left;
			temp->left=p->right;
			p->left=(*root);
			p->right=temp;
			(*root)=temp;
		}
		return;
	}
	if(temp->data>key)
	{
		Balance(&(*root),temp->left,key,str+"L");
	}
	else
	{
		Balance(&(*root),temp->right,key,str+"R");
	}
}*/
void Balance(node **root,node *temp,string str)
{
	if((DFS(temp->left)-DFS(temp->right))>=0)
	{
		// Balance(&(*root),temp->left,str+"L");
		temp=temp->left;
		str+="L";
	}
	else
	{
		// Balance(&(*root),temp->right,str+"R");
		temp=temp->right;
		str+="R";
	}
	{
		if(str[0]=='L' && str[1]=='R')
		{
			temp=(*root)->left;
			node *p=temp->right;
			(*root)->left=p->right;
			temp->right=p->left;
			p->left=temp;
			p->right=(*root);
			(*root)=p;
		}
		else if(str[0]=='L' && str[1]=='L')
		{
			temp=(*root)->left;
			(*root)->left=temp->right;
			temp->right=(*root);
			(*root)=temp;
		}
		else if(str[0]=='R' && str[1]=='R')
		{
			temp=(*root)->right;
			(*root)->right=temp->left;
			temp->left=(*root);
			(*root)=temp;
		}
		else if(str[0]=='R' && str[1]=='L')
		{
			temp=(*root)->right;
			node *p=temp->left;
			(*root)->right=p->left;
			temp->left=p->right;
			p->right=(temp);
			p->left=(*root);
			(*root)=p;
		}
		return;
	}
}
void Insert(node **root,int x)
{
	if((*root)==NULL)
	{
		node *p=new node(x);
		(*root)=p;
		return;
	}
	else if(((*root)->data)>x)
	{
		Insert(&((*root)->left),x);
		int Balance_Factor=(DFS((*root)->left)-DFS((*root)->right));
		if(Balance_Factor>1 || Balance_Factor<-1)
			Balance(root,(*root)->left,"L");
	}
	else if(((*root)->data)<x)
	{
		Insert(&((*root)->right),x);
		int Balance_Factor=(DFS((*root)->left)-DFS((*root)->right));
		if(Balance_Factor>1 || Balance_Factor<-1)
			Balance(root,(*root)->right,"R");
	}	
}
node *Delete(node *root,int key)
{
	if(root==NULL)
		return root;
	else if(root->data>key)
	{
		root->left=Delete(root->left,key);
		int Balance_Factor=(DFS((root)->left)-DFS((root)->right));
		if(Balance_Factor>1 || Balance_Factor<-1)
			Balance(&(root),root->right,"R");
		return root;
	}
	else if(root->data<key)
	{
		root->right=Delete(root->right,key);
		int Balance_Factor=(DFS((root)->left)-DFS((root)->right));
		if(Balance_Factor>1 || Balance_Factor<-1)
			Balance(&(root),root->left,"L");
		return root;
	}
	else
	{
		if(root->left==NULL)
		{
			node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			node *temp=root->left;
			free(root);
			return temp;
		}
		else
		{
			node *temp=root->right;
			node *temp2=temp;
			while(temp->left!=NULL)
			{
				temp2=temp;
				temp=temp->left;
			}
			root->data=temp->data;
			if(temp==temp2)
				(root)->right=temp->right;
			else
				temp2->left=temp->right;
			free(temp);
			return root;
		}
	}
}
void Display(node *root)
{
	if(root==NULL)
		return;
	Display(root->left);
	cout<<root->data<<" ";
	Display(root->right);
}
void Representation(node *root)
{
	node *temp=root;
	queue <node *> q;
	q.push(temp);
	cout<<"ROOT\t\t\t\tLEFT\t\t\t\tRIGHT\n";
	while(!q.empty())
	{
		cout<<temp->data<<"\t\t\t\t";
		if(temp->left!=NULL)
		{
			q.push(temp->left);
			cout<<temp->left->data;
		}
		else
			cout<<"NULL";
		cout<<"\t\t\t\t";
		if(temp->right!=NULL)
		{
			q.push(temp->right);
			cout<<temp->right->data;
		}
		else
			cout<<"NULL";
		q.pop();
		temp=q.front();
		cout<<endl;
	}
}
int main(int argc, char const *argv[])
{
	node *root=NULL;
	int ch;
	do{
		cout<<"\nEnter your Choice:	1.Insert	2.Delete	3.Display	4.Representation	0.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				int x;
				cin>>x;
				Insert(&root,x);
				break;
			case 2:
				if(root!=NULL)
				{
					int key;
					cin>>key;
					// Delete(&root,key);
					root=Delete(root,key);
				}
				else
					cout<<"TREE is Empty\n";
				break;
			case 3:
				if(root!=NULL)
					Display(root);
				else
					cout<<"TREE is Empty\n";
				break;
			case 4:
				if(root!=NULL)
					Representation(root);
				else
					cout<<"TREE is Empty\n";
				break;
			case 0:
				break;
		}
	}while(ch!=0);
	return 0;
}