#include<stdio.h>
#include<string.h>
int a[100][100];//�ȶ���һ��������
void xiao(int a[][100],int x,int y);
int main(){
    memset(a,0,sizeof(char)*10000);//�����ǽ��������鸳ֵΪ0
    int m,n,z=0;
    scanf("%d%d",&m,&n);
    //һ��Ҫ��1��ʼ��m
    //�����Ļ��ıߵ���������㻹����һ��ȫ��0������
    //������д���ܻ����
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d",&a[i][j]);
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]!=0){
                z++;
                xiao(a,i,j);
            }
        }
    }

    printf("%d",z);
    return 0;
}

void xiao(int a[][100],int x,int y){
    a[x][y]=0;
    if(a[x-1][y]!=0) xiao(a,x-1,y);
    if(a[x+1][y]!=0) xiao(a,x+1,y);
    if(a[x][y-1]!=0) xiao(a,x,y-1);
    if(a[x][y+1]!=0) xiao(a,x,y+1);
}
