#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <cstdio>
#include <iomanip>
using namespace std;



class Contact; // predeclaration of Contact class which is necessary for showobs()
class Call;
class TicTacToe;
class Phone;

bool selection(int &i, bool &flag, int arEnd);  // prototype for selections()
void showobs(int &n, Contact *obj);  // prototype for showobs()
void wp();                            // the wallpaper function

//double gBalance=0;
int CU=0;
int CP=0;

class Contact
{
public:
    char name[20];
    int number;
    void show()
    {
        cout << name << endl;
        cout << number << endl;
        cout << endl;
    }
};

Contact globalTemp[12];     // mainly used for PCR::setDialed()

class ContactList
{
    Contact ob[109];
public:
    ContactList();
    void showlist();
};


class PCR
{
    Contact missed[20];
    Contact received[20];
    Contact dialed[20];

    char mrd[5][10] = {"MISSED", "RECIEVED", "DIALED", "MISSED", "RECEIVED" };

public:
    PCR();
    void setDialed();
    void showPCR();
    void showMissed();
    void showReceived();
    void showDialed();


};



class PC : public ContactList , public PCR
{
    char Listing[2][20] = {"Contact List", "Call Record"};
//public:
    //PC();

};

    class TicTacToe
{
    char ch[9];
    bool flagTTT = true;
public:
    TicTacToe();
    void grid();
    int ticky();
    void check();
};


class Phone : public PC
{

    int phoneNumber;
    double balance = 0.0;
    char options[9][20] = {"Contacts", "Call Register", "Phone Settings", "Account Settings", "Games & Extras", "Contacts", "Call Register", "Phone Settings", "Account Settings" };
public:
    static int phoneRecord;
    Phone(){phoneRecord++;}
    void phoneInit();
    int getPhoneNumber();
    void setPhoneNumber();
    void phoneSettings();       // includes getPhoneNumber() and setPhoneNumber();
    void accountSettings();
    double getBalance();
    double getBalance(int notused);
    void setBalance();
    void setBalance(double blnce);
};

int Phone::phoneRecord;

Phone *cPhone;

 class Call
{
private:
    char *currentTime;
    double balance;
    const double costPerSec = 0.02;  // in TAKA
    double callCost;  // Also in TAKA
    int duration;


public:
    Call(Contact ob);
    //Call (Phone &p, Contact ob);
    ~Call();
    char *getTime();
    int callDur();             // return call duration in seconds
};


class Person : public Phone
{
private:
    static int num;
    char personName[30];
    char personAddress[40];
    int numberOfRegisteredPhones;
    Phone *phone;
public:
    Person();
void choosePhone();
    ~Person();
};

int Person::num;



