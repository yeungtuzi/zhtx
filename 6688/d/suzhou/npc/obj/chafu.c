//OBJECT: /d/suzhou/npc/obj/chafu.c
//by dwolf                   
//97.11.7

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name( BLK"茶壶"NOR, ({ "cha hu", "hu" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
		set("long", YEL"一只装茶水的茶壶。\n"NOR);
                set("value", 1000);
			set("max_liquid", 15);
        }
	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "tea",
		"name": "香茶",
		"remaining": 15,
		"drunk_apply": 6,
	]) );

        setup();
}                                                    

