// /obj/book/unix_hb.c

inherit ITEM;

void create()
{
        set_name("UNIX手册", ({ "unix handbook", "handbook", "book"}));
        set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","标准UNIX使用手册,美国AT&T实验室版权所有.\n");
                set("value", 10000);
                set("material", "paper");
                set("skill", ([
                        "name": "computer",
                "exp_required": 0,
                    "sen_cost": 90,
                  "difficulty": 55,
                   "max_skill": 99,
                ]) );
        }
}
