// /obj/toy/namecard.c

#include <ansi.h>

//inherit ITEM;
inherit COMBINED_ITEM;

void create()
{
        set_name("名片", ({ "namecard" }) );
        set_weight(10);
        set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "叠");
                set("base_unit", "张");
                set("base_weight", 5);
                set("base_value", 5);
                set_amount(1);
        }
}

