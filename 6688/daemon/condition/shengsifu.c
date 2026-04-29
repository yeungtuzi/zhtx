// shengsifu.c生死符

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("jing",20);
        me->receive_wound("qi",20);
        me->add("neili",-20);
        me->apply_condition("shengsifu", duration - 1);
        message_vision(HIG"$N中的" HIR "生死符" HIG "发作了！\n" NOR,me );
        tell_object(me,HIR"你但觉阵阵麻痒,直如万蚁噬心!\n" NOR );
        if((me->query("qi")<50)||(me->query("neili")<50))
message_vision(HIY"$N嗷嗷号叫,手在身上乱抓,全身都是抓出的血痕,神智已然不清!
\n"NOR,me);
        if( duration < 1 ) return 0;
        return 1;
}