int main()
{
    /*int num;

    cout << "How many users to be created?" << endl;
    cin>> num;

    Person user[num];

    system("cls");

    cout << num << " users created." << endl;
    getch();

    system("cls");

    cout << "Which user to be accessed?" << endl;
    cout << endl;

    for(int i=0; i < num; i++)
    {
        cout << "User " << i+1 << endl;
    }

    cin>> num;
    getch();

    while(true)
        user[num-1].choosePhone();
        */

        cout << "Welcome." << endl;
        cout << "How many persons (users) do you want to create?" << endl;
        cout << "Enter a number " << endl;
        cout << "Or just press Esc to let the program create a random number of users for you." << endl;
        cout << endl;

        int i = 0;
        char temp[20];
        char ch;
        int numberOfUsers;
        bool mflag = true;

        do{
            ch = getche();
            if((ch< '0' || ch > '9') && ch != 13 && ch != 27){
                system("cls");
                cout << ch << " is not a number. \nOnly numbers are accepted" << endl;
                //cout << "Try again: " < endl;
                for(int z = 0; z < 20; z++)
                    temp[z] = 0;
                i = 0;
                continue;
                }
            if(ch == 13){
                 numberOfUsers = atoi(temp);
                 if(numberOfUsers > 450 || numberOfUsers <= 0){
                    cout << "This many users may freeze your computer" << endl;
                    cout << "Or may cause this application to be crushed." << endl;
                    cout << "Please try a number between 1 to 10." << endl;
                    cout << "Or press f to force the program to create " << numberOfUsers << " users" << endl;
                    for(int z = 0; z < 20; z++)
                        temp[z] = 0;
                    i = 0;
                    continue;
                 }

                 mflag = false;
            }



            if(ch == 27){
                numberOfUsers = ((rand() + 30) % 11);
                mflag = false;
            }
            temp[i] = ch;
            i++;
            temp[i] = 0;

        } while(mflag);

        system("cls");
        Person user[numberOfUsers];

        cout << numberOfUsers << " user(s) created." << endl;

        getch();

        {
        fflush(stdin);
        char ch;
        int i = 1;
        int j = 0;
        bool flag = false;
        int m = 0;
        int count = 0;
        bool flag2 = true;
        int count2 = 0;
        int limit = 9;
        int count3 = 0;
        int limit2 = 0;

        while(flag2){
            system("cls");
            cout << "Which user do you want to access?" << endl;
            cout << endl;
            cout << "  ->  [ User " << j+1 << " ]  <-" << endl;;
            for( ; i < numberOfUsers; i++){
                if(count2 == limit){break; }
                cout << "        User " << i+1 << endl;
                count++;
                count2++;

            }
          //  for( ; i < numberOfUsers; i++)
            //    count++;
            if(flag){
                    int y = m;
                    limit2++;
                    count3 = 0;
                while(m > 0){
                    cout << "        User " << y-m+1 << endl;
                    m--;
                    count3++;
                    if(count3 == limit2){
                        break;
                    }
                }
                flag = false;
            }

            do{
                ch = getche();
                cout << '\b';
               } while(ch != 72 && ch != 80 && ch != 27 && ch != '0' && ch != 13);



            switch (ch)
            {
            case 80:
                if(j+1 == numberOfUsers){
                    j=0;
                    i=1;
                    flag = false;
                    count = 0;
                    count2 = 0;
                    limit2 = 0;
                    break;
                }

                j++;
                i-=count;
                //i++;
                i++;
                count=0;
                if(j+1 >= (numberOfUsers - limit)){
                    flag = true;
                    //limit3 = 0;
                }
                m = j;
                count2 = 0;
                break;


            case 72:

                if(j == 0){
                    i = 1;
                    flag = false;
                    count = 0;
                    count2 = 0;
                    limit2 = 0;
                    break;
                }
                j--;
                i-=count;
                i--;
                count=0;
                if(j+1 >= numberOfUsers - limit)
                    flag = true;
                m = j;
                count2 = 0;
                break;

            case 13:
                CU = j+1;
                user[j].choosePhone();
                system("cls");
                //flag2 = false;
                i = 1;
                j = 0;
                flag = false;
                m = 0;
                count = 0;
                count2 = 0;
                limit = 9;
                count3 = 0;
                limit2 = 0;

                break;

            }



        }
    }




    return 0;
}


// Selection function.
bool selection(int &i, bool &flag , int arEnd)
{
    char ch;
    bool callflag = false;
    do{
            ch = getche();
            cout << '\b';
           } while(ch != 'c' && ch != 'C' && ch != 72 && ch != 80 && ch != 27 && ch != '0');

            switch(ch)
            {
                case 'C': case 'c':
                    callflag = true;
                case '0': case 27:
                    flag = true;
                    break;
                case 72:
                    if(i-6) {i -= 6;}
                    else {i=1;}
                    break;
                case 80:
                    if(i-6<arEnd-1) i -= 4;
                    else{i=arEnd;}
                    break;
            }

        return callflag;
}


// Member functions of PCR

 PCR::PCR()
{


        int i;
        for(i=0; i < 10; i++){
            char n[30];
            char c[10];
            strcpy(n, "Person");
            strcat(n,itoa(i+1,c, 10));
            strcpy(missed[i].name, n);
            missed[i].number = 12345+i+1;
            strcpy(received[i].name, n);
            received[i].number = 12345+i+1;
            strcpy(dialed[i].name, n);
            dialed[i].number = 12345+i+1;
        }

        for(i=10; i < 20; i++){
            strcpy(missed[i].name, "\0");
            missed[i].number = 0;
            strcpy(received[i].name, "\0");
            received[i].number = 0;
            strcpy(dialed[i].name, "\0");
            dialed[i].number = 0;
        }


    }

void PCR::showPCR()
{
        int n = 1;
        int p;
        bool flag1 = true;
        char c;
        char ch;

        system("cls");

        while (flag1)
        {

            p = n+2;

            cout << "[" << mrd[n-1] << "] <-" <<  endl;
            cout << endl;

            for( ; n < p; n++)
            {
               cout << mrd[n] << endl;
               cout << endl;
            }


            do{
                ch = getche();
                cout << '\b';
            } while(ch != 72 && ch != 80 && ch != 27 && ch != '0' && ch != 13);


           switch(ch)
            {
                case '0': case 27:
                    flag1 = false;
                    break;
                case 72:
                    if(n-3) {n -= 3;}
                    else {n=1;}
                    break;
                case 80:
                    if(n-3< 2) n -= 1;
                    else {n=1;}
                    break;
                case 13:
                    switch (n-3)
                    {
                        case 0: case 3:
                            showMissed();
                            break;
                        case 1: case 4:
                            showReceived();
                            break;
                        case 2:
                            showDialed();
                            break;
                        }
                        n = 1;
                       break;

            }


            system("cls");
        }
    }


    void PCR::showMissed()
    {
        int i = 1;
        int p = i+5;
        char ch;
        bool flag = false;
        bool callflag = false;

        while(true){
            cout << "Missed Calls: " << endl;
            cout << endl;

            showobs(i, missed);
            callflag = selection(i, flag, 10);

            if(callflag){
                Call callm(missed[i-6]);
            }

            if(flag) break;
            system("cls");
            continue;

        }
    }


