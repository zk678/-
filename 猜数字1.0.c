#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<string.h> 

void loading();//���ض��� 
void menu();//�˵�
int game();//��Ϸ 
int rank();//��ȡ�����Ϣ��д���ļ� 
int list();//��ȡ�ļ������� 
int score = 0 ; //�������

typedef struct data //�������ݽṹ{����,����} 
{
    char name[20];//����,�ַ����� 
	int score; 
}player;

void loading()//���ض��� 
{
	int i;
	printf("�����ĵȴ�,���ڼ�����.....\n\n");
	//ͬ������i<= ??  ���Ըı�����ٶ�  i*x=100���� 
	for(i=1;i<=25;i++)
	{
        printf("");
        printf("%d%%",4*i);//50%x2=100%
        Sleep(101-1*i);//��������ִ��ʱ�� 
        printf("\b\b\b");//ɾ��֮ǰ��xx% 
	}
	printf("\b\n\n������ɣ�����˵�.....\n");
	Sleep(3); 
	system("cls");//��� 
}

void menu()
{	
	//1-23#,23-37�ո�,38-63# sleep()��ֹ˲����� 
	int i; 
	for(i=0;i<=63;i++)  
	{
		if(i>=1){printf("#");Sleep(7);} 
		else {printf("");Sleep(8);}
	}
	printf("\n");
	for(i=0;i<63;i++) 
	{
		if(i>=1&& i<23){printf("#");Sleep(9);}
		else if(i>=23&&i<37) {printf(" ");Sleep(10);} 
		else {printf("#");Sleep(9);}
	}
	printf("\n");
	printf("#######################    1. ��ʼ   ##########################\n");
    printf("#######################              ##########################\n");
    printf("#######################    2. �˳�   ##########################\n");
	printf("#######################              ##########################\n");    
    printf("#######################    3. ����   ##########################\n");
    printf("#######################              ##########################\n");
    printf("#######################    4. ����   ##########################\n");
	//�˵���ȫ��forѭ��ʵ��,���۵�ռ�ÿռ临�ӶȺ��ڴ� 
		for(i=0;i<63;i++) 
	{
		if(i>=1&& i<23){printf("#");Sleep(8);}
		else if(i>=23&&i<37) {printf(" ");Sleep(7);}
		else {printf("#");Sleep(8);}
	}
	printf("\n");
		for(i=0;i<=63;i++) 
	{
		if(i>=1){printf("#");Sleep(9);}
		else {printf("");Sleep(10);}
	}
	printf("\n");
	//�˵�����,��forѭ�����ʵ�� 
} 

int game()
{	
	int i=0;//���巶Χ
	printf("����������Ҫ�ķ�Χ�����ֵ��");
	scanf("%d",&i);
	if (i<=0)
	{
		printf("̫С�˲�����Ŷ,��һ���\n");
		game();
		return 0; 
		//����ִ����Ϸ
	}
	
    int random_num = rand() % i + 1; //��������� 
    int guess = 0;//����µ���
    int times = 1;//�洢����,��һ��Ҳ��,����time = 1 
     
    while(1)
    {
        printf("��������µ���: ");
        scanf("%d", & guess );
	        if ( guess  > random_num)
	        {
	            printf("�´���\n");
	            times++; 
	            Sleep(1);
	        }
	        else if ( guess  < random_num)
	        {
	            printf("��С��\n");
	            times++; 
	            Sleep(1);
	        }
	        else
	        {	
				if (times == 1)//�жϴ���,һ�θ������ 
				{
	 			   printf("����Ŷ,һ�ξͶ���!\n");
				}
				else
				{
				 	printf("��ϲ��¶���,��ȷ����%d,�����%d��\n",random_num,times);
				} 
	        	score = times; //��������ֵ��score ���� 
    			break;
	        }
		}
		return score; //���ط��� ��rank() �� list() ʹ��  
	//rank();	
}
    
int rank()//��ȡ�����Ϣ��д���ļ� 
{
	//printf("\n rank:%d!\n",score);
	player tmp;//��ʱ����ṹ�� 
	FILE *fp;
	printf("������������֣�");
	scanf("%s",&tmp.name);
	printf("лл,��ӭ�´�����!\n\n");
	tmp.score = score;
	fp=fopen("rank.txt","a"); 
	if(fp==NULL)
	        { 
	         printf("�򲻿��ļ�!\n");  
	         system("pause");  
	         return -1;//����ļ����ִ��󷵻�-1  
			}
	fprintf(fp,"%s %d",tmp.name,tmp.score);
	fclose(fp);
	return 0;
} 

int list()
{
	//printf("list!\n");
	printf("####################    ���а�   #############################\n\n");
	player tmp[10];//��ʱ����,����name,score
	player temp;//�м��������������ı���ֵ����
	int i = 0,n = 0,j = 0,k = 0;
	FILE *fp;
	fp = fopen("rank.txt","rb");//��д��ʽ���ļ� 
	if(fp==NULL)              
	{  	
		
        printf("����!!!û������!!!\n"); 
		printf("����Ϸ���ٲ鿴���а�!\n");
        system("pause");  
        return -1;
    }
	for(i=0;i<n-1;i++)//����ð�ݷ��������� 
    {  
        k=i;  
		for(j=i+1;j<n;j++)  
	    if(tmp[j].score>tmp[k].score)//����Ƚϴ�С 
        k=j;
		temp=tmp[k];
		tmp[k]=tmp[i];
		tmp[i]=temp;//����������ʱ�������ݽ���
	} 
	i = 0;
	printf("����:        ����:         ����:\n"); 
	while(i <= 10&&fscanf(fp,"%s%d",tmp[i].name,&tmp[i].score)!=EOF)//�ж��ļ��Ƿ�Ϊ�� 
	{
	printf("%3d  %15s  %10d\n",i+1,tmp[i].name,tmp[i].score);//������� 
	i++;
	}
	fclose(fp);
	return 0;
} 

void delete()//ɾ���ļ� 
{
	remove("rank.txt");
	printf("\nɾ���ɹ�!\n");
}

int main()
{	
	int i;
	printf("#######################    ������Ϸ   ##########################\n\n");
	printf("�����ĵȴ�,���ڼ�����.....\n\n"); 
	printf("��ǰ����:\n"); 
	for(i=1;i<=25;i++)
	{
        printf("");
        printf("%d%%",4*i);//25%x4=100%
        Sleep(101-1*i);//��������ִ��ʱ�� ����ʱע�͵� 
        printf("\b\b\b");//ɾ��֮ǰ��xx% 
	}
	printf("\b\n\n������ɣ���ת�˵���.....\n");
	sleep(3);
	system("cls");
	
    int input = 0;//����ѡ�� 
    srand((unsigned)time(NULL));
	//srand()�������������㷨�����ӣ�time(NULL)���ص�ǰ��ʱ�䣬�ѵ�ǰ��ʱ����Ϊ���Ӳ�����ͬ�����������
    do
    {	
        menu();
        printf("��ʼ�����!\n��ѡ����ţ�");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            rank();
            break;
        case 2:
            return 0;
    		break;
        case 3:  
    	 	list();//����
    	case 4:
			delete();
			break;
        default:
            printf("ѡ�����\n");
        }
    }
    while (input);//do while ѭ��
return 0;
}
