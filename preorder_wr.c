#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *l,*r;
};
typedef struct node tree;
tree *root=NULL;
void insert(int e){
	tree *x, *p;
	if (root==NULL){
		root=(tree*)malloc(sizeof(tree));
		root->data=e;
		root->l=NULL;
		root->r=NULL;
	}
	else{
		x=root;
		while (x!=NULL){
		p=x;
		if (x->data<e){
			x=x->r;
		}
		else{
			x=x->l;
		}
		}
		if (p->data<e){
			p->r=(tree *)malloc(sizeof(tree));
			p->r->data=e;
			p->r->l=NULL;
			p->r->r=NULL;
		}
		else{
			p->l=(tree *)malloc(sizeof(tree));
			p->l->data=e;
			p->l->l=NULL;
			p->l->r=NULL;	
		}
		}
}
void preorder(tree *root) {
    if (root == NULL) 
		return;
    tree *stack[100];
    int top = -1;
    stack[++top] = root; 
    while (top != -1) {
        tree *node = stack[top--]; // Pop from stack
        printf("%d ", node->data); // Process the node
        if (node->r != NULL) {
            stack[++top] = node->r;
        }
        if (node->l != NULL) {
            stack[++top] = node->l;
        }
    }
}

void main() {
    int n, i, v;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter value for node: ");
        scanf("%d", &v);
        insert(v);
    }
    printf("\nPREORDER TRAVERSAL:\n");
    preorder(root);
}
