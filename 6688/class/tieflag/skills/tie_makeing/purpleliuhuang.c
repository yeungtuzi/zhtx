inherit ITEM;
#include <ansi.h>
inherit F_UNIQUE;

void create()
{
        set_name(MAG"紫色硫磺"NOR, ({ "purpleliuhuang" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "不知道干什么用的。\n");
                set("unit", "把");
                set("value", 0);
        }
        setup();
}


