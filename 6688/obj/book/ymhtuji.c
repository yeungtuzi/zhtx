// /obj/book/ymhtuji.c

inherit ITEM;

void create()
{
        set_name("玉米糊突击班教材", ({ "tuji book", "book" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","突击班教材,玉米糊编著.\n");
                set("value", 10000);
                set("material", "paper");
                set("skill", ([
                        "name": "english",
                "exp_required": 0,
                    "sen_cost": 50,
                  "difficulty": 30,
                   "max_skill": 80,
                ]) );
        }
}
