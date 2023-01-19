#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class leap_year{//class to check leap year
    public:
        bool Is_leap_year(ll y){
            if(y%400==0)return true;
            else if(y%4==0&&y%100!=0)return true;
            else return false;
        };

};
class user_site: public leap_year{//derived class
    public:
        string name[100];
        char str[20];
        ll dd,mm,year;
        ll days=0,birth_year_days=366,current_month=0,current_year=0,i=0,c=0;
        ll months[12]={ 31, 29, 31, 30, 31, 30,
                    31, 31, 30, 31, 30, 31 };
        void func(){
            cout<<"Enter your name."<<endl;
            for(;;){
                cin>>name[c];
                c++;
                if(getchar()=='\n')break;
            }

            cout<<"\nEnter your birthdate in the following format:\ndd mm yyyy."<<endl;
            cin>>dd>>mm>>year;

            //strdate(current_date);
            time_t rawtime;
            struct tm * timeinfo;

            time (&rawtime);
            timeinfo = localtime(&rawtime);

            strftime(str,sizeof(str),"%d-%m-%Y %H:%M:%S",timeinfo);
            std::string current_date(str);
            
            current_year=(current_date[6]-48)*1000+(current_date[7]-48)*100+(current_date[8]-48)*10+(current_date[9]-48);
            current_month=(current_date[3]-48)*10+(current_date[4]-48);   

            for(i=year+1;i<current_year;i++){
                if(Is_leap_year(i))days+=366;
                else days+=365;
            }

            for(i=0;i<mm-1;i++)birth_year_days-=months[i];
            if(!Is_leap_year(year)&&i<=1)birth_year_days-=1;
            birth_year_days-=dd;
            days+=birth_year_days;

            ll current_year_days=0;

            for(i=0;i<current_month-1;i++)current_year_days+=months[i];

            if(!Is_leap_year(current_year)&&i>1)current_year_days--;
            current_year_days+=((current_date[0]-48)*10+(current_date[1]-48));
            days+=current_year_days;

            cout<<"Name:";
            for(i=0;i<c;i++)cout<<name[i]<<" ";
            cout<<"\nBirthday:"<<dd<<"-"<<mm<<"-"<<year<<endl;
            cout<<"Age in days:"<<days<<endl;
        };
};
int main()
{
    ll year;
    leap_year start_l;
    user_site start_u;

    cout<<"Enter a year."<<endl;
    cin>>year;

    if(start_l.Is_leap_year(year))cout<<"Leap year"<<endl;
    else cout<<"Not leap year"<<endl;
    start_u.func();
    return 0;
}