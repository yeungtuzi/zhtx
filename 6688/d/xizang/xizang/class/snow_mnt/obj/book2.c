// /d/xizang/class/snow_mnt/obj/book2.c
// force_book.c

inherit ITEM;

void create()
{
        set_name("楞伽经", ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这是一本常见的佛经。\n");
                set("value", 70);
                set("material", "paper");
                set("skill", ([
                        "name":                 "buddism",                // name of the skill
                        "exp_required": 0,                              // minimum combat experience required
                                                                                        // to learn this skill.
                        "sen_cost":             35,                             // gin cost every time study this
                        "difficulty":   25,                             // the base int to learn this skill
                                                                        // modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    20                              // the maximum level you can learn
                                                                                        // from this object.
                ]) );
        }
}