void PCR::showReceived()
{
        int i = 1;
        int p = i+5;
        char ch;
        bool flag = false;
        bool callflag = false;

        while(true){
            cout << "Received Calls: " << endl;
            cout << endl;

            showobs(i, received);
            callflag = selection(i, flag, 10);

            if(callflag){
                Call callm(received[i-6]);
            }


            if(flag) break;
            system("cls");
            continue;

        }
    }

void PCR::showDialed()
{

        int i = 1;
        int p = i+5;
        char ch;
        bool flag = false;
        bool callflag = false;

        setDialed();

        while(true){
              cout << "Dialed calls: " << endl;
              cout << endl;

            showobs(i, dialed);
            callflag = selection(i, flag, 10);

            if(callflag){
                Call callm(dialed[i-6]);
            }


            if(flag) break;
            system("cls");
            continue;

        }

    }

    void PCR::setDialed()
    {

        int i;
        for(i=0; strcmp(globalTemp[i].name, "\0")  &&  i<10; i++){
            this->dialed[i] = globalTemp[i];
        }
    }



    // Member functions of ContactList

    ContactList::ContactList()
    {
        int i;
        for(i=0; i < 100; i++){
            char n[30];
            char c[10];
            strcpy(n, "Person");
            strcat(n,itoa(i+1,c, 10));
            strcpy(ob[i].name, n);
            ob[i].number = 12345+i+1;
        }

        for(i=100; i < 110; i++){
            strcpy(ob[i].name, "\0");
            ob[i].number = 0;
        }
    }


void ContactList::showlist()
 {
        int i = 1;
        int p = i+5;
        //char ch;
        bool flag = false;
        bool callflag;

        system("cls");

        while(true){

            showobs(i,ob);

            callflag = selection(i, flag, 100);

            if(callflag)
            {
                Call call1(ob[i-6]);
                system("cls");
            }

            system("cls");
            if(flag) break;

            continue;

        }
    }


    // PC functions

    /*
    PC::PC()
     {
        //cout << "till now" << endl;
        int i = 0, j = 1;
        char ch;
        bool flag2 = true;

        while(true)
        {
            wp();
            getch();
            system("cls");
            flag2 = true;

            while(flag2){

                cout << "[" << Listing[i] << "]" << endl;
                cout << Listing[j] << endl;

                ch = getche();
                system("cls");

                switch(ch)
                {
                case 13:
                    if(!strcmp(Listing[i], "Contact List")) showlist();
                    else showPCR();
                    break;
                case 72: case 80:
                    int t;
                    t = i;
                    i = j;
                    j = t;

                    break;

                case 27:
                    flag2 = false;
                    break;
                }
            }

        }

    }
*/


    // member functions of Call class

Call::Call (Contact ob)
    {
        int delay1, delay2;
        this->balance = cPhone->getBalance(1);

        system("cls");
        cout << "Calling " << ob.name << endl;
        {
            int i;
            for(i=10; i > 0; i--){
                globalTemp[i] = globalTemp[i-1];
            }
            globalTemp[i] = ob;

        }
        this->duration = callDur();
        this->callCost = this->duration * this->costPerSec;
        this->balance -= this->callCost;

        if(!duration)
            { system("cls");
              cout << "Insufficient Balance\a" << endl;
                for(delay1=0; delay1 < 10000 ; delay1++)
                if(!kbhit())
                    for(delay2=0; delay2 < 100000 ; delay2++);
                else
                    {
                        getch();
                        break;
                    }
              return;
            }

        for(delay1=0; delay1 < 10 ; delay1++)
                if(!kbhit()){
                    for(delay2=0; delay2 < 100000000 ; delay2++);
                    cout << "..." ;
                }

                else
                    {
                        getch();
                        break;
                    }

        system("cls");

        this->currentTime = this->getTime();

        cout << ob.name << " in call." << endl;
        cout << this->currentTime << endl;


            for(delay1=0; delay1 < 10000 ; delay1++)
                if(!kbhit())
                    for(delay2=0; delay2 < 100000 ; delay2++);
                else
                    {
                        getch();
                        break;
                    }
    }


    /*Call::Call(Contact ob)
    {
        int delay1, delay2;
        this->balance = gBalance;

        system("cls");
        cout << "Calling " << ob.name << endl;
        {
            int i;
            for(i=10; i > 0; i--){
                globalTemp[i] = globalTemp[i-1];
            }
            globalTemp[i] = ob;

        }
        this->duration = callDur();
        this->callCost = this->duration * this->costPerSec;
        this->balance -= this->callCost;

        if(!duration)
            { system("cls");
              cout << "Insufficient Balance\a" << endl;
                for(delay1=0; delay1 < 10000 ; delay1++)
                if(!kbhit())
                    for(delay2=0; delay2 < 100000 ; delay2++);
                else
                    {
                        getch();
                        break;
                    }
              return;
            }

        for(delay1=0; delay1 < 10 ; delay1++)
                if(!kbhit()){
                    for(delay2=0; delay2 < 100000000 ; delay2++);
                    cout << "..." ;
                }

                else
                    {
                        getch();
                        break;
                    }

        system("cls");

        this->currentTime = this->getTime();

        cout << ob.name << " in call." << endl;
        cout << this->currentTime << endl;


            for(delay1=0; delay1 < 10000 ; delay1++)
                if(!kbhit())
                    for(delay2=0; delay2 < 100000 ; delay2++);
                else
                    {
                        getch();
                        break;
                    }
    }
*/

