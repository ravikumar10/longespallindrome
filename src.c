#include<iostream>
#include<cstring>
using namespace std;

int main(){
                int l,count,i,j,k,temp;
                int max=1;
                string s;
                cin >> s;
                l = s.length();
                for(i=0;i<l;i++)
                {
                                int m=i;count=0;
                                for(j=l-1;j>=m;j--)
                                {
                                                if(s[m]==s[j] && j!=i)
                                                {
                                                                if(m==j){
                                                                                count++;
                                                                                if(max<count)
                                                                                max=count;
                                                                }
                                                                else if(m<(j-1)){
                                                                                m++;count+=2;
                                                                }
                                                                else if(m<j){
                                                                                m++;count+=2;
                                                                                if(max<count)
                                                                                max=count;                                                                        
                                                                                }
                                                                else {
                                                                                break;
                                                                }
                                                }
                                                else
                                                {
                                                                m=i;count=0;
                                                }
                                cout << "i = " << i <<"; m = " << m << "; j= "<<j <<"; count = " <<count<< "; s[m] = " <<s[m]<<"; s[j] = " <<s[j]<<endl;
                                }
                                
                }
                cout<<max<<endl;
                for(i=0;i<(l-max+1);i++)
                {
                                temp=0;
                                for(j=0;j<(max);j++)
                                {
                                                if(s[i]!=s[i+max-1])
                                                temp=1;
                                }
                                if(temp==0)
                                {
                                                for(k=i;k<(max+i);k++)
                                                cout<<s[k];
                                }
                                cout<<endl;
                }
                return 0;
}
