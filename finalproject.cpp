


Skip to content
Using Gmail with screen readers

Conversations
0.26 GB (1%) of 15 GB used
Manage
Terms · Privacy · Program Policies
Last account activity: 47 minutes ago
Details

#include<bits/stdc++.h>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<cstdio>
#include<time.h>
#include<conio.h>
using namespace std;

struct nextlinks
{
    int index;
    char lname[30];
    char type[20];
    float distance;
    int bdays;
    nextlinks * next;

};
struct downlinks
{
    int index;
    char lname[30];
    char type[20];
    int bdays;
    downlinks *down;
    nextlinks * next;
};
 int nol=0;
downlinks * newlocation(downlinks *l, int a)
{
    downlinks *n, *newloc;
    nextlinks *newlink, *neww;
    n=new downlinks;
    cout<<"\n ENTER LOCATION NAME:";
    cin>>n->lname;
    nol++;
    n->index=nol;
    loctype:
    cout<<"\n CHOOSE LOCATION TYPE:";
    cout<<"\n 1. RESIDENTIAL \n 2. COMMERCIAL  \n 3. MARKET \n   CHOICE:";
    int c;
    cin>>c;
    switch(c)
    {
        case 1: strcpy(n->type, "RESIDENTIAL");
                n->bdays=7;
                break;
        case 2: strcpy(n->type,"COMMERCIAL");
                n->bdays=5;
                break;
        case 3: strcpy(n->type,"MARKET");
                n->bdays=2;
                break;
        default: cout<<"**********************INVALID CHOICE*************************";
                goto loctype;
    }
    n->down=NULL;
    n->next=NULL;
    if(l==NULL)
    {
        l=n;
    }
    else
    {
        newloc=l;
        int ans=-1;
        newlink=new nextlinks;
        newlink->index=n->index;
        strcpy(newlink->lname,n->lname);
        strcpy(newlink->type,n->type);
        newlink->bdays=n->bdays;
        newlink->next=NULL;
        while(newloc->down!=NULL)
        {
            cout<<"IS THE NEW LOCATION CONNECTED TO "<<newloc->lname<<"(0/1) ?  ";
            cin>>ans;
            if(ans==1)
            {
                cout<<" ENTER THE DISTANCE:";
                cin>>newlink->distance;
                if(newloc->next==NULL)
                {
                    newloc->next=new nextlinks;
                    newloc->next->index=newlink->index;
                    strcpy(newloc->next->lname,newlink->lname);
                    strcpy(newloc->next->type,newlink->type);
                    newloc->next->bdays=newlink->bdays;
                    newloc->next->distance=newlink->distance;
                    newloc->next->next=newlink->next;
                    /*newloc->next=newlink;*/
                }
                else
                {
                   // cout<<newloc->lname<<"*";
                    neww=newloc->next;
                    //cout<<neww->lname;
                    while(neww->next!=NULL)
                    {
                        //cout<<neww->lname<<"OO";
                        neww=neww->next;
                    }
                    neww->next=new nextlinks;
                    neww->next->index=newlink->index;
                    strcpy(neww->next->lname,newlink->lname);
                    strcpy(neww->next->type,newlink->type);
                    neww->next->bdays=newlink->bdays;
                    neww->next->distance=newlink->distance;
                    neww->next->next=newlink->next;
                    //cout<<"*"<<neww->lname<<neww->next->lname;
                    /*if(a==4)
                    {
                        cout<<"\n"<<newloc->down->lname<<" "<<newloc->down->next->next->next->lname;
                    }*/
                }
                //cout<<"\n 66";
                nextlinks *k=new nextlinks, *kk;
                k->index=newloc->index;
                strcpy(k->lname,newloc->lname);
                strcpy(k->type,newloc->type);
                k->bdays=newloc->bdays;
                k->distance=newlink->distance;
                k->next=NULL;
                if(n->next==NULL)
                {
                    //cout<<"cbbc";
                    n->next=k;
                }
                else
                {
                    //cout<<"caaac";
                    kk=n->next;
                    while(kk->next!=NULL)
                    {
                        kk=kk->next;
                    }
                    kk->next=k;
                    //cout<<"*";
                }
                ans=-1;
                //cout<<"\n 77";
            }
            //cout<<"\n 88";
            newloc=newloc->down;
        }
        cout<<"IS THE NEW LOCATION CONNECTED TO "<<newloc->lname<<"(0/1) ?  ";
            cin>>ans;
            if(ans==1)
            {
                cout<<" ENTER THE DISTANCE:";
                cin>>newlink->distance;
                if(newloc->next==NULL)
                {
                    newloc->next=newlink;
                }
                else
                {
              //      cout<<"BB";
                    neww=newloc->next;
                    while(neww->next!=NULL)
                    {
                        neww=neww->next;
                    }
                    neww->next=newlink;
                }
                //cout<<"\n 66";
                nextlinks *k=new nextlinks, *kk;
                strcpy(k->lname,newloc->lname);
                strcpy(k->type,newloc->type);
                k->bdays=newloc->bdays;
                k->index=newloc->index;
                k->distance=newlink->distance;
                k->next=NULL;
                if(n->next==NULL)
                {
                    n->next=k;
                }
                else
                {
                   // cout<<"AA";
                    kk=n->next;
                    while(kk->next!=NULL)
                    {
                        kk=kk->next;
                    }
                    kk->next=k;
                }
                ans=-1;
            }
        newloc->down=n;
    }
    return l;
}
void display(downlinks *l)
{
    downlinks *n;
    nextlinks *k;
    n=l;
    while(n!=NULL)
    {
        cout<<"\n "<<n->lname<<" "<<n->index;
        k=n->next;
        while(k!=NULL)
        {
            cout<<"  "<<k->lname<<" "<<k->index<<" "<<k->distance<<" ";
            k=k->next;
        }
        n=n->down;
    }
    getch();
}
int display_short(downlinks *l, int** arr,int n, char loc1[30], char loc2[30])
{
    downlinks *nn;
    nn=l;
    int a, b;
    while(nn!=NULL)
    {
        if(strcmpi(loc1, nn->lname)==0)
        a=nn->index;
        if(strcmpi(loc2, nn->lname)==0)
        b=nn->index;
        nn=nn->down;
    }
    /*cout<<"ENTER THE INDEX OF THE CURRENT AND FINAL LOCATION:";
    cin>>a>>b;*/
    return arr[a-1][b-1];
}
int shortest_path(int **arr,downlinks* r,int n, char loc1[30], char loc2[30])
{
    downlinks *l;
    l=r;
    while(l!=NULL)
    {
        int i=l->index-1;
        nextlinks* z=l->next;
        while(z!=NULL)
        {
            int q=z->index-1;

                   *(*(arr+i)+q)=z->distance;

            z=z->next;
        }
        l=l->down;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][k]!=INT_MAX&&arr[k][j]!=INT_MAX&&arr[i][j]>arr[i][k]+arr[k][j])
                    arr[i][j]=arr[i][k]+arr[k][j];
            }
        }
    }
    int kk;
    kk=display_short(r, arr,n, loc1, loc2);
    return kk;
}
struct drivers
{
    char dname[50];
    char city[30];
    char pno[11];
    char gender;
    int rating;
};
class customer;
class cabs
{
    char type[20];
    char name[20];
    float distance;
    drivers d;
    int rate;
    float fuel;
    int mileage;
    int norides;
    float earned;
    int cabid;
    int locationid;
    char location[30];
    int status;
    customer *c;
    public:
            cabs()
            {
                d.rating=norides=0;
                earned=0.0;
                status=0;
            }
            void getcabdets()
            {
                cout<<"\n\n\n\n\n\t\t";
                cout<<" ENTER NAME:";
                cin>>name;
                cout<<"\t\t ENTER CABID:";
                cin>>cabid;
                cin.get();
                cout<<"\n\t\t\t\t ENTER DRIVER'S DETAILS \n \t NAME: ";
                gets(d.dname);
                cout<<"\t  CITY: ";
                cin>>d.city;
                cout<<"\t  PHONE NO.:";
                cin>>d.pno;
                cout<<"\t  GENDER:";
                cin>>d.gender;
                cabtype:
                cout<<"\n\t\t\t CHOOSE TYPE:";
                cout<<"\n\t\t 1. PREMIUM \n\t\t 2. SUV  \n\t\t 3. MINI \n     CHOICE:";
                int c;
                cin>>c;
                switch(c)
                {
                    case 1: strcpy(type, "PREMIUM");
                            rate=10;
                            fuel=24;
                            mileage=25;
                            break;
                    case 2: strcpy(type, "SUV");
                            rate=14;
                            fuel=22.0;
                            mileage=16;
                            break;
                    case 3: strcpy(type, "MINI");
                            rate=7;
                            fuel=20.0;
                            mileage=22;
                            break;
                    default: cout<<"**********************INVALID CHOICE*************************";
                             goto cabtype;
                }
            }
            void modify()
            {
                int cmileage, crate, k, l;
                char dnam[50], dpno[11];
                char typ[20], dcit[30];
                float fu;
                crate=-1;
                cmileage=-1;
                strcpy(dpno, "*");
                strcpy(dcit, "*");
                cout<<"\n\t CAB ID :"<<cabid;
                cout<<"\n\t CAB NAME: "<<name;
                cout<<"\n\t CAB TYPE: "<<type;
                cout<<"\n\t CAB RATE: "<<rate;
                cout<<"\t\t MILEAGE "<<mileage;
                cout<<"\t\t FUEL: "<<fuel;
                cout<<"\n\t DRIVER NAME: "<<d.dname;
                cout<<"\n\t DRIVER CITY: "<<d.city;
                cout<<"\n\t DRIVER PHONE NO.: "<<d.pno;
                cout<<"\n\t DO YOU WANT TO CHANGE THE TYPE OF CAB(0 to retain old): ";
                cin>>k;
                if(k==0)
                    {
                        cout<<"\n\t ENTER MILEAGE(-1 to retain old): ";
                        cin>>cmileage;
                        cout<<"\n\t ENTER RATE(-1 to retain old): ";
                        cin>>crate;
                    }
                else
                {
                    cout<<"\n CHOOSE TYPE:";
                    cout<<"\n 1. PREMIUM \n 2. SUV  \n 3.MINI \n   CHOICE:";
                    int c;
                    cin>>c;
                    switch(c)
                    {
                        case 1: strcpy(type, "PREMIUM");
                                rate=10;
                                fuel=24;
                                mileage=25;
                                break;
                        case 2: strcpy(type, "SUV");
                                rate=14;
                                fuel=22.0;
                                mileage=16;
                                break;
                        case 3: strcpy(type, "MINI");
                                rate=7;
                                fuel=20.0;
                                mileage=22;
                                break;
                     }
                  }
                cout<<"\n\t DO YOU WANT TO CHANGE THE DRIVER OF CAB(0 to retain old): ";
                cin>>l;
                if(l==0)
                {
                    cout<<"\n\t ENTER CITY OF DRIVER(* to retain old): ";
                    cin>>dcit;
                    cout<<"\n\t ENTER PHONE NO. OF DRIVER(* to retain old): ";
                    cin>>dpno;
                }
                else
                {
                    cin.get();
                    cout<<"\n ENTER DRIVER'S DETAILS \n  NAME: ";
                    gets(d.dname);
                    cout<<"  CITY: ";
                    cin>>d.city;
                    cout<<"  PHONE NO.:";
                    cin>>d.pno;
                    cout<<"  GENDER:";
                    cin>>d.gender;
                }
                if(strcmpi( "*", dcit)!=0)
                    strcpy(d.city, dcit);
                if(strcmpi("*", dpno)!=0)
                    strcpy(d.pno, dpno);
                if(crate!=-1)
                    {rate=crate;}
                if(cmileage!=-1)
                    {mileage=cmileage;}
            }
            void getlocation(int id, char a[30])
            {
                locationid=id;
                strcpy(location, a);
            }
            void updateride(int dis)
            {
                status=1;
                norides++;
                distance=distance+dis;
                earned=earned+(dis*rate);
                //cout<<norides<<" "<<distance<<" "<<earned<<" "<<cabid;
                //getch();
            }
            void getcust(customer * cc)
            {
                c=cc;
            }
            int retstatus()
            {
                return status;
            }
            int retrate()
            {
                return rate;
            }
            char* retloc()
            {
                return location;
            }
            int retcid()
            {
                return cabid;
            }
            int retnorides()
            {
                return norides;
            }
            float retearned()
            {
                return earned;
            }
            void getstatus()
            {
                status=0;
            }
            void updateend(char loc[30])
            {
                status=0;
                strcpy(location, loc);
                c=NULL;
                cout<<"\n\n\t\t HOW WAS THE RIDE??? ";
                int k;
                cin>>k;
                d.rating=(d.rating+k)/2;
            }
            void cabdisplay1()
            {
                cout<<"\n"<<setw(10)<<cabid<<setw(14)<<name<<setw(15)<<type<<setw(17)<<location<<setw(19)<<d.dname<<setw(13)<<norides<<setw(14)<<earned<<setw(11)<<d.rating;
            }
            void driverdisplay()
            {
                cout<<"\n"<<setw(14)<<cabid<<setw(19)<<d.dname<<setw(14)<<d.city<<setw(15)<<d.pno<<setw(8)<<d.gender<<setw(13)<<norides<<setw(17)<<earned<<setw(11)<<d.rating;
            }
            void cabdisplay2()
            {
                cout<<"\n"<<setw(14)<<cabid<<setw(18)<<name<<setw(20)<<type<<setw(25)<<d.dname<<setw(19)<<rate<<setw(12)<<mileage;
            }
            /*void customer(customer * cc)
            {

            }*/
};
void aread()
{
 fstream f("cabss.dat",ios::in|ios::binary);
 cabs c;
 system("cls");
 cout<<"\n\t\t\t\t   \n\n";
cout<<"      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ CAB LIST ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
 cout<<setw(15)<<"CAB ID"<<setw(16)<<"NAME"<<setw(20)<<"TYPE"<<setw(25)<<"DRIVER'S NAME"<<setw(20)<<"RATE"<<setw(15)<<"MILEAGE\n\n";
 cout<<"      ---------------------------------------------------------------------------------------------------------\n\n";
  if(!f)
{
       cout<<"\t no record";
       getch();
      return;
}
  while(f)
 {
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  break;
  c.cabdisplay2();
 }
 getch();
 return;
}
void aread1()
{
 fstream f("cabss.dat",ios::in|ios::binary);
 cabs c;
 system("cls");
 cout<<"\n\t\t\t\t   \n\n";
cout<<"   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ CAB LIST ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
 cout<<setw(10)<<"CAB ID"<<setw(15)<<"NAME"<<setw(14)<<"TYPE"<<setw(18)<<"LOCATION"<<setw(20)<<"DRIVER'S NAME"<<setw(16)<<"NO. OF RIDES"<<setw(12)<<"EARNDED"<<setw(13)<<"RATING\n\n";
 cout<<"   ----------------------------------------------------------------------------------------------------------------\n\n";
  if(!f)
{
       cout<<"\t no record";
       getch();
      return;
}
  while(f)
 {
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  break;
  c.cabdisplay1();
 }
 getch();
 return;
}
void aread2()
{
 fstream f("cabss.dat",ios::in|ios::binary);
 cabs c;
 system("cls");
 cout<<"\n\t\t\t\t   \n\n";
cout<<"      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ CAB LIST ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
 cout<<setw(15)<<"CAB ID"<<setw(17)<<"DRIVER'S NAME"<<setw(13)<<"CITY"<<setw(16)<<"PHONE NO."<<setw(12)<<"GENDER"<<setw(18)<<"NO. OF RIDES"<<setw(12)<<"EARNDED"<<setw(13)<<"RATING\n\n";
 cout<<"      ---------------------------------------------------------------------------------------------------------\n\n";
  if(!f)
{
       cout<<"\t no record";
       getch();
      return;
}
  while(f)
 {
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  break;
  c.driverdisplay();
 }
 getch();
 return;
}
void append()
{
 char ans='y';
 cabs c;
 fstream f("cabss.dat",ios::binary|ios::out|ios::app);
  if(!f)
 {
  cout<<"\t CAN'T PROCEED\t";
  getch();
  exit(0);
 }
 while(ans=='y'||ans=='Y')
 {
  c.getcabdets();
  f.write((char*)&c,sizeof(c));
  cout<<"\n RECORD ADDED \n \t DO YOU WISH TO CONTINUE?";
  cin>>ans;
 }
 f.close();
}
void adelete()
{
 fstream temp,f;
 f.open("cabss.dat",ios::in|ios::binary);
 temp.open("temp.dat",ios::out|ios::binary);
  if(!f||!temp)
 {
  cout<<"\n\t CAN'T PROCEED";
  getch();
  exit(0);
 }
 char nm[50],ans3;
 cabs c;
 int k;
 int flag=0;
 aread();
 cout<<"\n\n\t ENTER CAB ID OF THE CAB TO BE DELETED:";
 cin>>k;
 while(f)
 {
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  {
      getch();
      break;
  }
  if(c.retcid()==k)
  {
   cout<<"\n\t\tTHE DETAILS ARE....\n";
   c.cabdisplay1();
   flag=1;
   cout<<"\n\tDO YOU WISH TO DELETE(Y or N)= ";
   cin>>ans3;
    if(ans3=='y'||ans3=='Y')
      cout<<"\n\t RECORD DELETED \t\n";
    else
    temp.write((char*)&c,sizeof(c));
  }
  else
{
   temp.write((char*)&c,sizeof(c));
}
}
f.close();
temp.close();
remove("cabss.dat");
rename("temp.dat","cabss.dat");
  if(flag==0)
  cout<<"\n\t record not found\t\n";
  f.close();
 }

