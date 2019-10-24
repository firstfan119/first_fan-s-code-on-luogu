#include <bits/stdc++.h>
#define ri register int
using namespace std;

const int maxn = 10100;
struct bign
{
	int len, s[maxn];
	bign()
	{
		memset(s, 0, sizeof(s));
		len = 1;
	}
	bign(int num)
	{
		*this = num;
	}
	bign(const char* num)
	{
		*this = num;
	}
	bign operator = (int num)
	{
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}
	string str() const
	{
		string res = "";
		for(ri i = 0; i < len; i++)
		{
			res = (char)(s[i] + '0') + res;
		}
		if(res == "")
		{
			res = "0";
		}
		return res;
	}
	void clear()
	{
		while(len > 1 && !s[len-1])
		{
			len--;
		}
	}
	bign operator = (const char* num)
	{
		len = strlen(num);
		for(ri i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
		return *this;
	}

	bign operator + (const bign& b) const
	{
		bign c;
		c.len = 0;
		for(ri i = 0, g = 0; g || i < max(len, b.len); i++)
		{
			int x = g;
			if(i < len) x += s[i];
			if(i < b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		return c;
	}

	bign operator * (const bign& b)
	{
		bign c;
		c.len = len + b.len;
		for(ri i = 0; i < len; i++)
			for(ri j = 0; j < b.len; j++)
				c.s[i+j] += s[i] * b.s[j];
		for(ri i = 0; i < c.len-1; i++)
		{
			c.s[i+1] += c.s[i] / 10;
			c.s[i] %= 10;
		}
		c.clear();
		return c;
	}

	bign operator - (const bign& b)
	{
		bign c;
		c.len = 0;
		for(ri i = 0, g = 0; i < len; i++)
		{
			int x = s[i] - g;
			if(i < b.len) x -= b.s[i];
			if(x >= 0) g = 0;
			else
			{
				g = 1;
				x += 10;
			}
			c.s[c.len++] = x;
		}
		c.clear();
		return c;
	}

	bool operator < (const bign& b) const
	{
		if(len != b.len) return len < b.len;
		for(ri i = len-1; i >= 0; i--)
			if(s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}

	bool operator > (const bign& b) const
	{
		return b < *this;
	}

	bool operator <= (const bign& b)
	{
		return !(b > *this);
	}

	bool operator == (const bign& b)
	{
		return !(b < *this) && !(*this < b);
	}

	bign operator += (const bign& b)
	{
		*this = *this + b;
		return *this;
	}
};

istream& operator >> (istream &in, bign& x)
{
	string s;
	in >> s;
	x = s.c_str();
	return in;
}

ostream& operator << (ostream &out, const bign& x)
{
	out << x.str();
	return out;
}

int main()
{
	int flg=false;
	bign a;
	bign b;
	bign tmp;
	cin >> a >> b;
	if(a<b)
	{
		tmp=a;
		a=b;
		b=tmp;
		flg=true;
	}
	if(flg)
	{
		cout<<"-";
	}
	cout << a-b << endl;
	return 0;
}//�߾�ģ�壬��ֵ��ӵ�У�
//���鿪С��2�Ρ���
