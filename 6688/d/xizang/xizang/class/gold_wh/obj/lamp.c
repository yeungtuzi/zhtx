// /d/xizang/class/gold_wh/obj/lamp.c

inherit ITEM;

void create()
{
        set_name("明灯", ({ "lamp", "deng", "ming deng"}));
	set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "盏");
                set("long","这是一盏长明灯。\n");
                set("value", 500);
                set("material", "iron");
		set("no_get","请不要把长明灯拿出明灯室!\n");
	}
}
