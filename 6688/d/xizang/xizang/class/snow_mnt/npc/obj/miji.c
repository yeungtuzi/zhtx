// /d/xizang/class/snow_mnt/npc/obj/miji.c
// 小无相功秘籍
// by mscat
//

inherit ITEM;

void create()
{
	set_name("小无相功秘籍", 
		({ "xiaowuxiang book", "book", "shu", "miji" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	 else {
		set("unit", "本");
		set("long","这是小无相功的基本修炼方法.\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name": "xiaowuxiang-gong",
			"exp_required": 20000,
			"sen_cost":  30,
			"difficulty":30,
			"max_skill": 99,
			"base_skill": "zang-buddhi",
			"base_skill_level": 99,
		]));
	}
}
