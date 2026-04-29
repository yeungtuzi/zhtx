// purple.c

inherit SKILL;
#include <ansi.h>

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
        int lvl;

        lvl = (int)me->query_skill("purple", 1);

        if( (int)me->query("shen") < 0 )
                return notify_fail("你的邪气太重，无法修炼紫气东来。\n");

        if(me->query("gender") == "无性" && lvl > 39)
                return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之气，无法领会里面的阴阳变化之道。\n");


        return 1;
}

int practice_skill(object me)
{
        return notify_fail("紫气东来只能靠学习来提高。\n");
}
void skill_improved(object me)
{
        int s;

        s = me->query_skill("purple", 1);
//        if(s<150||s>200)
//                return ;
      if( (int)me->query("con") >50 ) return 0; 
        if( (int)me->query("con") < s/4 ) 
        {
                tell_object(me, HIM "由於你勤于修炼紫气东来，你的体质提高了!\n" NOR);
                me->add("con", 2);
        }
}

