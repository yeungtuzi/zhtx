// calligraphy.c

inherit SKILL;
#include <ansi.h>

void create() { seteuid(getuid()); }

//string type() { return "knowledge"; }

int valid_learn(object me)
{
        int lvl,skill;

        lvl = (int)me->query_skill("literate", 1);

        if( lvl < 400 )
                return notify_fail("你读书识字水平太低，还无法学习书法。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("书法只能靠学习来提高。\n");
}
void skill_improved(object me)
{
        int s,g;

        s = me->query_skill("calligraphy", 1);
        g = (int)me->query("cor")+(int)me->query("cps");

        if( g < s/5 ) 
        {
                tell_object(me, HIC"你从书法的意境中渐渐感受到了武学的真谛，以前修习本派武学时的疑窦顿时破解，\n临敌时不可气馁，一招既出，则环环相扣，如挥毫泼墨，似行云流水，\n想到此处，你不由得哈哈大笑了几声，你的定力和胆识提高了！\n" NOR);
                me->add("cor", 1);
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

