#include <bits/stdc++.h>
using namespace std;

struct node {
	int num;//�任����
	string s;//�任n�κ�Ľ��
	node(int num,string s):num(num),s(s) {} //���캯��
};
string A,B;//��ʼ�ַ�����Ŀ���ַ���
vector< pair<string,string> >v;//�洢����
set<string>reapr;//����

bool bfs() {
	queue<node>q;
	q.push(node(0,A));
	while(!q.empty()) {
		node u=q.front();
		q.pop();
		if(u.num>10) {
			printf("NO ANSWER!\n");    //�����ͷ���ַ���ת����������10�Σ������ڴ�
			return false;
		}
		for (int i=0; i<v.size(); i++)
			if (u.s.find(v[i].first)!=-1);//������ַ������ڿ���ת�������
		for (int j=u.s.find(v[i].first) ; j<u.s.length(); j=u.s.find(v[i].first,j+1)) { //�Ӹ��ַ�������������һ������ת��λ��
			string t=u.s;
			t.replace(j,v[i].first.length(),v[i].second);//�����ת������ַ���
			if(t==B) {
				printf("%d\n",u.num+1);    //���ת������ַ���ΪĿ�괮B
				return true;
			}
			if(!reapr.count(t)) { //���أ��ǳ���Ҫ����Ȼһ���ᳬʱ
				q.push(node(u.num+1,t));
				reapr.insert(t);//���֮ǰû�г��ֹ����ַ���������뵽�ѳ��ֵļ��ϣ��Է��´��ٴγ���
			}
		}
	}
	return false;//�����ڴ�
}
int main() {
	//freopen("input.txt","r",stdin);
	cin>>A>>B;
	string a,b;
	while(cin>>a>>b)
		v.push_back(make_pair(a,b));
	if(!bfs()) printf("NO ANSWER!\n");
	return 0;
}
