// /d/xizang/class/bad/npc/obj/card5.c

inherit ITEM;

void create()
{
        set_name("均富卡", ({ "card" })):
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "张");
	set("long","这是一张小卡片,上面印着:<等贵贱,均贫富>");
	set("value", 175000);
        }
}
