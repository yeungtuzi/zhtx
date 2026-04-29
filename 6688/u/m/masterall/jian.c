//xuantian-jian.c
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
    set_name(HIG"玄天"+HIY"神"+HIC"剑"NOR, ({ "xuantian shenjian", "jian" }) );
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
                set("long", "这是当年龙象驰骋天下时所带的佩剑。其锋利已不在任何神兵利器之下。\n");
                set("wield_msg",HIB"一时间，斗转乾坤之势，$n已在$N手中，天地为之变色。\n"NOR);
                set("unwield_msg", HIC"$N将$n插回腰间，华光顿敛，天地间只闻龙鸣。\n"NOR);
        }
        init_sword(520);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{

     if( victim->query("id") == "long xiang" )  return 0;
        victim->receive_wound("kee",victim->query("max_kee")/2);
        return this_object()->name()+ HIR "刺穿了$n的$l，伤口顿时血流如柱，其相惨不忍睹！\n" NOR;
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query("id") == "long xiang" ) 
        {
        return ::wield();
        }else{
                return notify_fail("这是你的兵器吗？没看着写着龙象专用？！\n");
        }

}


