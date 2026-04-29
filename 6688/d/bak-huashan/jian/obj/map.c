//地图
//map.c
inherit ITEM;

void create()
{
        set_name("神秘地图", ({ "secret map","map" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("value", 1);
                set("long", "这是一张地图，上面的图画十分模糊，画得也不知道是什么地方。\n");
                }
        setup();
}

void init()
{
}
