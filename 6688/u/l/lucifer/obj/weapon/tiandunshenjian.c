//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 天 遁 神 剑 

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit SWORD;
//inherit F_UNIQUE;

int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIC"天 "+HIY"遁 "+HIB"神 "HIG"剑"NOR, ({ "tiandun shenjian", "jian" }) );
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
                set("long",  "这是当年吕洞宾祖师爷执剑斩妖除魔时化为青龙的天遁神剑。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "crimson gold");
                set("wield_msg",
                        HIC"天地间一道雳闪，青龙已出水，$n却在$N的手中，散发出摄人魂魄的光芒。\n"NOR);
                set("unequip_msg", HIM"$N将$n插回腰间的剑鞘。\n"NOR);
                set("weapon_prop/attack", this_player()->query_skill("tonggui-jian",1)/7);  
                set("weapon_prop/parry", this_player()->query_skill("yiyang-zhi",1)/4);  
       }
    init_sword(300);
       setup();
}

int wield()
{
        if( this_player()->query_skill("tonggui-jian",1) < 250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}

mixed hit_ob(object me)
{
        int skill,kee;
        skill=me->query_skill("tonggui-jian",1);
        kee=me->query("max_kee");
      //  if(random(3)==0)
        if(skill>random(399))
        message_vision(HIC"一道青色光气从天 遁 神 剑升起，在上空盘旋一周后注入$N的顶门！\n"NOR,me);
        me->add("eff_kee",kee*skill/800);

        if (me->query("eff_kee") > kee );
        {
        me->set("eff_kee",me->query("max_kee"));
        return; 
        }     
}
