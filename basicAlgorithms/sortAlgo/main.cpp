#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

void flaga_Polska(int* T, int n)
{
    int i = 0;
    int j = n - 1;

    while(i<j)
    {
        while(T[i]==0)  i++;
        while(T[j]==1)  j--;

        if(i<j)
        {
            swap(T[i],T[j]);
            i++;
            j--;
        }
    }
}
void flaga_Francuska(int* T, int n)
{
    int n1=-1;
    int n2=0;
    int n3=n;
    int p;
    while (n2<=n3)
    {
        p=T[n2];

        if (p==1)
        {
            n2++;
        }
        else if (p==0)
        {
            n1++;
            swap(T[n1],T[n2]);
            n2++;
        }
        else
        {
            n3--;
            swap(T[n3],T[n2]);
        }
    }
}
int wyszukiwanie_bisek(int* T, int lewa, int prawa, int szukana)
{
    if(lewa==prawa)
    {
        if(T[prawa]==szukana)
        {
            return T[prawa];
        }
    }
    else
    {
        int mediana =(lewa+prawa)/2;

        if(T[mediana]<szukana)
        {
            return wyszukiwanie_bisek(T,mediana+1,prawa,szukana);
        }
        else
        {
            return wyszukiwanie_bisek(T,lewa,mediana,szukana);
        }
    }
    return 0;
}
void quicksort(int lewy, int prawy, int* T)
{
    int i=lewy;
    int j=prawy;
    int mediana =(lewy+prawy)/2;
    mediana=T[mediana];

    do
    {
        while(T[i]<mediana)    i++;
        while(T[j]>mediana)    j--;

        if(i<=j)
        {
            swap(T[i],T[j]);

            i++;
            j--;
        }
    }while(i<=j);

    if(i<prawy) quicksort(i,prawy,T);
    if(j>lewy)  quicksort(lewy,j,T);
}

void insertsort(int* T, int n)
{
    int i,j,tmp;

    for(i=1;i<n;i++)
    {
        j=i-1;
        tmp=T[i];
        while(j>=0 && T[j]>tmp)
        {
            T[j+1]=T[j];
            j--;
        }
        T[j+1]=tmp;
    }
}
void selectsort(int* T, int n)
{
    int i,j,maks;
    for(i=0;i<n-1;i++)
    {
        maks=i;
        for(j=i;j<n;j++)
        {
            if(T[maks]<T[j])
            {
                maks=j;
            }
        }
        if(maks!=i)
        {
            swap(T[maks],T[i]);
        }
    }
}
void bobblesort(int* T, int n)
{
    int i,j;

    for(i=0;i<n-1;i++)
    {
        for(j=1;j<n;j++)
        {
            if(T[j]<T[j-1])
            {
                swap(T[j],T[j-1]);
            }
        }
    }
}
void Karp_Rabin(char Wzorzec[], char Tekst[])
{
    int nw=strlen(Wzorzec);
    int nt=strlen(Tekst);
    int kw=0;
    int kt=0;
    int i;
    for(i=0;i<nw;i++)
    {
        kw+=Wzorzec[i];
        kt+=Tekst[i];
    }
    kw%=256;
    kt%=256;

    int j;
    for(i=0;i<nt-nw+1;i++)
    {
        if(i!=0)
        {
            kt=(kt+Tekst[i+nw-1]-Tekst[i-1])%256;
        }
        j=0;
        if(kt==kw)
        {
            for(j=0;j<nw;j++)
            {
                if(Wzorzec[j]!=Tekst[j+i]) break;
            }
        }
        if(j==nw) cout<< "Znaleziono wzorzec na pozycji "<< i <<endl;
    }
}
void Knuth_Morris_Pratt(char Wzorzec[], char Tekst[])
{
    int dl_W,dl_T;
    dl_W=strlen(Wzorzec);
    dl_T=strlen(Tekst);
    int p[dl_W+1],t=0,i;
    p[0]=0;
    p[1]=0;
    for( i=2;i<=dl_W;i++)
    {
        while((t>0)&&(Wzorzec[t+1]!=Wzorzec[i]))
        {
            t=p[t];
        }
        if (Wzorzec[t+1]==Wzorzec[i])
        {
            t++;
        }
        p[i]=t;
    }
    i=1;
    int j=0;
    while(i<=dl_T-dl_W+1)
    {
      while((Wzorzec[j]==Tekst[i+j-1]) && (j<dl_W))
      {
          j++;
      }
      if (j==dl_W)
      {
          cout<<"Znaleziono wzorzec na pozycji  "<<i-1<<endl;

      }
      if(1>j-p[j])
      {
          i++;
      }
      else
      {
          i=i+j-p[j];
      }
      j=p[j];
    }
}

