#include<iostream>
using namespace std;
int main()
{
    int T,counter=1;
    cin>>T;
    while(T--)
    {
        int N,M;
        char matrix[9][9];
        cin>>N;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cin>>matrix[i][j];
                matrix[i][j]-='0';
            }
        }

        cin>>M;
        while(M--)
        {
            string s;
            int tmp[9][9];
            cin>>s;
            if(s=="row")
            {
                int a,b;
                cin>>a>>b;
                a--;
                b--;
                for(int i=0; i<N; i++)
                {
                    swap(matrix[a][i],matrix[b][i]);
                }
            }
            else if(s=="col")
            {
                int a,b;
                cin>>a>>b;
                a--;
                b--;
                for(int i=0; i<N; i++)
                {
                    swap(matrix[i][a],matrix[i][b]);
                }
            }
            else if(s=="inc")
            {
                for(int i=0; i<N; i++)
                {
                    for(int j=0; j<N; j++)
                    {
                        matrix[i][j]++;
                        matrix[i][j]%=10;
                    }
                }
            }
            else if(s=="dec")
            {
                for(int i=0; i<N; i++)
                {
                    for(int j=0; j<N; j++)
                    {
                        matrix[i][j]--;
                        matrix[i][j]+=10;
                        matrix[i][j]%=10;
                    }
                }
            }
            else if(s=="transpose")
            {
                for(int i=0; i<N; i++)
                {
                    for(int j=0; j<i; j++)
                    {
                        swap(matrix[i][j],matrix[j][i]);
                    }
                }
            }
        }

        cout<<"Case #"<<counter++<<endl;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cout<<(int)matrix[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
