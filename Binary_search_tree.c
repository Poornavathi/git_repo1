#include<stdio.h>
#include<stdlib.h>
struct Bst
{
	int data;
	struct Bst *left,*right;
};
void insert(struct Bst **ptr,int d);
void inorder(struct Bst *ptr);
struct Bst *min(struct Bst *root);
void max(struct Bst *root);
struct Bst *search(struct Bst *ptr,int value);
void preorder(struct Bst *ptr);
void postorder(struct Bst *ptr);
struct Bst *delete(struct Bst *ptr,int d);
void replace(struct Bst *ptr,int value1,int value2);
main()
{
	struct Bst *root=NULL,*temp=NULL;
	int data,choice,r;
	while(1)
	{
		printf("\n1.insert\n2.inorder\n3.minimum value\n4.maximum value\n5.search\n6.preorder\n7.postorder\n8.delete\n9.replace\n10.quit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the data\n");
			       scanf("%d",&data);
			       insert(&root,data);
			       break;
			case 2:inorder(root);
			       break;
			case 3:temp=min(root);
			       printf("minimum value in tree=%d\n",temp->data);
			       break;
			case 4:max(root);
			       break;
			case 5:printf("enter the data to be search:\n");
			       scanf("%d",&data);
			       temp=search(root,data);
			       if(temp==NULL)
			       {
				       printf("***sorry data not found***\n");
				       break;
			       }
			       printf("%d data found successfully..!!!!!!!\n",temp->data);
			       break;
			case 6:preorder(root);
			       break;
			case 7:postorder(root);
			       break;
			case 8:printf("enter the data to be delete\n");
				scanf("%d",&data);
                                root=delete(root,data);
                                 break;
			case 9:printf("which data to be replace:\nand replace with\n");
			       scanf("%d %d",&data,&r);
			       replace(root,data,r);
			       break;
			case 10:exit(0);
			default:printf("***invalid choice\n");
				break;
		}
	}
}

void insert(struct Bst **ptr,int d)
{
	struct Bst *nu=NULL;
	if(*ptr==NULL)
	{
		nu=calloc(1,sizeof(struct Bst));
		nu->data=d;
		*ptr=nu;
	}
	else if(d<(*ptr)->data)
		insert(&((*ptr)->left),d);
	else if(d>(*ptr)->data)
		insert(&((*ptr)->right),d);
	else
		printf("duplicate values are not allowed.........\n");


}

void inorder(struct Bst *ptr)
{
	///left  parent  right///
	if(ptr)
	{
		inorder(ptr->left);
		printf("%d ",ptr->data);
		inorder(ptr->right);
	}
}


struct Bst *min(struct Bst *ptr)
{
	while(ptr->left)
	{
		ptr=ptr->left;
	}
	if(ptr)
		return ptr;
	else
		return NULL;
}
void max(struct Bst *ptr)
{
	while(ptr->right)
	{
		ptr=ptr->right;
	}
	printf("maximum value in tree=%d\n",ptr->data);
}

struct Bst *search(struct Bst *ptr,int value)
{
	if(ptr==NULL)
		return NULL;
	else if(value<ptr->data)
		return search(ptr->left,value);
	else if(value>ptr->data)
		return search(ptr->right,value);
	else
		return ptr;
}
void preorder(struct Bst *ptr)
{
	///parent  left  right///
	if(ptr)
	{
		printf("%d ",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
void postorder(struct Bst *ptr)
{
	///left  right  parent////
	if(ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ",ptr->data);
	}
}

struct Bst *delete(struct Bst *ptr,int d)
{
	struct Bst *temp=NULL;
	if(ptr==NULL)
	{
		printf("%d is not found\n",d);
		return NULL;
	}
	else if(d<ptr->data)
		ptr->left=delete(ptr->left,d);
	else if(d>ptr->data)
		ptr->right=delete(ptr->right,d);
	else
	{
		//for two children node//
		if((ptr->right)&&(ptr->left))
		{
			temp=min(ptr->right);
			ptr->data=temp->data;
			ptr->right=delete(ptr->right,temp->data);
		}
		else
		{
			temp=ptr;
			if(ptr->left==NULL)
				ptr=ptr->right;
			else
				ptr=ptr->left;
			free(temp);
			temp=NULL;
			printf("given data %d deleted successfully!!!!!!!\n",d);
		}
	}
	return ptr;
}
void replace(struct Bst *ptr,int value1,int value2)
{
	struct Bst *temp;
	temp=search(ptr,value1);
	if(temp)
	{
		temp->data=value2;
		printf("%d is successfully replaced by %d\n",value1,value2);
	}
	else
		printf("entered data not found...\n");
}

