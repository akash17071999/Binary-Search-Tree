#include <iostream>
#include<iomanip>
using namespace std;

 struct node
	  {
		double tn, ph;
		string name, pos, addr, bg;
		int prn, id;
		node * l,*r;
	  };

class tree
{
     int f =0;
public :node *root;
 	 	 tree()
 	 	 {
 	 		 root=NULL;
 	 	 }
 	 	 void create();
 	 	 void display(node *temp);
 	 	 void search();
 	 	 void modify();
 	 	 void delet(string);
};
void tree :: create()
{
	node* nn=new node;
	cout<<"\nEnter Employee name: ";
	cin>>nn->name;
	cout<<"\nEnter cell phone number: ";
	cin>>nn->ph;
	cout<<"\nEnter address: ";
	cin>>nn->addr;
	cout<<"\nEnter blood group: ";
	cin>>nn->bg;
	cout<<"\nEnter employee position: ";
	cin>>nn->pos;
	cout<<"\nEnter employee's PRN number: ";
	cin>>nn->prn;
	cout<<"\nEnter employee's ID number: ";
	cin>>nn->id;
	nn->l=nn->r=NULL;
	if(root==NULL)
	{
		root=nn;
	}
	else
	{
		node *temp ,*parent;
		temp=root;
		while(temp!=NULL)
		{
			parent=temp;
			if(temp->name > nn->name)
				temp=temp->l;
			else
				temp=temp->r;

		}
		if(nn->name < parent->name)
			parent->l=nn;
		else
			parent->r=nn;
	}
}

void tree::display(node* tmp)
{
   	if(tmp!=NULL)
	{
		display(tmp->l);
		cout<<setw(10)<<tmp->name;
		cout<<setw(10)<<tmp->ph;
		cout<<setw(10)<<tmp->addr;
		cout<<setw(10)<<tmp->bg;
		cout<<setw(10)<<tmp->pos;
		cout<<setw(10)<<tmp->prn;
		cout<<setw(10)<<tmp->id;
		f=1;
		display(tmp->r);
	}
/*	if(f==0)
	    cout<<"\nNo records stored!";*/
}

void tree ::search()
{
	int s;
	char cs;
	node *temp=root;
	node *parent=temp;
	do{
		cout<<"\nSearch by: ";
		cout<<"\n1)Name \n2)PRN \n3)ID_number\n>>>";
		cin>>s;
		switch(s)
		{
			case 1: {
					string kname;
					cout<<"\nEnter the name: ";
					cin>>kname;
					while(temp!=NULL)
					{
						if(temp->name == kname)
						{
							cout<<"\nSearch successful!";
							cout<<"Employee name"<<setw(18)<<"Cell phone number"<<setw(18)<<"Address"<<setw(18)<<"Blood group"<<setw(18)<<"Employee position"<<setw(18)<<"Employee's PRN number"<<setw(18)<<"Employee's ID number\n";
							cout<<setw(10)<<temp->name;
							cout<<setw(10)<<temp->ph;
							cout<<setw(10)<<temp->addr;
							cout<<setw(10)<<temp->bg;
							cout<<setw(10)<<temp->pos;
							cout<<setw(10)<<temp->prn;
							cout<<setw(10)<<temp->id;
							break;
						}
						else if(temp->name>kname)
						{
							parent=temp;
							temp = temp->l;
						}
						else if(temp->name<kname)
						{
							parent=temp;
							temp = temp->r;
						}
						else
						{
						cout<<"\nSearch Unsuccessful! Please review the credentials carefully.";
						}
					}
					
				}
				break;
		
				case 2: {	temp = root;
						int kprn;
						cout<<"\nEnter the PRN: ";
						cin>>kprn;
						while(temp!=NULL)
						{
							if(temp->prn == kprn)
							{
								cout<<"\nSearch successful!";
							cout<<"Employee name"<<setw(18)<<"Cell phone number"<<setw(18)<<"Address"<<setw(18)<<"Blood group"<<setw(18)<<"Employee position"<<setw(18)<<"Employee's PRN number"<<setw(18)<<"Employee's ID number\n";
							cout<<setw(10)<<temp->name;
							cout<<setw(10)<<temp->ph;
							cout<<setw(10)<<temp->addr;
							cout<<setw(10)<<temp->bg;
							cout<<setw(10)<<temp->pos;
							cout<<setw(10)<<temp->prn;
							cout<<setw(10)<<temp->id;
							break;
							}
							else if(temp->prn>kprn)
							{
								parent=temp;
								temp = temp->l;
							}
							else if(temp->prn<kprn)
							{
								parent=temp;
								temp = temp->r;
							}
							else
							{
							cout<<"\nSearch Unsuccessful! Please review the credentials carefully.";
							}
						}
				}
				break;
			
				case 3: {	temp = root;
						int kid;
						cout<<"\nEnter the ID number: ";
						cin>>kid;
						while(temp!=NULL)
						{
							if(temp->id == kid)
							{
								cout<<"\nSearch successful!";
							cout<<"Employee name"<<setw(18)<<"Cell phone number"<<setw(18)<<"Address"<<setw(18)<<"Blood group"<<setw(18)<<"Employee position"<<setw(18)<<"Employee's PRN number"<<setw(18)<<"Employee's ID number\n";
							cout<<setw(10)<<temp->name;
							cout<<setw(10)<<temp->ph;
							cout<<setw(10)<<temp->addr;
							cout<<setw(10)<<temp->bg;
							cout<<setw(10)<<temp->pos;
							cout<<setw(10)<<temp->prn;
							cout<<setw(10)<<temp->id;
							break;
							}
							else if(temp->id>kid)
							{
								parent=temp;
								temp = temp->l;
							}
							else if(temp->id<kid)
							{
								parent=temp;
								temp = temp->r;
							}
							else
							{
							cout<<"\nSearch Unsuccessful! Please review the credentials carefully.";
							}
						}
					}
				}
				cout<<"\nSearch more records?(y/n): ";
				cin>>cs;	
			}while(cs=='y');
			/*while(temp!=NULL)
			{
				if(temp->word==k)
				{
					cout<<"found\t"<<temp->word<<"\t"<<temp->mean<<"\n";
					break;
				}
				else if(temp->word>k)
				{
					parent=temp;
					temp=temp->l;

				}
				else
				{
					parent=temp;
					temp=temp->r;
				}
			}
	if(temp==NULL)
	{
		cout<<"not found";
	}*/
}

