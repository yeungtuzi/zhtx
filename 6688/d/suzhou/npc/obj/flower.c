// medicine: zitanhua.c
// Jay 3/18/96
//write by lysh

#include <ansi.h>
inherit ITEM;

void setup()
{}


void create()
{
        set_name(RED"红玫瑰"NOR, ({"hong meigui", "meigui"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "这是一朵红玫瑰。\n");
                set("value", 20);
        }
        setup();
}


