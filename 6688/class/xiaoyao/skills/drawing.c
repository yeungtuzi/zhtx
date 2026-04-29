// literate.c

#include <ansi.h>

inherit SKILL;

//string type() { return "knowledge"; }

void skill_improved(object me)
{
	int s;

	s = me->query_skill("drawing", 1);
	if(s>160)
		return ;
	if( s%10==9 && (int)me->query("spi") < s/4 && !me->query("betrayer") ) 
	{
		tell_object(me, HIW "由於你勤练书画，你的灵性提高了。\n" NOR);
		me->add("spi", 2);
	}
}
