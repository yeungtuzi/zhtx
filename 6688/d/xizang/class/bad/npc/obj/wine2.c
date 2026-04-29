// /d/xizang/class/bad/npc/obj/wine2.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("烈酒", ({ "strong wine", "wine", "jiu"}));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一碗烈酒.");
		set("unit", "碗");
		set("value", 120);
		set("max_liquid", 1);
	}
	set("liquid", ([
		"type": "alcohol",
		"name": "烈酒",
		"remaining": 1,
		"drunk_apply": 50,
	]));
}
