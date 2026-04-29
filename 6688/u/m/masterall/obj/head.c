// head.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"首级"NOR, ({ "shou ji", "head" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一颗倭寇的首级，血淋淋的有些吓人，血债要用血来尝，这话的确不假。\n");
                set("unpawnable",1);
                set("research",400);
                set("unit", "颗");
                set("weight", 50);
                set("value", 100);
        }
}

