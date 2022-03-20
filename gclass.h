#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>//12:15am
#include<fstream.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
//global functions
int i;
char binaryfile[10];
char textfile[10];
//prototypes
void heading(),load(int),onlyheading(),loginpage(),messages(),settings(),load(char[]);
int choice();
//class
class user
{
    public:
    char name[20],username[20],password[20];
    int dob[3];
    void login(),createaccount(),userpage(),sendm(),readm();
};user u;
//class functions
void user::userpage()
{
    heading();
    cout<<"\t\t\t      Welcome "<<u.name<<"!\n";
    cout<<"1. Messages\n2. Settings\n3. Logout\n4. Exit";
    switch(choice())
    {
        case 1:
        messages();
        break;
        case 2:
        settings();
        break;
        case 3:
        load("     LOGGING OUT!");
        loginpage();
        getch();
        break;
        default:load(2);
    }
    u.userpage();
}
void user::login()
{
    char tempusername[20];
    heading();
    int flag=0;
    cout<<"\t\t\t   ________________________";
    cout<<"\n\t\t\t   | Enter username::";
    gets(tempusername);
    load("Looking for an account by that name");
    ifstream ib(binaryfile,ios::binary);
    while(ib.read((char*)&u,sizeof(u)))
    {
        if (!strcmp(tempusername,u.username))
        {
            flag=1;
            break;
        }
    }
    ib.close();
    if (!flag)
    {
        onlyheading();
        cout<<"That username doesn't exist!";
        getch();
    }
    if (flag==1)
    {
        char p[20];
        i=0;
        int j;
        while(i<strlen(u.password))
        {
            clrscr();
            onlyheading();
            cout<<u.name<<"'s account found!";
            cout<<"\nPassword::";
            for (j=0;j<i;j++)
                {
                cout<<"*";
                }
            delay(50);
            if(kbhit())
                {
                switch(getch())
                    {
                    case '1': p[i]='1';break;
                    case '2': p[i]='2';break;
                    case '3': p[i]='3';break;
                    case '4': p[i]='4';break;
                    case '5': p[i]='5';break;
                    case '6': p[i]='6';break;
                    case '7': p[i]='7';break;
                    case '8': p[i]='8';break;
                    case '9': p[i]='9';break;
                    case 'a': p[i]='a';break;
                    case 'b': p[i]='b';break;
                    case 'c': p[i]='c';break;
                    case 'd': p[i]='d';break;
                    case 'e': p[i]='e';break;
                    case 'f': p[i]='f';break;
                    case 'g': p[i]='g';break;
                    case 'h': p[i]='h';break;
                    case 'i': p[i]='i';break;
                    case 'j': p[i]='j';break;
                    case 'k': p[i]='k';break;
                    case 'l': p[i]='l';break;
                    case 'm': p[i]='m';break;
                    case 'n': p[i]='n';break;
                    case 'o': p[i]='o';break;
                    case 'p': p[i]='p';break;
                    case 'q': p[i]='q';break;
                    case 'r': p[i]='r';break;
                    case 's': p[i]='s';break;
                    case 't': p[i]='t';break;
                    case 'u': p[i]='u';break;
                    case 'v': p[i]='v';break;
                    case 'w': p[i]='w';break;
                    case 'x': p[i]='x';break;
                    case 'y': p[i]='y';break;
                    case 'z': p[i]='z';break;
                    default:break;
                    }
                i++;
                }
        }
        for (i=0;i<strlen(u.password);i++)
        {
            if (p[i]!=u.password[i])
            {
                cout<<"*\n\n\t\t\t\t  WRONG PASSWORD!";
                getch();
                flag=2;
                break;
            }
        }
        if (flag==1)
        {
            cout<<"*\n\n\t\t\t\t LOGIN SUCCESS!";
            getch();
            u.userpage();
        }
    }
}
void user::createaccount()
{
    ofstream ob(binaryfile,ios::binary|ios::app);
    ofstream ot(textfile,ios::app);
    heading();
    cout<<"\t\t______________________________";
    cout<<"\n\t\t|  Enter your name:";
    gets(u.name);
    cout<<"\n\t\t|  Choose a username:";
    gets(u.username);
    cout<<"\n\t\t|  Choose a password:";
    gets(u.password);
    cout<<"\n\t\t|  Enter your date of birth:";
    cin>>u.dob[0];
    clrscr();
    onlyheading();
    cout<<"\t\t______________________________";
    cout<<"\n\t\t|  Enter your name:";
    cout<<u.name<<endl;
    cout<<"\n\t\t|  Choose a username:";
    cout<<u.username<<endl;
    cout<<"\n\t\t|  Choose a password:";
    cout<<u.password<<endl;
    cout<<"\n\t\t|  Enter your date of birth:";
    cout<<u.dob[0]<<"/";
    cin>>u.dob[1];
    clrscr();
    onlyheading();
    cout<<"\t\t______________________________";
    cout<<"\n\t\t|  Enter your name:";
    cout<<u.name<<endl;
    cout<<"\n\t\t|  Choose a username:";
    cout<<u.username<<endl;
    cout<<"\n\t\t|  Choose a password:";
    cout<<u.password<<endl;
    cout<<"\n\t\t|  Enter your date of birth:";
    cout<<u.dob[0]<<"/"<<u.dob[1]<<"/";
    cin>>u.dob[2];
    cout<<"\t\t______________________________";
    ob.write((char*)&u,sizeof(u));
    ot<<"Name:"<<u.name<<"|Username:"<<u.username<<"|Password:"<<u.password;
    ot<<"|DOB:"<<dob[0]<<"/"<<dob[1]<<"/"<<dob[2]<<endl;
    cout<<"\n\nAccount created! Again? 0 or 1";
    ob.close();
    ot.close();
    if(choice()==1)
    {
        u.createaccount();
    }
}
void user::sendm()
{
    char from[20],to[20],text[50];
    int flag=0;
    strcpy(from,u.username);
    heading();
    ifstream ib(binaryfile,ios::binary);
    cout<<"Username list:";
    cout<<"\n\t\t____________________";
    while(ib.read((char*)&u,sizeof(u)))
    {
        cout<<"\n\t\t| "<<u.username;
    }
    ib.close();
    cout<<"\n\t\t|____________________";
    cout<<"\n\nSend message to ";
    gets(to);
    ib.open(binaryfile,ios::binary);
    while(ib.read((char*)&u,sizeof(u)))
    {
        if (!strcmp(to,u.username))
        {
            ofstream ot(to,ios::app);
            heading();
            cout<<"Sending message to "<<to<<"\nMessage:";
            gets(text);
            ot<<"\nFROM:"<<from<<"\nTo:"<<to<<"\nMessage:"<<text;
            ot.close();
            cout<<"\n\t\t\t SENT!";
            getch();
            flag++;
            break;
        }
    }
    ib.close();
    if (!flag)
    {
        heading();
        cout<<"\n\n\t\t\t    THE USER WAS NOT FOUND!";
        getch();
    }
    ib.open(binaryfile,ios::binary);
    while (ib.read((char*)&u,sizeof(u)))
    {
        if (!strcmp(from,u.username))
        {
            break;
        }
    }
    ib.close();
}
void user::readm()
{
    ofstream ot(u.username,ios::app);
    ot.close();
    heading();
    char c;
    ifstream it(u.username);
    while (!it.eof())
    {
        it.get(c);
        cout<<c;
    }
    getch();
}
//non-class utility functions
void onlyheading()
{
    cout<<"https://hermes.com";
    cout<<"\n\t\t\t\t   HERMES!";
    cout<<"\n\n\t\t\t      Lightning fast!\n\n\n";
}
int choice()
{
    cout<<"\n\n\n\t\t\tChoice:";
    int choice;
    cin>>choice;
    return choice;
}
void load(char message[])
{
    cout<<"\n\n\n\n\n\n\n\n";
        int lim=1;
        while (lim<18)
        {
            clrscr();
            cout<<"\n\n\n\n\n\n\n\n\t\t\t";
            cout<<message<<"\n\t\t\t   ";
            for(int t=1;t<=lim;t++)
            {
                cout<<" ";
            }
            cout<<"[...]";
            delay(70);
            if(kbhit())
            {
                break;
            }
            lim++;
        }
        clrscr();
}
void load(int choice)
{
    if (choice==1)
    {
        cout<<"\n\n\n\n\n\n\n\n";
        int lim=1;
        while (lim<18)
        {
            clrscr();
            cout<<"\n\n\n\n\n\n\n\n\t\t\t";
            for(int t=1;t<=lim;t++)
            {
                cout<<" ";
            }
            cout<<"[...]";
            delay(70);
            if(kbhit())
            {
                break;
            }
            lim++;
        }
        clrscr();
    }
    if(choice==2)
    {
        exit(0);
    }
}
void heading()
{
    load(1);
    cout<<"https://hermes.com";
    cout<<"\n\t\t\t\t   HERMES!";
    cout<<"\n\n\t\t\t      Lightning Fast!\n\n\n";
}
//program structure functions
void settings()
{
    heading();
    cout<<"1. View or modify your data\n2. Delete your account(BE SURE!)\n3. Go back";
    switch(choice())
    {
        case 1:
        heading();
        cout<<"Your data is:\n";
        cout<<"Name:"<<u.name<<"\nUsername:"<<u.username<<"\nPassword:"<<u.password<<"\nDate of Birth:"<<u.dob[0]<<"/"<<u.dob[1]<<"/"<<u.dob[2]<<"\n";
        cout<<"1. Modify name\n2. Modify username\n3. Modify password\n4. Modify dob\n5. Go back\n";
        break;
        case 2:
        ifstream ib2 (binaryfile,ios::binary);
        ofstream ob2("temp",ios::binary|ios::app);
        char usernametodel[20];
        strcpy(usernametodel,u.username);
        while(ib2.read((char*)&u,sizeof(u)))
        {
            if(strcmp(usernametodel,u.username))
            {
                ob2.write((char*)&u,sizeof(u));
            }
        }
        ob2.close();
        ib2.close();
        remove(binaryfile);
        rename("TEMP","BINARY");
        cout<<"YOUR ACCOUNT WAS DELETED!\nYOU WILL NOW BE LOGGED OUT!";
        getch();
        heading();
        loginpage();
        break;
        default:
        u.userpage();
        break;
    }
    settings();
}
void messages()
{
    heading();
    cout<<"1. Send messages\n2. Read your messages\n3. Go back";
    switch(choice())
    {
        case 1:u.sendm();break;
        case 2:u.readm();break;
        default:u.userpage();
    }
    messages();
}
void admin()
{
    heading();
        cout<<"1. View all login data\n2. Clear all data(BE SURE!)\n3. Back to login options\n4. Exit";
        switch(choice())
        {
            case 1:
            ofstream ob(binaryfile,ios::binary|ios::app);
            ob.close();
            char c;
            ifstream ib(binaryfile);
            while(ib.read((char*)&u,sizeof(u)))
            {
                cout<<"NAME:"<<u.name<<"|USERNAME:"<<u.username<<"|PASS:"<<u.password<<"|DOB"<<u.dob[0]<<"/"<<u.dob[1]<<"/"<<u.dob[2]<<"\n";
            }
            getch();
            ib.close();
            break;
            case 2:
            remove(binaryfile);
            remove(textfile);
            heading();
            cout<<"ALL DATA CLEARED!";
            getch();
            break;
            case 4: load(2);
            default: loginpage();break;
        }
    admin();
}
void loginpage()
{
    heading();
    cout<<"1. Login\n2. Create Account\n3. Admin\n4. Exit";
    switch(choice())
    {
        case 1:u.login();break;
        case 2:u.createaccount();break;
        case 3:
        heading();
        char temppass[3];
        cout<<"Enter admin password:";
        gets(temppass);
        if (!strcmp(temppass,"123"))
        {
            admin();
        }
        else
        {
            cout<<"Wrong Password!";
            getch();
        }
        break;
        case 4:load(2);break;
    }
    loginpage();
}
void mainmenu()
{
    clrscr();
    cout<<"\n\n\n\t\t\t\t    1.Enter\n\n\t\t\t\t    2. Exit";
    switch(choice())
    {
        case 1:loginpage();break;
        default:load(2);break;
    }
}
