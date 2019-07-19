#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void display();
int roll_dice();
int check_snake(int);
int check_ladder(int);
void main()
{
    int position=0;
    display();
    while(position<100)
    {
        printf("Press 1 to roll the dice\n");
        int cho;
        scanf("%d",&cho);
        int roll=roll_dice();
        printf("Your roll is .... %d\n",roll);
        position=position+roll;
        if(position==100)
        {
           break;
        }
        printf("your position : %d\n\n",position);
        position=check_snake(position);
        position=check_ladder(position);
    }
    printf("CONGRATS! YOU WON");
}

void display()
{
    printf("SNAKES : \n");
    printf("27 <---> 5\n40 <---> 3\n43 <---> 18\n54 <---> 31\n66 <---> 45\n76 <---> 58\n89 <---> 53\n99 <---> 41\n");
    printf("\nLADDERS : \n");
    printf("4  ===== 25\n13 ===== 46\n33 ===== 49\n42 ===== 63\n50 ===== 69\n62 ===== 81\n74 ===== 92\n\n");
}
int roll_dice()    // dice roll
{
		int roll;
        srand(time(0));
		roll=(rand()%6)+1;
		return roll;
}

int check_snake(int pos)
{
	int start_snake[]={27,40,43,54,66,76,89,99};
	int end_snake[]={6,3,18,31,45,58,53,41};

    int i;
	for(i=0;i<8;i++)
	{
		if(pos==start_snake[i])
		{
			int new_pos=end_snake[i];
            printf("You were bitten by a snake.\nYour new position is : %d\n\n",new_pos);
            return new_pos;
		}
	}
	return pos;
}

int check_ladder(int pos)
{
	int start_ladder[]={4,13,33,42,50,62,74};
	int end_ladder[]={25,46,49,63,69,81,92};

	int i;
	for(i=0;i<7;i++)
	{
		if(pos==start_ladder[i])
		{
			int new_pos=end_ladder[i];
            		printf("Hurrah! You found a ladder.\nYour new position is : %d\n\n",new_pos);
			return new_pos;
		}
	}
	return pos;
}
