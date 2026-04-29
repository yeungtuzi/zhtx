// calculate 菲波那契数列

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	int i,j,k,l,sum;
	int total;

	seteuid(geteuid(me));
	if( !arg || !(sscanf(arg,"%d",total)) || total < 2 ) return notify_fail("f num\n");
	i = 1;
	k = 1;
	write("Calculate "+total+" numbers\n");
	write("\n1\n1\n");
	while(total--)
	{
		l = i+k;
		sum += l;
		printf("%d\n",l);
		i = k;
		k = l;
	}
	printf("total sum is: %d\n",sum);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : f <数量>

计算从开始到<数值>的所有菲波那契数列,
并计算其总和.
HELP
    );
    return 1;
}
