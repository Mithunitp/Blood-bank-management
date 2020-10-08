#include <iostream>
#include <string.h>
using namespace std;
class Criteria
{
    char Fitness[50];
    int Age;
    int PulseRate;
    float Hemoglobin;
    int DBP,SBP;
    int BodyTemp;
    int Elig;
    
    public:
    
        int checkElig()
        {
            if (strcmp(Fitness,"Healthy")!=0)
                return 0;
            if (!(Age>=18 && Age<=65))
                return 0;
            if (!(PulseRate>50 && PulseRate<100))
                return 0;
            if (Hemoglobin<12.5)
                return 0;
            if (!(DBP>50 && DBP<100))
                return 0;
            if (!(SBP>100 && SBP<180))
                return 0;
            if (BodyTemp>37.5)
                return 0;
            Elig=1;
            return Elig;
        }
    
        int EnterCriteria()
        {
            cout<<"\t\tEnter Overall Fitness and Health:";
            cin>>Fitness;
            cout<<"\t\tEnter Donor Age:";
            cin>>Age;
            cout<<"\t\tEnter Donor Pulse Rate:";
            cin>>PulseRate;
            cout<<"\t\tEnter Donor Hemoglobin level:";
            cin>>Hemoglobin;
            cout<<"\t\tEnter Donor's Diastolic BP level:";
            cin>>DBP;
            cout<<"\t\tEnter Donor's Systolic BP level:";
            cin>>SBP;
            cout<<"\t\tEnter Donor's Body Temperature:";
            cin>>BodyTemp;
            Elig=checkElig();
            return Elig;
        }
    
};

class Eligiblity:public Criteria
{
    int TestID;
    char Name[50];
    long int PhNo;
    char gender[10];
    char EmailID[50];
    char DateofBirth[10];
    char ProofofAge[10];
    
    public:
        void EnterElDetails()
        {
            cout<<"\t\tENTER THE PERSONAL INFO:\n";
            cout<<"\t\tEnter TestID:";
            cin>>TestID;
            cout<<"\t\tEnter Donor's Name:";
            cin>>Name;
            cout<<"\t\tEnter Donor's Phone No:";
            cin>>PhNo;
            cout<<"\t\tEnter Donor's Gender:";
            cin>>gender;
            cout<<"\t\tEnter Donor's Email ID:";
            cin>>EmailID;
            cout<<"\t\tEnter Date of Birth(DD-MM-YYYY):";
            cin>>DateofBirth;
            cout<<"\t\tProof of Age Status:";
            cin>>ProofofAge;
            if(EnterCriteria())
            {
                cout<<"\n\n\t\t Result:\n";
                cout<<"\n\tYes, the prospected Donor is eligible to donate blood."<<endl;
            }
            else
            {
                cout<<"\n\n\t\t Result:\n";
                cout<<"\t\tNo, the prospected Donor is not eligible to donate blood."<<endl;
            }
            cout<<"\t\tThe results are based off of several parameters that determine the eligibility of an individual to donate blood.\n\n"<<endl;
            cout<<"\t\tThese guidelines laid down by the Ministry of Health, Government of India have to be followed by blood banks and organizations conducting blood donation camps.\n\n"<<endl;
        }
};

int main()
{
    Eligiblity EObject[30];
    int i=0,choice;
    char co='Y';
    
    cout<<"\n\n";
    cout<<"\t\t ----------------------------------------------------- \n";
    cout<<"\t\t |     WELCOME TO BLOOD BANK MANAGEMENT SYSTEM       | \n";
    cout<<"\t\t ----------------------------------------------------- \n";
    cout<<"\n\n";
    
    while(co=='Y')
    {
        
        cout<<"\t\t ::        Enter your choice         ::  \n";
        cout<<"\t\t [1]       Check if Donor is Eligible    \n";
        cout<<"\t\t [2]       Add a New Member              \n\t\t";
        cin>>choice;
        
        if(choice==1)
        {
            EObject[i].EnterElDetails();
        }
        
        cout<<"\t\t Do you wish to continue Yes(Y) or No(N) ?: ";
        cin>>co;
        cout<<"\n\n";
    }
    return 0;
}


