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
void postorder(tree* root) {
    if (root == NULL) return;

    tree* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    
    stack1[++top1] = root;
    
    while (top1 != -1) {
        tree* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->l != NULL)
            stack1[++top1] = current->l;
        if (current->r != NULL)
            stack1[++top1] = current->r;
    }
    
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
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
    printf("\nPOSTORDER TRAVERSAL:\n");
    postorder(root);
}
