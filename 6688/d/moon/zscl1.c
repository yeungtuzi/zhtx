/* 通往再生草庐的小路  红鹰 翠燕
   zscl1.c */
 
inherit ROOM;
  
void create()
{
        set("short", "王屋山小路");
        set("long", @LONG
此处王屋山下，王屋山并不高峻,前面两个年轻男女一边走一边高声谈笑着
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"zscl2",
  "north": __DIR__"entry",
]));
        set("objects", ([
        __DIR__"npc/yiting" : 1,
        __DIR__"npc/yiming" : 1, 
                        ]) ); 
   setup();      
   replace_program(ROOM);
}