void showobs(int &n, Contact *obj)
{
    int p = n+5;

    cout << "[" << obj[n-1].name << "] <-" <<  endl;
    cout << obj[n-1].number << endl;
    cout << endl;

    for( ; n < p; n++)
    {
        obj[n].show();
    }
}

Call::~Call()
{
        int delay1, delay2;

        system("cls");
        cout << "Call ended." << endl;
        cout << "Duration: " << this->duration/60 << " minutes, " << this->duration%60 << " seconds. " << endl;
        cout << "Cost: " << this->callCost << endl;
        cout << "Current Balance: " << this->balance << endl;
        cout << "Matro 99 Takay 1 GB internet nite 1 press korun" << endl;

        for(delay1=0; delay1 < 10000 ; delay1++)
                if(!kbhit())
                    for(delay2=0; delay2 < 100000 ; delay2++);
                else
                    {
                        getch();
                        break;
                    }

//         gBalance = this->balance;

        cPhone->setBalance(this->balance);


        return;

    }

int Call::callDur()
{
    int i, n=0;

    while(n < 500)
    {
        i = rand() + 100;
        if(((i/60) * this->costPerSec) <= this->balance)
            return (i/60);

        n++;

    }

    return (int)(this->balance/this->costPerSec);
 }

 char *Call::getTime()
 {
        struct tm *ptr;
        time_t t;

        t = time(NULL);
        ptr = localtime(&t);

        return (asctime(ptr));
    }

 //member functions of Phone

 void Phone::phoneInit()
 {
        system("cls");

        int n = 1;
        int p;
        bool flag1 = true;
        char c;
        char ch;

        while(true){
                wp();
                getch();
                system("cls");
                flag1 = true;

                while (flag1)
                {
                    cout << "               User: " << CU << ", Phone: " << CP << " options: " << endl;
                    cout << endl;

                    p = n+4;

                    cout << "              -> [" << options[n-1] << "] <-" <<  endl;
                    cout << endl;

                    for( ; n < p; n++)
                    {
                       cout << "                 " << options[n] << endl;
                       cout << endl;
                    }


                    do{
                        ch = getche();
                        cout << '\b';
                    } while(ch != 72 && ch != 80 && ch != 27 && ch != '0' && ch != 13);


                   switch(ch)
                    {
                        case '0': case 27:
                            flag1 = false;
                            break;
                        case 72:
                            if(n-5) {n -= 5;}
                            else {n=1;}
                            break;
                        case 80:
                            if(n-5< 4) n -= 3;
                            else {n=1;}
                            break;
                        case 13:
                            switch (n-5)
                            {
                                case 3: case 8:
                                    this->accountSettings();
                                    break;
                                case 2: case 7:
                                    this->phoneSettings();
                                    break;
                                case 1: case 6:
                                    this->showPCR();
                                    break;
                                case 0: case 5:
                                    this->showlist();
                                    break;
                                case 4:

                                    TicTacToe game1;

                                    break;
                                }

                                n = 1;
                               break;

                    }


                    system("cls");

                }
                break;

        }
    }

int Phone::getPhoneNumber()
    {
        return this->phoneNumber;
    }

