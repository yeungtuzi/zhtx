 //OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 紫薇软剑

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit SWORD;

int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIM"紫薇软剑"NOR, ({ "ziwei ruanjian", "jian" }) );
        set_weight(1);
        set("unpawnable",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "这是当年名震天下的独孤求败早年剑使用的一把剑，长约四尺，青光闪闪，确是利器。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "crimson gold");
                set("wield_msg",
                        HIC"青光一闪，$n"+HIC"已在$N手中，四周尽是逼人的杀气。\n"NOR);
                set("unequip_msg", HIM"$N将$n插回腰间的剑鞘。\n"NOR);
                set("weapon_prop/attack", 40);  
                set("weapon_prop/dodge", 75);  
       }
    init_sword(320);
       setup();
}

int query_unparryable(object me,object victim)
{
        object weap;
      
        return 100;  //普通技能或兵器10%的可parry机率
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这柄剑。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (damage_bonus < 0 ) return 0;
        if(random(3)>0)
        victim->receive_wound("kee",damage_bonus/6);
        return this_object()->name()+ HIC "激发出耀眼的青光和无边的剑气，$n唯一感受到的只有生命的消亡！\n" NOR;
}

