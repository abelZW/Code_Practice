#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int pos_p,pos_t,count_p,count_a,count_t,n;
	scanf("%d\n",&n);
    int flag[n];
	for(int num = 0; num < n; num++)
    {
		pos_p=pos_t=count_p=count_a=count_t=0;
		cin >> s;
		for(int i=0;i<s.length();i++){
			if(s[i] == 'P'){
				count_p++;
				pos_p = i;
			}else if(s[i] == 'A'){
				count_a++;
			}else if(s[i] == 'T'){
				count_t++;
				pos_t = i;
			}
		}
		if(count_p+count_a+count_t<s.length() || count_p>1 || count_t>1 || pos_p*(pos_t-pos_p-1)!=s.length()-pos_t-1 || pos_t-pos_p<=1)
		    flag[num] = 0;
              //printf("NO\n");
        else
            flag[num] = 1;
              //printf("YES\n");
	}
    for(int i = 0; i< n;i++){
    if(flag[i])
        printf("YES\n");
    else 
        printf("NO\n");
	}
    return 0;
}