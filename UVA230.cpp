#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class book
{
public:
    book(string, string);
    string author();
    string title();
    bool borrowed();
    bool returned();
    void set_borrowed(bool);
    void set_returned(bool);
private:
    string Author;
    string Title;
    bool Borrowed;
    bool Returned;
};

book::book(string a, string t)
{
    Author = a;
    Title = t;
    Borrowed = false;
    Returned = false;
}
string book::author()
{
    return Author;
}
string book::title()
{
    return Title;
}
bool book::borrowed()
{
    return Borrowed;
}
bool book::returned()
{
    return Returned;
}
void book::set_borrowed(bool b)
{
    Borrowed = b;
}
void book::set_returned(bool r)
{
    Returned = r;
}

bool cmp(book b1, book b2){
    if(b1.author()<b2.author()){
        return true;
    }
    else if(b1.author() == b2.author()){
        if(b1.title()>b2.title()){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}
int main()
{
    string s;
    string title="",author="";
    vector<book> b;
    while(getline(cin,s) && s!="END"){
        title="",author="";
        bool title_flag=false,author_flag=false;
        for(int i=0;i<s.length();i++){
            if(author_flag){
                author+=s[i];
            }

            if(s[i]=='\"' && !author_flag){
                title_flag = !title_flag;
                if(!title_flag){
                    title+=s[i];
                    i+=4;
                    author_flag=true;
                }
            }
            if(title_flag){
                title+=s[i];
            }
        }
        book temp(author,title);
        b.push_back(temp);
    }
    sort(b.begin(),b.end(),cmp);
    while(cin>>s && s!="END"){
        if(s=="BORROW"){
            cin.get();
            getline(cin,s);
            for(int i=0;i<b.size();i++){
                if(b[i].title()==s){
                    b[i].set_borrowed(true);
                }
            }
        }
        else if(s=="RETURN"){
            cin.get();
            getline(cin,s);
            for(int i=0;i<b.size();i++){
                if(b[i].title()==s){
                    b[i].set_borrowed(false);
                    b[i].set_returned(true);
                }
            }
        }
        else if(s=="SHELVE"){
            for(int i=0;i<b.size();i++){
                if(b[i].returned()){
                    b[i].set_returned(false);
                    if(i==0){
                        cout<<"Put "<<b[i].title()<<" first"<<endl;
                        continue;
                    }
                    for(int j=i-1;j>=0;j--){
                        if(!b[j].borrowed() && !b[j].returned()){
                            cout<<"Put "<<b[i].title()<<" after "<<b[j].title()<<endl;
                            break;
                        }
                        if(j==0){
                            cout<<"Put "<<b[i].title()<<" first"<<endl;
                        }
                    }
                }
            }
            cout<<"END"<<endl;
        }
    }

}
