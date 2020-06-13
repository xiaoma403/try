#include<stdio.h> 
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
int main()
{
    system("chmod +x get*.sh");
	time_t now_time;
	struct tm * lt;
	time (&now_time);
	lt = localtime (&now_time);
	int department_2;
	int doctor_2;
	int time_2;
    // These arrays are used to get the echo output in the shell script. 
    char name[1000];
	char id[1000];
	char time[1000];
	char department[1000];
	char doctor[1000];
	// Optional Departments
	char departments[9][1000] = {
		{"基金"},{"股票"},{"债券"},{"定期"},{"活期"},{"取款"},{"企业投资"},{"保险"},{"黄金"}
		};
	// Optional Doctors
	char doctors[9][3][1000] = {
		{{"张三"},{"李四"},{"王五"}},{{"小红"},{"小蓝"},{"小绿"}},						
		{{"刘伯然"},{"好名誉"},{"呈贡"}},{{"王辉煌"},{"王永"},{"胡奎"}},
		{{"王影"},{"五伯凡"},{"华仔"}},{{"家多宝"},{"和写"},{"华哥"}},
		{{"列凡"},{"毛不凡"},{"梭字"}},{{"杰哥"},{"玻利维亚"},{"小二"}},
		{{"小进程"},{"金错刀"},{"流失"}}
		};
	printf("---------欢迎使用xx银行网上预约---------\n");
	for(int i = 0;i < 5;i++){
		switch(i){
			// Enter name
			case 0 : printf("请输入你的姓名：\n");
			FILE *fp1;
			fp1 = popen("./getName.sh","r");// Call the shell script
			if(fp1 == NULL){
	                    perror("popen error!\n");
	            	    return -1;
			}
			fgets(name,1000,fp1);// Output the output of the script into the array
			pclose(fp1);
			if(name[0] == '2'){
					printf("请输入正确的姓名！！！\n");
					i--;
			}
			break;
			
			//
			case 1 : printf("请输入你的身份证号码号(18位)：\n");
			FILE *fp2;
			fp2 = popen("./getId.sh","r");// Call the shell script
			if(fp2 == NULL){
	                    perror("popen error!\n");
	            	    return -1;
			}
			fgets(id,1000,fp2);// Output the output of the script into the array
			pclose(fp2);
			if(id[0] == 'N'){
				printf("请输入正确的身份证号码！！！\n");
				i--;
			}
			break;
			
			//
			case 2 : 
			printf("-----------------------------\n");
			printf("现在的时间是%d/%d/%d\n",lt->tm_year+1900, (lt->tm_mon)+1, lt->tm_mday);
			printf("可预约9天内的时间!\n");
			for(int j = 0;j < 9;j++){
			printf("-%d:%d/%d/%d\n",j+1,lt->tm_year+1900, (lt->tm_mon)+1, lt->tm_mday+j+1);
			}
			printf("请输入你想预约的时间序号：\n");
			FILE *fp3;
			fp3 = popen("./getAll.sh","r");// Call the shell script
			if(fp3 == NULL){
	                    perror("popen error!\n");
	            	    return -1;
			}
			fgets(time,1000,fp3);// Output the output of the script into the array
			pclose(fp3);
			if(time[0] == 'N'){
				printf("请输入正确的时间！！！\n");
				i--;
			}
			time_2=time[0] - '0';
			break;
			
			//
			case 3 : 
			printf("----------------------\n");
			printf("------选择项目--------\n");
			for(int j = 0;j <9 ;j++){
				printf("-%d:",j+1);
				printf("%s\n",departments[j]);
			}
			printf("----------------------\n");
			printf("请选择你的项目：\n");
			FILE *fp4;
			fp4 = popen("./getAll.sh","r");// Call the shell script
			if(fp4 == NULL){
	                    perror("popen error!\n");
	            	    return -1;
			}
			fgets(department,1000,fp4);// Output the output of the script into the array
			pclose(fp4);
			if(department[0] == 'N'){
				printf("请输入正确的项目序号！！！\n");
				i--;
			}
			department_2 = department[0] - '0'-1; 
			break;
			
			
			//
			case 4 : printf("----------------------\n");
			printf("------接待员号码--------\n");
			for(int j = 0;j <3 ;j++){
				printf("-%d:",j+1);
				printf("%s接待员\n",doctors[department_2][j]);
			}
			printf("----------------------\n");
			printf("请选择接待员序号：\n");
			FILE *fp5;
			fp5 = popen("./getAll.sh","r");// Call the shell script
			if(fp5 == NULL){
	                    perror("popen error!\n");
	            	    return -1;
			}
			fgets(doctor,1000,fp5);// Output the output of the script into the array
			pclose(fp5);
			if(doctor[0] == 'N'||doctor[0] > '3'){
				printf("请输入正确的接待员序号！！！\n");
				i--;
			}
			doctor_2 = doctor[0] - '0'-1;
			break;
		}
	}
	
	//
	printf("预约成功！\n");
	printf("-------------预约单号----------------\n");
	printf("姓名：%s",name);
	printf("    身份证号码：%s\n",id);
	printf("预约时间：%d/%d/%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday+time_2);
	printf("预约项目：%s",departments[department_2]);
	printf("    接待员：%s\n",doctors[department_2][doctor_2]);
	printf("-------------------------------------\n");
	printf("************%d/%d/%d****************\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday);
	printf("-------------------------------------\n");
    return 0;
}

