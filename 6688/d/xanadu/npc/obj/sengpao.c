#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("灰布僧袍", ({ "huibu sengpao", "sengpao" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("rigidity",5000000); //后面加了个零,省的老被削断了
                set("unit", "把");
                set("value", 0);
                set("material", "steel");
                set("long", "这是一件毫不起眼的僧袍，已经破旧不堪。\n");
        }
        init_sword(1000);
        setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{

     if( victim->query("id") == "saodi seng" )  return 0;
        victim->receive_wound("kee",victim->query("max_kee")/2);
//        return this_object()->name()+ HIR "在$n的$l轻轻划过，所到之处嗤嗤之声不绝于耳，$n皮开肉绽，连声惨嚎！\n" NOR;
}


int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query("id") == "saodi seng" ) 
        {
        return ::wield();
        }else{
                return notify_fail("这是你的东西吗？\n");
        }

}

