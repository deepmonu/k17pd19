#include<bits/stdc++.h>
using namespace std;

#define totalprocess  5

class process
{
	public:
	int at,bt,pr,pno;
};
process proc[50];


bool compare(process a,process b)
{
	if(a.at == b.at)
	{
		return a.pr<b.pr;
	}
	else
	{
		return a.at<b.at;
	}
}

void get_wt_time(int wt[])             //using fcfs find wt
{
	int s[50],pt[50];                 
	s[0]=0;
	wt[0]=0;
	
	for(int i=0;i<totalprocess;i++)
	{
		s[i]=proc[i-1].bt + s[i-1];
		wt[i]=s[i]-proc[i].at+1;
		
		if(wt[i]<0)
		{
			wt[i]=0;
		}
		pt[i]=1+(wt[i]/proc[i].bt);
			proc[i].pr=pt[i];
	}
	sort(proc,proc+totalprocess,compare);
}
void get_tat_time(int tat[],int wt[])     //filling turnaroundtime
{
	for(int i=0;i<totalprocess;i++)
	{
		tat[i]=proc[i].bt+wt[i];
	}
}
void findgant_chart()
{
	int wt[50],tat[50];
	double wa_avg=0,t_avg=0;
	
	get_wt_time(wt);
	get_tat_time(tat,wt);
	
	int s_time[50],c_time[50];
	s_time[0]=1;
	c_time[0]=s_time[0]+tat[0];
	                                   
	for(int i=0;i<totalprocess;i++)
	{
		s_time[i]=c_time[i-1];
		c_time[i]=s_time[i]+tat[i]-wt[i];
	}
	
	cout<<"process_no\tstart_time\tcomplete_time\tturnaroundtime\twaiting_time"<<endl;
	
	for(int i=0;i<totalprocess;i++)
	{
		wa_avg += wt[i];
		t_avg +=tat[i];
		
		cout<<proc[i].pno<<"\t\t"<<s_time[i]<<"\t\t"<<c_time[i]<<"\t\t"<<tat[i]<<"\t\t\t"<<wt[i]<<endl;
	}
	cout<<"Average wating time is:";
	cout<<wa_avg/(float)totalprocess<<endl;
	cout<<"average turnaround time :";
	cout<<t_avg/(float)totalprocess<<endl;
}
int main()
{
	int arrivaltime[]={1,2,3,4,5};
	int bursttime[] = {3,5,1,7,4};

	for(int i=0;i<totalprocess;i++)
	{
		proc[i].at=arrivaltime[i];
		proc[i].bt=bursttime[i];
		proc[i].pno=i+1;
	}
	
	findgant_chart();
	return 0;
}
