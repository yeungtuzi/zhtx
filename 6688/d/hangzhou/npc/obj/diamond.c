//by tlang
//diamond.c
//97.12

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"明珠"NOR, ({"diamond", "ming zhu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "这是一朵白荷花。\n");
                set("value", 20);
        }
        setup();
}


