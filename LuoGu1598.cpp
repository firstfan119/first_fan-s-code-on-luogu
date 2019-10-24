#include <bits/stdc++.h>
#define ri register int
int table[27];
char ans[400][26];
char s[105];
int main()
{
	int n=-1;
	for(ri i=1; i<=4; i++)
	{
		gets(s);
		for(ri j=0; s[j]!='\0'; j++)
		{
			if(isalpha(s[j])) table[s[j]-'A']++;
		}
	}
	for(ri i=0; i<26; i++)
	{
		if(table[i]>n)
			n=table[i];
	}
	for(ri i=0; i<26; i++)
	{
		ans[n-1][i]='A'+i;
	}
	for(ri j=0; j<26; j++)
	{
		for(ri i=n-2; i>=n-table[j]-1; i--)
		{
			ans[i][j]='*';
		}
		for(ri i=n-table[j]-2; i>=0; i--)
		{
			ans[i][j]=' ';
		}
	}
	for(ri i=0; i<n; i++)
	{
		for(ri j=0; j<26; j++)
		{
			putchar(ans[i][j]);
			{
				if(j<25)
				{
					putchar(' ');
				}
			}
		}
			
		putchar('\n');
	}
}
/*
THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!

out:
                            *
                            *
        *                   *
        *                   *     *   *
        *                   *     *   *
*       *     *             *     *   *
*       *     * *     * *   *     * * *
*       *   * * *     * *   * *   * * * *
*     * * * * * *     * * * * *   * * * *     * *
* * * * * * * * * * * * * * * * * * * * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

std2:

 *
 *
 * * *
 * * * *
* * * * * * *
* * * * * * *
* * * * * * *
* * * * * * *
* * * * * * * *
* * * * * * * * * *
* * * * * * * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

what??

*/
