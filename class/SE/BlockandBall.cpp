#include<iostream>
#include<windows.h>
using namespace std;
int const RIGHT = 1;
int const LEFT = -1;
int const TOP = 1;
int const BOTTOM= -1;
typedef struct _ball
{
	double XCentre;
	double YCentre;
	double Radius;
	struct _ball* Next;

}ball;
typedef struct _field
{
	double Up;
	double Down;
	double Right;
	double Left;
	double TheRadius;
	ball* head;
}field;

class ballList
{
public:
	ball* head;
	bool insert(double TheXCentre, double TheYCentre, double TheRadius);
	bool judgeInsert(double TheXCentre, double TheYCentre, double TheRadius);
	ball* insertMax();
	friend DWORD WINAPI judgeInsertRadius(LPVOID tField);
	ballList();
};
ballList::ballList()
{
	head = 0;
}
bool ballList::insert(double TheXCentre, double TheYCentre, double TheRadius)
{
	bool judgement = judgeInsert( TheXCentre,  TheYCentre,  TheRadius);
	if (judgement == false)
		return false;

	ball* insertBall;
	//�α�point
	ball* p = head;

	//�½�һ��ball����ֵ׼�����롣
	insertBall = (ball *)new ball;
	insertBall->XCentre = TheXCentre;
	insertBall->YCentre = TheYCentre;
	insertBall->Radius = TheRadius;
	
	//����������������β��
	if (head == 0)
	{
		head = insertBall;
		insertBall->Next = 0;
	}
	else if (head->Next == 0)
	{
		head->Next = insertBall;
		insertBall->Next = 0;
	}
	else
	{
		while (p->Next != 0)
		{
			p = p->Next;
		}
		p->Next = insertBall;
		insertBall->Next = 0;
	}
	return true;
}
bool ballList::judgeInsert(double TheXCentre, double TheYCentre, double TheRadius)//�ж��ܷ���뵱ǰ��
{	
	ball* p=head;
	//�Ƿ�Բ��Խ��
	if (!(TheXCentre > -1 && TheXCentre<1 && TheYCentre>-1 && TheYCentre < 1))
		return false;

	double Distance;
	//Բ�Ƿ�Խ�������߽�
	Distance = RIGHT - TheXCentre;
	Distance = abs(Distance);
	if (Distance < TheRadius)
		return false;
	Distance = LEFT - TheXCentre;
	Distance = abs(Distance);
	if (Distance < TheRadius)
		return false;
	Distance = TOP - TheYCentre;
	Distance = abs(Distance);
	if (Distance < TheRadius)
		return false;
	Distance = BOTTOM - TheYCentre;
	Distance = abs(Distance);
	if (Distance < TheRadius)
		return false;

	//�Ƿ��������е�Բ�ص�
	while (p != 0)
	{
		Distance = sqrt(pow((p->XCentre - TheXCentre), 2) + pow((p->YCentre - TheYCentre), 2));
		if (Distance < (TheRadius + p->Radius))
			return false;
		p = p->Next;
	}
	return true;
}
ball* ballList::insertMax()//����һ����ǰ��״̬�µ����Բ,����ı����뾶
{
	ball* RT = new ball;//���ڽ���returnֵ
	ball*SUC = new ball;//���ڴ�����һ�����Բ����ֵ
	field tField[4];//���ڷŶ��̵߳Ĳ���
	HANDLE tThread[4];
	double radiusStep = 0.5;//���ڸı�뾶�Ĳ���
	double currentRadius = 0.5;//��ʼ�뾶
	DWORD RTD[4];
	while (radiusStep > 0.0001)
	{	
		double  RIGHT = 1 - currentRadius;
		double  LEFT = -1 + currentRadius;
		double  UP = 1 - currentRadius;
		double  DOWN = -1 + currentRadius;
		tField[0].Up = UP; tField[0].Down = 0; tField[0].Right = 0; tField[0].Left = LEFT; tField[0].TheRadius = currentRadius; tField[0].head = this->head;
		tField[1].Up = UP; tField[1].Down = 0; tField[1].Right = RIGHT; tField[1].Left = 0; tField[1].TheRadius = currentRadius; tField[1].head = this->head;
		tField[2].Up = 0; tField[2].Down = DOWN; tField[2].Right = 0; tField[2].Left = LEFT; tField[2].TheRadius = currentRadius; tField[2].head = this->head;
		tField[3].Up = 0; tField[3].Down = DOWN; tField[3].Right = RIGHT; tField[3].Left = 0; tField[3].TheRadius = currentRadius; tField[3].head = this->head;
		tThread[0] = CreateThread(NULL,0,judgeInsertRadius,(LPVOID) &tField[0], 0, 0);
		tThread[1] = CreateThread(NULL, 0, judgeInsertRadius, (LPVOID)&tField[1], 0, 0);
		tThread[2] = CreateThread(NULL, 0, judgeInsertRadius, (LPVOID)&tField[2], 0, 0);
		tThread[3] = CreateThread(NULL, 0, judgeInsertRadius, (LPVOID)&tField[3], 0, 0);
		WaitForMultipleObjects(4, tThread, true, INFINITE);
		GetExitCodeThread(tThread[0], &RTD[0]);
		GetExitCodeThread(tThread[1], &RTD[1]);
		GetExitCodeThread(tThread[2], &RTD[2]);
		GetExitCodeThread(tThread[3], &RTD[3]);
		RTD[0] = RTD[0] + RTD[1] + RTD[2] + RTD[3];
		RT = (ball*)RTD[0];
		STILL_ACTIVE;
		if (RT == 0)
		{
			radiusStep *= 0.5;
			currentRadius -= radiusStep;
		}
		else
		{
			SUC = RT;
			radiusStep *= 0.5;
			currentRadius += radiusStep;
		}
	}
	return SUC;
}
DWORD WINAPI judgeInsertRadius(LPVOID tField)//�жϵ�ǰ�뾶�ܷ�������е�ͼ�С�
{
	field* Tfield = (field*) tField;
	ball* RT = new ball;//���ڷ��أ�ʧ�ܷ���0��
	double Distance;
	double const POSITIONSTEP = 0.0001;
	double const RIGHT =Tfield->Right;
	double const LEFT = Tfield->Left;
	double const TOP = Tfield->Up;
	double const BOTTOM = Tfield->Down;//�����Բ�ĵķ�Χ��
	double xP = LEFT + POSITIONSTEP, yP = BOTTOM + POSITIONSTEP;//x,y������α�
	for ( ;xP<RIGHT; xP+=POSITIONSTEP)
	{	
		
		for (yP = BOTTOM + POSITIONSTEP; yP < TOP; yP += POSITIONSTEP)
		{
			ball* p = Tfield->head;
			while (p != 0)
			{
				Distance = sqrt(pow((p->XCentre - xP), 2) + pow((p->YCentre - yP), 2));
				if (Distance < (Tfield->TheRadius + p->Radius))
					break;		
				p = p->Next;
				if (p==0)
				{
					RT->Radius = Tfield->TheRadius;
					RT->XCentre = xP;
					RT->YCentre = yP;
					return (DWORD)RT;
				}

			}
		}
	}return 0 ;
}
void main()
{	
	ballList A;
	ball* B = new ball;//���ڽ���judgeInsertRadius����ֵ
	A.head = 0;
	double sum=0;
	A.insert(0.1, 0.2, 0);
	A.insert(-0.5, -0.3, 0);
	A.insert(-0.3, 0.4, 0);
	for (int i = 0 ; i < 3; i++)
	{
		B = A.insertMax();
		A.insert(B->XCentre, B->YCentre, B->Radius);
		sum += B->Radius*B->Radius;
		cout << "Radius" << B->Radius << "	XCentre" << B->XCentre << "	YCentre" << B->YCentre<<"\n";
	}
	cout << "The sum is"<<sum;
}
