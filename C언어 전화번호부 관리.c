#include <stdio.h>		// getchar() �Լ����
#include <windows.h>	// system() �Լ����
#include <conio.h>		// getch() �Լ����	
#include <string.h>		// memcmp() �Լ����

struct phoneaddr {
		int number;
		char name[20];
		char cellphone[20];
		char phone[20];
		char email[30];
	};

void input(struct phoneaddr *);		//�Է��Լ�
void search(struct phoneaddr *);		//�˻��Լ�
void edit(struct phoneaddr *);		//�����Լ�
void del(struct phoneaddr *);			//�����Լ�
void show(struct phoneaddr *);		//�����Լ�

	
	int count=0,i,j;
	
void main()
{
	int choice;
	struct phoneaddr info[10];
	struct phoneaddr *pinfo;	
	
	pinfo=info;

	for(i=0; i<10; i++)	//��ȣ �ʱ�ȭ
	{
		pinfo[i].number=0;
		for(j=0; j<20; j++)
		{
			pinfo[i].cellphone[j]='\0';	//�޴���ȭ �ʱ�ȭ
			pinfo[i].phone[j]='\0';		//����ȭ �ʱ�ȭ
		}
	}

	while(1)
	{
		system("cls");		//ȭ�� ������
		printf("************************************************\n");
		printf("* 1. ��ȭ��ȣ �Է�                             *\n");
		printf("* 2. ��ȭ��ȣ �˻�(�̸�, ��ȭ��ȣ)             *\n");
		printf("* 3. ��ȭ��ȣ ����                             *\n");
		printf("* 4. ��ȭ��ȣ ����                             *\n");
		printf("* 5. ��ü����                                  *\n");
		printf("* 6. ���α׷� ����                             *\n");
		printf("************************************************\n");
		printf("# �޴����� : ");
		scanf("%d",&choice);

		if(choice==1)
			input(pinfo);
		if(choice==2)
			search(pinfo);
		if(choice==3)
			edit(pinfo);
		if(choice==4)
			del(pinfo);
		if(choice==5)
			show(pinfo);
		if(choice==6)
			break;
	}
	printf("���α׷��� ���� �մϴ�.\n");

}

void input(struct phoneaddr *pinfo)
{
	int check;
	system("cls");
	for(i=0; i<10; i++)	//��ȣ ã��
	{
		if(pinfo[i].number==0)		// ��ȣ�� �ʱ�ȭ �Ǿ� �ִ°��� ã�´�.
		{
			count=i;
			break;
		}
	}
	printf("------------------------------------------\n");
	printf("1. ��ȣ : %d\n",count+1);		//��ȣ�� �ڵ����� �Է�
	pinfo[count].number=count+1;
	printf("2. �̸� : ");fflush(stdin);
	gets(pinfo[count].name);
	while(1)
	{
		printf("3. �޴���ȭ : ");
		gets(pinfo[count].cellphone);
		for(i=0; pinfo[count].cellphone[i]!='\0'; i++)
		{
			if(pinfo[count].cellphone[i]>=48 && pinfo[count].cellphone[i] <=57)	//���ڸ� �ִ��� Ȯ��
			{
				check=1;
			}
			else
			{
				check=0;
				break;
			}
		}
		if(check==0)
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���!!\n");
		else
			break;		//����� �ԷµǸ� ��������
	}
	while(1)
	{
		printf("4. ����ȭ : ");
		gets(pinfo[count].phone);
		for(i=0; pinfo[count].phone[i]!='\0'; i++)
		{
			if(pinfo[count].phone[i]>=48 && pinfo[count].phone[i] <=57) //���ڸ� �ִ��� Ȯ��
			{
				check=1;
			}
			else
			{
				check=0;
				break;
			}
		}
		
		if(check==0)
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���!!\n");
		else
			break;
	}
	printf("5. �̸��� : ");
	gets(pinfo[count].email);
	printf("------------------------------------------\n");
}

