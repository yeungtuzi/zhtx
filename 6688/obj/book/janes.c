// /obj/book/janes.c

inherit ITEM;

void create()
{
        set_name("简氏年鉴", ({ "janes yearbook of weapons", "janes book", 
"book" }) );
        set_weight(6400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "套");
                set("long","这是一套原文本简氏武器年鉴.\n");
                set("value", 450000);
                set("material", "paper");
                set("skill", ([
                        "name": "english",
                "exp_required": 0,
                "sen_cost":  60,
                "difficulty":45,
                "max_skill": 150,
                ]) );
        }
}
