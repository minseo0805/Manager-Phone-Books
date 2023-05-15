#include <stdio.h>		// getchar() 함수사용
#include <windows.h>	// system() 함수사용
#include <conio.h>		// getch() 함수사용	
#include <string.h>		// memcmp() 함수사용

struct phoneaddr {
		int number;
		char name[20];
		char cellphone[20];
		char phone[20];
		char email[30];
	};

void input(struct phoneaddr *);		//입력함수
void search(struct phoneaddr *);		//검색함수
void edit(struct phoneaddr *);		//수정함수
void del(struct phoneaddr *);			//삭제함수
void show(struct phoneaddr *);		//보기함수

	
	int count=0,i,j;
	
void main()
{
	int choice;
	struct phoneaddr info[10];
	struct phoneaddr *pinfo;	
	
	pinfo=info;

	for(i=0; i<10; i++)	//번호 초기화
	{
		pinfo[i].number=0;
		for(j=0; j<20; j++)
		{
			pinfo[i].cellphone[j]='\0';	//휴대전화 초기화
			pinfo[i].phone[j]='\0';		//집전화 초기화
		}
	}

	while(1)
	{
		system("cls");		//화면 깨끗이
		printf("************************************************\n");
		printf("* 1. 전화번호 입력                             *\n");
		printf("* 2. 전화번호 검색(이름, 전화번호)             *\n");
		printf("* 3. 전화번호 수정                             *\n");
		printf("* 4. 전화번호 삭제                             *\n");
		printf("* 5. 전체보기                                  *\n");
		printf("* 6. 프로그램 종료                             *\n");
		printf("************************************************\n");
		printf("# 메뉴선택 : ");
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
	printf("프로그램을 종료 합니다.\n");

}

void input(struct phoneaddr *pinfo)
{
	int check;
	system("cls");
	for(i=0; i<10; i++)	//번호 찾기
	{
		if(pinfo[i].number==0)		// 번호가 초기화 되어 있는것을 찾는다.
		{
			count=i;
			break;
		}
	}
	printf("------------------------------------------\n");
	printf("1. 번호 : %d\n",count+1);		//번호는 자동으로 입력
	pinfo[count].number=count+1;
	printf("2. 이름 : ");fflush(stdin);
	gets(pinfo[count].name);
	while(1)
	{
		printf("3. 휴대전화 : ");
		gets(pinfo[count].cellphone);
		for(i=0; pinfo[count].cellphone[i]!='\0'; i++)
		{
			if(pinfo[count].cellphone[i]>=48 && pinfo[count].cellphone[i] <=57)	//숫자만 있는지 확인
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
			printf("잘못 입력하셨습니다. 다시 입력하세요!!\n");
		else
			break;		//제대로 입력되면 다음으로
	}
	while(1)
	{
		printf("4. 집전화 : ");
		gets(pinfo[count].phone);
		for(i=0; pinfo[count].phone[i]!='\0'; i++)
		{
			if(pinfo[count].phone[i]>=48 && pinfo[count].phone[i] <=57) //숫자만 있는지 확인
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
			printf("잘못 입력하셨습니다. 다시 입력하세요!!\n");
		else
			break;
	}
	printf("5. 이메일 : ");
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
		printf("1. 이름으로 검색\n");
		printf("2. 전화번호로 검색\n");
		printf("선택하세요 : ");
		scanf("%d",&choice); fflush(stdin);
		if(choice==1)
		{
			printf("이름을 입력하세요 : ");
			scanf("%s",name); fflush(stdin);
			for(i=0; i<20; i++)		//문자가 몇개 입력됬는지 카운터
			{
				if(name[i]!='\0')
				{
					n++;
				}
			}

			for(i=0; i<10; i++)
			{
				save=memcmp(name,pinfo[i].name,n);	//카운터 된만큼 문자 체크
				if(save==0 && pinfo[i].number!=0)	//자료가 있는것중에서 문자 수가 같을때 출력
				{	
					printf("-------------------------------------\n");
					printf("번호 : %d\n",pinfo[i].number);
					printf("이름 : %s\n",pinfo[i].name);
					printf("휴대전화 : %s\n",pinfo[i].cellphone);
					printf("집전화 : %s\n",pinfo[i].phone);
					printf("이메일 : %s\n",pinfo[i].email);
					printf("-------------------------------------\n");
					find++;
				}
			}
		}
		if(choice==2)
		{
			printf("번호를 입력하세요 : ");
			scanf("%s",num); fflush(stdin);
			for(i=0; i<20; i++)		// 문자가 몇개 입력되었는지 카운터
			{
				if(num[i]!='a')
					n++;
			}
			for(i=0; i<10; i++)
			{
				save=memcmp(num,pinfo[i].cellphone,n);	// 휴대전화 같을때
				save2=memcmp(num,pinfo[i].phone,n);	//집전화 같을때
				if(save==0 || save2==0  && pinfo[i].number!=0)
				{
					printf("-------------------------------------\n");
					printf("번호 : %d\n",pinfo[i].number);
					printf("이름 : %s\n",pinfo[i].name);
					printf("휴대전화 : %s\n",pinfo[i].cellphone);
					printf("집전화 : %s\n",pinfo[i].phone);
					printf("이메일 : %s\n",pinfo[i].email);
					printf("-------------------------------------\n");
					find++;
				}			
			}
		}
		
		if(find==0)		//찾지 못했을 때
		{
			printf("같은 이름이나 숫자를 찾지 못했습니다.\n");
			getch(); fflush(stdin);
			break;
		}
		if(find!=0)		//찾았을 때
			printf("\n메뉴로 돌아갑니다.\n");
			getch(); fflush(stdin);
			break;
		if(choice!=1 || choice!=2)		// 다른숫자를 입력했을때
		{
			printf("잘못 입력하셨습니다. 다시 입력하세요!\n");
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
		if(pinfo[i].number !=0)	//리스트 표시
		{
			printf("번호 : %d\n",pinfo[i].number);
			printf("이름 : %s\n",pinfo[i].name);
			printf("휴대전화 : %s\n",pinfo[i].cellphone);
			printf("집전화 : %s\n",pinfo[i].phone);
			printf("이메일 : %s\n",pinfo[i].email);
			printf("-------------------------------------\n");
		}
	}
	printf("리스트 중 번호를 선택하세요 : ");
	scanf("%d",&choice); //배열은 0~ 9까지지만 숫자는 1~ 10까지이다.
	printf("------------------------------------------\n");
	printf("1. 번호 : %d\n",pinfo[choice-1].number);
	printf("2. 이름 : %s\n",pinfo[choice-1].name);
	printf("3. 휴대전화 : %s\n",pinfo[choice-1].cellphone);
	printf("4. 집전화 : %s\n",pinfo[choice-1].phone);
	printf("5. 이메일 : %s\n",pinfo[choice-1].email);
	printf("------------------------------------------\n");
	while(1)
	{
		printf("# 수정하고자 하는 항목의 번호를 입력하시오 : ");
		scanf("%d",&num);
		if(num==1)		// 숫자는 고칠수 없다
		{
			printf("고칠수 없습니다!!\n");
		}
		if(num==2)
		{
			printf("이름 : "); fflush(stdin);
			gets(pinfo[choice-1].name);
			break;
		}
		if(num==3)
		{
			printf("휴대전화 : "); fflush(stdin);
			gets(pinfo[choice-1].cellphone);
			break;
		}
		if(num==4)
		{
			printf("집전화 : "); fflush(stdin);
			gets(pinfo[choice-1].phone);
			break;
		}
		if(num==5)
		{
			printf("이메일 : "); fflush(stdin);
			gets(pinfo[choice-1].email);
			break;
		}
	}
	printf("\n수정되었습니다.\n");		//수정후 출력
	printf("------------------------------------------\n");
	printf("1. 번호 : %d\n",pinfo[choice-1].number);
	printf("2. 이름 : %s\n",pinfo[choice-1].name);
	printf("3. 휴대전화 : %s\n",pinfo[choice-1].cellphone);
	printf("4. 집전화 : %s\n",pinfo[choice-1].phone);
	printf("5. 이메일 : %s\n",pinfo[choice-1].email);
	printf("------------------------------------------\n");
	getch(); fflush(stdin);
}

void del(struct phoneaddr *pinfo)
{
	int choice;
	system("cls");
	for(i=0; i<10; i++)	//리스트 표시
	{
		if(pinfo[i].number !=0)
		{
			printf("번호 : %d\n",pinfo[i].number);
			printf("이름 : %s\n",pinfo[i].name);
			printf("휴대전화 : %s\n",pinfo[i].cellphone);
			printf("집전화 : %s\n",pinfo[i].phone);
			printf("이메일 : %s\n",pinfo[i].email);
			printf("-------------------------------------\n");
		}
	}
	printf("# 삭제할 번호를 입력하세요 : ");
	scanf("%d",&choice);
	pinfo[choice-1].number=0;	//표시되는 번호보다 배열의 주소는 1 작다
	printf("삭제되었습니다.\n");
	getch(); fflush(stdin);
}

void show(struct phoneaddr *pinfo)
{
	system("cls");
	for(i=0; i<10; i++)	//리스트 표시
	{
		if(pinfo[i].number !=0)	//자료가 있는것만
		{
			printf("번호 : %d\n",pinfo[i].number);
			printf("이름 : %s\n",pinfo[i].name);
			printf("휴대전화 : %s\n",pinfo[i].cellphone);
			printf("집전화 : %s\n",pinfo[i].phone);
			printf("이메일 : %s\n",pinfo[i].email);
			printf("-------------------------------------\n");
		}
	}
	getch(); fflush(stdin);
}
	






