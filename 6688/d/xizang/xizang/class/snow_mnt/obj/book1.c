// /d/xizang/class/snow_mnt/obj/book1.c
// force_book.c

inherit ITEM;

void create()
{
        set_name("金刚经", ({ "book" }));
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
                        "sen_cost":             30,                             // gin cost every time study this
                        "difficulty":   20,                             // the base int to learn this skill
                                                                        // modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    10                              // the maximum level you can learn
                                                                                        // from this object.
                ]) );
        }
}
