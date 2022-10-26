#include <stdio.h>
#include <string.h>

void norm(char *a, char *b)
{
    a[0] = toupper(a[0]);
    b[0] = toupper(b[0]);
    int i;
    for (i = 1; i < 30; i++)
    {
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
    }
}

void bez(char *b)
{
	int i, j, k=0;
	int y = strlen(b);
	char a[y];
	for(i=0; i<y; i++)
		a[i] = b[i];
	
	for(i=0; i<y-1; i++)
	{
		if(a[i] == -59 && a[i+1] == -68)
		{
			a[i] = 122;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -61 && a[i+1] == -77)
		{
			a[i] = 111;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -59 && a[i+1] == -126)
		{
			a[i] = 108;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -60 && a[i+1] == -121)
		{
			a[i] = 99;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -60 && a[i+1] == -103)
		{
			a[i] = 101;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -60 && a[i+1] == -123)
		{
			a[i] = 97;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -59 && a[i+1] == -101)
		{
			a[i] = 115;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -59 && a[i+1] == -70)
		{
			a[i] = 122;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -59 && a[i+1] == -124)
		{
			a[i] = 110;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -59 && a[i+1] == -69)
		{
			a[i] = 90;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -60 && a[i+1] == -124)
		{
			a[i] = 65;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -59 && a[i+1] == -102)
		{
			a[i] = 83;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -60 && a[i+1] == -122)
		{
			a[i] = 67;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -59 && a[i+1] == -71)
		{
			a[i] = 90;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -60 && a[i+1] == -104)
		{
			a[i] = 69;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -59 && a[i+1] == -125)
		{
			a[i] = 78;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -61 && a[i+1] == -109)
		{
			a[i] = 79;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
		if(a[i] == -59 && a[i+1] == -127)
		{
			a[i] = 76;
			j = i+1;
			while(a[j])
			{
				a[j] = a[j+1];
				j++;
			}
			k++;
		}
	}
	for(i=0; i<y-k; i++)
		b[i] = a[i];
	for(i=y-k; i<y; i++)
		b[i] = 0;
}