void Phone::setPhoneNumber()
{
        int i = 0;
        char temp[20];
        char ch;

        system("cls");
        cout << "Enter phone number: " << endl;

        do{
            ch = getche();
            if((ch< '0' || ch > '9') && ch != 13){
                cout << "Enter only numbers between '0' and '9'" << endl;
                cout << "Press 'Esc' to return or any other key to try again." << endl;
                ch = getche();
                if(ch == 27) return;
                else
                    {
                        setPhoneNumber();
                        return;
                    }
                }
            if(ch == 13){
                this->phoneNumber = atoi(temp);
            }
            temp[i] = ch;
            i++;
            temp[i] = 0;

        } while(ch != 13);

        system("cls");

        cout << "Your phone number has successfully been reset." << endl;

        getch();

        system("cls");
    }

    void Phone::phoneSettings()
    {
        char options1[2][30] = {"Current Phone Number", "Reset Phone Number"};
        system("cls");
        int i = 0, j = 1;
        char ch;
        bool flag2 = true;

            while(flag2){

                cout << "[" << options1[i] << "]" << endl;
                cout << options1[j] << endl;

                ch = getche();
                system("cls");

                switch(ch)
                {
                case 13:
                    if(!strcmp(options1[i], "Current Phone Number"))
                        {
                            system("cls");
                            cout << "Your currnet phone number is : ";
                            cout << getPhoneNumber();
                            getch();
                            system("cls");
                        }
                    else setPhoneNumber();
                    break;
                case 72: case 80:
                    int t;
                    t = i;
                    i = j;
                    j = t;

                    break;

                case 27:
                    flag2 = false;
                    break;
                }
            }

        }

 void Phone::accountSettings()
 {
        char options1[2][30] = {"Check Account Balance", "Recharge Account"};
        system("cls");
        int i = 0, j = 1;
        char ch;
        bool flag2 = true;

            while(flag2){

                cout << "[" << options1[i] << "]" << endl;
                cout << options1[j] << endl;

                ch = getche();
                system("cls");

                switch(ch)
                {
                case 13:
                    if(!strcmp(options1[i], "Check Account Balance")) this->getBalance();
                    else this->setBalance();
                    break;
                case 72: case 80:
                    int t;
                    t = i;
                    i = j;
                    j = t;

                    break;

                case 27:
                    flag2 = false;
                    break;
                }
            }

        }


double Phone::getBalance()
{
    system("cls");
    cout << "Your current Balance is " << this->balance << " Taka." << endl;
    getch();
    system("cls");
}

double Phone::getBalance(int notused)
{
        return this->balance;
}

void Phone::setBalance()
    {
        fflush(stdin);
        char temp[20];
        system("cls");
        cout << "Enter 8 digit number: " << endl;
        gets(temp);
        system("cls");
        cout << "Requesting..." ;
        for(int i=0; i < 10; i++){
            for(int j=0; j < 100000; j++);
            cout << "...";
        }
        system("cls");
        if(strcmp("15297892", temp)){
            cout << "Wrong Activation Number" << endl;
            getch();
            system("cls");
            return;
        }
        cout << "Account Recharged with BDT 500" << endl;

        this->balance += 500.00;
        //gBalance = this->balance;

        getch();

        system("cls");

        return;

        }

void Phone::setBalance(double blnce)
{
    this->balance = blnce;
}


void wp()     // this console art was collected from an internet forum : http://www.cplusplus.com/forum/general/58945/
              // But idea was genuinely mine (FDS).
    {
        cout<<"                        _                                  "<<endl;
	cout<<"                      -=\\`\\                                  "<<endl;
	cout<<"                  |\\ ____\\_\\__                              "<<endl;
	cout<<"                -=\\c`\"\"\"\"\"\"\" \"`)                      "<<endl;
	cout<<"                   `~~~~~/ /~~`\                               "<<endl;
	cout<<"                     -==/ /                                    "<<endl;
	cout<<"                       '-'                                     "<<endl;
	cout<<"                      _  _                                     "<<endl;
	cout<<"                     ( `   )_                                  "<<endl;
	cout<<"                    (    )    `)                               "<<endl;
	cout<<"                  (_   (_ .  _) _)                             "<<endl;
	cout<<"                                                 _             "<<endl;
	cout<<"                                                (  )           "<<endl;
	cout<<"                 _ .                         ( `  ) . )        "<<endl;
	cout<<"               (  _ )_                      (_, _(  ,_)_)      "<<endl;
	cout<<"             (_  _(_ ,)                                        "<<endl;

	return;
    }


// member functions of TicTacToe
TicTacToe::TicTacToe()
{

    int i;
    for(i=0; i < 9; i++)
        ch[i] = '\0';

    while(flagTTT){
        system("cls");
        grid();
        check();
        if(!flagTTT) break;
        s:
        scanf(" %d", &i);
        if (ch[i-1]){
            printf("\n This box is already taken.\n");
            goto s;
        }

        ch[i-1] = 'O';
        system("cls");
        grid();
        check();
        ch[ticky()]='X';
        if(!flagTTT) break;
    }

    }

