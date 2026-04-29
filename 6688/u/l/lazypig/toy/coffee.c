// /obj/food/waterpot.c

inherit ITEM;

int do_drink(string arg)
{
       object me;
       me=this_player();
       if (!id(arg))
return notify_fail("你要喝什么？\n");
me->add("sen",1000);
write("你喝下一杯咖啡,感觉清醒多了.\n");
destruct(this_object());
       return 1;
}
void init()
{
        add_action("do_drink","drink");
}
void create()
{
        set_name("咖啡", ({ "coffee","kafei"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一杯热气腾腾的咖啡,喝了也许会清醒一些. \n") ;
                set("unit", "个");
                set("value", 50);
                set("max_liquid", 10);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "name": "清水",
                "remaining": 10,
        ]) );
}
