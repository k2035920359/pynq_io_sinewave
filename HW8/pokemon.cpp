#include<iostream>
#include"pokemon.h"
using namespace std;
   
    char Name[100];
    int Lv;
    int Hp;
   
void InputData(struct Pokemon *p){
	cin>>Name;
    cin>>p->Lv;
    cin>>p->Hp;	
}
void ShowInfo(struct Pokemon p){
	cout<<"Name: "<<Name<<endl;
    cout<<"Lv: "<<p.Lv<<endl;
    cout<<"HP: "<<p.Hp<<endl<<endl;	
}

