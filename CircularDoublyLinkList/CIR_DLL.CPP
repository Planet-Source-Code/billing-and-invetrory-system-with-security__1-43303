#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class screen
   {
       public:
       void menu(void)
	  {
	    cout<<"\n\n\n\n              **************************************";
	    cout<<"\n\t\t\t\t"<<"1.CREAT"<<endl<<"\t\t\t\t"<<"2.APPEND"
	    <<endl<<"\t\t\t\t"<<"3.DELETE"<<endl<<"\t\t\t\t"<<"4.DISPLAY"
	    <<endl<<"\t\t\t\t"<<"5.INSERT BEGGNING"<<endl<<"\t\t\t\t"<<"6.INSERT"
	    <<endl<<"\t\t\t\t"<<"7.MODIFY"<<endl<<"\t\t\t\t"<<"8.INVERSE DISPLAY"
	    <<endl<<"\t\t\t\t"<<"9.FIND"
	    <<endl<<"\t\t\t\t"<<"10.EXIT";
	    cout<<"\n              **************************************";
	  }
    }s;

struct link_list
   {
       int info;
       struct link_list *next;
       struct link_list *pre;
   };

typedef struct link_list link;

int count=0;

class ll
  {
   link *first,*list,*temp,*pointer;
    public:
    ll()
      {
	first=list;
      }
    int isempty(void);
    void creat(void);
    void append(void);
    void del(void);
    void insbeg(void);
    void ins(void);
    void modify(void);
    void display(void);
    void inv(void);
    void find(int x);
 };

int ll::isempty()
  {
     if(first==list)
	  return(1);
     return(0);
 }

void ll::creat()
  {
      if(first==list)
	  count=0;
      else
	 count=1;
	if(count!=0)
	{
	 cout<<"\nTHE LIST ALREADY EXISTS!";
	 getch();
	 return;
	}
       char ch;
       list=new link;
       first=list;
       while(1)
	 {
	    cout<<"\nENTER INFO:";
	    cin>>list->info;
	    cout<<"\nDO U WANT TO CONTINUE:";
	    cin>>ch;
	    if(ch=='n')
	      break;
	    list->next=new link;
	    list->next->pre=list;
	    list=list->next;
	}
	list->next=first;
	first->pre=list;
     }

void ll::append()
  {
     if(first==list)
	  return;
     list=first;
     while(list->next!=first)
	 list=list->next;
     list->next=new link;
     list->next->pre=list;
     list=list->next;
     list->next=first;
     first->pre=list;
     cout<<"\nENTER INFO:";
     cin>>list->info;
  }

void ll::insbeg()
 {
    if(first==list)
	 return;
    temp=new link;
    cout<<"\nENTER INFO:";
    cin>>temp->info;
    temp->next=first;
    temp->pre=first->pre;
    first->pre->next=temp;
    first->pre=temp;
    first=temp;
  }

void ll::ins()
  {
    if(first==list)
	return;
    list=first;
    temp=new link;
    int rec;
    cout<<"\nENTER THE INFO AFTER WHICH NEW INFO IS TO BE INSERTED:";
    cin>>rec;
    while(list->next!=first)
      {
	if(list->info==rec)
	  {
	       temp->next=list->next;
	       temp->pre=list;
	       list->next->pre=temp;
	       list->next=temp;
	       cout<<"\nENTER THE INFO:";
	       cin>>temp->info;
	       list=list->next;
	       return;
	   }
	 list=list->next;
	}
      cout<<"\nRECORD NOT FOUND!";
      getch();
  }

void ll::del()
 {
 //   if(list==first)
  //  return;
    list=first;
    cout<<"\nENTER THE INFO WHICH IS TO BE DELETED:";
    int t;
    cin>>t;
    if(first->info==t)
      {
	  first->next->pre=first->pre;
	  first->pre->next=first->next;
	  first=first->next;
	  return;
      }
    while(list->next->next!=first)
      {
	 if(list->info==t)
	    {
		list->next->pre=list->pre;
		list->pre->next=list->next;
		return;
	    }
	   list=list->next;
       }
      if(list->next->next==first)
	{
	   if(list->next->info==t)
	      {
		list->next=first;
		first->pre=list;
		return;
	      }
       }

      cout<<"\nRECORD NOT FOUND!";
      getch();

 }

void ll::modify()
  {
    if(first==list)
       return;
    int t;
    list=first;
    temp=new link;
    cout<<"\nENTER THE INFO TO BE MODIFIED:";
    cin>>temp->info;
    if(first->info==temp->info)
      {
	  cout<<"\nENTER NEW INFO:";
	  cin>>t;
	  first->info=t;
	  delete temp;
	  list=list->next;
	  return;
      }

    while(list->next!=first)
      {
	if(list->info==temp->info)
	   {
	       cout<<"\nENTER NEW INFO:";
	       cin>>t;
	       list->info=t;
	       delete temp;
	       return;
	   }
	 list=list->next;
       }
       if(list->next==first)
	 {
	   if(list->info==temp->info)
		 {
		     cout<<"\nENTER INFO:";
		     cin>>t;
		     list->info=t;
		     list=list->pre;
		     return;
		   }
	 }
     cout<<"\nRECORD IS NOT IN THE LIST!";
     getch();
  }

void ll::inv()
 {
    clrscr();
    cout<<"\nTHE INVERTED LIST IS:";
    first=list;
    while(first->pre!=list)
      {
	 cout<<"\t"<<first->info;
	 first=first->pre;
       }
       cout<<"\t"<<first->info;
       getch();
  }

void ll::find(int x)
  {
     if(first==list)
	return;
     int count=1;
     list=first;
     if(first->info==x)
       {
	  list=list->next;
	  cout<<"\nTHE RECORD FOUND IN POSITION:"<<count;
	  getch();
	  return;
       }
     while(list->next!=first)
	{
	   if(list->info==x)
	      {
		 cout<<"\nTHE RECORD FOUND IN POSITION:"<<count;
		 getch();
		 return;
	      }
	     list=list->next;
	     count++;
	}
      if(list->next==first)
	 {
	   if(list->info==x)
	     {
	      cout<<"\nTHE RECORD FOUND IN POS:"<<count;
	      getch();
	      return;
	      }
	  }
	cout<<"\nRECORD NOT FOUND!";
	getch();
 }

void ll::display()
   {
      clrscr();
      int a=isempty();
      if(a==1)
      {
	  cout<<" LIST EMPTY!";
	  return;
      }
      list=first;
      cout<<"\nTHE LINKED LIST IS:";
      while(list->next!=first)
	  {
	     cout<<"\t"<<list->info;
	     list=list->next;
	  }
	  cout<<"\t"<<list->info;
   }


 void main()
   {
       clrscr();
       ll a;
       int ch;
       do
	 {
	    a.display();
	    s.menu();
	    cout<<"\nENTER CHOICE:";
	    cin>>ch;
	    switch(ch)
	      {
		case 1:a.creat();break;
		case 2:a.append();break;
		case 3:a.del();break;
		case 4:a.display();break;
		case 5:a.insbeg();break;
		case 6:a.ins();break;
		case 7:a.modify();break;
		case 8:a.inv();break;
		case 9:cout<<"ENTER THE INFO WHICH IS TO BE SEARCHED:";
		       int x;
		       cin>>x;
		       a.find(x);
		       break;
		case 10:break;
		default:cout<<"TRY AGAIN!";
			  getch();
	      }
	}while(ch!=10);
       getch();
  }