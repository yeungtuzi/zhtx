#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
        int lvl,i;
        object env, *inv;
        lvl = (int) me->query_skill("essencemagic", 1);
        lvl += (int) me->query("spi");
        if ( lvl <= 150)
                return notify_fail("你法术不够高！\n");
        if( me->query("atman") < 300 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 50 )
                return notify_fail("你的精不够！\n");
        me->add("atman", -200);
        me->receive_damage("gin", 50);
        if ( lvl <= random(400) )
	{
		me->start_busy(1);
                return notify_fail("你因法术不够熟练而失败了！\n");
        }
        message_vision(HIW "$N凝神提气，一团白芒乍出体内，整个人渐渐虚化．．．\n" NOR, me);
                me->set("env/invisibility", 1);
	me->set_temp("conjureing",1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), lvl/10);
        if( me->is_fighting() ) 
        	me->start_busy(3);
        return 1;

}
void remove_effect(object me)
{
        me->set("env/invisibility", 0);
	call_out("remove_mark",3,me);
	tell_object(me, "你的隐识失效了。\n");
}

void remove_mark(object me)
{
	me->delete_temp("conjureing");
}
