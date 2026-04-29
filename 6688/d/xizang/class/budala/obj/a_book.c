// /d/xizang/class/budala/obj/a_book.c

inherit ITEM;

void create()
{
        set_name("佛经", ({ "fo jing", "shu", "book", "jing"}));
	set_weight(600);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本由金粉混合鲜血抄写的佛经。\n");
                set("value", 1500);
		set("material", "paper");
                set("skill", ([
                        "name": "zang-buddhi",
			"exp_required": 10000,
			"jing_cost":    20,
			"difficulty":   30,
			"max_skill":    50+random(80),
			"base_skill": 	"zang-buddhi",
		"base_skill_level": 	50
		]) );
        }
}