void tree::modify()
{
	int s;
	
	char cs;
	node *temp=root;
	node *parent=temp;
	do{
	int flag=0;
		cout<<"\nSearch by: ";
		cout<<"\n1)Name \n2)PRN \n3)ID_number\n>>>";
		cin>>s;
		switch(s)
		{
			case 1: {
					string kname;
					cout<<"\nEnter the name: ";
					cin>>kname;
					while(temp!=NULL)
					{
						if(temp->name == kname)
						{
							cout<<"\n Match Found!";
							cout<<"\nSearch successful!";
							cout<<"Name"<<setw(17)<<"Phone number"<<setw(17)<<"Address"<<setw(17)<<"Blood group"<<setw(17)<<"Position"<<setw(17)<<"PRN number"<<setw(17)<<"ID number\n";
							cout<<setw(10)<<temp->name;
							cout<<setw(10)<<temp->ph;
							cout<<setw(10)<<temp->addr;
							cout<<setw(10)<<temp->bg;
							cout<<setw(10)<<temp->pos;
							cout<<setw(10)<<temp->prn;
							cout<<setw(10)<<temp->id;
							flag=1;
							break;
						}
						else if(temp->name>kname)
						{
							parent=temp;
							temp = temp->l;
						}
						else
						{
							parent=temp;
							temp = temp->r;
						}
					}
					if(temp==NULL)
					{
						cout<<"\nSearch Unsuccessful! Please review the credentials carefully.";
					}
				}
				break;
		
				case 2: {	temp = root;
						int kprn;
						cout<<"\nEnter the PRN: ";
						cin>>kprn;
						while(temp!=NULL)
						{
							if(temp->prn == kprn)
							{
								cout<<"\n Match Found!";
								cout<<"\nSearch successful!";
							cout<<"Name"<<setw(17)<<"Phone number"<<setw(17)<<"Address"<<setw(17)<<"Blood group"<<setw(17)<<"Position"<<setw(17)<<"PRN number"<<setw(17)<<"ID number\n";
							cout<<setw(10)<<temp->name;
							cout<<setw(10)<<temp->ph;
							cout<<setw(10)<<temp->addr;
							cout<<setw(10)<<temp->bg;
							cout<<setw(10)<<temp->pos;
							cout<<setw(10)<<temp->prn;
							cout<<setw(10)<<temp->id;
								flag=1;break;
							}
							else if(temp->prn>kprn)
							{
								parent=temp;
								temp = temp->l;
							}
							else
							{
								parent=temp;
								temp = temp->r;
							}
						}
						if(temp==NULL)
						{
							cout<<"\nSearch Unsuccessful! Please review the credentials carefully.";
						}
				}
				break;
			
				case 3: {	temp = root;
						int kid;
						cout<<"\nEnter the ID number: ";
						cin>>kid;
						while(temp!=NULL)
						{
							if(temp->id == kid)
							{
								cout<<"\n Match Found!";
								cout<<"\nSearch successful!";
							cout<<"Name"<<setw(17)<<"Phone number"<<setw(17)<<"Address"<<setw(17)<<"Blood group"<<setw(17)<<"Position"<<setw(17)<<"PRN number"<<setw(17)<<"ID number\n";
							cout<<setw(10)<<temp->name;
							cout<<setw(10)<<temp->ph;
							cout<<setw(10)<<temp->addr;
							cout<<setw(10)<<temp->bg;
							cout<<setw(10)<<temp->pos;
							cout<<setw(10)<<temp->prn;
							cout<<setw(10)<<temp->id;
								flag=1;break;
							}
							else if(temp->id>kid)
							{
								parent=temp;
								temp = temp->l;
							}
							else
							{
								parent=temp;
								temp = temp->r;
							}
						}
						if(temp==NULL)
						{
							cout<<"\nSearch Unsuccessful! Please review the credentials carefully.";
						}
					}
				}
				if(flag==1)
				{
					cout<<"\nEnter employee position: ";
					cin>>temp->pos;
					cout<<"\nEnter employee's PRN number: ";
					cin>>temp->prn;
					cout<<"\nEnter employee's ID number: ";
					cin>>temp->id;
					f=1;
				}
				cout<<"\nModify more records?(y/n): ";
				cin>>cs;	
			}while(cs=='y');
			
}

