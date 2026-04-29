// /obj/book/oxford.c

inherit ITEM;

void create()
{
        set_name("牛津英汉双解词典", ({ "oxford dictionary", "dictionary" }));
        set_weight(2400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","牛津英汉双解词典,商务印书馆出版.\n");
                set("value", 4000);
                set("material", "paper");
                set("skill", ([
                        "name": "english",
                "exp_required": 0,
                    "sen_cost": 35,
                  "difficulty": 25,
                   "max_skill": 60,
                ]) );
        }
}
