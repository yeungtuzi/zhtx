// dodge.c
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "但是和$p$l偏了几寸。\n",
        "但是被$p机灵地躲开了。\n",
        "但是$n身子一侧，闪了开去。\n",
        "但是被$p及时避开。\n",
        "但是$n已有准备，不慌不忙的躲开。\n",
});

string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


void skill_improved(object me)
{
        int s,s1,s2;

        s1 = me->query_skill("dodge", 1)/2;
        s2 = me->query_skill("move", 1)/2;
        s = s1+s2;
        if( s < 220 ) return;   
        if( (int)me->query("dex") < 50 ) return;
        if( s%10==9 && (int)me->query("dex") < s/4) {
                tell_object(me, HIW "由於你的勤学苦练，你的敏捷提高了。\n" NOR);
                me->add("dex", 2);
        }
}



