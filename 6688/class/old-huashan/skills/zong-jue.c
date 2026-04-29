// literate.c

#include <ansi.h>

inherit SKILL;


void skill_improved(object me)
{
        int s;

        s = me->query_skill("zong-jue",1);
        if((int)me->query("cps") < s/4) {
                tell_object(me, HIW "由於你勤奋学习独孤九剑的「总诀式」，你的定力提高了。\n" NOR);
                me->add("cps", 1);
        }
}

int learn_bonus()
{
        return -20;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 0;
}
