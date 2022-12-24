# include "iGraphics.h"

// Universal Variables and Functions=========================
void page1();
void S_Converter();
void Boxes();
void Box_Cordinate();
int page=0,T_mode=0,L_en=0,L=0,T_mode1=0,L_an=0,N;
char str[6];
int array[20];
struct{
	char str[6];
	int x,y;
}
number[20];
//=============================================================
// Variables and Functions of Bubble Sort===========================

int B_i=0,B_k=0,B_u=0,B_v=0,updw=1,rglf=0,dwup=0,B_p,B_q,B_count=0;
int flag_bbox=0,flag_bnew=0,Bubble_on=0;
void Move_Bubble();
void Show_Bsort();
void Exchange_Bubble();
void B_Data_Recover();
int save_array[200][2];
int sub_array[200];
int new_array[20];

//=======================================================//
// Variables of Inserton Sort============================//

int I_i=1,I_r,I_count=0,I_p,I_temp;
int flag_ibox=0,flag_inew=0,Insertion_on=0,flag_itemp,flag_ishow=0,flag_imove;
void Show_Isort();
void Move_Insertion();
void I_Data_Recover();
struct{
	char str[6];
	int x,y;
}temporary;

//==============================================================//

// Variables of Quick Sort===================================//

int co_x1=0,co_x2=0,Q_count_i=0,Q_count_j=0;
int flag_show_pivot=0,flag_show_right=0,flag_show_store=0,flag_show_compare=0,flag_show_newpivot=0,pivot_on=0, partition_on=0, Store_on=0;
int Q_i=0,Q_j=0,par;
int pivot_swap[100];
int pivot_index[100];
int right_index[100];
int flag_qnew=0;
int flag_qbox=0;
int Quick_on=0;
int store_on[100];
int partition_index[100];
int pivot_newindex[100];
int store_index[100][20];
int store_swap[100][20];
int compare_index[100][20];
int store_last[100];
void Move_Quick();
void Show_Qsort();
void Q_Data_Recover();
void Quicksort(int,int);
int  partition(int,int,int);

//===================================================================//

