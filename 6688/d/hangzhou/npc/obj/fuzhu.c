//by tlang 
//97.12
//fozhu.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"佛珠"NOR, ({ "fo zhu" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("material", "stell");
             }
        setup();
}

