// xiaoyaoring 

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit FINGER;

int query_autoload()
{
        return query("weapon_prop");
}


void create()
{
        set_name(HIM"七"+HIY"彩"+HIC"宝石"+HIR"戒指"NOR, ({ "xiaoyao ring", "ring" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        set("no_get",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long",   "这是逍遥派掌门信物，执戒指者即为逍遥派本代掌门。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "diamond");
                set("wield_msg",
                        "$N将$n拿出戴在右手无名指上，一道七色的光气从$n上升起，反过来又注入$N顶门。\n"NOR);
                set("weapon_prop/parry",this_player()->query_skill("douzhuanxingyi",1)/4);
                set("weapon_prop/attack", this_player()->query_skill("liumai-shenjian",1)/7);
        }
        init_finger(300);
       setup();
}

int wield()
{
        if( this_player()->query_skill("liumai-shenjian",1) < 250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weap;
        int    wap,wdp,skills;
        string weap_name;
        int skill;
        skill=this_player()->query_skill("liumai-shenjian",1);
        skills=-4*this_player()->query_skill("liumai-shenjian",1)/3;
               if (damage_bonus < 0 ) return 0;
        if(victim == me) return;
        if(skill>random(399))
 //       if(random(3)==0)
        victim->add("force", skills);
        me->add("force", -skills);
        if( me->query("force")> 2*me->query("max_force") )
        {
        me->set("force",2*me->query("max_force"));
        return;
        }
        return query("name")+HIR"轻微的接触到"+HIY"$n的$l，"+HIG"立即爆发出"+HIC"一道七彩的光芒！\n"+HIB"$n只觉得"+HIM"自己的内力犹如"+HIW"泥牛入海，去不复返！\n"NOR;
}