void amodify()
{
 int flag=0, k;
 char nm[50];
 cabs c;
 fstream f;
 f.open("cabss.dat",ios::in|ios::out|ios::binary);
 if(!f)
 {
  cout<<"Cannot proceed. Exitting..";
  getch();
  exit(0);
 }
 aread();
 cout<<"\n\n\tENTER CABID OF CAB WHOSE RECORDS ARE TO BE MODIFIED: ";
 cin>>k;
int p;
 while(f)
{
  p=f.tellg();
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  { break;  }
   if(c.retcid()==k)
 {
  cout<<"\n\t RECORD FOUND \t\n";
  c.modify();
  f.seekg(p,ios::beg);
  f.write((char*)&c,sizeof(c));
  cout<<"\tRECORD MODIFIED \n";
  c.cabdisplay2();
  flag=1;
  break;
 }
}
if(flag==0)
  cout<<"\tRecord Not Found";
 f.close();
 getch();
}
int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y / 4 - y / 100 +
             y / 400 + t[m - 1] + d) % 7;
}
int countcabs()
{
    int flag=0, k;
    char nm[50];
    cabs c;
    fstream f;
    f.open("cabss.dat",ios::in|ios::out|ios::binary);
    if(!f)
    {
    cout<<"Cannot proceed. Exitting..";
    getch();
    exit(0);
    }
    int d=0;
    while(f)
    {
        f.read((char*)&c,sizeof(c));
        if(f.eof())
        break;
        d++;
    }
    //cout<<d<<" ";
    return d;
}
void allocate(downlinks *root)
{
    int flag=0, k;
    cabs c;
    fstream f;
    if(root==NULL)
    {
        return;
    }
    downlinks *n=root;
    downlinks *nr=root;
    downlinks *nc=root;
    downlinks *nm=root;
    f.open("cabss.dat",ios::in|ios::out|ios::binary);
    /*if(!f)
    {
    cout<<"Cannot proceed. Exitting..";
    getch();
    exit(0);
    }*/
    int p, dd, dc, dow, nocabs;
    nocabs=countcabs();
    //cout<<nocabs<<" ";
    nocabs=nocabs-nol;
    int nocabsr, nocabsc, nocabsm;
    dd=dc=0;
    time_t now = time(0);
	tm *ltm = localtime(&now);
    dow=dayofweek(ltm->tm_mday, 1+ltm->tm_mon, 1900+ltm->tm_year);
    if(dow>=1 && dow<=5)
    {
        if(ltm->tm_hour<22 && ltm->tm_hour>=10)
        {
            nocabsr=nocabs*0.3;
            nocabsm=nocabs*0.3;
            nocabsc=nocabs-nocabsr-nocabsm;
        }
        else
        {
            nocabsr=nocabs/2;
            nocabsm=nocabs*0.2;
            nocabsc=nocabs-nocabsr-nocabsm;
            //cout<<nocabsr<<" "<<nocabsc<<" "<<nocabsm<<" ";
        }
    }
    else
    {
        nocabsr=nocabs*0.4;
        nocabsc=nocabs*0.2;
        nocabsm=nocabs-nocabsr-nocabsc;
    }
    while(f)
    {
        p=f.tellg();
        f.read((char*)&c,sizeof(c));
        if(f.eof())
        { break;  }
        if(dd<nol)
        {
            //cout<<"\n"<<dd;
            c.getstatus();
            c.getlocation(n->index, n->lname);
            f.seekg(p,ios::beg);
            f.write((char*)&c,sizeof(c));
            n=n->down;
            dd++;
        }
        else
        {
            int ff=0;
            if(dc<nocabsr)
            {
                //cout<<nocabsr<<" "<<dc<<"\n";
                //cout<<" *-* "<<nr->lname;
                while(ff!=1)
                {
                    if(strcmp(nr->type,"RESIDENTIAL")==0)
                    {
                        //cout<<"*"<<nr->lname;
                        //cout<<" *R* "<<nr->lname;
                        c.getstatus();
                        c.getlocation(nr->index, nr->lname);
                        f.seekg(p,ios::beg);
                        f.write((char*)&c,sizeof(c));
                        dc++;
                        ff=1;
                        //cout<<dc<<nr->lname;
                    }
                    nr=nr->down;
                    if(nr==NULL)
                    {
                        nr=root;
                    }
                }
            }
            else if((dc-nocabsr)<nocabsc)
            {
                //cout<<dc;
                while(ff!=1)
                {
                    if(strcmp(nc->type,"COMMERCIAL")==0)
                    {
                        //cout<<" *C* "<<nc->lname;
                        c.getstatus();
                        c.getlocation(nc->index, nc->lname);
                        f.seekg(p,ios::beg);
                        f.write((char*)&c,sizeof(c));
                        dc++;
                        ff=1;
                        //cout<<"*"<<nc->lname;
                    }
                    nc=nc->down;
                    if(nc==NULL)
                    {
                        nc=root;
                    }
                }
            }
            else
            {
                //cout<<dc;
                while(ff!=1)
                {
                    if(strcmp(nm->type,"MARKET")==0)
                    {
                        //cout<<" *M* "<<nm->lname;
                        c.getstatus();
                        c.getlocation(nm->index, nm->lname);
                        f.seekg(p,ios::beg);
                        f.write((char*)&c,sizeof(c));
                        dc++;
                        ff=1;
                        //cout<<dc<<nm->lname;
                    }
                    nm=nm->down;
                     if(nm==NULL)
                    {
                        nm=root;
                    }
                }
            }
        }
    }
}
cabs* check(char loc[30])
{
     /*cabs c;
    cabs *d=NULL;

    fstream f;
    f.open("cabss.dat",ios::in|ios::out|ios::binary);
    if(!f)
    {
    cout<<"Cannot proceed. Exitting..";
    getch();
    exit(0);
    }
    int k=0;
    while(f)
    {
        cout<<1;
        f.read((char*)&c,sizeof(c));
        if(f.eof())
        break;
        cout<<c.retloc()<<" "<<loc;
        if((strcmpi(loc, c.retloc())==0) && c.retstatus()==0)
        {

            d=&c;
            cout<<2;
            k=1;
            d->cabdisplay1();
            return d;
        }
    }
    if(k==0)
    {
        cout<<"\n\n\t\t SORRY.. NO CABS ARE AVAILABLE AT YOUR LOCATION!!";
        getch();
        return d;
    }*/
}
struct ride
{
    char sloc[30], floc[30];
    int dd, mm, yyyy;
    int hr, mins, secs;
    cabs *cabb;
    int id, cid;
    float fare;
    int distance;
};
class customer
{
    char custname[50];
    int custid;
    int trides;
    int bd, bm, by;
    char gender;
    char phone[11];
    char password[15];
    ride *r;

