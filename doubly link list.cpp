#include<iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
}*head=NULL;
void insert_end(int value)
{
    node *newnode,*temp;
    newnode=new node;
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
    {

        head=newnode;
        newnode->prev=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp->next;

    }
}
void insert_beg(int value)
{
    node *temp,*newnode;
    newnode=new node;
    newnode->data=value;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        temp=head;
        head=newnode;
        newnode->next=temp;
        temp->prev=newnode->next;
    }

}
void insert_after(int value,int b_value)
{
    node *newnode,*temp,*temp2;
    newnode=new node;
    newnode->data=value;
    temp=head;

    while(temp->next!=NULL)
    {
        if(temp->next==NULL && temp->data==b_value)
        {
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=NULL;
        }
        if(temp->data==b_value)
        {
            temp2=temp->next;
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=temp2;
            temp2->prev=newnode;
        }
         else if(temp->next->next==NULL && temp->next->data==b_value)
        {
            temp->next->next=newnode;
            newnode->prev=temp->prev;
            newnode->next=NULL;
            return;
        }
        temp=temp->next;
    }

}
void display()
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    node *temp=head;
    cout<<"Elements are: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
main()
{
    int choice;
    while(1)
    {
        cout<<"1.Insert value at the end"<<endl;
        cout<<"2.Insert value at the beginning"<<endl;
        cout<<"3.Insert after any value"<<endl;
        cout<<"4.Display list"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"------------------------------------------"<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value: ";
            int v;
            cin>>v;
            insert_end(v);
            break;
        case 2:
            cout<<"Enter value: ";
            int x;
            cin>>x;
            insert_beg(x);
            break;
        case 3:
            cout<<"Enter value you want to insert: ";
            int a;
            cin>>a;
            cout<<"Enter after which value you want to insert : ";
            int b;
            cin>>b;
            insert_after(a,b);
            break;
        case 4:
            display();
            break;
        case 0:
            return 0;
            break;
        default:
            cout<<"Wrong choice :( "<<endl;
        }
    }
    return 0;
}
