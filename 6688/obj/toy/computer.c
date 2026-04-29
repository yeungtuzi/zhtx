// /obj/toy/computer.c
// /d/peking/npc/obj/p2.c

inherit ITEM;

void create()
{
        set_name("奔腾II", ({ "computer", "p2" }) );
        set_weight(20000);
        set("no_get",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        "这是最新出品的奔腾II型机.\n");
                set("unit", "台");
                set("value", 1000000);
                set("using", 1 );
        }
        setup();
}