    public: customer()
            {
                trides=0;
                r=NULL;
            }
            void getcustdets()
            {
                cout<<"\n\n\n\n\n";
                cout<<"      --------------------------------------------------------------------------------------------------------\n\n";
                cout<<"\t\t\t\t ENTER CUSTOMER DETAILS\n\n";
                cout<<"      --------------------------------------------------------------------------------------------------------\n\n";
                cout<<"\t\t\t ENTER USER ID:";
                cin>>custid;
                cin.get();
                cout<<"\t\t\t ENTER USER NAME:";
                gets(custname);
                cout<<"\t\t\t ENTER GENDER:";
                cin>>gender;
                cout<<"\t\t\t ENTER DOB:";
                cin>>bd>>bm>>by;
                cout<<"\t\t\t ENTER PHONE NO.:";
                cin>>phone;
                cout<<"\t\t\t ENTER PASSWORD:";
                cin>>password;
                /*cout<<"\t\t\t ENTER PASSWORD:";
                cin>>password;*/
            }
            void modify()
            {
                int k, l;
                char p[15];
                cout<<"\n\t\t CUSTOMER DETAILS ";
                cout<<"\n\t CUSTOMER ID: "<<custid;
                cout<<"\n\t CUSTOMER NAME: "<<custname;
                cout<<"\n\t PHONE NO.: "<<phone;
                cout<<"\t\t DOB: "<<bd<<"-"<<bm<<"-"<<by;
                cout<<"\t\t GENDER: "<<gender;
                cout<<"\n\t DO YOU WANT TO CHANGE THE PHONE NO.(0 to retain old): ";
                cin>>k;
                if(k!=0)
                    {
                        cout<<"\n\t ENTER NEW PHONE NO.: ";
                        cin>>phone;
                    }
                cout<<"\n\t DO YOU WANT TO CHANGE THE PASSWORD(0 to retain old): ";
                cin>>l;
                int d=0;
                if(l!=0 && d!=3)
                {
                    check:
                        d++;
                    cout<<"\n\t ENTER OLD PASSWORD:";
                     int i=0;
                      char ch;
                      ch=getch();
                      p[0]=ch;
                      while(ch!=char(13))
                      {
                            cout<<"*";
                            ch=getch();
                            if(ch==char(13))
                                break;
                            i++;
                            p[i]=ch;
                      }
                      p[++i]='\0';
                    if(strcmp(p, password)==0)
                    {
                        cout<<"\t ENTER NEW PASSWORD:";
                        cin>>password;
                    }
                    else
                    {
                        cout<<"\n ******** ERROR!!! PASSWORD DOES NOT MATCH!! TRY AGAIN! **************** ";
                        if(d!=3)
                        goto check;
                        else
                            cout<<"\n\t\t WRONG PASSWORD ENTERED!!!";
                    }
                }
            }
            int retcustid()
            {
                return custid;
            }
            char* retpassword()
            {
                return password;
            }
            ride* retridedets()
            {
                return r;
            }
            char retgend()
            {
                return gender;
            }
            void getride(int **a, downlinks *l, int n, char loc[30])
            {
                r=new ride;
                trides++;
                //cout<<loc;
                strcpy(r->sloc, loc);
                cabs c;
                cabs *d=NULL;
                {fstream f;
                f.open("cabss.dat",ios::in|ios::out|ios::binary);
                if(!f)
                {
                    cout<<"Cannot proceed. Exitting..";
                    getch();
                    exit(0);
                }
                int k=0;
                while(f)
                {
                    //cout<<1;
                    f.read((char*)&c,sizeof(c));
                    if(f.eof())
                    break;
                    //cout<<c.retloc()<<" "<<loc;
                    if((strcmpi(loc, c.retloc())==0) && c.retstatus()==0)
                    {
                       //cout<<c.retloc()<<" "<<loc;
                        d=&c;
                        cout<<2;
                        k=1;
                        d->cabdisplay1();
                        break;
                    }
                }}
                /*r->cabb=*/
                //check(r->sloc)->cabdisplay1();
                r->cabb=d;
                cout<<"\t\t ENTER THE LOCATION YOU WANT TO VISIT:";
                cin>>r->floc;
                r->distance=shortest_path(a, l, n, r->sloc, r->floc);
                r->cabb->updateride(r->distance);
                r->fare=((r->cabb->retrate())*r->distance);
                r->cabb->cabdisplay1();
                r->cabb->getcust(this);

                {int flag=0, k;
                char nm[50];
                cabs c;
                fstream f;
                f.open("cabss.dat",ios::in|ios::out|ios::binary);
                if(!f)
                {
                    cout<<"Cannot proceed. Exitting..";
                    getch();
                    exit(0);
                }
                int p;
                while(f)
                {
                    p=f.tellg();
                    f.read((char*)&c,sizeof(c));
                    if(f.eof())
                    { break;  }
                    if(c.retcid()==r->cabb->retcid())
                    {
  //cout<<"\n\t RECORD FOUND \t\n";
  //c.modify();
                        f.seekg(p,ios::beg);
                        f.write((char*)&(*(r->cabb)),sizeof(*(r->cabb)));
  //cout<<"\tRECORD MODIFIED \n";
  //c.cabdisplay2();
                        flag=1;
                        break;
                    }
                }}

                time_t now = time(0);
                tm *ltm = localtime(&now);
				 r->hr=ltm->tm_hour;
				 r->mins=ltm->tm_min;
				 r->secs=ltm->tm_sec;
				 r->dd=ltm->tm_mday;
				 r->mm=1+ltm->tm_mon;
				 r->yyyy=1900+ltm->tm_year;
				 r->id=retcustid();

				 /*r->cid=*///cout<<r->cabb->retcid();
				 //customer c;
				 r->cid=r->cabb->retcid();
				 //cout<<r->cid;
				 //cout<<"\n";
				 //getch();
                 fstream f;
                 f.open("rides.dat",ios::binary|ios::out|ios::app);
                 if(!f)
                    {
                        cout<<"\t CAN'T PROCEED\t";
                        getch();
                        exit(0);
                    }
                    //cout<<8;
                    getch();
                  f.write((char*)&(*r),sizeof((*r)));
                  //cout<<"\n"<<setw(8)<<r->id<<setw(20)<<r->sloc<<setw(20)<<r->floc<<setw(14)<<r->distance<<setw(16)<<r->fare<<setw(18)<<r->dd<<"-"<<r->mm<<"-"<<r->yyyy<<setw(12)<<r->cabb->retcid();
                  //cout<<7;
                  //cout<<r->cabb->retcid();
                  getch();
                  f.close();
            }
            void custdisp()
            {
                cout<<"\n"<<setw(16)<<custid<<setw(24)<<custname<<setw(10)<<gender<<setw(12)<<bd<<"-"<<bm<<"-"<<by<<setw(19)<<phone<<setw(11)<<trides;
            }
            void rideend()
            {
                r=NULL;
            }
};
void endride()
{
    customer c;
    fstream f;
    ride r;
    f.open("rides.dat",ios::in|ios::out|ios::binary);
    //fstream fr("rides.dat",ios::binary|ios::out|ios::app);
    if(!f )
    {
    cout<<"\t CAN'T PROCEED\t";
    getch();
    exit(0);
    }
    int k;
    int a;
    char loc[30];
    cout<<"\n\n\t\t ENTER YOUR CAB ID:";
    cin>>k;
    while(f)
    {
        //p=f.tellg();
        f.read((char*)&r,sizeof(r));
        if(f.eof())
        {/* cout<<"HELLO";
            getch();*/
            break;  }
        if(r.cid==k)
        {
            a=r.id;
            strcpy(loc, r.floc);
        }
    }
    f.close();
    int p, flag;
    flag=0;
    f.open("customers.dat",ios::in|ios::out|ios::binary);
    if(!f )
    {
    cout<<"\t CAN'T PROCEED\t";
    getch();
    exit(0);
    }
    while(f)
    {
        p=f.tellg();
        f.read((char*)&c,sizeof(c));
        if(f.eof())
        { break;  }
        if(c.retcustid()==a)
        {
            c.rideend();
            f.seekg(p,ios::beg);
            flag=1;
            f.write((char*)&c,sizeof(c));
            //cout<<"\tRECORD MODIFIED \n";
            //c.custdisp();
            break;
        }
    }
    f.close();
    flag=0;
    cabs cc;
    f.open("cabss.dat",ios::in|ios::out|ios::binary);
    if(!f)
    {
        cout<<"Cannot proceed. Exitting..";
        getch();
        exit(0);
    }
    while(f)
    {
        p=f.tellg();
        f.read((char*)&cc,sizeof(cc));
        if(f.eof())
        { break;  }
        if(cc.retcid()==k)
        {
            flag=1;
            cc.updateend(loc);
            f.seekg(p,ios::beg);
            f.write((char*)&cc,sizeof(cc));
            //cout<<"\tRECORD MODIFIED \n";
            //c.custdisp();
            break;
        }
    }
}
void startride(downlinks *l)
{
    customer c;
    fstream f;

    f.open("customers.dat",ios::in|ios::out|ios::binary);
    //fstream fr("rides.dat",ios::binary|ios::out|ios::app);
    if(!f )
    {
    cout<<"\t CAN'T PROCEED\t";
    getch();
    exit(0);
    }
    int k;
    cout<<"\n\t\t ENTER YOUR CUSTOMER ID:";
    cin>>k;
    int ** a=new int*[nol];
    for(int i=0;i<nol;i++)
    {
        a[i]=new int[nol];
        for(int j=0;j<nol;j++)
        {
            if(i==j)
                a[i][j]=0;
            else
                a[i][j]=INT_MAX;
        }
    }
        //cout<<1;
    getch();
    char cpass[30];
    int p, flag=0;
    char loc[30];
    while(f)
    {
        p=f.tellg();
        f.read((char*)&c,sizeof(c));

        if(f.eof())
        { //cout<<"HELLO";
            //getch();
            break;  }
        if(c.retcustid()==k)
        {
            c.custdisp();
            cout<<"\n\t RECORD FOUND \t\n";
            flag=1;
            check2:
            cout<<"\t\t ENTER PASSWORD TO ACCOUNT:";
                int i=0;
                char ch;
                ch=getch();
                cpass[0]=ch;
                while(ch!=char(13))
                {
                    cout<<"*";
                    ch=getch();
                    if(ch==char(13))
                        break;
                    i++;
                    cpass[i]=ch;
                }
                cpass[++i]='\0';
        if(strcmp(cpass, c.retpassword())==0)
        {
            cout<<"\n\n\t\tENTER YOUR CURRENT LOCATION:";
            cin>>loc;
            {
                cabs c;
                cabs *d=NULL;
                fstream f;
                f.open("cabss.dat",ios::in|ios::out|ios::binary);
                if(!f)
                {
                    cout<<"Cannot proceed. Exitting..";
                    getch();
                    exit(0);
                }
                int k=0;
                while(f)
                {
                    //cout<<1;
                    f.read((char*)&c,sizeof(c));
                    if(f.eof())
                    break;
                    //cout<<c.retloc()<<" "<<loc;
                    if((strcmpi(loc, c.retloc())==0) && c.retstatus()==0)
                    {
                        d=&c;
                        //cout<<2;
                        k=1;
                        //d->cabdisplay1();
                    }
                }
                if(k==0)
                {
                    cout<<"\n\n\t\t SORRY.. NO CABS ARE AVAILABLE AT YOUR LOCATION!!";
                    getch();
                    break;
                }
            }
            /*if(check(loc)==NULL)
            {
                cout<<1;
                getch();
                break;
            }*/
            //cout<<1;
            c.getride(a, l, nol, loc);
            //cout<<2;
            f.seekg(p,ios::beg);
            f.write((char*)&c,sizeof(c));
            break;
        }
        else
        {
            cout<<"********** ERROR WRONG PASSWORD!! RETRY!!! ***********";
            goto check2;
        }
 }
}
}
void custaread()
{
 fstream f("customers.dat",ios::in|ios::binary);
 customer c;
 system("cls");
 cout<<"\n\t\t\t\t   \n\n";
cout<<"      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ CUSTOMER'S LIST ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
 cout<<setw(15)<<"ID"<<setw(20)<<"NAME"<<setw(17)<<"GENDER"<<setw(18)<<"BIRTH DATE"<<setw(17)<<"PHONE NO."<<setw(18)<<"TOTAL RIDES\n\n";
 cout<<"      ---------------------------------------------------------------------------------------------------------\n\n";
  if(!f)
{
       cout<<"\t no record";
       getch();
      return;
}
  while(f)
 {
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  break;
  c.custdisp();
 }
 getch();
 return;
}
void aridedisplay()
{
 fstream f("rides.dat",ios::in|ios::binary);
 //fstream fr("rides.dat",ios::in|ios::binary);
 customer c;
 ride r;
 system("cls");
 cout<<"\n  \n\n";
cout<<"      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ CAB'S RIDES ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
 cout<<setw(8)<<"ID"<<setw(22)<<"START POINT"<<setw(22)<<"DESTINATION"<<setw(14)<<"DISTANCE"<<setw(12)<<"FARE"<<setw(22)<<"RIDE DATE AND TIME"<<setw(18)<<"CUSTOMER ID\n\n";
 cout<<"      -------------------------------------------------------------------------------------------------------------\n\n";
  if(!f)
{
       cout<<"\t no record";
       getch();
      return;
}
int id;
cout<<"ENTER CAB ID:";
cin>>id;
  while(f)
 {
  f.read((char*)&r,sizeof(r));
  if(f.eof())
  break;
  if(id==r.cid)
  {
      cout<<"\n"<<setw(9)<<r.cid<<setw(20)<<r.sloc<<setw(20)<<r.floc<<setw(14)<<r.distance<<setw(12)<<r.fare<<setw(13)<<r.dd<<"-"<<r.mm<<"-"<<r.yyyy<<"   "<<r.hr<<":"<<r.mins<<":"<<r.secs<<setw(10)<<r.id;
  }
 }
 getch();
 return;
}
void custaridedisplay()
{
 fstream f("rides.dat",ios::in|ios::binary);
 //fstream fr("rides.dat",ios::in|ios::binary);
 customer c;
 ride r;
 system("cls");
 cout<<"\n  \n\n";
cout<<"      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ CUSTOMER'S RIDES ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
 cout<<setw(8)<<"ID"<<setw(21)<<"START POINT"<<setw(21)<<"DESTINATION"<<setw(14)<<"DISTANCE"<<setw(12)<<"FARE"<<setw(22)<<"RIDE DATE AND TIME"<<setw(18)<<"CAB ID\n\n";
 cout<<"      -------------------------------------------------------------------------------------------------------------\n\n";
  if(!f)
{
       cout<<"\t no record";
       getch();
      return;
}
int id;
cout<<"ENTER CUSTOMER ID:";
cin>>id;
  while(f)
 {
  f.read((char*)&r,sizeof(r));
  if(f.eof())
  break;
  //cout<<r.cabb->retcid();
  if(id==r.id)
  {
      cout<<"\n"<<setw(8)<<r.id<<setw(20)<<r.sloc<<setw(20)<<r.floc<<setw(12)<<r.distance<<setw(12)<<r.fare<<setw(13)<<r.dd<<"-"<<r.mm<<"-"<<r.yyyy<<"   "<<r.hr<<":"<<r.mins<<":"<<r.secs<<setw(12)<<r.cid;
  }
 }
 getch();
 return;
}
void custappend()
{
 char ans='y';
 customer c;
 fstream f("customers.dat",ios::binary|ios::out|ios::app);
  if(!f)
 {
  cout<<"\t CAN'T PROCEED\t";
  getch();
  exit(0);
 }
 while(ans=='y'||ans=='Y')
 {
  c.getcustdets();
  f.write((char*)&c,sizeof(c));
  cout<<"\n RECORD ADDED \n \t DO YOU WISH TO CONTINUE?";
  cin>>ans;
 }
 f.close();
}
void custadelete()
{
 fstream temp,f;
 f.open("customers.dat",ios::in|ios::binary);
 temp.open("temp.dat",ios::out|ios::binary);
  if(!f||!temp)
 {
  cout<<"\n\t CAN'T PROCEED";
  getch();
  exit(0);
 }
 char nm[50],ans3;
 customer c;
 int k;
 int flag=0;
 //custaread();
 cout<<"\n\n\t ENTER CUSTOMER ID OF THE CUSTOMER WHOSE ACCOUNT IS TO BE DELETED:";
 cin>>k;
 while(f)
 {
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  {
      getch();
      break;
  }
  if(c.retcustid()==k)
  {
   cout<<"\n\t\tTHE DETAILS ARE....\n";
   c.custdisp();
   flag=1;
   cout<<"\n\tDO YOU WISH TO DELETE(Y or N)= ";
   cin>>ans3;
    if(ans3=='y'||ans3=='Y')
      cout<<"\n\t RECORD DELETED \t\n";
    else
    temp.write((char*)&c,sizeof(c));
  }
  else
{
   temp.write((char*)&c,sizeof(c));
}
}
f.close();
temp.close();
remove("customers.dat");
rename("temp.dat","customers.dat");
  if(flag==0)
  cout<<"\n\t record not found\t\n";
  f.close();
 }

