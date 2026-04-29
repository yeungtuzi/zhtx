// /d/xizang/class/snow_mnt/obj/book4.c

inherit ITEM;

void create()
{
        set_name("波罗密多心经", ({ "bolomiduo xinjing" "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这是一本佛经。\n");
                set("value", 70);
                set("material", "paper");
                set("skill", ([
                        "name":                 "buddism",                // name of the skill
                        "exp_required": 0,                              // minimum combat experience required
                                                                                        // to learn this skill.
                        "sen_cost":             50,                             // gin cost every time study this
                        "difficulty":   50,                             // the base int to learn this skill
                                                                        // modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    150                              // the maximum level you can learn
                                                                                        // from this object.
                ]) );
        }
}
