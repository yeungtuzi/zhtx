// /d/xizang/class/bad/npc/obj/card4.c

inherit ITEM;

void create()
{
        set_name("复仇卡", ({ "card" })):
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "张");
	set("long","这是一张小卡片,上面印着:<睚眦必报>");
	set("value", 175);
        }
}
