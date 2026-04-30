
//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 玉竹杖

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit STAFF;
//inherit F_UNIQUE;

int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIG"玉竹杖"NOR, ({ "yuzhu zhang", "zhang" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        set("no_get",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long",   "一根泛着淡淡青光的竹杖。它是丐帮帮主的信物。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "bamboo");
                set("wield_msg",
                        HIG "$N抽出一根青光闪闪的竹杖抓在手中。\n"NOR);
                set("unequip_msg", HIG "$N把手中的玉竹杖插回腰中。\n"NOR);
                set("weapon_prop/attack", this_player()->query_skill("dagou-bang",1)/7);   
                set("weapon_prop/speed", this_player()->query_skill("dagou-bang",1)/4);  
                set("weapon_prop/dodge", this_player()->query_skill("dagou-bang",1)/4);         
        }
    init_staff(300);
       setup();
}

int wield()
{
        if( this_player()->query_skill("dagou-bang",1) < 250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        // 2026-04-30: unused variable commented out
        // object weap;
        // 2026-04-30: unused variable commented out
        // int    wap,wdp;
        // 2026-04-30: unused variable commented out
        // string weap_name;
        int skill;
        skill=this_player()->query_skill("dagou-bang",1);
               if (damage_bonus < 0 ) return 0;


        if(victim == me) return;
        if(skill>random(399))
    //    if(random(3)==0)
        victim->receive_damage("kee",damage_bonus*2/3,me);
        return this_object()->name()+ HIG "带着疾风扫到$n的$l，$n站立不稳一个跟头摔倒在地！\n"+HIB"脑袋正好磕在自己兵器上，登时痛得“哇哇”怪叫！\n" NOR;
}



