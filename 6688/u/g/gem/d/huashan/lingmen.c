// lingmen.c

inherit ROOM;

void create()
{
        set("short", "濪灵门");
        set("long", 
@LONG
西岳庙的山门称为“濪灵门”，它和五门楼同为高大的砖石建筑，形制与北京的
端门颇相类似，虽不是很高大，但是却显的很是庄严肃穆，门口站着几个小道士看
来是负责看守西岳庙的人了。
LONG);
        set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"yuetai",
		"east" :  __DIR__"xiaolu6",
]));
        set("objects", ([
		 __DIR__"npc/xiao-daoshi": 2 
]));
        
        set("no_clean_up", 0);

        setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{

        if( (this_player()->query("family/family_name")!="华山派剑宗")
        && (objectp(present("xiao daoshi", environment(me)))) )
        {
                if (dir == "north" )
                {
                    return notify_fail("小道士一把拦住了你的去路：“你怎敢擅闯这密地，还不赶紧离去！”\n");
					
                }
        }
        return ::valid_leave(me, dir);
}
