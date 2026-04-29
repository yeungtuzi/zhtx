// Room: /d/gumu/midao2.c 
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "midao2");
        set("long", @LONG
        你走在地道里，四周回响着“咚咚”的脚步声。尽管明知头上的怪石不会碰
着你，你仍不由自主的弓着腰身，加快了步伐...
LONG
        );
        set("no_sleep_room", 1);
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"rukou",
  "northwest" : __DIR__"dong3",
  "northeast" : __DIR__"midao3",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
> 