#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
    set_name("磁铁棋盘",({"citie qipan","qipan"}));
    set_weight(10000);
    if( clonep() )
         set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("value", 1);
                set("material", "steel");
                set("rigidity",500000);
                set("long", "一块铁铸的棋盘，看起来极其沉重。据说还有妙用\n");
                set("weapon_prop/attack", -4);
                set("weapon_prop/defense", 5);
        }
        init_hammer(40);
        setup();

}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weap;
        int    wap,wdp;
        string weap_name;

        if(victim == me) return;
        if( objectp(weap = victim->query_temp("weapon")) )
        {
               wap = weight() / 500
                        + query("rigidity")
                        + me->query("str");

                wdp = (int)weap->weight() / 500
                        + (int)weap->query("rigidity")
                        + (int)victim->query("str");

                if(  random(wap) > wdp )
                {
                       weap->move(me);
                       victim->reset_action();
                       return HIY"$n手中的" + weap_name
                                + "被$N挟雷霆万钧之势一挑，脱手飞出！\n"NOR;
                }
                                
        }
        else 
                return damage_bonus/2;
}