void TicTacToe::grid()
{
    printf(" %c | %c | %c ",ch[0],ch[1], ch[2]);
    printf("\n");
    printf("___|___|___\n");
    printf(" %c | %c | %c ",ch[3],ch[4], ch[5]);
    printf("\n");
    printf("___|___|___\n");
    printf(" %c | %c | %c ",ch[6],ch[7], ch[8]);
    printf("\n");
    printf("   |   |   \n");
}


int TicTacToe::ticky()
{
    int i;

   if( (ch[0]=='\0') &&  ((ch[1]=='X' && ch[2]=='X') || (ch[3]=='X' && ch[6]=='X') || (ch[4]=='X' && ch[8]=='X') ))  return 0;
   else if  ( (ch[1]=='\0') && ((ch[0]=='X' && ch[2]=='X')|| (ch[4]=='X' && ch[7]=='X'))) return 1;
   else if  ( (ch[2]=='\0') && ((ch[0]=='X' && ch[1]=='X')||(ch[5]=='X' && ch[8]=='X') || (ch[4]=='X' && ch[6]=='X'))) return 2;
   else if  ( (ch[3]=='\0') && ((ch[4]=='X' && ch[5]=='X')||(ch[0]=='X' && ch[6]=='X'))) return 3;
   else if  ( (ch[4]=='\0') && ((ch[0]=='X' && ch[8]=='X')|| (ch[1]=='X' && ch[7]=='X')||(ch[2]=='X' && ch[6]=='X')||(ch[3]=='X' && ch[5]=='X'))) return 4;
   else if  ( (ch[5]=='\0') && ((ch[3]=='X' && ch[4]=='X')||(ch[2]=='X' && ch[8]=='X'))) return 5;
   else if  ( (ch[6]=='\0') && ((ch[0]=='X' && ch[3]=='X')||(ch[7]=='X' && ch[8]=='X')||(ch[4]=='X' && ch[2]=='X'))) return 6;
   else if  ( (ch[7]=='\0') && ((ch[6]=='X' && ch[8]=='X')||(ch[1]=='X' && ch[4]=='X'))) return 7;
   else if  ( (ch[8]=='\0') && ((ch[0]=='X' && ch[4]=='X')||(ch[2]=='X' && ch[5]=='X')||(ch[6]=='X' && ch[7]=='X'))) return 8;

   else if  ( (ch[0]=='\0') &&  ((ch[1]=='O' && ch[2]=='O')|| (ch[3]=='O' && ch[6]=='O') || (ch[4]=='O' && ch[8]=='O') ))  return 0;
   else if  ( (ch[1]=='\0') &&  ((ch[0]=='O' && ch[2]=='O')|| (ch[4]=='O' && ch[7]=='O'))) return 1;
   else if  ( (ch[2]=='\0') && ((ch[0]=='O' && ch[1]=='O') || (ch[5]=='O' && ch[8]=='O') || (ch[4]=='O' && ch[2]=='O'))) return 2;
   else if  ( (ch[3]=='\0') && ((ch[4]=='O' && ch[5]=='O') || (ch[0]=='O' && ch[6]=='O'))) return 3;
   else if  ( (ch[4]=='\0') && ((ch[0]=='O' && ch[8]=='O') || (ch[1]=='O' && ch[7]=='O') || (ch[2]=='O' && ch[6]=='O') || (ch[3]=='O' && ch[5]=='O'))) return 4;
   else if  ( (ch[5]=='\0') && ((ch[3]=='O' && ch[4]=='O') || (ch[2]=='O' && ch[8]=='O'))) return 5;
   else if  ( (ch[6]=='\0') && ((ch[0]=='O' && ch[3]=='O') || (ch[7]=='O' && ch[8]=='O') || (ch[4]=='O' && ch[2]=='O'))) return 6;
   else if  ( (ch[7]=='\0') && ((ch[6]=='O' && ch[8]=='O') || (ch[1]=='O' && ch[4]=='O'))) return 7;
   else if  ( (ch[8]=='\0') && ((ch[0]=='O' && ch[4]=='O') || (ch[2]=='O' && ch[5]=='O') || (ch[6]=='O' && ch[7]=='O'))) return 8;
    // single
   else if (!ch[4]) return 4;
   else if((ch[4] == 'O') && !ch[0] && !ch[1] && !ch[2] && !ch[3] && !ch[5] && !ch[6] && !ch[7] && !ch[8]) return 2;
   // double
   else if((ch[4] == 'O') && (ch[2] == 'x')&& (ch[6] == 'O') && !ch[0] && !ch[1] && !ch[3] && !ch[5] && !ch[7] && !ch[8]) return 0;
   else if((ch[4] == 'X') && (ch[2] == 'O')&& (ch[6] == 'O') && !ch[0] && !ch[1] && !ch[3] && !ch[5] && !ch[7] && !ch[8]) return 1;
   else if((ch[4] == 'X') && (ch[2] == 'O')&& (ch[7] == 'O') && !ch[0] && !ch[1] && !ch[3] && !ch[5] && !ch[6] && !ch[8]) return 8;
   else if((ch[4] == 'X') && (ch[2] == 'O')&& (ch[3] == 'O') && !ch[0] && !ch[1] && !ch[6] && !ch[5] && !ch[7] && !ch[8]) return 0;
   else if((ch[4] == 'X') && (ch[0] == 'O')&& (ch[8] == 'O') && !ch[2] && !ch[1] && !ch[3] && !ch[5] && !ch[7] && !ch[6]) return 3;
   else if((ch[4] == 'X') && (ch[0] == 'O')&& (ch[7] == 'O') && !ch[2] && !ch[1] && !ch[3] && !ch[5] && !ch[8] && !ch[6]) return 6;
   else if((ch[4] == 'X') && (ch[0] == 'O')&& (ch[5] == 'O') && !ch[2] && !ch[1] && !ch[3] && !ch[8] && !ch[7] && !ch[6]) return 2;
   else if((ch[4] == 'X') && (ch[1] == 'O')&& (ch[6] == 'O') && !ch[0] && !ch[2] && !ch[3] && !ch[5] && !ch[7] && !ch[8]) return 0;
   else if((ch[4] == 'X') && (ch[5] == 'O')&& (ch[6] == 'O') && !ch[0] && !ch[2] && !ch[3] && !ch[1] && !ch[7] && !ch[8]) return 8;
   else if((ch[4] == 'X') && (ch[3] == 'O')&& (ch[8] == 'O') && !ch[0] && !ch[2] && !ch[1] && !ch[5] && !ch[7] && !ch[6]) return 6;
   else if((ch[4] == 'X') && (ch[1] == 'O')&& (ch[8] == 'O') && !ch[0] && !ch[2] && !ch[3] && !ch[5] && !ch[7] && !ch[6]) return 2;
   // cat3
   else if((ch[4] == 'X') && (ch[1] == 'O')&& (ch[7] == 'O') && !ch[0] && !ch[2] && !ch[3] && !ch[5] && !ch[6] && !ch[8]) return 0;
   else if((ch[4] == 'X') && (ch[1] == 'O')&& (ch[3] == 'O') && !ch[0] && !ch[2] && !ch[6] && !ch[5] && !ch[7] && !ch[8]) return 0;
   else if((ch[4] == 'X') && (ch[1] == 'O')&& (ch[5] == 'O') && !ch[0] && !ch[2] && !ch[3] && !ch[6] && !ch[7] && !ch[8]) return 2;

   else if((ch[4] == 'X') && (ch[3] == 'O')&& (ch[5] == 'O') && !ch[0] && !ch[2] && !ch[1] && !ch[6] && !ch[7] && !ch[8]) return 0;
   else if((ch[4] == 'X') && (ch[1] == 'O')&& (ch[5] == 'O') && !ch[0] && !ch[2] && !ch[3] && !ch[6] && !ch[7] && !ch[8]) return 2;
   else if((ch[4] == 'X') && (ch[5] == 'O')&& (ch[7] == 'O') && !ch[0] && !ch[2] && !ch[3] && !ch[1] && !ch[6] && !ch[8]) return 8;

   else if((ch[4] == 'X') && (ch[1] == 'O')&& (ch[7] == 'O') && !ch[0] && !ch[2] && !ch[3] && !ch[5] && !ch[6] && !ch[8]) return 0;
   else if((ch[4] == 'X') && (ch[5] == 'O')&& (ch[7] == 'O') && !ch[0] && !ch[2] && !ch[3] && !ch[1] && !ch[6] && !ch[8]) return 8;
   else if((ch[4] == 'X') && (ch[3] == 'O')&& (ch[7] == 'O') && !ch[0] && !ch[2] && !ch[1] && !ch[5] && !ch[6] && !ch[8]) return 6;

   else if((ch[4] == 'X') && (ch[3] == 'O')&& (ch[5] == 'O') && !ch[0] && !ch[2] && !ch[1] && !ch[6] && !ch[7] && !ch[8]) return 0;
   else if((ch[4] == 'X') && (ch[1] == 'O')&& (ch[3] == 'O') && !ch[0] && !ch[2] && !ch[6] && !ch[5] && !ch[7] && !ch[8]) return 0;
   else if((ch[4] == 'X') && (ch[3] == 'O')&& (ch[7] == 'O') && !ch[0] && !ch[2] && !ch[1] && !ch[5] && !ch[6] && !ch[8]) return 6;

   else
   {
       for(i=0; i<9; i++){
        if(!ch[i])
            break;
       }
       //printf("I send %d ", i);
       //getch();
       return i;
   }

    }


    void TicTacToe::check()
    {
        if((((ch[0] == 'O') && (ch[1] == 'O') && (ch[2] == 'O'))) || (((ch[3] == 'O') && (ch[4] == 'O') && (ch[5] == 'O'))) || (((ch[6] == 'O') && (ch[7] == 'O') && (ch[8] == 'O'))) || (((ch[0] == 'O') && (ch[3] == 'O') && (ch[6] == 'O'))) || (((ch[1] == 'O') && (ch[4] == 'O') && (ch[7] == 'O'))) || (((ch[2] == 'O') && (ch[5] == 'O') && (ch[8] == 'O'))) || (((ch[0] == 'O') && (ch[4] == 'O') && (ch[8] == 'O'))) || (((ch[2] == 'O') && (ch[4] == 'O') && (ch[6] == 'O')))   )
        {
            printf("\n\3\3 You win \3\3\n");
            getch();
            flagTTT = false;
            return;
        }

        else if((((ch[0] == 'X') && (ch[1] == 'X') && (ch[2] == 'X'))) || (((ch[3] == 'X') && (ch[4] == 'X') && (ch[5] == 'X'))) || (((ch[6] == 'X') && (ch[7] == 'X') && (ch[8] == 'X'))) || (((ch[0] == 'X') && (ch[3] == 'X') && (ch[6] == 'X'))) || (((ch[1] == 'X') && (ch[4] == 'X') && (ch[7] == 'X'))) || (((ch[2] == 'X') && (ch[5] == 'X') && (ch[8] == 'X'))) || (((ch[0] == 'X') && (ch[4] == 'X') && (ch[8] == 'X'))) || (((ch[2] == 'X') && (ch[4] == 'X') && (ch[6] == 'X')))   )
        {
            printf("\n\3\3 I win \3\3\n");
            getch();
            flagTTT = false;
            return;
        }
        else if(ch[0] && ch[1] && ch[2] && ch[3] && ch[4] && ch[5] && ch[6] && ch[7] && ch[8]){
            printf("\nGame Over\n");
            getch();
            flagTTT = false;
            return;
        }
    }




