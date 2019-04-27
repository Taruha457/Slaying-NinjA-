  struct ninjascore{
    int scoreofninja;
    char nameofplayer[10];
    ninjascore()
    {

    }


};
int number,n,i,j;

typedef struct ninjascore abc;
  abc a1[6];
void bubblesort(abc bir[])
{   abc t;
	//int m;
	for( i=0;i<n;i++)
	{

		for( j=i+1;j<n;j++)
		{
			if(bir[i].scoreofninja<bir[j].scoreofninja)
			{
				t=bir[i];
				bir[i]=bir[j];
				bir[j]=t;

			}
		}
	}
}
