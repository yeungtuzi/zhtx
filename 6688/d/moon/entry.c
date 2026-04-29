/* 通往再生草庐的小路  红鹰 翠燕
   entry.c */
 
inherit ROOM;
  
void create()
{
        set("short", "王屋山路口");
        set("long", @LONG，
此处王屋山下脚下的一条小路，前面就是王屋山，虽然山并不高，但据说也是藏龙卧虎之地。
路边灌木成林，不是跑出来一只兔子。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"zscl1",
  "north" : "/d/road/rjdtoly3",
]));
        set("objects", ([
        __DIR__"npc/rabit" : random(3)+1,
                        ]) ); 
   setup();      
   replace_program(ROOM);
}
