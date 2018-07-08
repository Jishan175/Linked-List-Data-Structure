#include<stdio.h>
#include<iostream>
using namespace std;
struct node
{
    int info;
    node *next;
}*head=NULL;
void insert_end(int value)
{
    node *temp,*newnode;
    newnode=new node;
    newnode->info=value;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;

    }
}
void display()
{

    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->next;

    }
    cout<<endl;
}
void count()
{
    node *temp;
    if(head==NULL)
    {
        cout<<"NO nodes"<<endl;
    }
    else
    {
        int count=0;
        temp=head;
        while(temp!=NULL)
        {
            count=count+1;
            temp=temp->next;
        }

        cout<<"Number of nodes: "<<count<<endl;
    }
}
void search(int value)
{

    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->info==value)
        {
            cout<<endl<<value<<" is found"<<endl;
            return;
        }
        else
        {
            temp=temp->next;
        }
    }
    cout<<endl<<value<<" is absent in the list"<<endl;
}
void del(int value)
{
    node *temp1,*temp2;

    if(head->info==value)
    {
        temp1=head;
        head=head->next;
        delete(temp1);
        return;
    }
    temp1=head;
    while(temp1->next!=NULL)
    {
        if(temp1->next->info==value)
        {
            temp2=temp1->next;

            temp1->next=temp2->next;
            delete(temp2);
            return;
        }
        temp1=temp1->next;


    }
    if(temp1->info!=value)
    {
        cout<<value<<" is absent in the list"<<endl;
    }
}
void insert_begng(int value)
{
    node *temp,*newnode;
    temp=head;
    newnode=new node;
    newnode->info=value;
    head=newnode;
    newnode->next=temp;
}
void insert_after(int value,int b_value)
{
    node *temp1,*temp2,*newnode;
    temp1=head;
    newnode=new node;
    newnode->info=value;
    while(temp1!=NULL)
    {
        if(temp1->info==b_value)
        {
            temp2=temp1->next;
            temp1->next=newnode;
            newnode->next=temp2;
            return;
        }
        temp1=temp1->next;
    }

}
void maximum()
{
    if(head==NULL)
    {
        cout<<endl<<"List is empty"<<endl;
        return;
    }
    node *temp1;
    temp1=head;
    int max=temp1->info;
    while(temp1!=NULL)
    {

        if(max<=temp1->info)
        {
            max=temp1->info;
        }
        temp1=temp1->next;
    }
    cout<<endl<<"Maximum number of the list is: "<<max<<endl;
}
void minimum()
{
    if(head==NULL)
    {
        cout<<endl<<"List is empty"<<endl;
        return;
    }
    node *temp;
    temp=head;
    int min=temp->info;
    while(temp!=NULL)
    {
        if(min>=temp->info)
        {
            min=temp->info;

        }
        temp=temp->next;
    }

    cout<<endl<<"Minimum number is :"<<min<<endl;
}
void average()
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    node *temp;
    temp=head;
    int sum=0,count=0;
    while(temp!=NULL)
    {
        sum=sum+temp->info;
        count=count+1;
        temp=temp->next;
    }
    float f;
    f=(float)sum/count;
    printf("Average of the list is :%.2f\n",f);
}
void odd_number()
{
    if(head==NULL)
    {
        cout<<endl<<"List is empty"<<endl;
        return;
    }
    cout<<"Odd numbers are: ";
    while(head!=NULL)
    {
        if(head->info%2!=0)
        {
            cout<<head->info<<" ";
        }
        head=head->next;
    }
    cout<<endl;
}
void even_number()
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Even numbers are : ";
    while (head!=NULL)
    {
        if(head->info%2==0)
        {
            cout<<head->info<<" ";
        }
        head=head->next;
    }
    cout<<endl;
}

main(void)
{
    int choice;

    while(1)
    {
        cout<<endl;
        cout<<"1.Insert value at the end "<<"      "<<"2.Insert value at the beginning"<<endl;
        cout<<"3.Insert value after any value"<<"  "<<"4.Display element"<<endl;
        cout<<"5.Count nodes"<<"                   "<<"6.Search value "<<endl;
        cout<<"7.Delete value"<<"                  "<<"8.Maximum Number"<<endl;
        cout<<"9.Minimum number"<<"                "<<"10.Average of the element's"<<endl;
        cout<<"11.Find the odd number"<<"          "<<"12.Find the even number "<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"------------------------------------------------------------------"<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;
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
            int a;
            cin>>a;
            insert_begng(a);
            break;
        case 3:
            int nv,bv;
            cout<<"Enter value you want to insert: ";
            cin>>nv;
            cout<<endl<<"Enter after which value you want to insert: ";
            cin>>bv;
            insert_after(nv,bv);
            break;
        case 4:
            if(head==NULL)
            {
                cout<<"List is empty"<<endl;
            }
            else
            {
                cout<<"Elements are : ";
                display();
            }
            break;
        case 5:
            count();
            break;
        case 6:
            if(head==NULL)
            {
                cout<<"List is empty"<<endl;
                break;
            }
            int w;
            cout<<"Enter the value: ";
            cin>>w;
            search(w);
            break;
        case 7:
            if(head==NULL)
            {
                cout<<"List is empty"<<endl;
                break;
            }
            int x;
            cout<<"Enter value you want to delete : ";
            cin>>x;
            del(x);
            break;
        case 8:
            maximum();
            break;
        case 9:
            minimum();
            break;
        case 10:
            average();
            break;
        case 11:
            odd_number();
            break;
        case 12:
            even_number();
            break;
        case 0:
            return 0;
            break;
        default:
            cout<<"wrong choice :("<<endl;
        }
    }
    return 0;
}

