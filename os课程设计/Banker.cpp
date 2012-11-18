#include <iostream.h> 
#include <string.h> 
#define M 3 //��Դ�������� 
#define N 5 //���̵ĸ��� 

void output(int iMax[N][M],int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N]); //ͳһ�������ʽ 
bool safety(int iNeed[N][M],int iMax[N][M],int iAllocation[N][M],int iAvailable[M],char cName[N]); 
bool banker(int iRequest[M],int iNeed[N][M],int iAllocation[N][M],int iAvailable[M],char cName[N]); 

int main() 
{ 
	char cName[N]={'a','b','c','d','e'};//������
   int iAvailable[M]={3,3,2}; //��ǰ����ÿ����Դ����Դ��   
   int iMax[N][M]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}}; //ϵͳ��N�������е�ÿһ�����̶�M����Դ���������    
   int iAllocation[N][M]={{0,1,1},{2,0,0},{3,0,2},{2,1,1},{0,0,2}}; //iAllocation[N][M]Ϊϵͳ��ÿһ����Դ��ǰ�ѷ����ÿһ���̵���Դ�� 
   int iNeed[N][M];//ÿһ����������ĸ�����Դ��          
   char ch; //����ѡ���Ƿ�����������ʱ��������ֵ
   int iRequest[M];//�������ʱ������Դ��������,�����������ʱ���̴�������

   //����iNeed[N][M]��ֵ 
   for(int i=0;i<N;i++) 
   for(int j=0;j<M;j++) 
   iNeed[i][j]=iMax[i][j]-iAllocation[i][j]; 
   
   bool bSafe; //��Ű�ȫ���ı�־ 
   bool bExitFlag=true; //�˳����
     
   output(iMax,iAllocation,iNeed,iAvailable,cName); //�����ʼֵ����   
   bSafe=safety(iNeed,iMax,iAllocation,iAvailable,cName);//�жϵ�ǰ״̬�Ƿ�ȫ
   while(bSafe) 
   {
       //�Ƿ����������� 
       while(bExitFlag) 
	   { 
            cout<<"\n"<<"����������룿\tyΪ�ǣ�nΪ��"; 
            cin>>ch; 
            switch(ch) 
			{ 
                 case 'y':bSafe=banker(iRequest,iNeed,iAllocation,iAvailable,cName); 
                          if (bSafe) //��ȫ��������仯������� 
                                output(iMax,iAllocation,iNeed,iAvailable,cName); 
                          break; 
                case 'n': cout<<"�˳�"; 
                          bExitFlag=false; 
                          break; 
                default:cout<<"�����������������룺\n"; 
			} 
	   } 
   }
return 0;
} 

//��� 
void output(int iMax[N][M],int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N]) 
{ 
   int i,j; 

   cout<<"\n\t Max \tAllocation\tNeed\t Available"<<endl; 
   cout<<"Process\tA B C\tA B C\t\tA B C\t A B C"<<endl; 

   for(i=0;i<N;i++) 
   { 
       cout<<cName[i]<<"\t"; 

       for(j=0;j<M;j++) 
       cout<<iMax[i][j]<<" "; 
       cout<<"\t"; 

       for(j=0;j<M;j++) 
       cout<<iAllocation[i][j]<<" "; 
       cout<<"\t\t"; 

       for(j=0;j<M;j++) 
       cout<<iNeed[i][j]<<" "; 
       cout<<"\t"; 
       cout<<" "; 

     //Availableֻ��Ҫ���һ�� 
       if (i==0) 
       for(j=0;j<M;j++) 
       cout<<iAvailable[j]<<" "; 

       cout<<endl; 
   } 
} 

