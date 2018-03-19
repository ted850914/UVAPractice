#include<iostream>
#include<sstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class History
{
private:
    string date;
    int check_number;
    double dollar;
    bool star;
public:
    History(string,int,double);
    void print_history();
    void set_star(bool);
    int get_check_number();
};
History::History(string date,int check_number,double dollar){
    this->date = date;
    this->check_number = check_number;
    this->dollar = dollar;
    star = false;
}
void History::print_history(){
    if(star)
        cout<<setw(4)<<check_number<<"* "<<setw(9)<<fixed<<setprecision(2)<<dollar<<" "<<date;
    else
        cout<<setw(4)<<check_number<<"  "<<setw(9)<<fixed<<setprecision(2)<<dollar<<" "<<date;
}
void History::set_star(bool){
    star = true;
}
int History::get_check_number(){
    return check_number;
}
bool cmp(History h1,History h2){
    if(h1.get_check_number()<h2.get_check_number()){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    int N;
    cin>>N;
    cin.get();
    cin.get();
    while(N--)
    {
        vector<History> history;
        string s;
        while(getline(cin,s))
        {
            if(s=="")
            {
                break;
            }
            stringstream ss;
            string date;
            int check_number;
            double dollar;
            ss<<s;
            ss>>date>>check_number>>dollar;
            history.push_back(History(date,check_number,dollar));
        }
        sort(history.begin(),history.end(),cmp);
        for(int i=1;i<history.size();i++){
            if(history[i].get_check_number()-history[i-1].get_check_number()>1){
                history[i].set_star(true);
            }
        }
        if(history.size()==4){
            for(int i=0;i<ceil(history.size()/2.0);i++){
                for(int j=i;j<history.size();j+=ceil(history.size()/2.0)){
                    if(i==j)
                        history[j].print_history();
                    else{
                        cout<<"   ";
                        history[j].print_history();
                    }

                }
                cout<<endl;
            }
        }
        else{
            for(int i=0;i<ceil(history.size()/3.0);i++){
                for(int j=i;j<history.size();j+=ceil(history.size()/3.0)){
                    if(i==j)
                        history[j].print_history();
                    else{
                        cout<<"   ";
                        history[j].print_history();
                    }

                }
                cout<<endl;
            }
        }
        if(N){
            cout<<endl;
        }
    }
}
