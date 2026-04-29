// /d/xizang/class/budala/npc/obj/jiasha.c
// jiasha.c

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("喇嘛袍", ({"lama cloth", "robe", "cloth"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一件普通的喇嘛袍,似乎男女都可以穿\n");
                set("unit", "件");
                set("material", "cloth");
		set("armor_prop/armor", 1); 
       }
        setup();
}
