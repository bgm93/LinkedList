#include <stdio.h>
#include <stdlib.h>

//include some branch comments
struct node {

	int data;
	struct node *next;
};

struct node *head=NULL, *rear=NULL;


int insert(int data) {
	
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	if(head==NULL) {
		head = rear = temp;
		
	} else {
		rear->next = temp;	
		rear = temp;
		
	}

	return 1;
}

int delete(int val) {
	
	struct node *curr, *prev;
	curr = prev = head;

	while(curr->data != val && curr->next != NULL) {
		prev = curr;
		curr = curr->next;
		
	}
	
	if(curr->data == val) {
		if(curr == head) {
			if(curr->next == NULL) {
				head = rear = NULL;
			} else {
				head = curr->next;	
			}
			free(curr);
		} else {
			if(curr == rear) {
				rear = prev;
			}
			prev->next = curr->next;
			free(curr);		
		}
		return 1;
	}else {
		printf("%d, Element not present\n", val);
		return -1;
	}
	return 0;
}

int search(int val) {

	struct node *temp;
	int cnt=1;
	temp = head;

	if(head == NULL) return -1;

	while(1) {
		if(temp->data == val) {
			return cnt;
		} else if(temp->next == NULL) {
			break;
		} else {
			cnt++;
			temp = temp->next;
		}
		
	}
	return -1;

}

void disp() {
	struct node *temp;
	temp = head;
	if(head == NULL) return;
	while(1) {
		printf("%d", temp->data);
		if(temp->next == NULL) break;
		temp = temp->next;
	}
}

int main() {
	
	
	insert(1);
	insert(2);
	delete(3);
	insert(3);
	insert(6);
	delete(5);
	delete(8);
	delete(6);

	insert(5);
	insert(7);
	delete(3);
	delete(30);
	// insert(40);
	//printf("%d\n", search(10));
	disp();
	// printf("%d", rear->data);
	return 0;
}


// int delete(int data) {

// 	struct node *temp, *prev;
// 	temp = head;

// 	while(1) {

// 		if(temp->data == data) {

// 			if(temp==head) {
// 				head = temp->next;
// 			} else if(temp==rear) {
// 				prev->next=NULL;
// 				rear = prev;
// 			}else {
// 				prev->next = temp->next;
// 			}
			
// 			return 1;

// 		} else if(temp->next!=NULL) {
// 			break;
// 		} else {
// 			prev = temp;
// 			temp = temp->next;
// 		}
// 	}

// 	return -1;

	
// }

