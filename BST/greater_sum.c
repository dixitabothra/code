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

void rev_sum(struct node *head, int *sum)
{
	if(head == NULL)
		return ;
	rev_sum(head->right, sum);
	*sum = *sum + head->val;
	head->val = *sum;
	rev_sum(head->left, sum);
}


int main(int argc, char** argv )
{
	int i;
	int sum = 0;

	for(i = 1; i< argc; i++)
	{

		add_node(create_node(atoi(argv[i])));
	}	
	
	inorder_traversal(head);
	printf("\n");

	rev_sum(head, &sum);
	printf("\nReversed SUM\n");
	inorder_traversal(head);


}