void odwroc(char *W, int m)
{
    int i;
    char s[255];

    for(i=0;i<m;i++)
    {
        s[i]=W[m-i-1];
    }
    for(i=0;i<m;i++)
    {
        W[i]=s[i];
    }
}

void Boyer_Moore_obl_FP(char Wzorzec[],int Funkcja[]) // OBLICZANIE JAK W KMP
{
    int m,k,q;
    m=strlen(Wzorzec);
    Funkcja[0]=0;
    Funkcja[1]=0;
    k=0;
    q=2;
    for(q=2;q<=m;q++)
    {
        while((k>0) && (Wzorzec[k+1]!=Wzorzec[q]))
        {
            k=Funkcja[k];
        }
        if (Wzorzec[k+1]==Wzorzec[q])
        {
            k=k+1;
        }
        Funkcja[q]=k;
    }
}

void Boyer_Moore(char Tekst[],char Wzorzec[])
{
    int i,j,s;
    int k=0;
    int m=strlen(Wzorzec);
    int n=strlen(Tekst);

    int ostatnieWystopienie[255],przedrostkowaWzoru[m+1],przedrostkowaWzoruOdw[m+1],dobryPrzedrostek[255];

    for(i=0;i<=255;i++)
    {
        ostatnieWystopienie[i]=0;
    }
    for (i=1;i<=m;i++)
    {
        ostatnieWystopienie[((int)Wzorzec[i])]=i;
    }

    Boyer_Moore_obl_FP(Wzorzec,przedrostkowaWzoru);
    odwroc(Wzorzec,m);

    Boyer_Moore_obl_FP(Wzorzec,przedrostkowaWzoruOdw);

    odwroc(Wzorzec,m);

    for(j=0;j<=m;j++)
    {
        dobryPrzedrostek[j]=m-przedrostkowaWzoru[m];
    }
    for (i=1;i<=m;i++)
    {
        j=m-przedrostkowaWzoruOdw[i];
        if (dobryPrzedrostek[j]>i-przedrostkowaWzoruOdw[i])
        {
            dobryPrzedrostek[j]=i-przedrostkowaWzoruOdw[i];
        }
    }

    s=0;

    while (s<=n-m)
    {
        j=m;

        while ((j>0)&&(Wzorzec[j-1]==Tekst[s+j-1]))// !!!!!!!! -1 NIE MA W SKRYPCIE
        {                                          // NIE MOZE BYC WZORZEC Z MTYM ELEMENETEM
            j--;
        }
        if (j==0)
        {

            cout << "S to: "<<s<<endl;
            s=s+dobryPrzedrostek[0];
        }
        else
        {

            s=s+max(dobryPrzedrostek[j],(j-ostatnieWystopienie[((int)Tekst[s+j])]));

        }
   }
}

int main()
{
    int n=100;
    int T[n];
 //   int check[n];
    //T=(int*)malloc(n*sizeof(int));
    int i=0;
 //   srand( time( NULL ) );

    char txt[] = "KALAFIOR DUZY I DOBRY";
                //012345678901234567890123456
    char pat[] = "DOBRY";
//    int q = 101;
/*
    for (i=0;i<n;i++)
    {
        T[i]=rand()%n+1;
        //T[i]=rand()%3+0;
        check[i]=T[i];
    }*/
    //quicksort(0,n,T);
    //flaga_Polska(T,n);
    //flaga_Francuska(T,n);
    //bobblesort(T,n);
    //insertsort(T,n);
    //selectsort(T,n);
    /*
    for (i=0;i<n;i++)
    {
        cout << T[i] <<"   " << i <<"   " << check[i]<< endl;
    }
    cout <<"   " << endl;
    cout <<"   " << endl;
    cout <<"   " << endl;
    */
    //cout <<wyszukiwanie_bisek(T,0,n-1,16) << endl;
    //Karp_Rabin(pat,txt);
    Boyer_Moore(txt,pat);
    //Knuth_Morris_Pratt(pat,txt);

    return 0;
}
