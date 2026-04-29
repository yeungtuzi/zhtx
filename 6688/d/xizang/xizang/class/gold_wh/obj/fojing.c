// /d/xizang/class/gold_wh/obj/fojing.c

inherit ITEM;

void create()
{
        set_name("佛经", ({ "fo jing", "shu", "book", "jing"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本普通的佛经。\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "zang-buddhi",
                        "exp_required": 0,
                        "jing_cost":    10,
                        "difficulty":   10,
                        "max_skill":    10+random(50)
                ]) );
        }
}
