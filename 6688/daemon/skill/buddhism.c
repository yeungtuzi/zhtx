// buddhism.c
#include <ansi.h>
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("你的杀气太重，无法修炼大乘佛法。\n");
        return 1;
}

void skill_improved(object me)
{
        int s;
        s= me->query_skill("buddhism",1);
        me=this_player();
        tell_object(me, "你对佛法更进一步的领悟化解了你的杀气。\n");
        me->delete("bellicosity");
        if( me->query("family/family_name") != "少林派")
                return 0;
        if( (int)me->query("cps") < s/5 ) 
               {
                tell_object(me, HIW "由於你勤奋研修大乘佛法，你的定力提高了。\n" NOR);
                me->add("cps",1);
               }
}

