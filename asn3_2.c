#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
int main(int argc, char *argv[])
{
    system("python upgrade.py");
    FILE* outputFile;int i;char s[50];
    char* filename;char* logname;
	char usnme[20];char name[20];
    	char pas[10];
    	time_t current_time;
	char* c_time_string,test[]="",convert[50];
	current_time = time(NULL);
         int c;
char *fvalue= NULL,*lvalue= NULL,flag=0;
FILE *filepointer;
if (current_time == ((time_t)-1)) {
		(void) fprintf(stderr, "Failure to compute the current time.");
        	return EXIT_FAILURE;
    	}
	c_time_string = ctime(&current_time);
	if (c_time_string == NULL) {
        	(void) fprintf(stderr, "Failure to convert the current time.");
        	return EXIT_FAILURE;
    	}
while((c=getopt(argc,argv,"l:f:")) !=-1) {
                switch(c) {
                        case 'f':flag=1;
				 filename=optarg;
                                 
                                 break;
                        case 'l':
				logname =optarg;
                                 
                                 break;
                        default:
                                 printf("Invaild input \n");
                                 exit(EXIT_FAILURE);
                }
	}
	(void) printf("Current time is %s", c_time_string);
	filepointer=fopen(logname,"a+");
	fprintf(filepointer,"%s",c_time_string);
	fflush(filepointer);
	
       
    	 for(i=0;i<3;i++)
	{
        //open the specified file
   
	printf("Enter the username\n");
	scanf("%s",usnme);
	printf("Enter password not more than 10 characters\n");
	scanf("%s",pas);
	printf("Enter the Name\n");
	scanf("%s",name);
	if(i>0)
	{
		fclose(outputFile);
		outputFile=fopen(filename,"r");
		fscanf(outputFile,"%[^,]",s);
		if(strcmp(s,usnme)==0)
		{
		printf("Username already exists-Enter another name \n");
		scanf("%s",usnme);
		fclose(outputFile);
		goto LOOP;
		
		}
		else goto LOOP;
	}
	else	
LOOP:   {
	 outputFile = fopen(filename, "a+");	
    fprintf(outputFile,usnme);
	fprintf(outputFile,",");
	fprintf(outputFile,pas);
	fprintf(outputFile,",");
	fprintf(outputFile,name);
	fprintf(outputFile,"\n");

    	}
(void) printf("input recieved at %s", c_time_string);
filepointer=fopen(logname,"a+");
	fprintf(filepointer,"%s",c_time_string);
	fflush(filepointer);
   
	   
     

    
	}//for loop
         fclose(outputFile);
         
    return 0;
}

