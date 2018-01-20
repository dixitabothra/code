#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node{
	int val;
	struct node *left;
	struct node *right;

} node;

struct node *head = NULL;

/*
 * @val : value of node
 * create_node take the val as input and creates a node
 * */

node* create_node(int val)
{
	node* temp = (node*)malloc(sizeof(node));
        temp->val = val;
	temp->left = NULL;
	temp->right = NULL;

}

/*
 *Add the node in BST
 * */

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
/*
 * Do the inoder traversal of the BST
 * */
void inorder_traversal(struct node *head)
{
	if(head == NULL)
		return;
	inorder_traversal(head->left);
	printf("%d ", head->val);
	inorder_traversal(head->right);
}

/*
 * @head : pointer to the current head
 * @k	 : kth position 
 * @curr : holds the value of kth smallest element
 *
 * */
void kth_smallest(struct node *head, int * k, int *  curr)
{
	if(head == NULL)
		 return ;
	if(*curr != 0)
		return;
        
	kth_smallest(head->left, k, curr);
	*k = *k - 1;
	if(*k == 0 && *curr == 0)
	{
		*curr = head->val;
		return;
	}
	kth_smallest(head->right, k, curr);
}

int main(int argc, char** argv )
{
	int i;
	int k;
	int curr = 0;
	for(i = 1; i< argc-1; i++)
	{
		add_node(create_node(atoi(argv[i])));
	}	
	
	inorder_traversal(head);
	printf("\n");
	k =  atoi(argv[argc-1]);  // last element would the Kth value 
	kth_smallest(head, &k,&curr);

	printf("Kth smallest %d", curr);


}
