//copied from xo-wizard by tlang

inherit ITEM;

void create()
{
	set_name("照片", ({ "photo" }) );
	set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "曝光严重过度，照片上一片白花花的，根本看不清是谁。\n");
                }
        setup();
}

void init()
{
}
