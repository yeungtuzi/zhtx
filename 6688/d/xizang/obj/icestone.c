// /d/xizang/obj/icestone.c

inherit ITEM;

void create()
{
	set_name("冰碛石", ({ "ice stone", "stone" }));
	set_wieght("500");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long",@TEXT
这是一块晶莹洁白的石头,差不多有拳头一样大.它就是夹藏于万年冰川中
的冰碛石,是一种雕刻的好材料.
TEXT
);
	set("value", 50);
	}
}
