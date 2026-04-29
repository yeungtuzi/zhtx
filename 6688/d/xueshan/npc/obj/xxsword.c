//OBJ:/d/xueshan/npc/obj/xsword.c
//By tlang for 旋芒宝剑

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit SWORD;
int move();


int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIM"旋芒"+HIW"宝剑"NOR, ({ "lighting sword", "sword" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "旋芒宝剑，留赠有缘.\n");
                set("value", 0);
                set("material", "crimson gold");
        }
        init_sword(299);
        setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        me->add("force",me->query("force_factor"));
        return this_object()->name()+ HIC "从"+HIR"$N"+HIC"手中化作"+HIW"数"+HIG"道"+HIY"旋"+HIM"芒"+HIC"，刺破了天灵万物，直飞向寰宇！\n"NOR;
}