void search(struct phoneaddr *pinfo)
{
	int choice,find=0,save,save2,n=0;
	char name[20]={"0"};
	char num[20]={"a"};
	while(1)
	{
		system("cls");
		printf("1. �̸����� �˻�\n");
		printf("2. ��ȭ��ȣ�� �˻�\n");
		printf("�����ϼ��� : ");
		scanf("%d",&choice); fflush(stdin);
		if(choice==1)
		{
			printf("�̸��� �Է��ϼ��� : ");
			scanf("%s",name); fflush(stdin);
			for(i=0; i<20; i++)		//���ڰ� � �Է���� ī����
			{
				if(name[i]!='\0')
				{
					n++;
				}
			}

			for(i=0; i<10; i++)
			{
				save=memcmp(name,pinfo[i].name,n);	//ī���� �ȸ�ŭ ���� üũ
				if(save==0 && pinfo[i].number!=0)	//�ڷᰡ �ִ°��߿��� ���� ���� ������ ���
				{	
					printf("-------------------------------------\n");
					printf("��ȣ : %d\n",pinfo[i].number);
					printf("�̸� : %s\n",pinfo[i].name);
					printf("�޴���ȭ : %s\n",pinfo[i].cellphone);
					printf("����ȭ : %s\n",pinfo[i].phone);
					printf("�̸��� : %s\n",pinfo[i].email);
					printf("-------------------------------------\n");
					find++;
				}
			}
		}
		if(choice==2)
		{
			printf("��ȣ�� �Է��ϼ��� : ");
			scanf("%s",num); fflush(stdin);
			for(i=0; i<20; i++)		// ���ڰ� � �ԷµǾ����� ī����
			{
				if(num[i]!='a')
					n++;
			}
			for(i=0; i<10; i++)
			{
				save=memcmp(num,pinfo[i].cellphone,n);	// �޴���ȭ ������
				save2=memcmp(num,pinfo[i].phone,n);	//����ȭ ������
				if(save==0 || save2==0  && pinfo[i].number!=0)
				{
					printf("-------------------------------------\n");
					printf("��ȣ : %d\n",pinfo[i].number);
					printf("�̸� : %s\n",pinfo[i].name);
					printf("�޴���ȭ : %s\n",pinfo[i].cellphone);
					printf("����ȭ : %s\n",pinfo[i].phone);
					printf("�̸��� : %s\n",pinfo[i].email);
					printf("-------------------------------------\n");
					find++;
				}			
			}
		}
		
		if(find==0)		//ã�� ������ ��
		{
			printf("���� �̸��̳� ���ڸ� ã�� ���߽��ϴ�.\n");
			getch(); fflush(stdin);
			break;
		}
		if(find!=0)		//ã���� ��
			printf("\n�޴��� ���ư��ϴ�.\n");
			getch(); fflush(stdin);
			break;
		if(choice!=1 || choice!=2)		// �ٸ����ڸ� �Է�������
		{
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���!\n");
			getch(); fflush(stdin);
		}
	}
}

			
void edit(struct phoneaddr *pinfo)
{
	int choice,num;
	system("cls");
	for(i=0; i<10; i++)
	{
		if(pinfo[i].number !=0)	//����Ʈ ǥ��
		{
			printf("��ȣ : %d\n",pinfo[i].number);
			printf("�̸� : %s\n",pinfo[i].name);
			printf("�޴���ȭ : %s\n",pinfo[i].cellphone);
			printf("����ȭ : %s\n",pinfo[i].phone);
			printf("�̸��� : %s\n",pinfo[i].email);
			printf("-------------------------------------\n");
		}
	}
	printf("����Ʈ �� ��ȣ�� �����ϼ��� : ");
	scanf("%d",&choice); //�迭�� 0~ 9�������� ���ڴ� 1~ 10�����̴�.
	printf("------------------------------------------\n");
	printf("1. ��ȣ : %d\n",pinfo[choice-1].number);
	printf("2. �̸� : %s\n",pinfo[choice-1].name);
	printf("3. �޴���ȭ : %s\n",pinfo[choice-1].cellphone);
	printf("4. ����ȭ : %s\n",pinfo[choice-1].phone);
	printf("5. �̸��� : %s\n",pinfo[choice-1].email);
	printf("------------------------------------------\n");
	while(1)
	{
		printf("# �����ϰ��� �ϴ� �׸��� ��ȣ�� �Է��Ͻÿ� : ");
		scanf("%d",&num);
		if(num==1)		// ���ڴ� ��ĥ�� ����
		{
			printf("��ĥ�� �����ϴ�!!\n");
		}
		if(num==2)
		{
			printf("�̸� : "); fflush(stdin);
			gets(pinfo[choice-1].name);
			break;
		}
		if(num==3)
		{
			printf("�޴���ȭ : "); fflush(stdin);
			gets(pinfo[choice-1].cellphone);
			break;
		}
		if(num==4)
		{
			printf("����ȭ : "); fflush(stdin);
			gets(pinfo[choice-1].phone);
			break;
		}
		if(num==5)
		{
			printf("�̸��� : "); fflush(stdin);
			gets(pinfo[choice-1].email);
			break;
		}
	}
	printf("\n�����Ǿ����ϴ�.\n");		//������ ���
	printf("------------------------------------------\n");
	printf("1. ��ȣ : %d\n",pinfo[choice-1].number);
	printf("2. �̸� : %s\n",pinfo[choice-1].name);
	printf("3. �޴���ȭ : %s\n",pinfo[choice-1].cellphone);
	printf("4. ����ȭ : %s\n",pinfo[choice-1].phone);
	printf("5. �̸��� : %s\n",pinfo[choice-1].email);
	printf("------------------------------------------\n");
	getch(); fflush(stdin);
}

void del(struct phoneaddr *pinfo)
{
	int choice;
	system("cls");
	for(i=0; i<10; i++)	//����Ʈ ǥ��
	{
		if(pinfo[i].number !=0)
		{
			printf("��ȣ : %d\n",pinfo[i].number);
			printf("�̸� : %s\n",pinfo[i].name);
			printf("�޴���ȭ : %s\n",pinfo[i].cellphone);
			printf("����ȭ : %s\n",pinfo[i].phone);
			printf("�̸��� : %s\n",pinfo[i].email);
			printf("-------------------------------------\n");
		}
	}
	printf("# ������ ��ȣ�� �Է��ϼ��� : ");
	scanf("%d",&choice);
	pinfo[choice-1].number=0;	//ǥ�õǴ� ��ȣ���� �迭�� �ּҴ� 1 �۴�
	printf("�����Ǿ����ϴ�.\n");
	getch(); fflush(stdin);
}

void show(struct phoneaddr *pinfo)
{
	system("cls");
	for(i=0; i<10; i++)	//����Ʈ ǥ��
	{
		if(pinfo[i].number !=0)	//�ڷᰡ �ִ°͸�
		{
			printf("��ȣ : %d\n",pinfo[i].number);
			printf("�̸� : %s\n",pinfo[i].name);
			printf("�޴���ȭ : %s\n",pinfo[i].cellphone);
			printf("����ȭ : %s\n",pinfo[i].phone);
			printf("�̸��� : %s\n",pinfo[i].email);
			printf("-------------------------------------\n");
		}
	}
	getch(); fflush(stdin);
}
	






