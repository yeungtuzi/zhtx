// shanlu2.c 山路
// by Masterall
 
inherit ROOM;
 
void create()
{
        set("short", "山路");
        set("long", @LONG
    你走在一条崎岖的山路上，周围草莽林立，险象环生，难怪乾坤教会把总舵选在这
里，据说官府派兵前来剿灭，没有一次功成而返，全身而退的。你心中一怕，不由得感
到有些心惊胆战，不寒而栗。
LONG
        );
         set("outdoors", "qiankun");
 
        set("exits", ([
                "southdown" : __DIR__"shanlu3",
                "westup" : __DIR__"shanlu1",
        ]));
        set("objects",([
                 __DIR__"npc/jiaotu" : 2,
         ]));
        setup();
        replace_program(ROOM);
} 
 

