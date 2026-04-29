// literate.c

#include <ansi.h>

inherit SKILL;

//string type() { return "knowledge"; }

void skill_improved(object me)
{
	int s;

	s = me->query_skill("qi", 1);
	if(s<180||s>200)
		return ;
	if( s%10==9 && (int)me->query("int") < s/8 && !me->query("betrayer") ) 
	{
		tell_object(me, HIW "由於你的勤练棋艺，你的悟性提高了。\n" NOR);
		me->add("int", 2);
	}
}
