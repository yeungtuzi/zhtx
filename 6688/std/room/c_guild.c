//guild.c
//modified by tlang

#include <ansi.h>
inherit ROOM;

void re_rank(object);
void setup()
{
	::setup();
}

void init()
{
	add_action("do_join", "join");
}

int do_join(string arg)
{
	object me;
	me = this_player();
	
	if(me->query("gender")=="无性")
		return notify_fail("镖局之中，不收无性之人。\n");
	if(me->query("biao_ju") )
		return notify_fail("你已经加入过了。\n");
//	if(stringp(me->query("class")) )
//		return notify_fail("这儿不收加入过门派的人。\n");
	me->set("biao_ju", 1);
	re_rank(me);
	me->set("startroom", CLASS_D("guard") + "/bjdting");
	write("\n恭喜，从今天起您已经成为一名镖局会员！\n\n");
		return 1;
}

void re_rank(object student)
{
        int exp;

//      string old_rank;
//      old_rank=student->query("title");

        exp = (int) student->query("combat_exp");
        if( exp <= 10000 ) {
                student->set("nickname",RED"趟子手"NOR);
                return ;
        } else if ( exp <= 100000 ) {
                student->set("nickname",BLU"趟子手"NOR);
                return ;
        } else if ( exp <= 200000 ) {
                student->set("nickname",MAG"镖头"NOR);
                return ;
        } else
                student->set("nickname",YEL"副总镖头"NOR);
                return ;
}


