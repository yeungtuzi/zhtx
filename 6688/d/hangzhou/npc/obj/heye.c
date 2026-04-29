// heye.c
//by dwolf

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(GRN"荷叶"NOR, ({"he ye", "ye", "leaf"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "片");
                set("long", "这是一片新鲜的荷叶。\n");
                set("value", 20);
        }
        setup();
}


