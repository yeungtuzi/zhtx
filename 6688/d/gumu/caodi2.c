// Room: /d/gumu/caodi2.c 
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "草地");
        set("long", @LONG
    这是一终南山山后中的一片草地，地上长着绿油油
的小草，走在上面感到很舒服，草间夹杂着许多野花，不时
散发出阵阵幽香. 

LONG
        );
       set("exits", ([  
  "north" : __DIR__"caodi3",
 "south" : __DIR__"caodi",
 "west" : __DIR__"caoping",
 
]));
 /* set("objects", ([
                __DIR__"npc/yangnu" : 1,
        ]));*/
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}