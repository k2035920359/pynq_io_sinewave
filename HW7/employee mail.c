#include<stdio.h>

struct Employee
{  //宣告資料結構 
	char Name[20];
	char Phone[20];
	char mail[100];
};


int main()
{
	struct Employee p[50];
	int inp=0;
	char op;
	char filename[100];
	FILE *f1;
	int i;
    
    
	while(1){
		//puts("i 插入");
		//puts("l 列出");
		//puts("s 存檔");
		//puts("o 讀檔");
		//puts("q 結束");
		
		scanf("%c",&op);
		switch(op){
			case 'i':
		        scanf("%s",p[inp].Name);  
	            scanf("%s",p[inp].Phone);
	            scanf("%s",p[inp].mail);
	            inp++;   
				break;
			case 'l':
			    for(i=0;i<inp;i++){
				    printf("Name: %s\n",p[i].Name);
				    printf("Phone: %s\n",p[i].Phone);
				    printf("Email: %s\n",p[i].mail);
			    }	
			    break;
			case 's':
				scanf("%s",filename); //input file name
				f1=fopen(filename,"w");
				//if(f1==NULL){
				//    printf("開寫檔失敗!");
				//    return 1;
				//}
			    
			    //else{
				for(i=0;i<inp;i++){
				    fprintf(f1,"%s\n",p[i].Name);
				    fprintf(f1,"%s\n",p[i].Phone);
				    fprintf(f1,"%s\n",p[i].mail);
				        
			    }
				
				//}
				fclose(f1);
				break;
			case 'o':
				scanf("%s",filename);  //input file name
			    f1=fopen(filename,"r");
			    
			    //if (f1==NULL){
				//    printf("讀檔失敗!");
				//    return 1;
				//}
				
				//else{
				for(i=0;i<inp;i++){
		            fscanf(f1,"%s",p[i].Name); 
	                fscanf(f1,"%s",p[i].Phone);
	                fscanf(f1,"%s",p[i].mail);
	                    
	                }
				//}
	            fclose(f1);	
				break;		
			case'c':
			    system("cls");
				break;			
			case'q':
				return 0;
				
	    }
	    
    }
	return 0;
} 
