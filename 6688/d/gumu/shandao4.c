// Room: /d/gumu/shandao4.c 
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "山道");
        set("long", @LONG
    这是一终南山山后中的一条小道，小道的东边是一
处峭壁，西边是一片荆棘。不时从树丛中传来声声虫叫。

LONG
        );
       set("exits", ([  
  "north" : __DIR__"xiaoxi.c",
 "southeast" : __DIR__"shandao5",
 
 
]));
 /* set("objects", ([
                __DIR__"npc/yangnu" : 1,
        ]));*/
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}