#include<iostream>
using namespace std;

class Money
{
	public:
		int val;
		eCash()
		{			
			val=0;
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
	    		cout<<"eCash: You stored "<<val<<"."<<endl;	    		
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
	    		cout<<"eCash: You spend "<<val<<"."<<endl;
			}
	    	
		}
	    void display()
		{
	    	cout<<"eCash: You remaining "<<val<<"."<<endl;	
		}
};

int main()
{
	Money c;
	char key;
	int val; //Á`ª÷ÃB 
	
	while(1){
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
			    cout<<"eCash: Thank you. Bye Bye.";
			    return 0;
			    break;
	    }
	}
}




