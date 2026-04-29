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
	if(me->query("class")=="guard")
		return notify_fail("你已经加入过了。\n");
//	if(stringp(me->query("class")) )
//		return notify_fail("这儿不收叛师之人。\n");
	me->set("class", "guard");
	re_rank(me);
	me->set("startroom", CLASS_D("guard") + "/bjdting");
	write("\n恭喜，从今天起您已经成为一名镖局会员！\n\n");
		return 1;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 10000 ) {
                student->set("title",RED"二级趟子手"NOR);
                return ;
        } else if ( exp <= 100000 ) {
                student->set("title",BLU"一级趟子手"NOR);
                return ;
        } else if ( exp <= 200000 ) {
                student->set("title",MAG"镖头"NOR);
                return ;
        } else 
                student->set("title",YEL"副总镖头"NOR);
                return ;
}

