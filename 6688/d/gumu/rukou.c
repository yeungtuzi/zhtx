inherit ROOM; 
 
void create() 
{ 
        set("short", "rukou");
        set("long", @LONG
        一种怪异的感觉涌上心头，似乎有什么东西象山似的压着你。抬头一看，只见
一嶙峋巨石就在你头顶上，随时都会掉下来的样子。两旁的石壁上挂着擦得干干净净的
油灯，那火舌一吞一吐、一摇一晃的动着，十分诡异。这里是一个地道的入口。
LONG
        );
        set("no_sleep_room", 1);
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"midao3",
  "north" : __DIR__"midao2",
  "up" : __DIR__"guancai3",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);}