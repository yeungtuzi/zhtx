// qishi.c

inherit ROOM;

void create()
{
        set("short", "棋室");
        set("long", @LONG
这间屋子的四壁都是白色的，屋里什么东西都没有，只是在屋子的
中央放着一张竹制的桌子，上面放着一张棋枰，旁边有两把椅子而已。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"southeast"  : __DIR__"zoulang1",
]));
        
        set("objects", ([
                (__DIR__"npc/heibaizi"):1,
         ]));               
        setup();
        replace_program(ROOM);
}