void custamodify()
{
 int flag=0, k;
 char cpass[15];
 customer c;
 fstream f;
 f.open("customers.dat",ios::in|ios::out|ios::binary);
 if(!f)
 {
  cout<<"Cannot proceed. Exitting..";
  getch();
  exit(0);
 }
 //custaread();
 cout<<"\n\n\tENTER ID OF CUSTOMER WHOSE DETAILS ARE TO BE MODIFIED: ";
 cin>>k;
int p;
 while(f)
{
  p=f.tellg();
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  { break;  }
   if(c.retcustid()==k)
 {
    cout<<"\n\t RECORD FOUND \t\n";
    flag=1;
    check2:
    cout<<"\t\t ENTER PASSWORD TO ACCOUNT:";
                         int i=0;
                      char ch;
                      ch=getch();
                      cpass[0]=ch;
                      while(ch!=char(13))
                      {
                            cout<<"*";
                            ch=getch();
                            if(ch==char(13))
                                break;
                            i++;
                            cpass[i]=ch;
                      }
                      cpass[++i]='\0';
    if(strcmp(cpass, c.retpassword())==0)
    {
        c.modify();
        f.seekg(p,ios::beg);
        f.write((char*)&c,sizeof(c));
        cout<<"\tRECORD MODIFIED \n";
        c.custdisp();
        break;
    }
    else
    {
        cout<<"********** ERROR WRONG PASSWORD!! RETRY!!! ***********";
        goto check2;
    }
 }
}
if(flag==0)
  cout<<"\tRecord Not Found";
 f.close();
 getch();
}
int cfileexists(const char * filename){
    /* try to open file to read */
    FILE *file;
    if (file = fopen(filename, "r")){
        fclose(file);
        return 1;
    }
    return 0;
}
void intro()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"                |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n";
    cout<<"                ||----------------------------------------------------------------------------|| \n";
    cout<<"                ||  @@      @@  @@@@@@@@   @@      @@@@@@@   @@@@@@    @@       @@   @@@@@@@@ || \n";
    cout<<"                ||  @@      @@  @@         @@      @@       @@    @@   @@ @   @ @@   @@       || \n";
    cout<<"                ||  @@  @   @@  @@@@@      @@      @@       @@    @@   @@   @   @@   @@@@@    || \n";
    cout<<"                ||  @@ @  @ @@  @@         @@      @@       @@    @@   @@       @@   @@       || \n";
    cout<<"                ||  @@      @@  @@@@@@@@   @@@@@@  @@@@@@@   @@@@@@    @@       @@   @@@@@@@@ || \n";
    cout<<"                ||----------------------------------------------------------------------------|| \n";
    cout<<"                |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n";
    cout<<"\n\n\n";
    getch();
}
int main()
{
    //intro();
    int choice, c, i;
    char p[20];
    int d, c1, c2, c3;
    int k=0;
    downlinks *l, *n;
    l=NULL;
    //aread2();
    //cabs c;
    start:
	    system("cls");
	    cout<<"\n\n\n\n\n";
	    cout<<"\t\t===========================================================================================\n";
	    cout<<"\t\t\t\t\t\t    * * * * * * * * * \n";
        cout<<"\t\t\t\t\t\t    *   MAIN MENU   * \n";
        cout<<"\t\t\t\t\t\t    * * * * * * * * * \n";
        cout<<"\t\t===========================================================================================\n";
        cout<<"\n\n\t\t\t\t 1. LOCATIONS";
        cout<<"\n\t\t\t\t 2. CABS";
        cout<<"\n\t\t\t\t 3. CUSTOMERS";
        cout<<"\n\t\t\t\t 4. EXIT";
        cout<<"\n\t\t\t\t    CHOICE:";
        cin>>choice;
        switch(choice)
        {
            case 1:   cout<<"\n\n\n\n"<<setw(50)<<" PLEASE ENTER THE PASSWORD ";
                       i=0;
                      char ch;
                      ch=getch();
                      p[0]=ch;
                      while(ch!=char(13))
                      {
                            cout<<"*";
                            ch=getch();
                            if(ch==char(13))
                                break;
                            i++;
                            p[i]=ch;
                      }
                      p[++i]='\0';
                      if(strcmpi(p,"cabss123")!=0)	  //password is "cabss123"
                      {
                         cout<<"\n\n\n"<<setw(50)<<"  WRONG PASSWORD ";
                         cout<<"\n\t\t......access denied......\t\t\n";
                         getch();
                         exit(0);
                      }
                      tkk:
                         system("cls");
                         cout<<"\n\n\n\n\n\t"<<setw(45)<<" MENU \n";
                         cout<<"\n\t================================================================================\n";
                         cout<<"\t\t\t\t\t\t 1. ADDING LOCATION TO THE LIST\n";
                         cout<<"\t\t\t\t\t\t 2. DISPLAYING LOCATION ON THE LIST\n";
                         cout<<"\t\t\t\t\t\t 3. RETURN TO MAIN MENU\n";
                         cout<<"\t\t\t\t\t\t  CHOICE=";
                         cin>>c1;
                         switch(c1)
                         {
                             case 1: system("cls");
                                     k++;
                                     l=newlocation(l, 0);
                                     goto tkk;
                             case 2: system("cls");
                                     display(l);
                                     goto tkk;
                             case 3: system("cls");
                                     goto start;
                         }
                    break;
            case 2: /*if(k!=0 && cfileexists("cabss.dat"));
                    {allocate(l);
                    k=0;}*/
                    ttk:
                         system("cls");
                         cout<<"\n\n\n\n\n\n\t\t"<<setw(45)<<" MENU \n";
                         cout<<"\n\t\t===================================================================================\n";
                         cout<<"\n\t\t\t\t\t"<<" 1. ADDING CABS TO THE LIST\n";
                         cout<<"\t\t\t\t\t"<<" 2. ALLOCATE CABS\n";
                         cout<<"\t\t\t\t\t"<<" 3. END RIDE\n";
                         cout<<"\t\t\t\t\t"<<" 4. MODIFYING CAB DETAILS\n";
                         cout<<"\t\t\t\t\t"<<" 5. DELETING CABS \n";
                         cout<<"\t\t\t\t\t"<<" 6. DISPLAY CAB DETAILS\n";
                         cout<<"\t\t\t\t\t"<<" 7. DISPLAY DRIVER DETAILS\n";
                         cout<<"\t\t\t\t\t"<<" 8. DISPLAY RIDE DETAILS\n";
                         cout<<"\t\t\t\t\t"<<" 9. RETURN TO MAIN MENU\n";
                         cout<<"\t\t\t\t\t"<<" CHOICE=";
                         cin>>c2;
                         switch(c2)
                         {
                             case 1: system("cls");
                                     append();
                                     goto ttk;
                             case 2: allocate(l);
                                     cout<<"\n\n\t\t ALLOCATED CABS SUCCESSFULLY";
                                     goto ttk;
                             case 3: system("cls");
                                     endride();
                                     goto ttk;
                             case 4: system("cls");
                                     amodify();
                                     goto ttk;
                             case 5: system("cls");
                                     adelete();
                                     goto ttk;
                             case 6: system("cls");
                                     aread1();
                                     goto ttk;
                             case 7: system("cls");
                                     aread2();
                                     goto ttk;
                             case 8: system("cls");
                                     aridedisplay();
                                     goto ttk;
                             case 9: system("cls");
                                     goto start;
                         }
                     break;
            case 3:
                     tk:
                         system("cls");
                         cout<<"\n\n\n\n\n\n\t\t"<<setw(45)<<" MENU \n";
                         cout<<"\n\t\t===================================================================================\n";
                         cout<<"\n\t\t\t\t\t"<<" 1. ADDING CUSTOMER ACCOUNT\n";
                         cout<<"\t\t\t\t\t"<<" 2. START RIDE\n";
                         cout<<"\t\t\t\t\t"<<" 3. MODIFYING CUSTOMER DETAILS\n";
                         cout<<"\t\t\t\t\t"<<" 4. DELETING CUSTOMER ACCOUNT \n";
                         cout<<"\t\t\t\t\t"<<" 5. DISPLAY CUSTOMER ACCOUNTS\n";
                         cout<<"\t\t\t\t\t"<<" 6. DISPLAY CUSTOMER RIDES\n";
                         cout<<"\t\t\t\t\t"<<" 7. RETURN TO MAIN MENU\n";
                         cout<<"\t\t\t\t\t"<<" CHOICE=";
                         cin>>c3;
                         switch(c3)
                         {
                             case 1: system("cls");
                                     custappend();
                                     goto tk;
                             case 2: system("cls");
                                     startride(l);
                                     goto tk;
                             case 3: system("cls");
                                     custamodify();
                                     goto tk;
                             case 4: system("cls");
                                     custadelete();
                                     goto tk;
                             case 5: system("cls");
                                     custaread();
                                     goto tk;
                             case 6: system("cls");
                                     custaridedisplay();
                                     goto tk;
                             case 7: system("cls");
                                     goto start;
                         }
                     break;
            case 4:  getch();
                     exit(0);


        }
    return 0;
}

final.cpp
Displaying final.cpp.