// member functions of class Person

Person::Person()
{
        char temp[10];
        strcpy(personName, "User ");
        itoa(++num,temp,10);
        strcat(personName,temp);

        strcpy(personAddress, "Unknown");

        this->numberOfRegisteredPhones = (int)(2+(rand()+20)%6);

        this->phone = new Phone[numberOfRegisteredPhones];

        if(!phone){
            system("cls");
            cout << "Dynamic Allocation Failed\n";
            cout << "Closing Application" << endl;
            exit(1);
        }

        //choosePhone();
}

void Person::choosePhone()
{
        fflush(stdin);
       // cout << "[NB: Total numbers of phone created: " << Phone::phoneRecord << endl;
        //getch();
        char ch;
        int i = 1;
        int j = 0;
        bool flag = false;
        int m = 0;
        int count = 0;
        bool flag2 = true;

        while(flag2){
            system("cls");
            cout << "Currently Accessing : User " << CU << endl;
            cout << "Which phone do you want to access?" << endl;
            cout << endl;
            cout << "   --->[ Phone " << j+1 << " ]<---" << endl;
            for( ; i < numberOfRegisteredPhones; i++){
                cout << "         Phone " << i+1 << endl;
                count++;
            }
            if(flag){
                    int y = m;
                while(m > 0){
                    cout << "         Phone " << y-m+1 << endl;
                    m--;
                }
                flag = false;
            }

            do{
                ch = getche();
                cout << '\b';
               } while(ch != 72 && ch != 80 && ch != 27 && ch != '0' && ch != 13);

          //  fflush(stdin);

            switch (ch)
            {
            case 80:
                if(j+1 == numberOfRegisteredPhones){
                    j=0;
                    i=1;
                    flag = false;
                    count = 0;
                    break;
                }

                j++;
                i-=count;
                i++;
                count=0;
                flag = true;
                m = j;
                break;

            case 72:

                if(j == 0){
                    i = 1;
                    flag = false;
                    count = 0;
                    break;
                }
                j--;
                i-=count;
                i--;
                count=0;
                flag = true;
                m = j;
                break;

            case 13:
                CP = j+1;
                cPhone = &phone[j];
                phone[j].phoneInit();
                i = 1;
                j = 0;
                flag = false;
                m = 0;
                count = 0;


                system("cls");
                //flag2 = false;
                break;

            case 27:
                flag2 = false;
                break;

            }
        }

    }

    Person::~Person()
     {
        delete [] phone;
        getch();
    }