void iDraw()
{
	iClear();
	if(page==0)									// First Page to Display
	{
		iShowBMP(0, 0, "new1.bmp");
	}
	 else if(page==1)								// Presing Enter the 2nd Page will come calling Page1() function
	{
		page1();
	}	
	 else if(page==2)																// Clicking on Button of Bubble Sort the page for input Type will appeare
	{
		iShowBMP(0,0,"BubBLE sort.bmp");
	}
	 else if(page==21)																  //  This is the page of Bubble sort animation 
	{

		iShowBMP(0,0,"bubble.bmp");											 //show the background or theme
		iSetColor(1,1,1);													// set color for getting text of Number of Items 
		iText(46,250,"Item:",GLUT_BITMAP_HELVETICA_18);						// Items text Filed
		iRectangle(100,250,50,50);											// Showing Rectangle of Utem Box
		iText(110,260,str,GLUT_BITMAP_HELVETICA_18);						//Showing Item Numbers
		if(T_mode1==1)
		{
			iText(110,260,str,GLUT_BITMAP_HELVETICA_18);						 // Getting input Item numbers as string
		}
		if(flag_bbox==1)
		{
			Boxes();
		}
		if(flag_bbox==2)
		{
			Show_Bsort();
		}
	}		
	else if(page==3)
	{
		iShowBMP(0,0,"insertionsort.bmp");
	}
	else if(page==31)
	{
		iShowBMP(0,0,"insertion.bmp");
		iSetColor(1,1,1);													 
		iText(46,250,"Item:",GLUT_BITMAP_HELVETICA_18);					
		iRectangle(100,250,50,50);
		iText(110,260,str,GLUT_BITMAP_HELVETICA_18);
		if(T_mode1==1)
		{
			iText(110,260,str,GLUT_BITMAP_HELVETICA_18);						
		}
		if(flag_ibox==1)
		{
			Boxes();
		}
		if(flag_ibox==2)
		{
			Show_Isort();
		}
	}
	else if(page==4)
	{
	iShowBMP(0,0,"merge.bmp");
	}
	else if(page==5)
	{
	iShowBMP(0,0,"quicksort.bmp");
	}
	else if(page==51)
	{
		iShowBMP(0,0,"quick.bmp");
		iSetColor(1,1,1);													 
		iText(46,250,"Item:",GLUT_BITMAP_HELVETICA_18);					
		iRectangle(100,250,50,50);
		iText(110,260,str,GLUT_BITMAP_HELVETICA_18);
		if(T_mode1==1)
		{
			iText(110,260,str,GLUT_BITMAP_HELVETICA_18);						
		}
		if(flag_qbox==1)
		{
			Boxes();
		}
		if(flag_qbox==2)
		{
			Show_Qsort();
		}
	}
	else if(page==6)
	{
	iShowBMP(0,0,"selection.bmp");
	}
	
	
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	printf("%d %d\n",mx,my);
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if((mx>=548 && mx<=548+24) && (my>=302 && my<=324)&& page==1)
		{
		page=2;
		}
		else if((mx>=484 && mx<=508) && (my>=244 && my<=266)&& page==1)
		{
		page=3;
		}
		else if((mx>=565 && mx<=565+24) && (my>=187 && my<=187+22)&& page==1)
		{
		page=5;
		}
		
		/*else if((mx>=636 && mx<=660) && (my>=228 && my<=250)&& page==1)
		{
		page=4;
		}
		else if((mx>=556 && mx<=580) && (my>=126 && my<=148)&& page==1)
		{
		page=6;
		}*/

		else if((mx>=77 && mx<=167) && (my>=65 && my<=104)&& (page>=2 && page<=6))
		{
		page=1;
		}
		else if((mx>=77 && mx<=167) && (my>=65 && my<=104)&& (page>6))
		{
			if(page==21)
			{
				B_Data_Recover();
				page=page/10;
			}
			if(page==31)
			{
				I_Data_Recover();
				page=page/10;
			}
			if(page==51)
			{
				page=page/10;
				Q_Data_Recover();
			}
		
		}
		else if((mx>=80&&mx<=392)&&(my>=440 && my<=544)&&page==2)
		{
			page=21;
		}
		else if((mx>=80&&mx<=392)&&(my>=440 && my<=544)&&page==3)
		{
			page=31;
		}
		/*else if((mx>=77&&mx<=403)&&(my>=282 && my<=377)&&page==2)
		{
			page=22;
		}*/
		else if((mx>=80&&mx<=392)&&(my>=440 && my<=544)&&page==5)
		{
			page=51;
		}
		else if((mx>=100 && mx<=150)&&(my>=250 && my<=300)&& (page==21||page==31||page==51))
		{
			T_mode1=1;
		}
		else if((mx>=100&&mx<=((N*50)+100))&&(my>=400&&my<=450)&&(page==21||page==31||page==51)&&T_mode==0 && L<N)
		{
			L++;
			T_mode=1;
		}
		else if((mx>=208&&mx<=402)&&(my>=56&&my<=104)&&page==21&&T_mode==0&&L==N&&flag_bbox==1&&Bubble_on==0)
		{
			flag_bbox=2;
			flag_bnew=1;
			Bubble_on=1;
		}
    	else if((mx>=208&&mx<=402)&&(my>=56&&my<=104)&&page==31&&T_mode==0&&L==N&&flag_ibox==1&&Insertion_on==0)
		{
			flag_ibox=2;
			flag_inew=1;
			Insertion_on=1;
		}
		else if((mx>=208&&mx<=402)&&(my>=56&&my<=104)&&page==51&&T_mode==0&&L==N&&flag_qbox==1&&Quick_on==0)
		{
			flag_qbox=2;
			flag_qnew=1;
			Quick_on=1;
		}
		else if((mx>=476&&mx<=590)&&(my>=56&&my<=104)&&page==21&&T_mode==0&&Bubble_on==1)
		{
			Bubble_on=0;
		}
		else if((mx>=476&&mx<=590)&&(my>=56&&my<=104)&&page==51&&T_mode==0&&Quick_on==1)
		{
			Quick_on=0;
		}
		else if((mx>=208&&mx<=402)&&(my>=56&&my<=104)&&page==21&&T_mode==0&&L==N&&flag_bbox==2&&Bubble_on==0)
		{
			Bubble_on=1;
		}
		else if((mx>=208&&mx<=402)&&(my>=56&&my<=104)&&page==51&&T_mode==0&&L==N&&flag_qbox==2&&Quick_on==0)
		{
			Quick_on=1;
		}
		else if((mx>=208&&mx<=402)&&(my>=56&&my<=104)&&page==31&&T_mode==0&&L==N&&flag_ibox==2&&Insertion_on==0)
		{
			Insertion_on=1;
		}
		else if((mx>=680&&mx<=818)&&(my>=56&&my<=104)&&page==21&&T_mode==0&&B_i==B_k-1&&flag_bbox==2)
		{
			B_Data_Recover();
		}
		else if((mx>=476&&mx<=590)&&(my>=56&&my<=104)&&page==31&&T_mode==0&&Insertion_on==1)
		{
			Insertion_on=0;
		}
		else if((mx>=680&&mx<=818)&&(my>=56&&my<=104)&&page==31&&T_mode==0&&I_i==N-1&&flag_ibox==2)
		{
			I_Data_Recover();
		}
		else if((mx>=680&&mx<=818)&&(my>=56&&my<=104)&&page==51&&T_mode==0&&Q_j==Q_i-1&&flag_qbox==2)
		{
			Q_Data_Recover();
		}

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

void iKeyboard(unsigned char key)
{
	if(page==0 && key=='\r')
	{
		page=1;
	}
	if(T_mode==1 && (page==21||page==31||page==51))
	{
		if(key=='\r')
		{
			number[L-1].str[L_en] = '\0';
			if(L==N)
			{
				S_Converter();
				if(page==21)
				{
					Exchange_Bubble();
				}
				if(page==51)
				{
					Quicksort(0,N-1);
				}
				
			}

			T_mode = 0;
			L_en=0;
		}
		else if(key=='\b')
		{
			if(L_en>0)
			{
				number[L-1].str[--L_en]='\0';
			}
		}
		else
		{
			number[L-1].str[L_en] = key;
			number[L-1].str[L_en+1] = '\0';
			L_en++;
		}
	
	}

	if(T_mode1==1 && (page==21||page==31||page==51))
	{
		if(key=='\r')
		{
			T_mode1 = 0;
			if(page==21)
			{
				flag_bbox=1;
			}
			if(page==31)
			{
				flag_ibox=1;
			}
			if(page==51)
			{
				flag_qbox=1;
			}
			N=atoi(str);
			Box_Cordinate();
			str[L_an]='\0';
			L_an=0;
		}
		else if(key=='\b')
		{
			if(L_an>0)
			{
				str[--L_an]='\0';
			}
			
		}
		else
		{
			str[L_an] = key;
			str[L_an+1]='\0';
			L_an++;
		}
	
	}
	
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}

int main()
{
	iSettimer(25,Move_Bubble);
	iSettimer(25,Move_Insertion);
	iSettimer(25,Move_Quick);
	iInitialize(960, 720, "Sorting Algorithm Simulation");
	return 0;
}
void page1()
{
	iShowBMP(0,0,"new2.bmp");
	iSetColor(1,1,1);
	iRectangle(548,302,24,22);
	iRectangle(484,244,24,22);
	iRectangle(565,187,24,22);
	
}


void S_Converter()
{
	int s;
	for(s=0;s<N;s++)
	{
		array[s]=atoi(number[s].str);
	}
}

void Box_Cordinate()
{
	int s;
	number[0].x=100;
	for(s=0;s<N;s++)
	{
		number[s+1].x=number[s].x+50;
		number[s].y=400;
	}
}

void Show_Bsort()
{
	
	if(flag_bnew==1)
	{
		for(int s=0;s<N;s++)
	{
			iSetColor(1.0,1.0,1.0);
			iRectangle(number[s].x,number[s].y,50,50);
			if((s==save_array[B_i][0]||s==save_array[B_i][1])&&s!=new_array[s])
			{
				iSetColor(0.62745,0.1254,0.9411);
				iFilledRectangle(number[s].x+1,number[s].y+1,48,48);
			}
			if(s==new_array[s])
			{
				iSetColor(1,0,0);
				iFilledRectangle(number[s].x+1,number[s].y+1,48,48);
			}
			iSetColor(1,1,1);
			iText(number[s].x+10,number[s].y+10,number[s].str,GLUT_BITMAP_HELVETICA_18);
	}
	
	}
	else
	{
		
		for(int s=0;s<N;s++)
	{
			iSetColor(1.0,1.0,1.0);
			iRectangle(number[s].x,number[s].y,50,50);
			iSetColor(1,0,0);
			iFilledRectangle(number[s].x+1,number[s].y+1,48,48);
			iSetColor(1,1,1);
			iText(number[s].x+10,number[s].y+10,number[s].str,GLUT_BITMAP_HELVETICA_18);
	}

	}
}

void Show_Isort()
{
	
	if(flag_inew==1)
	{
		for(int s=0;s<N;s++)
	{
			if(flag_ishow==1)
			{
			    if(s!=flag_itemp)
			    {
			         iSetColor(1.0,1.0,1.0);
                     iRectangle(number[s].x,number[s].y,50,50);
					 if(s==I_r)
					 {
						 iSetColor(0.62745,0.1254,0.9411);
						 iFilledRectangle(number[s].x+1,number[s].y+1,48,48);
					 }
                     iSetColor(1,1,1);
                     iText(number[s].x+10,number[s].y+10,number[s].str,GLUT_BITMAP_HELVETICA_18);
			        
			    }
                     iSetColor(1.0,1.0,1.0);
                     iRectangle(temporary.x,temporary.y,50,50);
					 iSetColor(1,0,0);
					 iFilledRectangle(temporary.x+1,temporary.y+1,48,48);
                     iSetColor(1,1,1);
                     iText(temporary.x+10,temporary.y+10,temporary.str,GLUT_BITMAP_HELVETICA_18);
			}
			if(flag_ishow==0)
			{

                     iSetColor(1.0,1.0,1.0);
                     iRectangle(number[s].x,number[s].y,50,50);
					 if(s==I_i)
					 {
					 iSetColor(1,0,0);
					 iFilledRectangle(number[s].x+1,number[s].y+1,48,48);
					 }
                     iSetColor(1,1,1);
                     iText(number[s].x+10,number[s].y+10,number[s].str,GLUT_BITMAP_HELVETICA_18);
			}
			
	}
	
	}
	else
	{
		
		for(int s=0;s<N;s++)
	{
			iSetColor(1.0,1.0,1.0);
			iRectangle(number[s].x,number[s].y,50,50);
			iSetColor(1,0,0);
			iFilledRectangle(number[s].x+1,number[s].y+1,48,48);
			iSetColor(1,1,1);
			iText(number[s].x+10,number[s].y+10,number[s].str,GLUT_BITMAP_HELVETICA_18);
	}

	}
}


void Show_Qsort()
{
	if(flag_qnew==1)
	{
		for(int s=0;s<N;s++)
		{
			iSetColor(1.0,1.0,1.0);
			iRectangle(number[s].x,number[s].y,50,50);
			if(flag_show_pivot==1)
			{
				if(pivot_index[Q_j]==s)
				{
				iSetColor(0.196,0.8039,0.196);
				iFilledRectangle(number[s].x+1,number[s].y+1,48,48);
				//iSetColor(1,1,1);
			   // iText(number[s].x+10,number[s].y+10,number[s].str,GLUT_BITMAP_HELVETICA_18);
				}
			}
			if(flag_show_right==1)
			{
				if(right_index[Q_j]==s)
				{
				iSetColor(0.62745,0.1254,0.9411);
				iFilledRectangle(number[s].x+1,number[s].y+1,48,48);
				//iSetColor(1,1,1);
				//iText(number[s].x+10,number[s].y+10,number[s].str,GLUT_BITMAP_HELVETICA_18);
				}
			}
			if(flag_show_store==1)
			{
				if(store_index[Q_j][par]==s)
				{
					iSetColor(0.62745,0.1254,0.9411);
					iFilledRectangle(number[s].x+1,number[s].y+1,48,48);
				}
			}
			if(flag_show_compare==1)
			{
				if(compare_index[Q_j][par]==s)
				{
					iSetColor(0.62745,0.1254,0.9411);
					iFilledRectangle(number[s].x+1,number[s].y+1,48,48);
				}
			}
			if(flag_show_newpivot==1)
			{
				if(pivot_newindex[Q_j]==s)
				{
					iSetColor(0.62745,0.1254,0.9411);
					iFilledRectangle(number[s].x+1,number[s].y+1,48,48);
				}
			}
			iSetColor(1,1,1);
		    iText(number[s].x+10,number[s].y+10,number[s].str,GLUT_BITMAP_HELVETICA_18);
			
			
		}

		
	}
	else
	{
				for(int s=0;s<N;s++)
		{
	       iSetColor(1.0,1.0,1.0);
           iRectangle(number[s].x,number[s].y,50,50);
		   iSetColor(1.0,0,0);
		   iFilledRectangle(number[s].x+1,number[s].y+1,48,48);
           iSetColor(1,1,1);
           iText(number[s].x+10,number[s].y+10,number[s].str,GLUT_BITMAP_HELVETICA_18);
		}

	}
}



void Boxes()
{
	int s;
	for(s=0;s<N;s++)
	{
		iSetColor(1.0,1.0,1.0);
		iRectangle(number[s].x,number[s].y,50,50);
		iSetColor(1,1,1);
		iText(number[s].x+10,number[s].y+10,number[s].str,GLUT_BITMAP_HELVETICA_18);
	}
}

void Exchange_Bubble()
{
	int s,r,temp;
	for(s=0;s<N;s++)
	{
		for(r=s+1;r<N;r++)
		{
			if(array[s]>array[r])
			{
				sub_array[B_k]=1;
				save_array[B_k][0]=s;
				save_array[B_k][1]=r;
				temp=array[s];
				array[s]=array[r];
				array[r]=temp;
			}
			else
			{
				save_array[B_k][0]=s;
				save_array[B_k][1]=r;
				sub_array[B_k]=0;
			}
			B_k++;
		}
		new_array[B_u]=B_k-1;
		B_u++;
	}
}


void Quicksort(int left, int right)
{
	      if (left < right)
 {
          int pivotIndex=left+(right-left)/2;
		  pivot_swap[Q_i]=1;
		  pivot_index[Q_i]=pivotIndex;
		  right_index[Q_i]=right;
          int pivotNewIndex = partition(left, right, pivotIndex);
          Quicksort(left, pivotNewIndex - 1);
          Quicksort( pivotNewIndex + 1, right);
 }
		else if(left==right || left>right)
{
		  pivot_swap[Q_i]=0;
		  pivot_index[Q_i]=right;
		  Q_i++;
}
}

int partition(int left, int right, int pivotIndex)
{
      int temp,i;
	  int temp_p=0;
      int pivotValue = array[pivotIndex];
      temp=array[right];
      array[right]=array[pivotIndex];
      array[pivotIndex] = temp;
      int storeIndex = left;
      for (i=left;i<=right-1;i++)
         {
			 compare_index[Q_i][temp_p]=i;
			 store_index[Q_i][temp_p] = storeIndex;
           if (array[i] < pivotValue)
           {
			   if(store_index[Q_i][temp_p]!=compare_index[Q_i][temp_p])
			   {
				   store_swap[Q_i][temp_p]=1;
			   }
			   else
			   {
				   store_swap[Q_i][temp_p]=0;
			   }
			   temp=array[i];
               array[i]=array[storeIndex];
               array[storeIndex] = temp;
               storeIndex = storeIndex + 1;
           }
		   else
		   {
			   store_swap[Q_i][temp_p]=0;
			   store_index[Q_i][temp_p] = storeIndex;
		   }
		   temp_p++;
         }
	     store_last[Q_i]=temp_p-1;
		 pivot_newindex[Q_i]=storeIndex;
		 if(storeIndex!=right)
		 {
			 store_on[Q_i]=1;
		 }
		 else
		 {
			 store_on[Q_i]=0;
		 }
         temp=array[right];
         array[right]=array[storeIndex];
         array[storeIndex] = temp;
		 Q_i++;
         return (storeIndex);
}




void Move_Bubble()
{
	if(Bubble_on==1)
	{

		if(flag_bnew==1)
		{

		if(B_count<20)
		{
			B_count++;
		}
		else 
		{
			if(sub_array[B_i]==1)
				{
	
				if(updw==1)
				{

					if(number[save_array[B_i][0]].y==476 && number[save_array[B_i][1]].y==324)
					{
						updw=0;
						rglf=1;
						B_p=number[save_array[B_i][0]].x;
						B_q=number[save_array[B_i][1]].x;
					}
					else if(number[save_array[B_i][0]].y<476 && number[save_array[B_i][1]].y>324)
					{
						number[save_array[B_i][0]].y+=2;
						number[save_array[B_i][1]].y-=2;
					}
					
				}
				else if(rglf==1)
				{
					if(number[save_array[B_i][0]].x==(abs(save_array[B_i][1]-save_array[B_i][0])*50+B_p) && number[save_array[B_i][1]].x==(B_q-abs(save_array[B_i][1]-save_array[B_i][0])*50))
					{
						updw=0;
						rglf=0;
						dwup=1;
					}
					else 
					{
						number[save_array[B_i][0]].x+=2;
						number[save_array[B_i][1]].x-=2;
					}

				}
				else if(dwup==1)
				{
					if(number[save_array[B_i][0]].y==400 && number[save_array[B_i][1]].y==400)
					{
						
						rglf=0;
						dwup=0;
						if(B_i==B_k-1)
						{
							flag_bnew=0;
						}
						
						if(B_i<B_k-1)
						{
							if(B_count==20)
							{
							int num1,num2;
							char tempo[10];
							num1=number[save_array[B_i][0]].x;
							num2=number[save_array[B_i][0]].y;
							number[save_array[B_i][0]].x=number[save_array[B_i][1]].x;
							number[save_array[B_i][0]].y=number[save_array[B_i][1]].y;
							number[save_array[B_i][1]].x=num1;
							number[save_array[B_i][1]].y=num2;
							strcpy(tempo,number[save_array[B_i][0]].str);
							strcpy(number[save_array[B_i][0]].str,number[save_array[B_i][1]].str);
							strcpy(number[save_array[B_i][1]].str,tempo);
							B_count++;
							}
							if(B_count==21)
							{
								if(B_i==new_array[B_v])
								{
									new_array[B_v]=save_array[B_i-1][0];
									B_v++;
								}
								if(B_count<40)
								{
									B_count++;
								}
								if(B_count=40)
								{
									B_i++;
								    updw=1;
									B_count=0;
									
								}
								
							}
						}
						
					}
					else 
					{
						number[save_array[B_i][0]].y-=2;
						number[save_array[B_i][1]].y+=2;
					}


			}

			}

		else
			{
				if(B_i==B_k-1)
				{
					flag_bnew=0;
					Bubble_on=0;
					
				}
				if(B_i<B_k-1)
				{
					if(B_i==new_array[B_v])
					{
						new_array[B_v]=save_array[B_i-1][0];
						B_v++;
					}
					if(B_count<40)
					{
						B_count++;
					}
					if(B_count==40)
					{
						B_count=0;
						B_i++;
						updw=1;
					}

				}
				
			}
	}
			

			
}

}

}

void B_Data_Recover()
{
	 T_mode=0,L_en=0,L=0,T_mode1=0,L_an=0,B_i=0,B_k=0,B_u=0,B_v=0,updw=1,rglf=0,dwup=0,B_p=0,B_q=0,B_count=0;
	 flag_bbox=0,flag_bnew=0,Bubble_on=0;
	 
	 for(int s=0;s<N;s++)
	 {
		 number[s].x=0;
		 number[s].y=0;
		 for(int r=0;r<6;r++)
		 {
			number[s].str[r]='\0';
		 }
		 
	 }
	 for(int r=0;r<6;r++)
	 {
		 str[r]='\0';
	 }
	 N=0;
}

void Move_Insertion()
{
	if(Insertion_on==1)
	{

	if(flag_inew==1)
	{
	    if(I_count<30)
	    {
	        I_count++;
	    }
	    else
	    {
	        if(flag_ishow==0)
	        {
	            if(number[I_i].y<476)
	            {
	                number[I_i].y+=2;
	            }
	            if(number[I_i].y==476)
	            {
	                flag_itemp=I_i;
	                flag_ishow=1;
	                temporary.x=number[I_i].x;
	                temporary.y=number[I_i].y;
					I_p=number[I_i].x;
	                strcpy_s(temporary.str,number[I_i].str);
	                I_temp=array[I_i];
	                I_r=I_i-1;
	                if(I_temp<array[I_r])
	                {
	                    flag_imove=1;
						I_count=0;
						
	                }
	                else 
	                {
	                    flag_imove=0;
	                }    
	            }
	        }
	        else 
	        {
	            if(flag_imove==1)
	            {
	                if(number[I_r].x<I_p)
	                {
	                    number[I_r].x+=2;
	                }
	                if(number[I_r].x==I_p)
	                {
	                    array[I_r+1]=array[I_r];
	                    flag_itemp=I_r;
	                    number[I_r+1].x=I_p;
	                    number[I_r+1].y=400;
	                    strcpy_s(number[I_r+1].str,number[I_r].str);
	                    I_p=I_p-50;
                        if(I_r==0)
	                    {
	                        I_r--;
	                        flag_imove=0;
	                    }
	                    else
	                    {
                            I_r--;
                            if(I_temp<array[I_r])
                            {
                                flag_imove=1;
								I_count=0;
                            }
                            else
                            {
                                flag_imove=0;
                            }
	                    }

	                    
	                }

	            }
	            else if(flag_imove==0)
	            {
	                if(I_count<60)
	                {
	                    I_count++;
	                }
	                if(I_count==60)
                {
	                if(temporary.x>I_p)
	                {
	                    temporary.x-=2;
	                }
	                if(temporary.x==I_p)
	                {
	                    if(temporary.y>400)
	                    {
	                        temporary.y-=2;
	                    }
	                    if(temporary.y==400)
	                    {
	                        number[I_r+1].x=temporary.x;
	                        number[I_r+1].y=400;
	                        strcpy_s(number[I_r+1].str,temporary.str);
	                        if(I_i==N-1)
	                        {
	                            flag_inew=0;
								Insertion_on=0;
	                        }
	                        if(I_i<N-1)
	                        {
	                            flag_itemp=-1;
	                            flag_ishow=0;
	                            I_i++;
	                            array[I_r+1]=I_temp;
	                            I_count=0;
	                        }

	                    }
	                }
                }
	            }
	        }
	    }

	}
}

}


void I_Data_Recover()
{
	 T_mode=0,L_en=0,L=0,T_mode1=0,L_an=0,I_i=1,I_p=0,I_count=0;
	 flag_ibox=0,flag_inew=0,Insertion_on=0,flag_ishow=0;
	
	 for(int s=0;s<N;s++)
	 {
		 number[s].x=0;
		 number[s].y=0;
		 for(int r=0;r<6;r++)
		 {
			number[s].str[r]='\0';
		 }
		 
		 temporary.x=0;
		 temporary.y=0;
		 
	 }
	 for(int r=0;r<6;r++)
	 {
		 temporary.str[r]='\0';
		  str[r]='\0';
	 }
	 N=0;
}

void Move_Quick()
{
	if(Quick_on==1)
	{
		  if(flag_qnew==1)
	{
		if(Q_count_i<30)
		{
			Q_count_i++;
			if(Q_count_i==30)
			{
				printf("%d\n",Q_j);
				flag_show_pivot=1;
				pivot_on=1;
				Q_count_j=0;
			}
		}
		else
		{
			if(pivot_swap[Q_j]==1)
			{
				if(pivot_on==1)
			  {
				if(Q_count_i<60)
				{
					Q_count_i++;
				}
				else if(Q_count_i==60)
				{
					flag_show_right=1;
					if(Q_count_j<30)
					{
						Q_count_j++;
					}
					if(Q_count_j==30)
					{
						Q_count_i++;
						updw=1;
						rglf=0;
						dwup=0;
						Q_count_j=0;
					}
				}
				else
				{
					if(updw==1)
					{
					if((number[pivot_index[Q_j]].y != 476) && (number[right_index[Q_j]].y != 324))
					{
						number[pivot_index[Q_j]].y+=2;
						number[right_index[Q_j]].y-=2;
						if((number[pivot_index[Q_j]].y==476) && (number[right_index[Q_j]].y==324))
						{
							printf("pivot index == %d   right index == %d\n",pivot_index[Q_j],right_index[Q_j]);
							co_x1=number[pivot_index[Q_j]].x;
							co_x2=number[right_index[Q_j]].x;
							updw=0;
							rglf=1;
							dwup=0;
						}
					}
					}
					if(rglf==1)
					{
						if((number[pivot_index[Q_j]].x != co_x2) && (number[right_index[Q_j]].x != co_x1))
						{
							number[pivot_index[Q_j]].x+=2;
							number[right_index[Q_j]].x-=2;
							if((number[pivot_index[Q_j]].x==co_x2) && (number[right_index[Q_j]].x ==co_x1))
							{
								rglf=0;
								dwup=1;
								updw=0;
							}
						}
					}
					if(dwup==1)
					{
						if((number[pivot_index[Q_j]].y != 400) && (number[right_index[Q_j]].y != 400))
						{
							number[pivot_index[Q_j]].y-=2;
							number[right_index[Q_j]].y+=2;
							if((number[pivot_index[Q_j]].y==400) && (number[right_index[Q_j]].y==400))
							{
							int num1;
							char tempo[10];
							num1=number[pivot_index[Q_j]].x;
							number[pivot_index[Q_j]].x=number[right_index[Q_j]].x;
							number[right_index[Q_j]].x=num1;
							strcpy(tempo,number[pivot_index[Q_j]].str);
							strcpy(number[pivot_index[Q_j]].str,number[right_index[Q_j]].str);
							strcpy(number[right_index[Q_j]].str,tempo);
							number[pivot_index[Q_j]].y=400;
							number[right_index[Q_j]].y=400;
							partition_on=1;
							pivot_on=0;
							Store_on=0;
							Q_count_i=30;
							par=0;
							flag_show_pivot=0;
							flag_show_right=0;
							flag_show_store=1;
							flag_show_compare=0;
							updw=0;dwup=0;rglf=0;
							}
						}
					}

					}
				}
				if(partition_on==1)
				{
					if(Q_count_i<60)
					{
						Q_count_i++;
					}
					else if(Q_count_i==60)
						{
							flag_show_compare=1;
							if(Q_count_j<30)
							{
								Q_count_j++;
							}
							if(Q_count_j==30)
							{
								Q_count_i++;
								Q_count_j=0;
								updw=1;
								rglf=0;
								dwup=0;
							}
						}
					else
					{
						if(store_swap[Q_j][par]==1)
						{
								if(updw==1)
								{
									if((number[store_index[Q_j][par]].y!=476) && (number[compare_index[Q_j][par]].y!=324))
					            {
										number[store_index[Q_j][par]].y+=2;
										number[compare_index[Q_j][par]].y-=2;
										if((number[store_index[Q_j][par]].y==476) && (number[compare_index[Q_j][par]].y==324))
										{
											printf("store index == %d   compare index == %d\n",store_index[Q_j][par],compare_index[Q_j][par]);
											co_x1=number[store_index[Q_j][par]].x;
											co_x2=number[compare_index[Q_j][par]].x;
											updw=0;rglf=1;
										}
								}

								}
								if(rglf==1)
								{
										if((number[store_index[Q_j][par]].x!=co_x2) && (number[compare_index[Q_j][par]].x != co_x1))
										{
										number[store_index[Q_j][par]].x+=2;
										number[compare_index[Q_j][par]].x-=2;
										}
										if((number[store_index[Q_j][par]].x==co_x2) && (number[compare_index[Q_j][par]].x == co_x1))
										{
											rglf=0;
											dwup=1;
											updw=0;
										}

								}
								if(dwup==1)
								{
									if((number[store_index[Q_j][par]].y != 400 ) && (number[compare_index[Q_j][par]].y != 400))
										{
										number[store_index[Q_j][par]].y-=2;
										number[compare_index[Q_j][par]].y+=2;
										if((number[store_index[Q_j][par]].y==400) && (number[compare_index[Q_j][par]].y==400))
										{
											int num1;
											char tempo[10];
											num1=number[store_index[Q_j][par]].x;
											number[store_index[Q_j][par]].x=number[compare_index[Q_j][par]].x;
											number[compare_index[Q_j][par]].x=num1;
											strcpy(tempo,number[store_index[Q_j][par]].str);
											strcpy(number[store_index[Q_j][par]].str,number[compare_index[Q_j][par]].str);
											strcpy(number[compare_index[Q_j][par]].str,tempo);
											number[store_index[Q_j][par]].y=400;
											number[compare_index[Q_j][par]].y=400;
											if(par==store_last[Q_j])
											{
												flag_show_newpivot=1;
												flag_show_store=0;
												flag_show_compare=0;
												if(store_on[Q_j]==1)
												{
													Store_on=1;
													partition_on=0;
													pivot_on=0;
													updw=1;
													rglf=0;
													dwup=0;
													Q_count_i=30;
												}
												else
												{
													if(Q_j==Q_i-1)
												{
													flag_qnew=0;
													printf("%d  %d  %d  %d  ",pivot_index[7],pivot_index[8],pivot_index[9],pivot_index[10]);
												}
													if(Q_j<Q_i-1)
													{

													if(Q_count_j<30)
												{
													Q_count_j++;
												}
												if(Q_count_j==30)
												{
													pivot_on=0;
													partition_on=0;
													Store_on=0;
													Q_j++;
													Q_count_i=0;
													updw=0;
													rglf=0;
													dwup=0;
													Q_count_j=0;
													flag_show_pivot=0;
													flag_show_right=0;
													flag_show_newpivot=0;
													flag_show_compare=0;
													flag_show_store=0;
												}

													}

												}
												
											}
											if(par<store_last[Q_j])
											{
												flag_show_store=1;
												flag_show_compare=0;
												par++;
												updw=0;
												dwup=0;
												rglf=0;
												Q_count_i=30;
											}
												
											}

											}
									}

								}

						else
						{
							if(par==store_last[Q_j])
								{
									flag_show_newpivot=1;
									flag_show_store=0;
									flag_show_compare=0;
									if(store_on[Q_j]==1)
									{
										Store_on=1;
										partition_on=0;
										pivot_on=0;
										updw=0;
										rglf=0;
										dwup=0;
										Q_count_i=30;
										Q_count_j=0;
									}
									else
									{
											if(Q_j==Q_i-1)
											{
												flag_qnew=0;
												printf("%d  %d  %d  %d  ",pivot_index[7],pivot_index[8],pivot_index[9],pivot_index[10]);
											}
											if(Q_j<Q_i-1)
											{
												if(Q_count_j<30)
												{
													Q_count_j++;
												}
												if(Q_count_j==30)
												{
													pivot_on=0;
													partition_on=0;
													Store_on=0;
													Q_j++;
													Q_count_i=0;
													updw=0;
													rglf=0;
													dwup=0;
													Q_count_j=0;
													flag_show_pivot=0;
													flag_show_right=0;
													flag_show_newpivot=0;
													flag_show_compare=0;
													flag_show_store=0;
												}
												
											}
									}
									
								}
							if(par<store_last[Q_j])
							{
								flag_show_store=1;
								flag_show_compare=0;
								Q_count_i=30;
								par++;
								updw=0;
								dwup=0;
								rglf=0;
							}
											
						}
							
						}
					}
			
				if(Store_on==1)
				{
					if(Q_count_i<60)
					{
						Q_count_i++;
					}
					else if(Q_count_i==60)
					{
						flag_show_right=1;
						if(Q_count_j<30)
						{
							Q_count_j++;
						}
						if(Q_count_j==30)
						{
							Q_count_i++;
							updw=1;
							dwup=0;
							rglf=0;
							Q_count_j=0;
						}
					}
					else
					{

					if(updw==1)
					{
						if((number[pivot_newindex[Q_j]].y != 476) && (number[right_index[Q_j]].y!=324))
					            {
										number[pivot_newindex[Q_j]].y+=2;
										number[right_index[Q_j]].y-=2;
										if((number[pivot_newindex[Q_j]].y==476) && (number[right_index[Q_j]].y==324))
										{
											printf("pivot new index == %d   right index == %d\n",pivot_newindex[Q_j],right_index[Q_j]);
											co_x1=number[pivot_newindex[Q_j]].x;
											co_x2=number[right_index[Q_j]].x;
											rglf=1;
											dwup=0;
											updw=0;
										}
								}
					}
					if(rglf==1)
					{
						if((number[pivot_newindex[Q_j]].x!=co_x2) && (number[right_index[Q_j]].x != co_x1))
						{
							number[pivot_newindex[Q_j]].x+=2;
							number[right_index[Q_j]].x-=2;
							
							if((number[pivot_newindex[Q_j]].x==co_x2) && (number[right_index[Q_j]].x == co_x1))
							{
							dwup=1;
							rglf=0;
							updw=0;
							}
						}

					}
					if(dwup==1)
						{
						if((number[pivot_newindex[Q_j]].y != 400) && (number[right_index[Q_j]].y != 400))
							{
							number[pivot_newindex[Q_j]].y-=2;
							number[right_index[Q_j]].y+=2;
							if((number[pivot_newindex[Q_j]].y==400) && (number[right_index[Q_j]].y==400))
							{
								int num1;
								char tempo[10];
								num1=number[pivot_newindex[Q_j]].x;
								number[pivot_newindex[Q_j]].x=number[right_index[Q_j]].x;
								number[right_index[Q_j]].x=num1;
								strcpy(tempo,number[pivot_newindex[Q_j]].str);
								strcpy(number[pivot_newindex[Q_j]].str,number[right_index[Q_j]].str);
								strcpy(number[right_index[Q_j]].str,tempo);
								number[pivot_newindex[Q_j]].y=400;
								number[right_index[Q_j]].y=400;
								if(Q_j==Q_i-1)
								{
									flag_qnew=0;
									printf("%d  %d  %d  %d  ",pivot_index[7],pivot_index[8],pivot_index[9],pivot_index[10]);
								}
								if(Q_j<Q_i-1)
								{
									pivot_on=0;
									partition_on=0;
									Store_on=0;
									Q_j++;
									Q_count_i=0;
									Q_count_j=0;
									updw=0;
									rglf=0;
									dwup=0;
									flag_show_pivot=0;
									flag_show_right=0;
									flag_show_newpivot=0;
									flag_show_compare=0;
									flag_show_store=0;

								}
							}

							}

						}

				}

				}
			}

				else
				{
						if(Q_count_i<60)
				{
					Q_count_i++;
					if(Q_count_i==60)
					{
						if(Q_j==Q_i-1)
						{
							flag_qnew=0;
							printf("%d  %d  %d  %d  ",pivot_index[7],pivot_index[8],pivot_index[9],pivot_index[10]);
						}
						if(Q_j<Q_i-1)
						{
							flag_show_pivot=0;
							flag_show_right=0;
							flag_show_newpivot=0;
							flag_show_compare=0;
							flag_show_store=0;
							Q_j++;
							pivot_on=0;
							partition_on=0;
							Store_on=0;
							Q_count_i=0;
							updw=0;
							rglf=0;
							dwup=0;
						}
					}
				}

			}

}

}
	}
}


void Q_Data_Recover()
{
	 T_mode=0,L_en=0,L=0,T_mode1=0,L_an=0,Q_i=0,Q_j=0,updw=0,rglf=0,dwup=0,co_x1=0,co_x2=0,Q_count_i=0,Q_count_j=0;
	 flag_qbox=0,flag_qnew=0,Quick_on=0;
	 int flag_show_pivot=0,flag_show_right=0,flag_show_store=0,flag_show_compare=0,flag_show_newpivot=0,pivot_on=0, partition_on=0, Store_on=0;
	 for(int s=0;s<N;s++)
	 {
		 number[s].x=0;
		 number[s].y=0;
		 for(int r=0;r<6;r++)
		 {
			number[s].str[r]='\0';
		 }
		 
	 }
	 for(int r=0;r<6;r++)
	 {
		 str[r]='\0';
	 }
	 N=0;
}