//��ȫ���㷨�����а�ȫ�Լ�飻��ȫ����true�����������ȫ���У�����ȫ����false�����������ȫ����ʾ�� 
bool safety(int iNeed[N][M] ,int iMax[N][M],int iAllocation[N][M],int iAvailable[M],char cName[N]) 
{
   int i,j;
   int loc;

   int currentavail[M];
   bool possible=false;
   for(i=0;i<N;i++)
    {	int x=0;
		for(j=0;j<M;j++)		
		    if(iAvailable[j]>=iNeed[i][j])  x++;
		if(x==M) {loc=i; possible=true;break;}
	}		
	  
   while(possible)
   {
   for(j=0;j<M;j++)
       currentavail[j]=iAvailable[j]+iNeed[loc][j];
   for(i=loc;i<N;i++)
     for(j=0;j<N;j++)  
	   iNeed[loc][j]=iNeed[loc+1][j];
   for(i=0;i<N-1;i++)
    {	
		   int y=0;
	       for(j=0;j<M;j++)		
		        if(currentavail[j]>=iNeed[i][j])  y++;
		   if(y==M) {
			   cout<<"ϵͳ���ڰ�ȫ״̬";
               for(int i=0;i<N;i++) 
                 for(int j=0;j<M;j++) 
                   iNeed[i][j]=iMax[i][j]-iAllocation[i][j]; 
		   return true;
		   }
	 }
   }  
     cout<<"ϵͳ���ڲ���ȫ״̬!!!"<<endl;
	 return false;
			
}

//��λch��Ӧ�Ľ������������е�λ��,û�Ҽ����أ�1�����򷵻������±� 
int locate(char cName[N],char ch) 
{ 
   int i; 
   for(i=0;i<N;i++) 
       if(cName[i]==ch) //�ҵ� 
          return i; 
   return -1;    //δ�ҵ�   
} 

//�������,�����������Ľ�������Ӧ���±� 
int request(char cName[N],int iRequest[M]) 
{ 
   int i,loc; 
   char ch; 
   bool bFlag=true; 

   //�ж�����Ľ������Ƿ����� 
   while(bFlag) 
   { 
	   cout<<"��������";
       //�������������
       for(i=0;i<N;i++) 
       cout<<cName[i]<<" "; 

       cout<<"\n���������Դ����Ľ�����:"; 
       cin>>ch; 

      //��λch��Ӧ�Ľ������ڽ����������е�λ�� 
       loc=locate(cName,ch);       
       if (loc==-1) //û�ҵ�����������
          cout<<"\n������Ľ���������!����������!"<<endl;     
       else //�ҵ����˳�ѭ��
          bFlag=false; 
   } 
   cout<<"�������������Դ��������"; 
   for(i=0;i<M;i++) 
   cin>>iRequest[i]; 

   //�����������Ľ�������Ӧ���±� 
   return loc; 
} 

bool banker(int iRequest[M],int iNeed[N][M],int iAllocation[N][M],int iAvailable[M],char cName[N]) 
{ 
	int n,m;
	int currentavail[M],currentneed[N][M];
	for(n=0;n<N;n++)
		for(m=0;m<M;m++)
	        currentneed[n][m]=iNeed[n][m];	  
	int i=request(cName,iRequest);
	int x=0;
	bool possible=false,flage=false;
    for(m=0;m<M;m++)
		if(iRequest[m]<=iAvailable[m]) x++;
	if(x=M)  possible=true;
    while(possible)
	{
          for(m=0;m<M;m++)
		  {   
			  currentavail[m]=iAvailable[m]-iRequest[m];  
	          currentneed[i][m]=iNeed[i][m]-iRequest[m];
		  }

          for(n=0;n<N;n++)
		  {	
		      int y=0;
	          for(m=0;m<M;m++)		
				  if(currentavail[m]>=currentneed[n][m])  y++;
		      if(y==M)
			  {
			     flage=true;
			     break;
			  }			
		  }
        if(flage)
		{  
			cout<<"ϵͳ���ڰ�ȫ״̬���ѷ���";
	        for(m=0;m<M;m++)
			{
               iAvailable[m]=currentavail[m];
	           iNeed[i][m]=currentneed[i][m];
               iAllocation[i][m]=iAllocation[i][m]+iRequest[m];	       
			} 
			return true;
		}
		else{
		   possible=false;
		}
	 
	} 
    cout<<"ϵͳ���ڲ���ȫ״̬!!!"<<endl;
	return false;
}

