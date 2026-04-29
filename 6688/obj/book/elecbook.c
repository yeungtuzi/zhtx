// /obj/book/elecbook.c

inherit ITEM;

void create()
{
        set_name("电子线路", ({"electronics book", "electronics", "book"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本电子线路教科书.\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name": "electronics",
                "exp_required": 0,
                    "sen_cost": 40,
                "difficulty": 30,
                "max_skill": 45,
                ]) );
        }
}
