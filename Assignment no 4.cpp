#include<iostream>
using namespace std;
class Node {
	public:
		int data;
		Node* next;
		Node(int v) {
			data = v;
			next = NULL;
		}
};
class SLL {
	public:
		Node* head;
		SLL() {
			head = NULL;
		}
		// ------------------ ADDING MATHODS ----------------------
		// 1 Add at head
		void addFirst(int v) {
			Node* newNode = new Node(v);
			newNode->next = head;
			head = newNode;
		}
		// 2 Add at last
		void addLast(int v){
			Node* newNode = new Node(v);
			Node* temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
			
		}
		// 3 Add at position
		void addAt(int v,int pos){
			Node* newNode = new Node(v);
			Node* temp = head;
			// if pos is 1 or less than 1
			if(pos == 1 || pos < 1 ){
				addFirst(v);
				return;
			}
			int c = 1;
			while(c<pos-1){
				temp = temp->next;
				// if pos is grater than numbers of Nodes
				if(temp->next == NULL){
					addLast(v);
					return;
				}
				c++;
			}
			newNode->next = temp->next;
			temp->next = newNode;			
		}
		/////////////////////////////////////////////////////////////////////
		//---------------------- DELETEING MATHODS --------------------------
		// 4 Delete First
		void deleteFirst(){
			if(head == NULL){
				return;
			}
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		// 5 Delete Last
		void deleteLast(){
			if(head == NULL){
				return;
			}
			Node* temp1=head;
			Node* temp2=NULL;
			while(temp1->next != NULL){
				temp2 = temp1;
				temp1 = temp1->next;	
			}
			temp2->next = NULL;
			delete temp1;
			
		}
		//////////////////////////////////////////////////////////////////////
		// 6 Search 
		void search(int v){
			if(head == NULL){
				return;
			}
			int flag = 0;
			Node* temp = head;
			while(temp != NULL){
				if(temp->data == v){
					cout<<"Number is : "<<temp->data<<endl;
					flag++;
					return;
				}
				temp = temp->next;
			}
			if(flag==0){
				cout<<"Number Not Found"<<endl;
			}
			
		}
		//////////////////////////////////////////////////////////////////////////
		// 7 ispalindrome
	  bool isPalindrome() {
    // Find the middle node of the linked list
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    Node* prev = nullptr;
    Node* curr = slow;
    Node* next = nullptr;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    // Compare the first half with the reversed second half
    Node* firstHalf = head;
    Node* secondHalf = prev;
    bool isPalindrome = true;
    while (firstHalf && secondHalf) {
      if (firstHalf->data != secondHalf->data) {
        isPalindrome = false;
        break;
      }
      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }

    // Reverse the second half back to its original state
    curr = prev;
    next = nullptr;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return isPalindrome;
  }
		// 8 Count Nodes
		void countNodes(){
			if(head == NULL){
				return;
			}
			Node* temp = head;
			int c = 0;
			while(temp != NULL){
				c++;
				temp = temp->next;
			}
			cout<<"Total Nodes Are : "<<c<<endl;
		}
		// 9 Maxim Value
		void max(){
			if(head == NULL){
				return;
			}
			int max=0;
			Node* temp = head;
			while(temp != NULL){
				if(temp->data>max){
					max = temp->data;
				}
				temp = temp->next;
			}
			cout<<"Maximum is : "<<max<<endl;
		}
		// 10 average
		void avg(){
			if(head == NULL){
				return;
			}
			int sum = 0;
			int count = 0;
			Node* temp = head;
			while(temp!=NULL){
				sum = sum + temp->data;
				count++;
				temp = temp->next;
			}
			float avg = sum/count;
			cout<<"Average of Node is : "<<avg<<endl;
		}
		// 11 Reverse 
		void reverse(){
			if(head==NULL){
				return;
			}
			Node* prev = NULL;
			Node* curr = head;
			Node* forward = NULL;
			while(curr!=NULL){
				forward = curr->next;
				curr->next = prev;
				prev = curr;
				curr = forward;
			}
			head = prev;
		}
		// 12 detect loopa
		void detectloop(){
			cout<<"in dect loop"<<endl;
			if(head==NULL){
				return;
			}
			int flag = 0;
			Node* fast = head;
			Node* slow = head;
			while(slow!=NULL && fast!=NULL){
				//cout<<"in while loop"<<endl;
				fast=fast->next;
				if(fast!=NULL){
//					cout<<"fast not = null"<<endl;
					fast=fast->next;
				}
//				cout<<"before slow"<<endl;
				slow=slow->next;
				if(slow->next==fast->next){
					cout<<"loop dectect"<<endl;
					flag++;
					return;
				}
//				cout<<"after if"<<endl;
			}
			if(flag==0){
				cout<<"Not Loop detect"<<endl;
			}
			
		}
		// Display
		void display() {
			if (head == NULL) {
				return;
			} else {
				Node *temp = head;
				while (temp != NULL) {
					cout << temp->data << " ";
					temp = temp->next;
				}
				cout << endl;
			}
		}
};
class Node2{
	public:
	int data;
	Node2* prev;
	Node2* next;
	Node2(int v){
		data = v;
		prev = NULL;
		next = NULL;
	}	
};
class DLL{
	public:
		Node2* head;
		DLL(){
			head = NULL;
		}
		//--------------------------------------------------------------------------------------
		// 1 add node 
		void add(int v){
			Node2* newNode = new Node2(v);
			if(head == NULL)
			{
				head = newNode;
				return;
			}
			Node2* temp = head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
		// 2 add node at first
		void addFirst(int v){
			Node2* newNode = new Node2(v);
			if(head == NULL){
				head = newNode;
				return;
			}
			newNode->next = head;
			if(head != NULL){
				head->prev = newNode;
			}
			head->prev= newNode;
			head = newNode;
		}
		// 3 add node at any posiction
		void addAt(int v,int pos){
			Node2* newNode = new Node2(v);
			if(head == NULL){
				head = newNode;
				return;
			}
			if(pos==1 || pos < 1){
				addFirst(v);
				return;
			}
			int c = 1;
			Node2* temp = head;
			while(c<pos-1){
				temp = temp->next;
				if(temp->next==NULL){
					add(v);
					return;
				}
				c++;
			}
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next = newNode;
		}
		// ------------------------------------------------------------------------------
		// 4 delete first
		void deleteFirst(){
			if(head==NULL){
				return;
			}
			Node2* temp = head;
			head = head->next;
			if(head != NULL){
				head->prev=NULL;
			}
			delete temp;
		}
		// 5 delete last
		void deleteLast(){
			if(head==NULL){
				return;
			}
			Node2* temp1 = head->next;
			Node2* temp2 = head;
			while(temp1->next != NULL){
				temp2 = temp1;
				temp1 = temp1->next;
			}
			temp1->prev = NULL;
			temp1 = NULL;
			temp2->next = NULL;
			delete temp1;
			
		}
		// delete any node
		void deleteAny(int pos){
			if(head==NULL){
				return;
			}
			if(pos==1 || pos<1){
				deleteFirst();
				return;
			}
			Node2* temp1 = head->next;
			Node2* temp2 = head;
			int c = 1;
			while(c<pos-1){
				temp2 = temp1;
				temp1 = temp1->next;
				if(temp1->next==NULL){
					deleteLast();
					return;
				}
				c++;
			}
			temp2->next = temp1->next;
			temp1->next->prev = temp2;
			temp1->next=NULL;
			temp1->prev=NULL;
			delete temp1;
			
		}
		//-------------------------------------------------------------
		// 6 search 
		void search(int v){
			if(head==NULL){
				return;
			}
			int flag = 0;
			Node2* temp = head;
			while(temp != NULL){
				if(temp->data==v){
					cout<<"Number Found : "<<temp->data<<endl;
					flag++;
					break;
				}
				temp = temp->next;
			}
			if(flag==0){
			cout<<"Number Not Found"<<endl;	
			}
			
		}
		// 7 check palindrome
  bool isPalindrome() {
    // Initialize two pointers, slow and fast, to the head of the list
    Node2* slow = head;
    Node2* fast = head;

    // Move the fast pointer to the end of the list
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Compare the first half of the list with the second half in reverse
    Node2* curr = slow;
    Node2* prev = nullptr;
    while (curr) {
      Node2* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    Node2* firstHalf = head;
    Node2* secondHalf = prev;
    bool isPalindrome = true;
    while (firstHalf && secondHalf) {
      if (firstHalf->data != secondHalf->data) {
        isPalindrome = false;
        break;
      }

      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }

    // Restore the original order of the second half
    curr = prev;
    prev = nullptr;
    while (curr) {
      Node2* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return isPalindrome;
  }
		// 8 count nodes
		void count(){
			if(head==NULL){
				return;
			}
			Node2* temp = head;
			int count = 0;
			while(temp!=NULL){
				count++;
				temp=temp->next;
			}
			cout<<"Total Nodes are : "<<count<<endl;
			
		}
		// 9 max 
		void max(){
			if(head==NULL){
				return;
			}
			int max=0;
			Node2* temp = head;
			while(temp!=NULL){
				if(max<temp->data){
					max=temp->data;
				}
				temp=temp->next;
			}
			cout<<"Maximum Number is : "<<max<<endl;
		}
		// 10 average
		void avg(){
			if(head==NULL){
				return;
			}
			int sum=0;
			int count=0;
			Node2* temp = head;
			while(temp!=NULL){
				sum=sum+temp->data;
				count++;
				temp=temp->next;
			}
			double avg = sum/count;
			cout<<"Average is : "<<avg<<endl;
			
		}
		// 11 reverse
		void reverse(){
			if(head==NULL){
				return;
			}
			Node2* temp1 = head;
			Node2* temp2 = head->next;
			temp1->next = NULL;
			temp1->prev = temp2;
			while(temp2!=NULL){
				temp2->prev = temp2->next;
				temp2->next = temp1;
				temp1 = temp2;
				temp2 = temp2->prev;
			}
			head = temp1;
		}
		// detect loop
			void detectloop(){
			if(head==NULL){
				return;
			}
			Node2* fast = head;
			Node2* slow = head;
			while(slow!=NULL && fast!=NULL){
				fast=fast->next;
				if(fast!=NULL){
					fast=fast->next;
				}
				slow=slow->next;
				if(slow->next==fast->next){
					cout<<"loop dectect"<<endl;
					return;
				}
			}
			cout<<"Not Loop detect"<<endl;
		}
		// display
		void display(){
			if(head==NULL){
				return;
			}
			Node2* temp = head;
			while(temp != NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
};

int main(){
	int ch;
	cout<<"Enter Your Choice"<<endl;
	cout<<"1 Singly Link List"<<endl;
	cout<<"2 Doubly Link List"<<endl;
	cin>>ch;
	if(ch==1){
		SLL s;
		int operation;
		int v;
		int pos;
		do{
		
		cout<<"Which Operation You Perform"<<endl;
		cout<<"1 Add First"<<endl;
		cout<<"2 Add Last"<<endl;
		cout<<"3 Delete First"<<endl;
		cout<<"4 Delete Last"<<endl;
		cout<<"5 Insert At"<<endl;
		cout<<"6 Search"<<endl;
		cout<<"7 Is Palindrome"<<endl;
		cout<<"8 Count Nodes"<<endl;
		cout<<"9 Find Max"<<endl;
		cout<<"10 Average"<<endl;
		cout<<"11 Reverse"<<endl;
		cout<<"12 Detect Loop"<<endl;
		cout<<"13 Display"<<endl;
		cin>>operation;
		switch(operation)
		{
			case 1: cout<<"Enter Value"<<endl; cin>>v; s.addFirst(v); break;
			case 2: cout<<"Enter Value"<<endl; cin>>v;s.addLast(v); break;
			case 3: s.deleteFirst(); break;
			case 4: s.deleteLast(); break;
			case 5: cout<<"Enter Value"<<endl; cin>>v; cout<<"Enter Pos "<<endl; cin>>pos; s.addAt(v,pos); break;
			case 6: cout<<"Enter Value"<<endl; cin>>v; s.search(v); break;
			case 7: 	if(s.isPalindrome())
			{
	   						cout<<"YES"<<endl;
			}
			else
			{
							cout<<"NO"<<endl;
			}
		    break;
			case 8: s.countNodes(); break;
			case 9: s.max(); break;
			case 10: s.avg(); break;
			case 11: s.reverse(); break;
			case 12: s.detectloop(); break;
			case 13: s.display(); break;
			default: cout<<"Invalid Option"<<endl; break;
		}
	}
		while(operation!=0);	
	}else if(ch==2){
		DLL s;
		int operation;
		int v;
		int pos;
		do{
		
		cout<<"Which Operation You Perform"<<endl;
		cout<<"1 Add First"<<endl;
		cout<<"2 Add Last"<<endl;
		cout<<"3 Delete First"<<endl;
		cout<<"4 Delete Last"<<endl;
		cout<<"5 Insert At"<<endl;
		cout<<"6 Search"<<endl;
		cout<<"7 Is Palindrome"<<endl;
		cout<<"8 Count Nodes"<<endl;
		cout<<"9 Find Max"<<endl;
		cout<<"10 Average"<<endl;
		cout<<"11 Reverse"<<endl;
		cout<<"12 Detect Loop"<<endl;
		cout<<"13 Display"<<endl;
		cin>>operation;
		switch(operation)
		{
			case 1: cout<<"Enter Value"<<endl; cin>>v; s.addFirst(v); break;
			case 2: cout<<"Enter Value"<<endl; cin>>v;s.add(v); break;
			case 3: s.deleteFirst(); break;
			case 4: s.deleteLast(); break;
			case 5: cout<<"Enter Value"<<endl; cin>>v; cout<<"Enter Pos "<<endl; cin>>pos; s.addAt(v,pos); break;
			case 6: cout<<"Enter Value"<<endl; cin>>v; s.search(v); break;
			case 7: if(s.isPalindrome()){
			cout<<"Palindrome"<<endl;	
			}
			else{
				cout<<"Not Palindrome"<<endl;
			} break;
			case 8: s.count(); break;
			case 9: s.max(); break;
			case 10: s.avg(); break;
			case 11: s.reverse(); break;
			case 12: s.detectloop(); break;
			case 13: s.display(); break;
			default: cout<<"Invalid Option"<<endl; break;
		}
	}
		while(operation!=0);
	}
	else{
		cout<<"Invalid Choice"<<endl;
	}
	return 0;
}
