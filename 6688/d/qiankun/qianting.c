// qianting.c 前厅
// by Masterall
inherit ROOM;
void create()

{set("short", "前厅");
set("long", @LONG
    这里是乾坤教的前厅，里面布置得倒是干净后院，几张太师椅，几个茶几，你要是
渴了可以先在这里喝口水(drink)。南面是大门，北面是石板路，有一条小路通往乾坤教
的机密要处。
LONG
        );
 
        set("exits", ([
                "north" : __DIR__"shibanlu3",
                "south" : __DIR__"gate",
        ]));
setup();
} 
void init()
{
         add_action("do_drink", "drink");
}
 
int do_drink(string arg)
{
if( (int)this_player()->query("water") >=
                 (int)this_player()->max_water_capacity() )
                 return notify_fail("你已经再也喝不下一滴水了。\n");
         message_vision("$N在桌边端起茶杯喝了几口水。\n", this_player());
         this_player()->add("water", 20);
         return 1;
}

