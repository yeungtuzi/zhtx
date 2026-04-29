#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit WHIP;

int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIM "魔鞭翩珑" NOR,  ({ "mobian pianlong", "bian" }) );
        set_weight(1);
        set("no_sell",1);
        set("no_drop",1);
        set("no_paimai",1);
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
                set("weapon_prop/attack", 70);
                set("weapon_prop/personality",75);   
                set("weapon_prop/dodge", 175); 
       }
    init_whip(550);
       setup();
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("snowwhip",1) < 200)
        {
                return notify_fail("你的寒雪鞭法等级太低了，用不了这件兵器。\n");
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这根鞭子。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
          int skill;
          me->add("force",me->query("force_factor"));
          skill=this_player()->query_skill("snowwhip",1);
          if (damage_bonus < 0 ) return 0;
          if (random(3) > 1 )
          victim->apply_condition("rose_poison",20+random(100));
          victim->update_condition();

        return this_object()->name()+ HIR "上面的倒刺钩上了$n的$l，$n只觉得伤口处火辣辣的疼痛，接着又是一阵麻痒难当！\n" NOR;
}

