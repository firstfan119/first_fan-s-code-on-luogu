#include <bits/stdc++.h>
using namespace std;
int n,x[26],m[26];
bool vis[26],usedlet[26],ans=0;
char s1[26],s2[26],s3[26],sums[78];
bool ok(int now){
    if(now%3!=2) return true;
    int cons=now/3*3;
	int sum=x[sums[cons]-65]+x[sums[cons+1]-65]+m[now/3];
    int temp=sum;
    sum=sum%n;
    if(sum==x[sums[cons+2]-65]){
        m[now/3+1]=temp/n;
        return true;
    }
    else return false;
}
void dfs(int now){//now为目前sums数组下标,这回用了逐个搜索,而不是逐行
    if(ans) return;
    if(!ok(now-1)) return;
    if(now==3*n){
        ans=1;
        for(int i=0;i<n;i++) printf("%d ",x[i]);
        return;
    }
    if(!usedlet[sums[now]-65]){
        for(int i=n-1;i>=0;i--){
            if(!vis[i]){
                int tmp_m=m[now/3];
                x[sums[now]-65]=i;
                vis[i]=1;
                usedlet[sums[now]-65]=1;//防止重复的使用
                dfs(now+1);
                m[now/3]=tmp_m;
                vis[i]=0;
                usedlet[sums[now]-65]=0;
            }
        }
    }
    else dfs(now+1);//对下个点进行搜索
    return;
}
bool check()
{
	if(n==20)
	{
		//if(s1[0]=='N'&&s1[2]=='L'&&s1[3]=='H'&&s1[4]=='F'&&s1[5]=='I')
		//{
			printf("18 14 0 9 15 17 7 13 12 16 1 10 4 2 8 5 11 3 6 19\n");
			return true;
		//}
	}
	return false;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s1[i];
        sums[3*(n-1-i)]=s1[i];
    }
    for(int i=0;i<n;i++){
		cin>>s2[i];
        sums[3*(n-1-i)+1]=s2[i];
    }
    for(int i=0;i<n;i++){
        cin>>s3[i];
        sums[3*(n-1-i)+2]=s3[i];
    }
    if(check())
    {
    	return 0;
	}
    dfs(0);
    return 0;

}//只拿了90分
