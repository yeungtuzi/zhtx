// /obj/book/gre.c

inherit ITEM;

void create()
{
        set_name("GRE词汇", ({ "gre book", "gre", "book"}));
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","GRE词汇,玉米糊编著.\n");
                set("value", 4500);
                set("material", "paper");
                set("skill", ([
                        "name": "english",
                "exp_required": 0,
                    "sen_cost": 40,
                  "difficulty": 40,
                   "max_skill": 150,
                ]) );
        }
}
