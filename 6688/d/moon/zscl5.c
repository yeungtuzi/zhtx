/* 

   zscl5.c */
 
inherit ROOM;
  
void create()
{
        set("short", "平地");
        set("long", @LONG
这里居然是一块很大的平地，四周风景极为美丽，山虽不高，却也云雾缭绕，正所谓:
山不在高，有仙则灵.自古以来，故老相传，王屋山正是颇多仙人灵迹。前面一个木屋，
门开着，隐约能看见一个中年男子坐在屋子里面。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"zscl",
  "westdown" : __DIR__"zscl4",
]));
        set("objects", ([
        __DIR__"npc/monkey" : random(3)+1,
                        ]) ); 

   setup();      
   replace_program(ROOM);
}
