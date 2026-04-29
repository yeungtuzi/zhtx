//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 魔鞭翩珑

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit WHIP;
//inherit F_UNIQUE;

int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIM "魔鞭翩珑" NOR,  ({ "mobian pianlong", "bian" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        set("no_get",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "这是一条玲珑剔透的鞭子，轻柔但却坚韧，好似女子的玩物，\n若不细看，很难发现上面居然还有暗红色的倒刺！\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "龙筋");
                set("wield_msg",
                        HIM"$N曼起舞步，轻轻一抖，一条如丝带般轻柔，却如毒蛇般阴戾的鞭子飞了出来。\n"NOR);
                set("unequip_msg", HIM"$N舞步一停，将魔鞭翩珑盘在腰中。\n"NOR);
                set("weapon_prop/attack", this_player()->query_skill("snowwhip",1)/7);
                set("weapon_prop/personality", this_player()->query_skill("stormdance",1)/4);   
                set("weapon_prop/dodge", this_player()->query_skill("stormdance",1)/4); 
       }
    init_whip(300);
       setup();
}

int wield()
{
        if( this_player()->query_skill("snowwhip",1) < 250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
          int skill;
          skill=this_player()->query_skill("snowwhip",1);
               if (damage_bonus < 0 ) return 0;
          if(skill>random(399))
          victim->apply_condition("rose_poison",50);
          victim->update_condition();
          victim->start_busy(1);

        return this_object()->name()+ HIR "上面的倒刺钩上了$n的$l，$n只觉得伤口处火辣辣的疼痛，接着又是一阵麻痒难当！\n" NOR;
}

