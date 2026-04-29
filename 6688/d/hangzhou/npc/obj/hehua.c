// hehua.c
//by dwolf

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"荷花 "NOR, ({"he hua", "hua", "flower"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "这是一朵白荷花。\n");
                set("value", 20);
        }
        setup();
}


