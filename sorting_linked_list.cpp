#include<cstdlib>
#include<iostream>
using namespace std;
struct node
{
	int n;
	struct node* next;
}*head;
void Insert(int ins)
{
	if(head == NULL)
	{
		node* temp;
		temp = (struct node *)malloc(sizeof(struct node));
		temp->n = ins;
		head = temp;
		head -> next = NULL;
	}
	else
	{
		int i = 0;
		node* temp;
		node* temp1;
		temp1 = (struct node *)malloc(sizeof(struct node));
		temp1->n = ins;
		temp1->next = NULL;
		temp = head;
		node* tmp;
		tmp = NULL;
		while(temp)
		{
			if(temp->n < ins)
			{
				tmp = temp;
				temp = temp->next;
			}
			else
			{
				i = 1;
				if(tmp == NULL)
				{
					temp1->next = temp;
					head = temp1;
					return;
				}
				else
				{
					temp1->next = temp;
					tmp = temp1;
					return;
				}
				break;
			}
		}
		if(!i)
			tmp->next = temp1;
	}
}
void Delete(int del)
{
	node* temp;
	if(head == NULL)
	{
		cout << "We got an empty list.Please,insert." << endl;
		return;
	}
	temp = head;
	node* tmp;
	while(temp)
	{
		if(temp->n == del)
		{
			cout << "Ya,I gotcha and done the job." << endl;
			if(temp == head)
				head = temp->next;
			else
				tmp->next = temp->next;
			return;
		}
		tmp = temp;
		temp = temp->next;
	}
	cout << "Sorry,bro i didn't find that no. to delete :-(." << endl;
}
void Search(int ser)
{
	node* temp;
	temp = head;
	if(head == NULL)
	{
		cout << "Empty string." << endl;
		return;
	}
	while(temp)
	{
		if(temp->n == ser)
		{
			cout << "Ya!,we got that no. in list." << endl;
			return;
		}
		temp = temp->next;
	}
	cout << "Boo!,we didn't got that no. in the list." << endl;
	return;
}
void Print()
{
	int x = 0;
	if(head == NULL)
		cout << "empty-list" << endl;
	else
	{
		node* temp;
		temp = head;
		while(temp != NULL)
		{
			cout << temp->n << endl;
			temp = temp->next;
		}
	}
}

/********************************************************************************
void printing(node *tmp)
{
	cout << temp->n << endl;
	temp = temp->next;
	if(temp == NULL)
		cout << "This is the list." << endl;
	else
		printing(temp);
}
************************************************************************************/

main()
{
	bool well = NULL;
	while(!well)
	{
		cout << "1.Insert" << endl << "2.Delete" << endl << "3.Search" << endl << "4.Print list" << endl << "5.End" << endl << "Select an option:";
		int opt,i = 1;
		cin >> opt;
		switch(opt)
		{
			case(1):
			{
				cout << "**********************************************" << endl;
				cout << "what no. do u want to insert:";
				int ins;
				cin >> ins;
				Insert(ins);
				cout << "***********************************************" << endl;
				break;
			}
			case(2):
			{
				cout << "***********************************************" << endl << "what no. do u want to delete:";
				int del;
				cin >> del;
				Delete(del);
				cout << "************************************************" << endl;
				break;
			}
			case(3):
			{
				cout << "**********************************************" << endl << "What no. u want search for : ";
				int ser;
				cin >> ser;
				Search(ser);
				cout << "************************************************" << endl;
				break;
			}
			case(4):
			{
				cout << "**************************************************" << endl << "This is the list :" << endl;
			Print();
				cout << "*************************************************" << endl;
				break;
			}
			case(5):
			{
				well = 1;
				cout << "***************************************************" << endl;
				break;
			}
		}
	}
	cout << "Thanks for your time." << endl;
	cout << "****************************************************" << endl;
return 0;
}
