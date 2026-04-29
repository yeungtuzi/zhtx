// /obj/book/ymhtigao.c

inherit ITEM;

void create()
{
        set_name("玉米糊提高班教材", ({ "tigao book", "book" }) );
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","提高班教材,玉米糊编著.\n");
                set("value", 12000);
                set("material", "paper");
                set("skill", ([
                        "name": "english",
                "exp_required": 0,
                    "sen_cost": 60,
                  "difficulty": 44,
                   "max_skill": 160,
                ]) );
        }
}
