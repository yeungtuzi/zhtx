/* 再生草庐 内室1
   neishi1.c */

inherit ROOM;
  
void create()
{
        set("short", "过道");
        set("long", @LONG
这是一间通往内室的过道

LONG
        );
        set("exits", ([ 
  "east" : __DIR__"zscl",
  "west" : __DIR__"neishi",

]));
   setup();      
   replace_program(ROOM);
}
