//金钥匙
//key.c
inherit ITEM;

void create()
{
        set_name("金钥匙", ({ "gold key","key" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("long", "这是一把金光灿灿，小巧玲珑的金钥匙，不知道有什么用处。\n");
                }
        setup();
}

void init()
{
}
