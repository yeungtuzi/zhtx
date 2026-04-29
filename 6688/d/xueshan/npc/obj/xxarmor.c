//OBJ:/d/xueshan/npc/obj/xsword.c
//By tlang for 旋芒宝剑

#include <armor.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit ARMOR;
//inherit F_UNIQUE;

int query_autoload()
{
        return query("armor_prop");
}

void create()
{
        set_name(HIC"寒于"+HIW"宝衣"NOR, ({ "lighting armor", "armor" }) );
	set_weight(1);
        set("owner","no_owner");
	set("marks/寒于",1);
	set("no_drop",1);
	set("unpawnable",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "件");
                set("long",  "寒于宝衣，天衣无缝.\n");
		set("value", 0);
		set("material", "crimson gold");
                set("armor_prop/armor", 300);
                set("armor_prop/armor_vs_force", 300);
        }
	setup();
}

/*void init()
{
	seteuid(geteuid());
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	//victim->receive_wound("kee",damage_bonus/10);
	me->add("force",me->query("force_factor"));
}
*/
/*
int wear()
{
        if( this_player()->query_skill("force",1) < 300 )
                return notify_fail("你的内功不够，无法控制寒于宝衣的神奇力量。\n");
        return ::wear();
}
*/
