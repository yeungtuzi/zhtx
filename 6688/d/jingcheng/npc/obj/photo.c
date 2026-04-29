//seal.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("照片",({ "photo" }) );
        set("long", "一张泛著黄光的照片。\n");
        set_weight(20);
        set("no_sell", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "paper");
        }
        setup();    	

}

