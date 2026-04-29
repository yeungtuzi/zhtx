//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 黑索

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
        set_name(BLK "黑  索" NOR,  ({ "hei suo", "bian" }) );
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
                set("long",  "这是一条长约两丈的长索，通体黝黑无光，质地坚韧却极其柔软。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "龙筋");
                set("wield_msg",
                        BLK"$N运足内力，用劲一抖，手里变多了一条漆黑的长索，\n瞬间它便化成一条笔直的兵刃，如长矛，如杆棒，随时可能势如奔雷般的向着对方攻击而至。\n"NOR);
                set("unequip_msg", BLK"$N左拨右带，便将$卷上身来。\n"NOR);
                set("weapon_prop/attack", this_player()->query_skill("riyue-bian",1)/7);   
                set("weapon_prop/parry", this_player()->query_skill("riyue-bian",1)/4);   
       }
    init_whip(300);
       setup();
}

int wield()
{
        if( this_player()->query_skill("riyue-bian",1) < 250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
          int skill;
          skill=this_player()->query_skill("riyue-bian",1);
               if (damage_bonus < 0 ) return 0;
          if(skill>random(399))
    //    if(random(3)>0)
              victim->start_busy(me->query_skill("riyue-bian",1)/200+2);
        return this_object()->name()+ HIB "在$n的$l处又兜了回来，将$n全身紧紧缠住！\n" NOR;
}

