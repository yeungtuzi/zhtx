// /d/xizang/class/bad/npc/obj/jianpu.c

inherit ITEM;

void create()
{
        set_name("剑谱", ({ "sword book", "book", "shu"}));
	set_weight(120);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是本手抄的剑谱.");
		set("value", 500);
		set("material", "paper");
                set("skill", ([
                        "name": "yaksword",
			"exp_required": 2000,
			"sen_cost":  30,
			"difficulty":20,
			"max_skill": 125,
		]));
	}
}
