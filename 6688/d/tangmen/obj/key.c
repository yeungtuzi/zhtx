//key.c
//by tang

#include <ansi.h>

inherit ITEM;

void create()
{
    	set_name("钥匙",({ "key" }) );
        	set("long", "一把黄澄澄的钥匙。\n");
        	set("unit", "枚");
        	set("base_weight", 200);

        	set("no_sell", 1);
}

