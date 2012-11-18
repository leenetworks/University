#include <iostream.h> 
#include <string.h> 
#define M 3 //资源的种类数 
#define N 5 //进程的个数 

void output(int iMax[N][M],int iAllocation[N][M],int iNeed[N][M],int iAvailable[M],char cName[N]); //统一的输出格式 
bool safety(int iNeed[N][M],int iMax[N][M],int iAllocation[N][M],int iAvailable[M],char cName[N]); 
bool banker(int iRequest[M],int iNeed[N][M],int iAllocation[N][M],int iAvailable[M],char cName[N]); 

int main() 
{ 
	char cName[N]={'a','b','c','d','e'};//进程名
   int iAvailable[M]={3,3,2}; //当前可用每类资源的资源数   
   int iMax[N][M]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}}; //系统中N个进程中的每一个进程对M类资源的最大需求    
   int iAllocation[N][M]={{0,1,1},{2,0,0},{3,0,2},{2,1,1},{0,0,2}}; //iAllocation[N][M]为系统中每一类资源当前已分配给每一进程的资源数 
   int iNeed[N][M];//每一个进程尚需的各类资源数          
   char ch; //接收选择是否继续提出申请时传进来的值
   int iRequest[M];//提出申请时各类资源的申请数,接收提出申请时键盘传来的数

   //计算iNeed[N][M]的值 
   for(int i=0;i<N;i++) 
   for(int j=0;j<M;j++) 
   iNeed[i][j]=iMax[i][j]-iAllocation[i][j]; 
   
   bool bSafe; //存放安全与否的标志 
   bool bExitFlag=true; //退出标记
     
   output(iMax,iAllocation,iNeed,iAvailable,cName); //输出初始值界面   
   bSafe=safety(iNeed,iMax,iAllocation,iAvailable,cName);//判断当前状态是否安全
   while(bSafe) 
   {
       //是否继续提出申请 
       while(bExitFlag) 
	   { 
            cout<<"\n"<<"继续提出申请？\ty为是；n为否"; 
            cin>>ch; 
            switch(ch) 
			{ 
                 case 'y':bSafe=banker(iRequest,iNeed,iAllocation,iAvailable,cName); 
                          if (bSafe) //安全，则输出变化后的数据 
                                output(iMax,iAllocation,iNeed,iAvailable,cName); 
                          break; 
                case 'n': cout<<"退出"; 
                          bExitFlag=false; 
                          break; 
                default:cout<<"输入有误，请重新输入：\n"; 
			} 
	   } 
   }
return 0;
} 

//输出 
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

     //Available只需要输出一次 
       if (i==0) 
       for(j=0;j<M;j++) 
       cout<<iAvailable[j]<<" "; 

       cout<<endl; 
   } 
} 

//安全性算法，进行安全性检查；安全返回true，并且输出安全序列，不安全返回false，并输出不安全的提示； 
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
			   cout<<"系统处于安全状态";
               for(int i=0;i<N;i++) 
                 for(int j=0;j<M;j++) 
                   iNeed[i][j]=iMax[i][j]-iAllocation[i][j]; 
		   return true;
		   }
	 }
   }  
     cout<<"系统处于不安全状态!!!"<<endl;
	 return false;
			
}

//定位ch对应的进程名在数组中的位置,没找见返回－1，否则返回数组下标 
int locate(char cName[N],char ch) 
{ 
   int i; 
   for(i=0;i<N;i++) 
       if(cName[i]==ch) //找到 
          return i; 
   return -1;    //未找到   
} 

//提出申请,返回提出申请的进程名对应的下标 
int request(char cName[N],int iRequest[M]) 
{ 
   int i,loc; 
   char ch; 
   bool bFlag=true; 

   //判断输入的进程名是否有误 
   while(bFlag) 
   { 
	   cout<<"进程名：";
       //输出进程名界面
       for(i=0;i<N;i++) 
       cout<<cName[i]<<" "; 

       cout<<"\n输入提出资源申请的进程名:"; 
       cin>>ch; 

      //定位ch对应的进程名在进程名数组中的位置 
       loc=locate(cName,ch);       
       if (loc==-1) //没找到，重新输入
          cout<<"\n您输入的进程名有误!请重新输入!"<<endl;     
       else //找到，退出循环
          bFlag=false; 
   } 
   cout<<"输入申请各类资源的数量："; 
   for(i=0;i<M;i++) 
   cin>>iRequest[i]; 

   //返回提出申请的进程名对应的下标 
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
			cout<<"系统处于安全状态，已分配";
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
    cout<<"系统处于不安全状态!!!"<<endl;
	return false;
}

