#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<fstream>
using namespace std;
//for frst page of graphics
class Display
{
  private:
  int i,j;
  public:
  void start();
};

void Display::start()
{
    cleardevice();
    setbkcolor(BLACK);
    setcolor(RED);
   for(i=0;i<640;i++)
    line(i,0,i,500);
    for(i=320,j=320;i>=50;i--,j++)
    {
     setcolor(0);
     line(i,0,i,500);line(j,0,j,500);
     delay(0.1);
    }
    setcolor(MAGENTA);
    j=100;i=5;
    settextstyle(1,HORIZ_DIR,i);
    outtextxy(j,100,"I");
    delay(0.5);
    outtextxy(j,100,"IP");
    delay(0.5);
    outtextxy(j,100,"IPL");
    delay(0.5);
    outtextxy(j,175,"T");
    delay(0.5);
    outtextxy(j,175,"TE");
    delay(0.5);
    outtextxy(j,175,"TEA");
    delay(0.5);
    outtextxy(j,175,"TEAM ");
    delay(0.5);
    outtextxy(j,250,"E");
    delay(0.5);
    outtextxy(j,250,"EL ");
    delay(0.5);
    outtextxy(j,250,"ELI ");
    delay(0.5);
     outtextxy(j,250,"ELIM ");
    delay(0.5);
     outtextxy(j,250,"ELIMI ");
    delay(0.5);
     outtextxy(j,250,"ELIMIN ");
    delay(0.5);
     outtextxy(j,250,"ELIMINA");
    delay(0.5);
     outtextxy(j,250,"ELIMINAT");
    delay(0.5);
     outtextxy(j,250,"ELIMINATI");
    delay(0.5);
     outtextxy(j,250,"ELIMINATIO ");
    delay(0.5);

     outtextxy(j,250,"ELIMINATION");
    delay(0.5);
    j=135;
    outtextxy(240,330,"...?... ");
    settextstyle(5,HORIZ_DIR,2);
    outtextxy(105,400,"by-NIKHIL,BHAVNA,VAIBHAV,NANDINI");
    setcolor(YELLOW);
    settextstyle(7,HORIZ_DIR,1);
    for(i=0;i<450;i+=20)
    {
    outtextxy(80,i,"$");
    outtextxy(550,i,"$");
    delay(5);
    }
    getch();
    setcolor(CYAN);
    for(i=0;i<320;i+=5)
        {
            delay(20);
            line(i,0,i,500);
            line(638-i,0,638-i,500);
        }
    //exit(0);
    cleardevice();
    setbkcolor(0);
}
using namespace std;
# define n 4
# define a 3
struct team
{
    char name[20];
    int w;
    int p;
    int match[n];
}s[n];


int sum=0;
bool maxflow(int sn[a],int tmp[n],int b[a][2])
{
    int i,j,k,x,y,ans=0,mn;
    for(i=0;i<a;i++)
    {
        if(sn[i]!=0)
        {

            x=b[i][0];
            y=b[i][1];
          // cout<<x<<" "<<y<<" "<<tmp[y]<<" "<<tmp[x]<<" "<<sn[i]<<" "<<s[x].match[y]<<endl;
            int tmp2=s[x].match[y];
            mn=min(tmp2,tmp[y]);
            sn[i]-=mn;
            tmp[y]-=mn;
            tmp2-=mn;
            ans+=mn;
            mn=min(tmp2,tmp[x]);
            tmp[x]-=mn;
            sn[i]-=mn;
            ans+=mn;
        }

    }
    cout<<"max flow is "<<ans<<endl;
    if(ans>=sum)
        return true;
    else
        return false;
}

int maxx=0;
int main()
{ int i,j,k,l;

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    setbkcolor(0);
    Display x;
    x.start();
    FILE * fp;
 fp=fopen("hey.txt","r");

    //string word;
    int ai=0;
    int ctr=0;

   while (!feof(fp))
    {
         fscanf(fp,"%s %d %d ",s[ai].name,&s[ai].w,&s[ai].p);
         if(s[ai].w>maxx)
            maxx=s[ai].w;
         //cout<<s[ai].name<<s[ai].w<<s[ai].p<<endl;
         for(ctr=0;ctr<n;ctr++)
         {   if(i==n-1)
         fscanf(fp,"%d\n",&s[ai].match[ctr]);
             else
             fscanf(fp,"%d ",&s[ai].match[ctr]);
             //cout<<s[ai].match[ctr]<<endl;
         }
         ai++;
     }
     /*for(int hh=0;hh<n;hh++)
     {
         cout<<"name is "<<s[hh].name<<endl;
         cout<<"this team won"<<s[hh].w<<endl;
         cout<<"this team left with"<<s[hh].p<<endl;
         for(int ll=0;ll<n;ll++)
         {
             cout<<s[hh].match[ll]<<"\t";
         }
         cout<<"\n";
     }

*/

    for(i=0;i<n;i++)
   {
sum=0;
    int t=s[i].w+ s[i].p;
    cout<<s[i].name<<endl;

    int b[a][2];
           if(t<maxx)
           cout<<s[i].name<<" team IS elliminated \n";
           else
           {int tmp[n];



         for(j=0;j<n;j++)
            {
                if(j!=i)
                tmp[j]=t-s[j].w;
                else
                tmp[j]=-1;
            }
        int o=0;
         for( k=0;k<n;k++)
         {
              if(k!=i)
                {
                    for(l=k+1;l<n;l++)
                    {
                        if(l!=i)
                        {
                            b[o][0]=k;
                            b[o][1]=l;
                            //cout<<b[o][0]<<"\t"<<b[o][1]<<"\n";
                            o++;
                        }
                    }
                }
         }
       for(int ii=0;ii<o;ii++)
         {
             cout<<"match of "<<b[ii][0]<<"\t"<<"with"<<b[ii][1]<<"\n";
         }
         cout<<"midmatrix\n";
        int an[o][n],sn[o],tn[n];
        for(int k=0;k<o;k++)
        {
            for(int l=0;l<n;l++)
            {
               // cout<<l<<" "<<k<<" "<<s[b[k][1]].match[b[k][0]]<<" ";
               // cout<<b[k][0]<<" "<<b[k][1]<<" "<<l<<" "<<s[b[k][1]].match[b[k][0]]<<" ";
                if(l==b[k][1]||l==b[k][0])
                    an[k][l]=s[b[k][1]].match[b[k][0]];
                else
                    an[k][l]=0;
                cout<<an[k][l]<<"\t";
            }
           cout<<"\n";
        }
        cout<<"source\n";

        for(int k=0;k<o;k++)
        {
            sn[k]=s[b[k][1]].match[b[k][0]];
            sum+=sn[k];
            cout<<sn[k]<<"\t";
        }
        cout<<"\n";
        int z=0;
        cout<<"destination\n";
        for(int k=0;k<n;k++)
        {
            if(tmp[k]!=-1)
            {
                tn[z]=tmp[k];
                cout<<tn[z]<<"\t";
                z++;
            }
        }
        cout<<"\n";
        if(maxflow(sn,tmp,b))
        {
            cout<<s[i].name<<" is not eliminated"<<endl;
        }
        else{
            cout<<s[i].name<<" is eliminated"<<endl;

        }
}

   }
    return 0;
}

