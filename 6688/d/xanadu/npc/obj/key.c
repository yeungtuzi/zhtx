// key.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("接天楼主钥匙", ({ "jtl key", "key" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是浪翻云掌管的接天楼的钥匙。\n");
                set("no_get", 1);
                set("no_put", 1);
                set("unpawnable",1);
                set("research",300);
                set("unit", "把");
                set("weight", 50);
                set("value", 100);
        }
}

