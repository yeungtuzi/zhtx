// crystal.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"魔族水晶"NOR, ({ "magic crystal", "crystal" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "象征着权力和实力的水晶，归庞斑所有。\n");
//                set("no_get", 1);
//                set("no_give", 1);
//                set("no_drop", 1);
//                set("no_put", 1);
                set("unpawnable",1);
                set("research",400);
                set("unit", "颗");
                set("weight", 50);
                set("value", 100);
        }
}

