#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node{
	int val;
	struct node *left;
	struct node *right;

} node;

struct node *head = NULL;

node* create_node(int val)
{
	node* temp = (node*)malloc(sizeof(node));
        temp->val = val;
	temp->left = NULL;
	temp->right = NULL;

}

void add_node( struct node *node)
{

	struct node *temp_head;
	struct node *prev_head;
	temp_head = head;
	if(head == NULL)
	{
		head = node;
		return;
	}

	while(temp_head)
	{
		prev_head = temp_head;
		if(temp_head->val < node->val)
			temp_head = temp_head->right;
		else
			temp_head = temp_head->left;
	
	}
	if(prev_head->val < node->val)
		prev_head->right = node;
	else
		prev_head->left = node;


}

void inorder_traversal(struct node *head)
{
	if(head == NULL)
		return;
	inorder_traversal(head->left);
	printf("%d ", head->val);
	inorder_traversal(head->right);
}

void preorder_traversal(struct node *head)
{
        if(head == NULL)
                return;
	printf("%d ", head->val);
        preorder_traversal(head->left);
        //printf("%d ", head->val);
        preorder_traversal(head->right);
}

void postorder_traversal(struct node *head)
{
        if(head == NULL)
                return;
        postorder_traversal(head->left);
        postorder_traversal(head->right);
	printf("%d ", head->val);
}


int main(int argc, char** argv )
{
	int i;
	int sum = 0;
	int curr = 0;
	struct node * k;
	for(i = 1; i< argc; i++)
	{

		add_node(create_node(atoi(argv[i])));
	}	
	 printf("\nInorder ");
	inorder_traversal(head);
	printf("\nPreorder ");
	preorder_traversal(head);
	printf("\nPostorder ");
        postorder_traversal(head);

}
