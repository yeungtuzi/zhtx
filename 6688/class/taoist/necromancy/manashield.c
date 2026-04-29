// mana-shield.c

#include <ansi.h>

inherit SSERVER;

void remove_effect(object me, int amount);

int cast(object me, object target)
{
        int skill,amount;

        if( !objectp(target) ) target = me;
        if( target != me ) return notify_fail("你只能对自己使用红幻之盾。\n");

        if( (int)me->query("mana") < 500 )     return notify_fail("你的法力不够了。\n");
        if( (int)me->query_temp("manashield") ) return notify_fail("你已经有防护了。\n");
       if( (int)me->query_temp("broke-shield") ) return notify_fail("你的体内的真元已经被打散了，无法继续提精运气。\n");

        skill = me->query_skill("spells");
        amount = skill/5+me->query("max_mana")/10; 

        if( skill < 100 ) return notify_fail("你由于对法术不够熟练而失败了。\n");

        me->add("mana", -80);

        message_vision(
                MAG"$N双手平伸，口中念了几句咒语，一道淡淡的红色光芒从顶门升起，幻作薄薄的一道光幕罩住$N的全身。\n" NOR, me);

        me->set_temp("manashield", 1);
        me->add_temp("apply/armor", amount*2); 
        me->add_temp("apply/armor_vs_force", amount); 

        
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, amount :), skill*2);


        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}


void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", -amount*2); 
        me->add_temp("apply/armor_vs_force", - amount);
        me->delete_temp("manashield");
        message_vision(
                HIR "$N身周的光幕渐渐转淡，慢慢消失不见。\n" NOR, me);
}

