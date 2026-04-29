//feifengmodao.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
    set_name(HIM"飞凤"+HIR"魔"+HIC"刀"NOR, ({ "feifeng modao", "dao" }) );
    set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 0);
                set("no_drop",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_paimai",1);
                set("material", "iron");
                set("rigidity", 90000000); 
                set("long", "这是当年不知火舞斩杀庞斑时所使用的佩刀，据说堂堂的魔师居然连一刀也经受不住就挂了。\n");
                set("wield_msg",HIM"天际深处飞来一只五彩祥凤，盘旋在$N的上空，瞬时又飞入$N的手中。\n"NOR);
        }
        init_blade(520);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{

     if( victim->query("id") == "buzhi huowu" )  return 0;
        victim->receive_wound("kee",victim->query("max_kee")/2);
        return this_object()->name()+ HIR "在$n的$l轻轻划过，所到之处嗤嗤之声不绝于耳，$n皮开肉绽，连声惨嚎！\n" NOR;
}


int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query("id") == "buzhi huowu" ) 
        {
        return ::wield();
        }else{
                return notify_fail("这是你的兵器吗？没看着写着不知火舞专用？！\n");
        }

}


