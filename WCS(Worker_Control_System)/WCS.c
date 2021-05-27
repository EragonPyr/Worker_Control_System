#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include<locale.h>
int month,day,hour,minute;
struct list{
	char password[50];
	char name[50];
	char surname[50];
	char telnum[50];
	char email[50];
	int late;
	float mainsal;
	int less;
	int more;
}worker[9999];
time_finder(){
	time_t now;
	now=time(NULL);
	hour=now%86400;
	hour=hour/3600;
	hour=hour+3;
	minute=now%3600;
	minute=minute/60;
	now=now/86400;
	now=now-18627;
	for(month=1;now>0;month++){
		if(now<=31){
			day=now;
			return 1;
		}
		else{
			month++;
			now=now-31;
			if(month==8){
				if(now<=31){
					day=now;
					return 1;
				}
				day=day-31;
				month++;
			}
			if(month==2){
				if(now<=28){
					day=now;
					return 1;
				}
				now=now-28;
			}
			else{
				if(now<=30){
					day=now;
					return 1;
				}
				now=now-30;
			}
		}
	}
}
sound(){
	Beep(370,465);Beep(370,232);Beep(554,232);Beep(494,465);Beep(440,465);
	/*Beep(415,465);Beep(415,232);Beep(415,232);Beep(494,465);Beep(440,232);
	Beep(415,232);Beep(370,465);Beep(370,232);Beep(880,232);Beep(831,232);
	Beep(880,232);Beep(831,232);Beep(880,232);Beep(370,465);Beep(370,232);
	Beep(880,232);Beep(831,232);*/
}
main(){
	setlocale(LC_ALL,"Turkish");
	int i,l,k,err=0,adminid,nnn,id[9999],testid,here[9999],stahou,stamin,finhou,finmin,nec_1,nec_2,mes=0,fro[9999],warn=0,warnid[9999],newshou,newsmin,newfhou,newfmin;
	char testpass[50],adminpass[50],choice,message[50][500],newpass[3][50];
	float sall;
	int g,h,y=0;
	time_finder();
	
	printf("----------------System Starting---------------- \n");
	        printf(" ");
            printf(" O\n");
            printf(" ");
            printf("/|\\\n"); 
            printf(" / \\");
           	sound(); 
	while(y<3){
	 	for( h=0; h<15; h++){
	 		if (y==0){
	       		printf("System Starting.\n");
			}
		   	else if (y==1){
		   		printf("System Starting..\n");
			}
		   	else if (y==2){
		   		printf("System Starting...\n");
			}
		    for(g=0; g<h; g++){
				printf(" ");  
			}
            printf(" O\n");
            for( g=0; g<h; g++){
				printf(" ");
			}
            printf("/|\\\n"); 
            for( g=0; g<h; g++){
				printf(" ");
			}
            if(h%2==0){
            	printf(" /\\");
			}
            else{
            	printf(" |");
			}
            Sleep(30);
            system("CLS");
		}
		y++;
	}
	FILE *fworkers;
	FILE *fadmin;
	FILE *fhappen;
	FILE *fmessage;
	
	fworkers=fopen("workers.txt","r");
	if(fworkers==NULL){
      	printf("Error: workers.txt\n");
      	err+=1;
      	sleep(1);
    }
    fclose(fworkers);
    
    fadmin=fopen("admin.txt","r");
	if(fadmin==NULL){
      	printf("Error: admin.txt\n");
      	err+=1;
      	sleep(1);
    }
    fclose(fadmin);
    
    fhappen=fopen("happen.txt","r");
	if(fhappen==NULL){
      	printf("Error: happen.txt\n");
      	err+=1;
      	sleep(1);
    }
    fclose(fhappen);
    
    fmessage=fopen("messages.txt","r");
	if(fmessage==NULL){
      	printf("Error: messages.txt\n");
      	err+=1;
      	sleep(1);
    }
    fclose(fmessage);
    
    if(err!=0){
    	printf("\nSystem could not find %d file(s).\nThe system is shutting down...",err);
    	sleep(2);
    	exit(0);
	}
	
	fadmin=fopen("admin.txt","r");
	fscanf(fadmin,"%d %s",&adminid,&adminpass);
	fclose(fadmin);
	
	fhappen=fopen("happen.txt","r");
	fscanf(fhappen,"%d %d %d %d",&stahou,&stamin,&finhou,&finmin);
	fclose(fhappen);
	
	fworkers=fopen("workers.txt","r");
	fscanf(fworkers,"%d",&nnn);
	for(l=0;l<nnn;l++){
		fscanf(fworkers,"%d",&id[l]);
		if(here[id[l]]==2){
			printf("Error: id %d \nSystem shutting down...",id[l]);
			sleep(3);
			return 0;
		}
		testid=id[l]/1000;
		if(testid<1||testid>9){
			printf("Error: id %d \nSystem shutting down...",id[l]);
			sleep(3);
			return 0;
		}
		fscanf(fworkers,"%s %s %s %s %s %d %f %d %d",&worker[id[l]].password,&worker[id[l]].name,&worker[id[l]].surname,&worker[id[l]].telnum,&worker[id[l]].email,&worker[id[l]].late,&worker[id[l]].mainsal,&worker[id[l]].less,&worker[id[l]].more);
		worker[id[l]].late++;
		worker[id[l]].less+=480;
		here[id[l]]=2;
		if(worker[id[l]].late>3){
			warnid[warn]=id[l];
			warn++;
		}
	}
	fclose(fworkers);
	
	
	printf("Admin Password: ");
	scanf("%s",&testpass);
	if(strcmp(adminpass,testpass)==0){
		system("CLS"); 
		y=0;
  		printf("----------------System Opened----------------\n");
		sleep(2);
	}
	else{
		system("CLS");
		printf("Your input is not correct\nThe system is shutting down...");
		exit(0);
	}
	
	startin:
	system("CLS");
	printf("Welcome User\nWhat are you want:\n\t1 = Check the date\n\t2 = Login the system\n\t\t+");
	scanf("%s",&choice);
	system("CLS");
	
	if(choice=='1'){
		time_finder();
		printf("%d/%d/2021   %d:%d\n\nPress a key...",day,month,hour,minute);
		getch();
		goto startin;
	}
	else if(choice=='2'){
		printf("User id: ");
		scanf("%d",&testid);
		system("CLS");
		if(testid==adminid){
			goto admin;
		}
		printf("Password: ");
		scanf("%s",&testpass);
		system("CLS");
		
		if(strcmp(worker[testid].password,testpass)==0){
			time_finder();
			printf("Welcome %s",worker[testid].name);
			sleep(2);
			system("CLS");
		}
		else{
			printf("Your input is not correct\nPress a key...");
			getch();
			goto startin;
		}
		if(here[testid]==2){
			printf("Your start time saved");
			here[testid]=1;
			if(hour>=stahou){
				if(minute>stamin||hour>stahou){
					nec_1=hour-stahou;
					nec_2=minute-stamin;
					nec_1=nec_1*60;
					nec_1=nec_1+nec_2;
					worker[testid].less-=480;
					worker[testid].less+=nec_1;
				}
				else{
					nec_1=stamin-minute;
					worker[testid].less-=480;
					worker[testid].more+=nec_1;
					worker[testid].late--;
				}
			}
			else{
				nec_1=stahou-hour;
				nec_2=stamin-minute;
				nec_1=nec_1*60;
				nec_1=nec_1+nec_2;
				worker[testid].less-=480;
				worker[testid].more+=nec_1;
				worker[testid].late--;
			}
			sleep(2);
		}
		prof:
		system("CLS");
		printf("What do you want:\n\t1 = See your profile\n\t2 = See your sallary\n\t3 = Send a message to admin\n\t4 = Change your password\n\t5 = Logout\n\t6 = Exit from office\n\t\t+");
		scanf("%s",&choice);
		system("CLS");
		if(choice=='1'){
			printf("id:\t\t%d\nName:\t\t%s\nSurname:\t%s\nTel Number:\t%s\nEmail:\t\t%s\nMain Sallary:\t%.2f\n\nPress a key...",testid,worker[testid].name,worker[testid].surname,worker[testid].telnum,worker[testid].email,worker[testid].mainsal);
			getch();
			goto prof;
		}
		else if(choice=='2'){
			sall=worker[testid].mainsal;
			sall=sall+((sall/19200)*worker[testid].more);
			sall=sall-(worker[testid].late*(worker[testid].mainsal/60));
			sall=sall-(worker[testid].less*(worker[testid].mainsal/19200));
			printf("Main Sallary:\t\t%.2f\nCalculated Sallary:\t%.2f\nLate Days:\t\t%d\nLess Works:\t\t%d minute(s)\nMore Works:\t\t%d minute(s)\nTotal:\t\t\t%d minute(s)\n\nPress a key...",worker[testid].mainsal,sall,worker[testid].late,worker[testid].less,worker[testid].more,(worker[testid].more-worker[testid].less));
			getch();
			goto prof;
		}
		else if(choice=='3'){
			getchar();
			printf("Message:\n");
			scanf("%[^\n]",&message[mes]);
			fro[mes]=testid;
			mes++;
			printf("\n\nPress a key...");
			getch();
			time_finder();
			fmessage=fopen("messages.txt","a");
    		fprintf(fmessage,"Date: %d/%d/2021\nTime: %d:%d\nFrom: %d\n\n%s\n\n\n\n",day,month,hour,minute,testid,message[mes-1]);
    		fclose(fmessage);
			goto prof;
		}
		else if(choice=='4'){
			printf("Password: ");
			scanf("%s",&newpass[2]);
			system("CLS");
			if(strcmp(worker[testid].password,newpass[2])!=0){
				printf("Your input is not correct\nPress a key...");
				getch();
				goto prof;
			}
			printf("New Password: ");
			scanf("%s",&newpass[0]);
			system("CLS");
			printf("Again New Password: ");
			scanf("%s",&newpass[1]);
			system("CLS");
			if(strcmp(newpass[0],newpass[1])!=0){
				printf("Your inputs is not same\nPress a key...");
				getch();
				goto prof;
			}
			strcpy(worker[testid].password,newpass[1]);
			printf("Your password changed\nPress a key...");
			getch();
			goto prof;
		}
		else if(choice=='5'){
			goto startin;
		}
		else if(choice=='6'){
			printf("Are you sure Y/N : ");
			scanf("%s",&choice);
			system("CLS");
			if(choice=='Y'||choice=='y'){
				if(here[testid]==3){
					printf("Your finish time already saved");
					sleep(2);
					goto startin;
				}
				printf("Your finish time saved");
				sleep(2);
				/*
				y=0;
    			while(y<10){
					y++;
    				printf("\n----------GOOD BYE----------\n\n");
					printf("  ");
	    			if(y%2==0){
	   			 		printf(" \\O\n");
					}
	    			else{
	    				printf("__O\n");
					}
	    			Sleep(10);
	    			printf("  ");
    				printf("  |\\\n");
					printf("  ");
    				printf(" / \\");
					Sleep(500);
   					system("CLS");	
  				}
  				*/
				time_finder();
				nec_1=hour-finhou;
				nec_1*=60;
				nec_2=minute-finmin;
				nec_1=nec_1+nec_2;
				if(nec_1>=0){
					worker[testid].more+=nec_1;
				}
				else{
					worker[testid].less-=nec_1;
				}
				here[testid]=3;
				goto startin;
			}
			goto prof;
		}
		else{
			printf("Your input is wrong\nPress a key...");
			getch();
			goto prof;
		}
		
	}
	else{
		printf("Your input is wrong\nPress a key...");
		getch();
		goto startin;
	}
	admin:
	fadmin=fopen("admin.txt","r");
	fscanf(fadmin,"%d %s",&adminid,&adminpass);
	fclose(fadmin);
	system("CLS");
	printf("Password: ");
	scanf("%s",&testpass);
	system("CLS");
	if(strcmp(adminpass,testpass)==0){
		printf("Welcome Admin");
		sleep(2);
		system("CLS");
	}
	else{
		printf("Your input is wrong\nPress a key...");
		getch();
		goto startin;
	}
	adminin:
	system("CLS");
	printf("What are you want:\n\t1 = Check the date\n\t2 = Check a worker's profile\n\t3 = [%d]Warning(s)\n\t4 = [%d]Message(s)\n\t5 = Change working time\n\t6 = Change admin id\n\t7 = Change admin password\n\t8 = Logout\n\t9 = Close WCS\n\t\t+",warn,mes);
	scanf("%s",&choice);
	system("CLS");
	if(choice=='1'){
		time_finder();
		printf("%d/%d/2021  %d:%d\nPress a key...",day,month,hour,minute);
		getch();
		goto adminin;
	}
	else if(choice=='2'){
		printf("Worker's id: ");
		scanf("%d",&testid);
		system("CLS");
		if(worker[testid].mainsal==0){
			printf("This id did not find\nPress a key...");
			getch();
			goto adminin;
		}
		sall=worker[testid].mainsal;
		sall=sall+((sall/19200)*worker[testid].more);
		sall=sall-(worker[testid].late*(worker[testid].mainsal/60));
		sall=sall-(worker[testid].less*(worker[testid].mainsal/19200));
		printf("Name:\t\t\t%s\nSurname:\t\t%s\nTel Number:\t\t%s\nE-mail:\t\t\t%s\nMain Sallary:\t\t%.2f\nCalculated Sallary:\t%.2f\nLate day(s):\t\t%d\n\nPress a key...",worker[testid].name,worker[testid].surname,worker[testid].telnum,worker[testid].email,worker[testid].mainsal,sall,worker[testid].late);
		getch();
		goto adminin;
	}
	else if(choice=='3'){
		if(warn==0){
			printf("No warning\nPress a key...");
			getch();
		}
		for(i=0;i<warn;i++){
			printf("Warning %d/%d\nWorker's id:\t\t%d\n",i+1,warn,warnid[i]);
			testid=warnid[i];
			sall=worker[testid].mainsal;
			sall=sall+((sall/19200)*worker[testid].more);
			sall=sall-(worker[testid].late*(worker[testid].mainsal/60));
			sall=sall-(worker[testid].less*(worker[testid].mainsal/19200));
			printf("Name:\t\t\t%s\nSurname:\t\t%s\nTel Number:\t\t%s\nE-mail:\t\t\t%s\nMain Sallary:\t\t%.2f\nCalculated Sallary:\t%.2f\nLate day(s):\t\t%d\n\nPress a key...",worker[testid].name,worker[testid].surname,worker[testid].telnum,worker[testid].email,worker[testid].mainsal,sall,worker[testid].late);
			getch();
			system("CLS");
		}
		goto adminin;
	}
	else if(choice=='4'){
		if(mes==0){
			printf("No messages\nPress a key...");
			getch();
		}
		for(i=0;i<mes;i++){
			printf("Messages %d/%d\nFrom: %d\n\n",i+1,mes,fro[i]);
			printf("%s\n\nPress a key...",message[i]);
			getch();
			system("CLS");
		}
		goto adminin;
	}
	else if(choice=='5'){
		printf("New start hour: ");
		scanf("%d",&newshou);
		system("CLS");
		if(newshou>=0&&newshou<=23){
			printf("");
		}
		else{
			printf("Your input is not suitable\nPress a key...");
			getch();
			goto adminin;
		}
		printf("New start minute: ");
		scanf("%d",&newsmin);
		system("CLS");
		if(newsmin>=0&&newsmin<=59){
			printf("");
		}
		else{
			printf("Your input is not suitable\nPress a key...");
			getch();
			goto adminin;
		}
		
		printf("New finish hour: ");
		scanf("%d",&newfhou);
		system("CLS");
		if(newfhou>=0&&newfhou<=23&&newfhou>=newshou){
			printf("");
		}
		else{
			printf("Your input is not suitable\nPress a key...");
			getch();
			goto adminin;
		}
		printf("New finish minute: ");
		scanf("%d",&newfmin);
		system("CLS");
		if(newfmin>=0&&newfmin<=59&&newfmin>=newsmin){
			printf("");
		}
		else if(newfmin>=0&&newfmin<=59&&newshou<newfhou){
			printf("");
		}
		else{
			printf("Your input is not suitable\nPress a key...");
			getch();
			goto adminin;
		}
		system("CLS");
		printf("Are you sure Y/N : ");
		scanf("%s",&choice);
    	if(choice=='Y'||choice=='y'){
    		system("CLS");
		    stahou=newshou;
		    stamin=newsmin;
		    finhou=newfhou;
		    finmin=newfmin;
		    fhappen=fopen("happen.txt","w");
		    fprintf(fhappen,"%d %d %d %d",stahou,stamin,finhou,finmin);
		    fclose(fhappen);
		    printf("Your change saved");
		    sleep(2);
		}
		goto adminin;
	}
	else if(choice=='6'){
		printf("New admin id : ");
		scanf("%d",&newshou);
		system("CLS");
		newsmin=newshou/10000;
		if(newsmin<1||newsmin>9){
			printf("Your input is not suitable\nPress a key...");
			getch();
			goto adminin;
		}
		printf("Again New id : ");
		scanf("%d",&newfhou);
		system("CLS");
		if(newshou==newfhou){
			adminid=newshou;
			fadmin=fopen("admin.txt","w");
			fprintf(fadmin,"%d %s",adminid,adminpass);
			fclose(fadmin);
			printf("Your id changed\nPress a key...");
			getch();
			goto adminin;
		}
		else{
			printf("Your inputs is not same\nPress a key...");
			getch();
			goto adminin;
		}
	}
	else if(choice=='7'){
		printf("New admin password : ");
		scanf("%s",&newpass[0]);
		system("CLS");
		printf("Again New admin password : ");
		scanf("%s",&newpass[1]);
		system("CLS");
		if(strcmp(newpass[0],newpass[1])!=0){
				printf("Your inputs is not same\nPress a key...");
				getch();
				goto adminin;
		}
		strcpy(adminpass,newpass[1]);
		fadmin=fopen("admin.txt","w");
		fprintf(fadmin,"%d %s",adminid,newpass[1]);
		fclose(fadmin);
		printf("Your password changed\nPress a key...");
		getch();
		goto adminin;
	}
	else if(choice=='8'){
  		printf("Are you sure Y/N : ");
		scanf("%s",&choice);
    	if(choice=='Y'||choice=='y'){
		    goto startin;
		}
		goto adminin;
	}
	else if(choice=='9'){
		printf("Are you sure Y/N : ");
		scanf("%s",&choice);
		if(choice=='Y'||choice=='y'){
			goto save;
		}
		goto adminin;
	}
	getch();
	save:
	fworkers=fopen("workers.txt","w");
	fprintf(fworkers,"%d",nnn);
	for(i=0;i<nnn;i++){
		fprintf(fworkers,"\n");
		fprintf(fworkers,"%d %s %s %s %s %s %d %f %d %d",id[i],worker[id[i]].password,worker[id[i]].name,worker[id[i]].surname,worker[id[i]].telnum,worker[id[i]].email,worker[id[i]].late,worker[id[i]].mainsal,worker[id[i]].less,worker[id[i]].more);
	}
    fclose(fworkers);
}
