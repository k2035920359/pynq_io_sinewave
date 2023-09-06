#include<iostream>
#include<stdio.h>
#include <string.h>
using namespace std;

class money
{
	
	
	private:
		char filename[100]; //使用者帳號 
		int val;  //可用金額 
		FILE *f1; //存入檔案
	public:
		
		money()
		{			
			val=0;
		} 
		
		void login(char *name) //登入，如無新帳號則創一個存在txt，第二次登入創建帳號，如已有帳號則直接登入，這裡數手無策 
		{    
		    char *ret;
			cout<<"eCash: 請輸入您的帳號:";
		    cin>>filename;  //input file name
		    ret = strcpy(name, filename);
		    f1=fopen(filename,"r");
		    if (f1==NULL){
			    cout<<"eCash: 帳號不存在, 第一次使用!";
			    return;
		    }	
		    else{
		    	fscanf(f1,"%d\n",&val);
		        
		    }	
			fclose(f1);	
		}
		
		logout()  //登出存檔 
		{   
			f1=fopen(filename,"w");
			fprintf(f1,"%d\n",val);
			cout<<"eCash: 帳號登出, 已存檔!"<<endl;
			cout<<"謝謝，Bye Bye."<<endl;
			fclose(f1);
		} 
	    void store(int m)
		{
	    	cin>>m;
	    	if(m<=0){
	    		cout<<"eCash: Please enter a number > 0."<<endl;
	    		return;
			}
	    	else{
	    		val+=m;
	    		cout<<"eCash: You stored "<<m<<"."<<endl;	    		
			}
	    	
		}
	    void pay(int m)
		{
	    	cin>>m;
	    	if(m<=0){
	    		cout<<"eCash: Please enter a number > 0."<<endl;
	    		return;
	    	}
	    	if(m>val){
	    		cout<<"eCash: Insufficient balance."<<endl;
			}
	    	else{
	    		val-=m;
	    		cout<<"eCash: You spend "<<m<<"."<<endl;
			}
	    	
		}
	    void display()
		{
	    	cout<<"eCash: You remaining "<<val<<"."<<endl;	
		}
};

int main()
{
	money c;
	char key;  
	int val; 
	char name[100];
	
	c.login(name);      	
	
	while(1){
		
		cout<<name<<"您好請選擇項目"<<endl; 
		cout<<"輸入’s’: 儲值"<<endl;
		cout<<"輸入’p’: 消費"<<endl;
		cout<<"輸入’d’:查詢餘額"<<endl;
		cout<<"輸入’q’: 離開"<<endl;
			
	    cin>>key;
	    switch(key){
		    case's':
			    c.store(val);
			    break;	
		    case'p':
			    c.pay(val);
			    break;		
		    case'd':
			    c.display();
			    break;	
		    case'q':
		    	c.logout();
		    	system("PAUSE");
			    return 0;
			    break;
	    }
	}
}