void tree::delet(string keyn)
{
	node *cn,*parent;
	parent=NULL;
	cn=root;
	while(cn!=NULL)
	{
		if(cn->name==keyn)
		{
			break;
		}
		else
		{
			parent=cn;
			if(keyn < cn->name)
			cn=cn->l;
			else
			cn=cn->r;
		}
		
	}
	if(cn==NULL)
	{
		cout<<"\nNOT PRESENT";
	}
//***********************Node with no child  ***************************
  if(cn->l==NULL && cn->r==NULL)
    {
        if(cn==root)
        {
            root= NULL;
            cout<<"\nDatabase Empty!!!";
            return;
        }
        if(cn->name<parent->name)
            parent->l=NULL;
        else
            parent->r=NULL;
        delete cn;
    }

//********************  Node with left child  **********************
    else if(cn->l!=NULL && cn->r==NULL)
    {
        if(cn==root)
        {
            root=cn->l;
            return;
        }
        if(cn->l->name<parent->name)
            parent->l=cn->l;
        else
            parent->r=cn->l;
        if(cn==parent)
        {
            root=cn->l;
        }
        delete cn;
    }
// ******************* Node with right child  ********************
    else if(cn->l==NULL && cn->r!=NULL)
    {
        if(cn==root)
        {
            root= cn->r;
            delete cn;
        }
        else
        {
            if(cn->r->name < parent->name)
                parent->l = cn->r;
            else
                parent->r = cn->r;
            delete cn;
        }
    }
    
// **************Node with two child**********************
  else if(cn->l!=NULL && cn->r!=NULL)
    {
        node *temp;
        temp=cn->l;
        while(temp->r)
            temp=temp->r;
        string newn,newpos,newad,newbg;
        int newprn,newid;
        double newph;
        //pos, addr, bg
        cn->name  = temp->name;
        cn->pos = temp->pos;
        cn->addr = temp->addr;
        cn->bg = temp->bg;
        cn->prn = temp->prn;
        cn->id = temp->id;
        cn->ph = temp->ph;
       
        delet(newn);
        
        cn->name = newn;
   	cn->pos = newpos;
   	cn->addr = newad;
   	cn->bg = newbg;
   	cn->prn = newprn;
   	cn->id = newid;
   	cn->ph = newph;
   	
    }
    
	
}

int main()
{
	tree e;
	int x;
	char ch;
	do{
		cout<<"\n-------------EMPLOYEE DATABASE-------------";
		cout<<"\nPossible actions: ";
		cout<<"\n1)Create new database";
		cout<<"\n2)Display current database";
		cout<<"\n3)Search a record in database";
		cout<<"\n4)Modify a record in database";
		cout<<"\n5)Delete a record from current database\n>>>";
		cin>>x;
		switch(x)
		{
			case 1: e.create();
			break;
			
			case 2:cout<<"Employees details\n";
				cout<<setw(5)<<"Name"<<setw(17)<<"Phone number"<<setw(17)<<"Address"<<setw(17)<<"Blood group"<<setw(17)<<"Position"<<setw(17)<<"PRN number"<<setw(17)<<"ID number\n";
				e.display(e.root);
				break;
			
			case 3: e.search();
			break;
			
			case 4: e.modify();
			break;
			
			case 5: string ke;
				cout<<"Enter the Employee Name to be deleted\n";
				cin>>ke;
			
				e.delet(ke);
			break;	
			
			//default:cout<<"Invalid Selection!!!";
			//break;
		}
		cout<<"\nDo you want to repeat operations?(y/n): ";
		cin>>ch;
	}while(ch=='y');
	return 0;
}
