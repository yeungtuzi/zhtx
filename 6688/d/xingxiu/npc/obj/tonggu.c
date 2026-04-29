// tonggu.c

inherit ITEM;

void create()
{
        set_name("铜鼓", ({ "tonggu" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一只金光闪闪的铜鼓，鼓吹具。\n");
                set("value", 70);
        }
        setup();
}
