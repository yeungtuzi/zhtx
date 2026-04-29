#include <ansi.h>

#include <armor.h>
inherit WRISTS;

void create()
{
    set_name(HIG "魔法钻戒" NOR, ({"magic ring","ring"}) );
     set_weight(50);
     set("no_sell",1);
     set("unpawnable",1);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", "一枚精致的戒指，具有神奇的魔力。\n");
            set("unit", "枚");
            set("value", 0);
            set("no_drop", 1);
            set("armor_prop/armor",10);
            set("armor_prop/dodge", 10);
            set("armor_prop/spells", 50);
            set("wear_msg", "$N把$n带在手上。\n");
     }
     setup();
}

void init()
{
	object me;

	me = this_player();
        if( me==environment() && me->query("mana_factor")<100 )
//i change it to 100 le masterall
	{
		message_vision(GRN"$N手上的"+query("name")+GRN"突然闪出一道奇异的光芒注入$N的顶门！\n"NOR,me);
//                this_player()->add("mana_factor",50);
	}
}
