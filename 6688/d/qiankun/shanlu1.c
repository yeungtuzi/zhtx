// shanlu1.c 山路
// by Masterall
 
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
    你走在一条坚实的石阶上，再往前走就是乾坤教的总舵了，地势也逐渐开阔了起来
，但你仍然感觉到一阵阵的杀气，让你不由得又打了个冷颤。
LONG
        );
         set("outdoors", "qiankun");
 
        set("exits", ([
                "eastdown" : __DIR__"shanlu2",
                "northup" : __DIR__"guangchang",
        ]));
        set("objects",([
                 __DIR__"npc/jiaotu" : 2,
         ]));
setup();
replace_program(ROOM);
} 
 

