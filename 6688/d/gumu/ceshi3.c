// Room: /d/gumu/ceshi3.c
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "侧室");
        set("long", @LONG
        你这是一间较小的石室，约一人高，这里是古墓派
储藏物品的地方。


LONG
        );
        set("no_sleep_room", 1);
        set("exits", ([ /* sizeof() == 3 */
  
  "south" : __DIR__"zoudao3",
  
]));
	set("objects",([
	  	__DIR__"obj/jiang":1,
//		__DIR__"obj/yufengzhen":1,				
	]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 